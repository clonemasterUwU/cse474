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
    GE      ">="
    EQ      "=="
    LE      "<="
    GT      ">"
    LT      "<"
    NE      "!="
    AND     "&&"
    OR      "||"
    NOT     "!"
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
        DO
        WHILE
        IF
        THEN
        ELSE
        ;
%token <std::string> IDENTIFIER "identifier"
%token <int> SV_INT
%token <char> SV_CHAR
%token <double> SV_REAL
%token <bool> SV_BOOL

%type <int> sv_sign_int
%type <double> sv_sign_real


%type <std::unique_ptr<StatementList>> declare_block declare_line_list main_block statement_list basic_block
%type <std::unique_ptr<MultiDeclarationStatement>> declare_line
%type <std::pair<std::string,std::unique_ptr<Exp>>> declare_statement
%type <primitive> type_identifier
%type <std::unique_ptr<Exp>> expression
%type <arithmetic_b_op> a_b_op
%type <bool_a_op> b_a_op
%type <bool_b_op> b_b_op
%type <bool_u_op> b_u_op
%type <std::vector<std::unique_ptr<IdentifierExist>>> identifier_list
%type <std::unique_ptr<AssignmentStatement>> assignment
%type <std::unique_ptr<StatementLike>> statement else_block
%type <std::unique_ptr<ReadStatement>> read_statement
%type <std::unique_ptr<WriteStatement>> write_statement
%type <std::vector<std::unique_ptr<Exp>>> expression_list
%type <std::unique_ptr<IfThenElse>> if_then_else if_else_if
%type <std::unique_ptr<WhileDo>> while_do
%type <std::unique_ptr<BooleanExp>> boolean_expression
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
        basic_block "." 
    {
        $$=std::move($1);
    }
    ;
    
basic_block:
    BEGIN statement_list END
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
    |   if_then_else
    {
        $$=std::move($1);
    }
    |   while_do
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

if_then_else:
        if_else_if else_block
    {   
        $$=std::move($1);
        $$->_else = std::move($2);
    }
    ;

if_else_if:
        IF boolean_expression THEN basic_block
    {
        $$ = std::make_unique<IfThenElse>();
        $$->add(std::move($2),std::move($4));
    }
    |   if_else_if ELSE IF boolean_expression THEN basic_block
    {
        $1->add(std::move($4),std::move($6));
        $$=std::move($1);
    }
    ;

else_block:
        %empty
    {
        $$=std::unique_ptr<StatementLike>(nullptr);
    }
    |   ELSE basic_block
    {
        $$=std::move($2);
    }
    ;

while_do:
        WHILE boolean_expression DO basic_block
    {
        $$=std::make_unique<WhileDo>(std::move($2),std::move($4));
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

%left "==" "!=" "<" ">" ">=" "<=" ;
%left "+" "-" "||" ;
%left "*" "/" "%" "&&" ;
%precedence NEG;
%precedence "!";
/*
https://www.gnu.org/software/bison/manual/html_node/Infix-Calc.html
https://stackoverflow.com/questions/57835669/flex-a-number-with-a-leading-sign-but-dont-eat-addition-subtraction?rq=1
*/

boolean_expression:
        SV_BOOL
    {
        $$ = std::make_unique<LiteralBoolExp>(drv,std::make_unique<BoolLiteral>(drv,$1));
    }
    |   expression b_a_op expression
    {
        $$ = std::make_unique<BinaryArithmeticBoolExp>(drv,std::move($1),std::move($3),$2);
    }
    |   boolean_expression b_b_op boolean_expression
    {
        $$ = std::make_unique<BinaryBoolExp>(drv,std::move($1),std::move($3),$2);
    }
    |
    b_u_op boolean_expression %prec "!"
    {
        $$ = std::make_unique<UnaryBoolExp>(drv,std::move($2),$1);
    }
    ;

expression:
        IDENTIFIER
    {
        $$= std::make_unique<IdentifierExist>(drv,std::move($1));
    }
    |   sv_sign_int
    {
        $$=std::make_unique<IntegerLiteral>(drv,$1);
    }
    |   sv_sign_real
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
    |   expression a_b_op expression
    {
        $$ = std::make_unique<ArithmeticExp>(drv,std::move($1),std::move($3),$2);
    }
    |   "(" expression ")"
    {
        $$ = std::move($2);
    }
    ;

sv_sign_int:
        SV_INT
    {
        $$=$1;
    }
    |   "-" SV_INT %prec NEG
    {
        $$=-$2;
    }
    ;

sv_sign_real:
        SV_REAL
    {
        $$=$1;
    }
    |   "-" SV_REAL %prec NEG
    {
        $$=-$2;
    }
    ;

a_b_op:
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
    |   "%"
    {
        $$=h_ast::MOD;
    }
    ;


b_a_op:
        ">="
    {
        $$=h_ast::GE;
    }
    |   "!="
    {
        $$=h_ast::NE;
    }
    |   "=="
    {
        $$=h_ast::EQ;
    }
    |   "<"
    {
        $$=h_ast::LT;
    }
    |   ">"
    {
        $$=h_ast::GT;
    }
    |   "<="
    {
        $$=h_ast::LE;
    }
    ;

b_b_op:
        "&&"
    {
        $$=h_ast::AND;
    }
    |   "||"
    {
        $$=h_ast::OR;
    }
    ;

b_u_op:
        "!"
    {
        $$=h_ast::NOT;
    }
    ;

%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}


