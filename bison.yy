%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#include <unordered_map>
#include <string>
#include <vector>


class driver;
#include "parser_def.h"
#include "bison.h"

}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {

#include "driver.h"
}

%define api.token.prefix {H_}
//%define api.value.automove

%token
    EOF  0  "end of file"
    ASSIGN  ":="
    MINUS   "-"
    PLUS    "+"
    STAR    "*"
    SLASH   "/"
    LPAREN  "("
    RPAREN  ")"
    COMMA   ","
    SEMI    ";"
    DOT     "."
;

%token  PROGRAM "program"
        BEGIN
        END
        READ
        WRITE
        INTEGER
        REAL
        CHAR
        BOOLEAN
        TRUE
        FALSE
        VAR
        ;
%token <std::string> IDENTIFIER "identifier"
%token <int> SV_INT
%token <char> SV_CHAR
%token <double> SV_REAL
%token <bool> SV_BOOL


%type <std::pair<std::string,type>> declare_statement;
%type <std::pair<std::string,type>> expression;
%type <std::vector<std::pair<std::string,type>>> declare_statement_list;
%type <std::vector<std::pair<std::string,type>>> identifier_exist_list;
%type <std::vector<std::pair<std::string,type>>> expression_list;
%type <std::string> identifier_not_exist;
%type <type> type_identifier;
%type <std::pair<std::string,type>> identifier_exist;




%%
%start program;
program:
        "program" declare_block main_block 
    {
        drv.output << "halt\n";
    }
    ;

declare_block:
        %empty
    |   VAR declare_line_list {}
    ;

declare_line_list:
        declare_line
    |   declare_line_list declare_line
    ;
declare_line:
        type_identifier declare_statement_list ";"
        {
            for(auto p:$2){
                if( p.second == ::ANY){
                    p.second = $1;
                    drv.symbol_table[p.first]=$1;
                } else if(p.second != $1 && $1 != ::REAL ){
                    throw yy::parser::syntax_error (drv.location,"conversion from " + p.second + " to " + $1 + " is not allowed");
                }
            }
            for(auto p:$2){
                drv.output << "declare " << p.first << "," << $1 << '\n';
            }
            drv.output << drv.buffer.rdbuf();
            drv.buffer.clear();
        }
    ;

type_identifier:
        INTEGER {$$=::INT;}
    |   REAL {$$=::REAL;}
    |   CHAR {$$=::CHAR;}
    |   BOOLEAN {$$=::BOOL;}
    ;

declare_statement_list:
        declare_statement 
    {
        $$=std::vector<std::pair<std::string,std::string>>{std::move($1)};
    }
    |   declare_statement_list COMMA declare_statement 
    {
        $1.push_back(std::move($3));
        $$ = std::move($1);
    }
    ;

declare_statement:
        identifier_not_exist
    {
        $$=make_pair($1,"any");
    }
    |   identifier_not_exist ":=" SV_INT
    {
        drv.buffer << "store " << $3 << ", " << $1 << '\n';
        drv.symbol_table[$1]=drv.INT;
        $$=std::make_pair($1,drv.INT);
    }
    |   identifier_not_exist ":=" SV_REAL
    {
        drv.buffer << "store " << $3 << ", " << $1 << '\n';
        drv.symbol_table[$1]=drv.REAL;
        $$=std::make_pair($1,drv.REAL);
    }
    |   identifier_not_exist ":=" SV_CHAR
    {
        drv.buffer << "store '" << $3 << "', " << $1 << '\n';
        drv.symbol_table[$1]=drv.CHAR;
        $$=std::make_pair($1,drv.CHAR);
    }
    |   identifier_not_exist ":=" SV_BOOL
    {
        drv.buffer << "store " << $3 << ", " << $1 << '\n';
        drv.symbol_table[$1]=drv.BOOL;
        $$=std::make_pair($1,drv.BOOL);
    }
    |   identifier_not_exist ":=" identifier_exist
    {
        drv.buffer << "store " << $3.first << ", " << $1 << '\n';
        drv.symbol_table[$1]=$3.second;
        $$=std::make_pair($1,$3.second);
    }
    ;

identifier_not_exist:
    IDENTIFIER
    {
        drv.symbol_not_exist($1);
        $$=std::move($1);
    }
    ;

identifier_exist:
    IDENTIFIER
    {
        $$=drv.find_symbol($1);
    }
    ;
    
main_block:
        BEGIN statement_list END "." {}
    ;

statement_list:
        statement 
    |   statement_list statement 
    ;

statement:
        READ "(" identifier_exist_list ")" ";" 
    {
        for(auto& p:$3){
            drv.output << "read " << p.first << ", " << p.second << '\n';
        }
    }
    |   WRITE "(" expression_list ")" ";"
    {
        for(auto& p:$3){
            drv.output << "write " << p.first << ", " << p.second << '\n';
        }
    }
    |   identifier_exist ":=" expression ";"
    {
        if($3.second != $1.second){
            if($1.second!=drv.INT && $1.second!=drv.REAL){
                throw yy::parser::syntax_error(drv.location,"cannot assign "+$3.second+" to a "+$1.second+" variables");
            }
            auto temp = drv.get_temp_name();
            drv.output << ($1.second == drv.INT ? "rtoi ":"itor ") << $3.first << ", " << temp << '\n';
            $3.first = std::move(temp);
        }
        drv.output << "store " << $3.first << ", " << $1.first << '\n';
    }
    ;

identifier_exist_list:
        identifier_exist
    {
        $$=std::vector<std::pair<std::string,std::string>>{std::move($1)};
    }
    |   identifier_exist_list "," identifier_exist
    {
        $1.push_back(std::move($3));
        $$=std::move($1);
    }
    ;

expression_list:
        expression
    {
        $$=std::vector<std::pair<std::string,std::string>>{std::move($1)};
    }
    |   expression_list "," expression
    {
        $1.push_back(std::move($3));
        $$ = std::move($1);
    }
    ;

%left "+" "-";
%left "*" "/";
expression:
        expression "+" expression
    {
        $$ = drv.op($1,$3,"add");
    }
    |   expression "-" expression
    {
        $$ = drv.op($1,$3,"sub");
    }
    |   expression "*" expression
    {
        $$ = drv.op($1,$3,"mul");
    }
    |   expression "/" expression
    {
        $$ = drv.op($1,$3,"div");
    }
    |   "(" expression ")"
    {
        $$ = std::move($2);
    }
    |   identifier_exist
    {
        $$ = std::move($1);
    }
    |   SV_INT
    {
        $$ = make_pair(std::to_string($1),drv.INT);
    }
    |   SV_CHAR 
    {
        $$ = make_pair("'"+$1+'\'',drv.CHAR);
    }
    |   SV_REAL 
    {
        $$ = make_pair(std::to_string($1),drv.REAL);
    }
    |   SV_BOOL 
    {
        $$ = make_pair(std::to_string(($1?1:0)),drv.BOOL);
    }
    ;
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}


