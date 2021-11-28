%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>

# include "bison.h"
#include "driver.h"
// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

%}

%option noyywrap nounput batch debug noinput caseless

alpha [a-zA-Z]
digit [0-9]
white_space [ \t]+
new_line "\r"|"\n"|"\r\n"
identifier {alpha}(_|{alpha}|{digit})*
int_literal {digit}+
real_literal {digit}+\.({digit}+)?
bool_literal "TRUE"|"FALSE"
char_literal '.'

%{
    // Code run each time a pattern is matched.
    #define YY_USER_ACTION \
        loc.step(); \
        for (int i = 0; yytext[i] != '\0'; i++) { \
            if(yytext[i] == '\n') { \
                loc.lines(); \
                loc.end.column=1; \
            } else { \
                loc.columns(); \
            } \
        }
%}

%x STATE_COMMENT
%%
%{
    // A handy shortcut to the location held by the driver.
    yy::location& loc = drv.location;
    // Code run each time yylex is called.
    loc.step ();
%}

"/*" { BEGIN(STATE_COMMENT); }
<STATE_COMMENT>"*/" { BEGIN(INITIAL); }
<STATE_COMMENT>[^*] { /* ignore the text of the comment */ }
<STATE_COMMENT>\* { /* ignore *'s that aren't part of */ }
    /* single line comment */
"//".* { /* ignore single line comment */ }
{white_space} { /* ignore white space */ }
{new_line} { /* ignore new line */ }

"-"         return yy::parser::make_MINUS  (loc);
"+"         return yy::parser::make_PLUS   (loc);
"*"         return yy::parser::make_STAR   (loc);
"/"         return yy::parser::make_SLASH  (loc);
"%"         return yy::parser::make_MOD    (loc);
"("         return yy::parser::make_LPAREN (loc);
")"         return yy::parser::make_RPAREN (loc);
":="        return yy::parser::make_ASSIGN (loc);
";"         return yy::parser::make_SEMI (loc);
","         return yy::parser::make_COMMA (loc);
"."         return yy::parser::make_DOT (loc);
">="        return yy::parser::make_GE(loc);
"<>"        return yy::parser::make_NE(loc);
"<="        return yy::parser::make_LE(loc);
"="        return yy::parser::make_EQ(loc);
">"        return yy::parser::make_GT(loc);
"<"        return yy::parser::make_LT(loc);





  /* keywords */
"PROGRAM"   return yy::parser::make_PROGRAM (loc);
"BEGIN"     return yy::parser::make_BEGIN (loc);
"END"       return yy::parser::make_END (loc);
"VAR"       return yy::parser::make_VAR (loc);
"READ"      return yy::parser::make_READ (loc);
"WRITE"     return yy::parser::make_WRITE (loc);
"INTEGER"   return yy::parser::make_INTEGER (loc);
"REAL"      return yy::parser::make_REAL (loc);
"CHAR"      return yy::parser::make_CHAR (loc);
"BOOLEAN"   return yy::parser::make_BOOLEAN (loc);
"IF"        return yy::parser::make_IF (loc);
"THEN"      return yy::parser::make_THEN (loc);
"ELSE"      return yy::parser::make_ELSE (loc);
"WHILE"     return yy::parser::make_WHILE (loc);
"DO"        return yy::parser::make_DO (loc);
"AND"        return yy::parser::make_AND(loc);
"OR"        return yy::parser::make_OR(loc);
"NOT"        return yy::parser::make_NOT(loc);
{int_literal}      {
    errno = 0;
    long n = strtol (yytext, nullptr, 10);
    if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "integer is out of range: "
                                    + std::string(yytext));
    return yy::parser::make_SV_INT (n, loc);
}
{real_literal}      {
    errno = 0;
    double n = strtod (yytext,nullptr);
    if(errno==ERANGE) throw yy::parser::syntax_error (loc, "real is out of range: "
                                                          + std::string(yytext));
    return yy::parser::make_SV_REAL(n,loc);
}
{bool_literal}      {
    return yy::parser::make_SV_BOOL(strcmp(yytext,"true")==0,loc);
}
{char_literal}      return yy::parser::make_SV_CHAR(yytext[1],loc);

{identifier}        return yy::parser::make_IDENTIFIER (yytext, loc);


.                   throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));

<<EOF>>    return yy::parser::make_EOF (loc);
%%

void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}
