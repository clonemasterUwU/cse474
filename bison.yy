%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#include <string>
#include <vector>


class driver;
#include "ast.h"
#include "bison.h"
using namespace h_ast;

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
    MOD     "%"
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



%type <std::unique_ptr<StatementList>> declare_block declare_line_list main_block statement_list
%type <std::unique_ptr<MultiDeclarationStatement>> declare_line
%type <std::pair<std::string,std::unique_ptr<Exp>>> declare_statement
%type <primitive> type_identifier
%type <std::unique_ptr<Exp>> expression
%type <arithmetic_b_op> alu
%type <std::vector<std::unique_ptr<IdentifierExist>>> identifier_list
%type <std::unique_ptr<AssignmentStatement>> assignment
%type <std::unique_ptr<StatementLike>> statement
%type <std::unique_ptr<ReadStatement>> read_statement
%type <std::unique_ptr<WriteStatement>> write_statement
%type <std::vector<std::unique_ptr<Exp>>> expression_list
%%
%start program;
program:
        "program" declare_block main_block 
    {
        $2->recursive_compile(drv);
        $3->recursive_compile(drv);
        drv.output << "halt\n";
    }
    ;

declare_block:
        %empty
    {
        $$ = std::unique_ptr<StatementList>();
    }
    |   VAR declare_line_list 
    {
        $$ = std::move($2);
    }
    ;

declare_line_list:
        declare_line ";"
    {
        $$ = std::make_unique<StatementList>();
        $$->add(std::move($1));
    }
    |   declare_line_list declare_line ";"
    {
        $1->add(std::move($2));
        $$=std::move($1);
    }
    ;
declare_line:
        type_identifier declare_statement 
    {
        $$ = std::make_unique<MultiDeclarationStatement>($1);
        $$->add(drv,std::move($2.first),std::move($2.second));
    }
    |   declare_line "," declare_statement
    {
        $1->add(drv,std::move($3.first),std::move($3.second));
        $$=std::move($1);
    }
    ;

type_identifier:
        INTEGER {$$=INT;}
    |   REAL {$$=REAL;}
    |   CHAR {$$=CHAR;}
    |   BOOLEAN {$$=BOOL;}
    ;

declare_statement:
        IDENTIFIER
    {
        $$={std::move($1),nullptr};
    }
    |   IDENTIFIER ":=" expression
    {
        $$={std::move($1),std::move($3)};
    }
    ;

main_block:
        BEGIN statement_list END "." 
    {
        $$=std::move($2);
    }
    ;
    
statement_list:
        %empty
    {
        $$=std::make_unique<StatementList>();
    }
    |   statement_list statement
    {
        $1->add(std::move($2));
        $$=std::move($1);
    }
    ;
statement:
        read_statement
    {
        $$=std::move($1);
    }
    |   write_statement
    {
        $$=std::move($1);
    }
    |   declare_line ";"
    {
        $$=std::move($1);
    }
    |   assignment ";"
    {
        $$=std::move($1);
    }
    ;

read_statement:
        READ "(" identifier_list ")" ";"
    {
        $$ = std::make_unique<ReadStatement>(std::move($3));
    }
    ;

write_statement:
        WRITE "(" expression_list ")" ";"
    {
        $$ = std::make_unique<WriteStatement>(std::move($3));
    }
    ;
    
assignment:
    IDENTIFIER ":=" expression 
    {
        $$=std::make_unique<AssignmentStatement>(drv,std::make_unique<IdentifierExist>(drv,std::move($1)),std::move($3));
    }
    ;

identifier_list:
        %empty
    {
        $$=std::vector<std::unique_ptr<IdentifierExist>>();
    }
    |   identifier_list IDENTIFIER
    {
        $1.push_back(std::make_unique<IdentifierExist>(drv,std::move($2)));
        $$=std::move($1);
    }
    ;

expression_list:
        %empty
    {
        $$=std::vector<std::unique_ptr<Exp>>();
    }
    |   expression_list expression
    {
        $1.push_back(std::move($2));
        $$=std::move($1);
    }
    ;

%left "+" "-";
%left "*" "/" "%";
expression:
        expression alu expression
    {
        $$ = std::make_unique<ArithmeticExp>(drv,std::move($1),std::move($3),$2);
    }
    
    |   "(" expression ")"
    {
        $$ = std::move($2);
    }
    |   IDENTIFIER
    {
        $$= std::make_unique<IdentifierExist>(drv,std::move($1));
    }
    |   SV_INT
    {
        $$=std::make_unique<IntegerLiteral>(drv,$1);
    }
    |   SV_REAL
    {
        $$=std::make_unique<RealLiteral>(drv,$1);
    }
    |   SV_BOOL
    {
        $$=std::make_unique<BoolLiteral>(drv,$1);
    }
    |   SV_CHAR
    {
        $$=std::make_unique<CharLiteral>(drv,$1);
    }
    ;

alu:
        "+"
    {
        $$=h_ast::ADD;
    }
    |   "-"
    {
        $$=h_ast::SUB;
    }
    |   "/"
    {
        $$=h_ast::DIV;
    }
    |   "*"
    {
        $$=h_ast::MUL;
    }
    | "%"
    {
        $$=h_ast::MOD;
    }
%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}


