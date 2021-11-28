// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "bison.h"


// Unqualified %code blocks.
#line 29 "/home/deal_with/CLionProjects/cse474/bison.yy"


#include "driver.h"

#line 50 "/home/deal_with/CLionProjects/cse474/bison.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 141 "/home/deal_with/CLionProjects/cse474/bison.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 70: // a_b_op
        value.YY_MOVE_OR_COPY< arithmetic_b_op > (YY_MOVE (that.value));
        break;

      case 44: // SV_BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 71: // b_a_op
        value.YY_MOVE_OR_COPY< bool_a_op > (YY_MOVE (that.value));
        break;

      case 72: // b_b_op
        value.YY_MOVE_OR_COPY< bool_b_op > (YY_MOVE (that.value));
        break;

      case 73: // b_u_op
        value.YY_MOVE_OR_COPY< bool_u_op > (YY_MOVE (that.value));
        break;

      case 42: // SV_CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case 43: // SV_REAL
      case 69: // sv_sign_real
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 41: // SV_INT
      case 68: // sv_sign_int
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 51: // type_identifier
        value.YY_MOVE_OR_COPY< primitive > (YY_MOVE (that.value));
        break;

      case 52: // declare_statement
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::unique_ptr<Exp>> > (YY_MOVE (that.value));
        break;

      case 40: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 59: // assignment
        value.YY_MOVE_OR_COPY< std::unique_ptr<AssignmentStatement> > (YY_MOVE (that.value));
        break;

      case 66: // boolean_expression
        value.YY_MOVE_OR_COPY< std::unique_ptr<BooleanExp> > (YY_MOVE (that.value));
        break;

      case 67: // expression
        value.YY_MOVE_OR_COPY< std::unique_ptr<Exp> > (YY_MOVE (that.value));
        break;

      case 60: // if_then_else
      case 61: // if_else_if
        value.YY_MOVE_OR_COPY< std::unique_ptr<IfThenElse> > (YY_MOVE (that.value));
        break;

      case 50: // declare_line
        value.YY_MOVE_OR_COPY< std::unique_ptr<MultiDeclarationStatement> > (YY_MOVE (that.value));
        break;

      case 57: // read_statement
        value.YY_MOVE_OR_COPY< std::unique_ptr<ReadStatement> > (YY_MOVE (that.value));
        break;

      case 56: // statement
      case 62: // else_block
        value.YY_MOVE_OR_COPY< std::unique_ptr<StatementLike> > (YY_MOVE (that.value));
        break;

      case 48: // declare_block
      case 49: // declare_line_list
      case 53: // main_block
      case 54: // basic_block
      case 55: // statement_list
        value.YY_MOVE_OR_COPY< std::unique_ptr<StatementList> > (YY_MOVE (that.value));
        break;

      case 63: // while_do
        value.YY_MOVE_OR_COPY< std::unique_ptr<WhileDo> > (YY_MOVE (that.value));
        break;

      case 58: // write_statement
        value.YY_MOVE_OR_COPY< std::unique_ptr<WriteStatement> > (YY_MOVE (that.value));
        break;

      case 65: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<Exp>> > (YY_MOVE (that.value));
        break;

      case 64: // identifier_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<IdentifierExist>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 70: // a_b_op
        value.move< arithmetic_b_op > (YY_MOVE (that.value));
        break;

      case 44: // SV_BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 71: // b_a_op
        value.move< bool_a_op > (YY_MOVE (that.value));
        break;

      case 72: // b_b_op
        value.move< bool_b_op > (YY_MOVE (that.value));
        break;

      case 73: // b_u_op
        value.move< bool_u_op > (YY_MOVE (that.value));
        break;

      case 42: // SV_CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case 43: // SV_REAL
      case 69: // sv_sign_real
        value.move< double > (YY_MOVE (that.value));
        break;

      case 41: // SV_INT
      case 68: // sv_sign_int
        value.move< int > (YY_MOVE (that.value));
        break;

      case 51: // type_identifier
        value.move< primitive > (YY_MOVE (that.value));
        break;

      case 52: // declare_statement
        value.move< std::pair<std::string,std::unique_ptr<Exp>> > (YY_MOVE (that.value));
        break;

      case 40: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 59: // assignment
        value.move< std::unique_ptr<AssignmentStatement> > (YY_MOVE (that.value));
        break;

      case 66: // boolean_expression
        value.move< std::unique_ptr<BooleanExp> > (YY_MOVE (that.value));
        break;

      case 67: // expression
        value.move< std::unique_ptr<Exp> > (YY_MOVE (that.value));
        break;

      case 60: // if_then_else
      case 61: // if_else_if
        value.move< std::unique_ptr<IfThenElse> > (YY_MOVE (that.value));
        break;

      case 50: // declare_line
        value.move< std::unique_ptr<MultiDeclarationStatement> > (YY_MOVE (that.value));
        break;

      case 57: // read_statement
        value.move< std::unique_ptr<ReadStatement> > (YY_MOVE (that.value));
        break;

      case 56: // statement
      case 62: // else_block
        value.move< std::unique_ptr<StatementLike> > (YY_MOVE (that.value));
        break;

      case 48: // declare_block
      case 49: // declare_line_list
      case 53: // main_block
      case 54: // basic_block
      case 55: // statement_list
        value.move< std::unique_ptr<StatementList> > (YY_MOVE (that.value));
        break;

      case 63: // while_do
        value.move< std::unique_ptr<WhileDo> > (YY_MOVE (that.value));
        break;

      case 58: // write_statement
        value.move< std::unique_ptr<WriteStatement> > (YY_MOVE (that.value));
        break;

      case 65: // expression_list
        value.move< std::vector<std::unique_ptr<Exp>> > (YY_MOVE (that.value));
        break;

      case 64: // identifier_list
        value.move< std::vector<std::unique_ptr<IdentifierExist>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 70: // a_b_op
        value.copy< arithmetic_b_op > (that.value);
        break;

      case 44: // SV_BOOL
        value.copy< bool > (that.value);
        break;

      case 71: // b_a_op
        value.copy< bool_a_op > (that.value);
        break;

      case 72: // b_b_op
        value.copy< bool_b_op > (that.value);
        break;

      case 73: // b_u_op
        value.copy< bool_u_op > (that.value);
        break;

      case 42: // SV_CHAR
        value.copy< char > (that.value);
        break;

      case 43: // SV_REAL
      case 69: // sv_sign_real
        value.copy< double > (that.value);
        break;

      case 41: // SV_INT
      case 68: // sv_sign_int
        value.copy< int > (that.value);
        break;

      case 51: // type_identifier
        value.copy< primitive > (that.value);
        break;

      case 52: // declare_statement
        value.copy< std::pair<std::string,std::unique_ptr<Exp>> > (that.value);
        break;

      case 40: // "identifier"
        value.copy< std::string > (that.value);
        break;

      case 59: // assignment
        value.copy< std::unique_ptr<AssignmentStatement> > (that.value);
        break;

      case 66: // boolean_expression
        value.copy< std::unique_ptr<BooleanExp> > (that.value);
        break;

      case 67: // expression
        value.copy< std::unique_ptr<Exp> > (that.value);
        break;

      case 60: // if_then_else
      case 61: // if_else_if
        value.copy< std::unique_ptr<IfThenElse> > (that.value);
        break;

      case 50: // declare_line
        value.copy< std::unique_ptr<MultiDeclarationStatement> > (that.value);
        break;

      case 57: // read_statement
        value.copy< std::unique_ptr<ReadStatement> > (that.value);
        break;

      case 56: // statement
      case 62: // else_block
        value.copy< std::unique_ptr<StatementLike> > (that.value);
        break;

      case 48: // declare_block
      case 49: // declare_line_list
      case 53: // main_block
      case 54: // basic_block
      case 55: // statement_list
        value.copy< std::unique_ptr<StatementList> > (that.value);
        break;

      case 63: // while_do
        value.copy< std::unique_ptr<WhileDo> > (that.value);
        break;

      case 58: // write_statement
        value.copy< std::unique_ptr<WriteStatement> > (that.value);
        break;

      case 65: // expression_list
        value.copy< std::vector<std::unique_ptr<Exp>> > (that.value);
        break;

      case 64: // identifier_list
        value.copy< std::vector<std::unique_ptr<IdentifierExist>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 70: // a_b_op
        value.move< arithmetic_b_op > (that.value);
        break;

      case 44: // SV_BOOL
        value.move< bool > (that.value);
        break;

      case 71: // b_a_op
        value.move< bool_a_op > (that.value);
        break;

      case 72: // b_b_op
        value.move< bool_b_op > (that.value);
        break;

      case 73: // b_u_op
        value.move< bool_u_op > (that.value);
        break;

      case 42: // SV_CHAR
        value.move< char > (that.value);
        break;

      case 43: // SV_REAL
      case 69: // sv_sign_real
        value.move< double > (that.value);
        break;

      case 41: // SV_INT
      case 68: // sv_sign_int
        value.move< int > (that.value);
        break;

      case 51: // type_identifier
        value.move< primitive > (that.value);
        break;

      case 52: // declare_statement
        value.move< std::pair<std::string,std::unique_ptr<Exp>> > (that.value);
        break;

      case 40: // "identifier"
        value.move< std::string > (that.value);
        break;

      case 59: // assignment
        value.move< std::unique_ptr<AssignmentStatement> > (that.value);
        break;

      case 66: // boolean_expression
        value.move< std::unique_ptr<BooleanExp> > (that.value);
        break;

      case 67: // expression
        value.move< std::unique_ptr<Exp> > (that.value);
        break;

      case 60: // if_then_else
      case 61: // if_else_if
        value.move< std::unique_ptr<IfThenElse> > (that.value);
        break;

      case 50: // declare_line
        value.move< std::unique_ptr<MultiDeclarationStatement> > (that.value);
        break;

      case 57: // read_statement
        value.move< std::unique_ptr<ReadStatement> > (that.value);
        break;

      case 56: // statement
      case 62: // else_block
        value.move< std::unique_ptr<StatementLike> > (that.value);
        break;

      case 48: // declare_block
      case 49: // declare_line_list
      case 53: // main_block
      case 54: // basic_block
      case 55: // statement_list
        value.move< std::unique_ptr<StatementList> > (that.value);
        break;

      case 63: // while_do
        value.move< std::unique_ptr<WhileDo> > (that.value);
        break;

      case 58: // write_statement
        value.move< std::unique_ptr<WriteStatement> > (that.value);
        break;

      case 65: // expression_list
        value.move< std::vector<std::unique_ptr<Exp>> > (that.value);
        break;

      case 64: // identifier_list
        value.move< std::vector<std::unique_ptr<IdentifierExist>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 70: // a_b_op
        yylhs.value.emplace< arithmetic_b_op > ();
        break;

      case 44: // SV_BOOL
        yylhs.value.emplace< bool > ();
        break;

      case 71: // b_a_op
        yylhs.value.emplace< bool_a_op > ();
        break;

      case 72: // b_b_op
        yylhs.value.emplace< bool_b_op > ();
        break;

      case 73: // b_u_op
        yylhs.value.emplace< bool_u_op > ();
        break;

      case 42: // SV_CHAR
        yylhs.value.emplace< char > ();
        break;

      case 43: // SV_REAL
      case 69: // sv_sign_real
        yylhs.value.emplace< double > ();
        break;

      case 41: // SV_INT
      case 68: // sv_sign_int
        yylhs.value.emplace< int > ();
        break;

      case 51: // type_identifier
        yylhs.value.emplace< primitive > ();
        break;

      case 52: // declare_statement
        yylhs.value.emplace< std::pair<std::string,std::unique_ptr<Exp>> > ();
        break;

      case 40: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      case 59: // assignment
        yylhs.value.emplace< std::unique_ptr<AssignmentStatement> > ();
        break;

      case 66: // boolean_expression
        yylhs.value.emplace< std::unique_ptr<BooleanExp> > ();
        break;

      case 67: // expression
        yylhs.value.emplace< std::unique_ptr<Exp> > ();
        break;

      case 60: // if_then_else
      case 61: // if_else_if
        yylhs.value.emplace< std::unique_ptr<IfThenElse> > ();
        break;

      case 50: // declare_line
        yylhs.value.emplace< std::unique_ptr<MultiDeclarationStatement> > ();
        break;

      case 57: // read_statement
        yylhs.value.emplace< std::unique_ptr<ReadStatement> > ();
        break;

      case 56: // statement
      case 62: // else_block
        yylhs.value.emplace< std::unique_ptr<StatementLike> > ();
        break;

      case 48: // declare_block
      case 49: // declare_line_list
      case 53: // main_block
      case 54: // basic_block
      case 55: // statement_list
        yylhs.value.emplace< std::unique_ptr<StatementList> > ();
        break;

      case 63: // while_do
        yylhs.value.emplace< std::unique_ptr<WhileDo> > ();
        break;

      case 58: // write_statement
        yylhs.value.emplace< std::unique_ptr<WriteStatement> > ();
        break;

      case 65: // expression_list
        yylhs.value.emplace< std::vector<std::unique_ptr<Exp>> > ();
        break;

      case 64: // identifier_list
        yylhs.value.emplace< std::vector<std::unique_ptr<IdentifierExist>> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 111 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[1].value.as < std::unique_ptr<StatementList> > ()->recursive_compile(drv);
        yystack_[0].value.as < std::unique_ptr<StatementList> > ()->recursive_compile(drv);
        drv.output << "halt\n";
    }
#line 1072 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 3:
#line 120 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > () = std::unique_ptr<StatementList>();
    }
#line 1080 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 4:
#line 124 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1088 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 5:
#line 131 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > () = std::make_unique<StatementList>();
        yylhs.value.as < std::unique_ptr<StatementList> > ()->add(std::move(yystack_[1].value.as < std::unique_ptr<MultiDeclarationStatement> > ()));
    }
#line 1097 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 6:
#line 136 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[2].value.as < std::unique_ptr<StatementList> > ()->add(std::move(yystack_[1].value.as < std::unique_ptr<MultiDeclarationStatement> > ()));
        yylhs.value.as < std::unique_ptr<StatementList> > ()=std::move(yystack_[2].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1106 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 7:
#line 143 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<MultiDeclarationStatement> > () = std::make_unique<MultiDeclarationStatement>(yystack_[1].value.as < primitive > ());
        yylhs.value.as < std::unique_ptr<MultiDeclarationStatement> > ()->add(drv,std::move(yystack_[0].value.as < std::pair<std::string,std::unique_ptr<Exp>> > ().first),std::move(yystack_[0].value.as < std::pair<std::string,std::unique_ptr<Exp>> > ().second));
    }
#line 1115 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 8:
#line 148 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[2].value.as < std::unique_ptr<MultiDeclarationStatement> > ()->add(drv,std::move(yystack_[0].value.as < std::pair<std::string,std::unique_ptr<Exp>> > ().first),std::move(yystack_[0].value.as < std::pair<std::string,std::unique_ptr<Exp>> > ().second));
        yylhs.value.as < std::unique_ptr<MultiDeclarationStatement> > ()=std::move(yystack_[2].value.as < std::unique_ptr<MultiDeclarationStatement> > ());
    }
#line 1124 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 9:
#line 155 "/home/deal_with/CLionProjects/cse474/bison.yy"
                {yylhs.value.as < primitive > ()=INT;}
#line 1130 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 10:
#line 156 "/home/deal_with/CLionProjects/cse474/bison.yy"
             {yylhs.value.as < primitive > ()=REAL;}
#line 1136 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 11:
#line 157 "/home/deal_with/CLionProjects/cse474/bison.yy"
             {yylhs.value.as < primitive > ()=CHAR;}
#line 1142 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 12:
#line 158 "/home/deal_with/CLionProjects/cse474/bison.yy"
                {yylhs.value.as < primitive > ()=BOOL;}
#line 1148 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 13:
#line 163 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::unique_ptr<Exp>> > ()={std::move(yystack_[0].value.as < std::string > ()),nullptr};
    }
#line 1156 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 14:
#line 167 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::unique_ptr<Exp>> > ()={std::move(yystack_[2].value.as < std::string > ()),std::move(yystack_[0].value.as < std::unique_ptr<Exp> > ())};
    }
#line 1164 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 15:
#line 174 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > ()=std::move(yystack_[1].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1172 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 16:
#line 181 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > ()=std::move(yystack_[1].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1180 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 17:
#line 188 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementList> > ()=std::make_unique<StatementList>();
    }
#line 1188 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 18:
#line 192 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[1].value.as < std::unique_ptr<StatementList> > ()->add(std::move(yystack_[0].value.as < std::unique_ptr<StatementLike> > ()));
        yylhs.value.as < std::unique_ptr<StatementList> > ()=std::move(yystack_[1].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1197 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 19:
#line 200 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[0].value.as < std::unique_ptr<ReadStatement> > ());
    }
#line 1205 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 20:
#line 204 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[0].value.as < std::unique_ptr<WriteStatement> > ());
    }
#line 1213 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 21:
#line 208 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[1].value.as < std::unique_ptr<MultiDeclarationStatement> > ());
    }
#line 1221 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 22:
#line 212 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[1].value.as < std::unique_ptr<AssignmentStatement> > ());
    }
#line 1229 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 23:
#line 216 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[0].value.as < std::unique_ptr<IfThenElse> > ());
    }
#line 1237 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 24:
#line 220 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[0].value.as < std::unique_ptr<WhileDo> > ());
    }
#line 1245 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 25:
#line 227 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<ReadStatement> > () = std::make_unique<ReadStatement>(std::move(yystack_[2].value.as < std::vector<std::unique_ptr<IdentifierExist>> > ()));
    }
#line 1253 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 26:
#line 234 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<WriteStatement> > () = std::make_unique<WriteStatement>(std::move(yystack_[2].value.as < std::vector<std::unique_ptr<Exp>> > ()));
    }
#line 1261 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 27:
#line 241 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<AssignmentStatement> > ()=std::make_unique<AssignmentStatement>(drv,std::make_unique<IdentifierExist>(drv,std::move(yystack_[2].value.as < std::string > ())),std::move(yystack_[0].value.as < std::unique_ptr<Exp> > ()));
    }
#line 1269 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 28:
#line 248 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {   
        yylhs.value.as < std::unique_ptr<IfThenElse> > ()=std::move(yystack_[1].value.as < std::unique_ptr<IfThenElse> > ());
        yylhs.value.as < std::unique_ptr<IfThenElse> > ()->_else = std::move(yystack_[0].value.as < std::unique_ptr<StatementLike> > ());
    }
#line 1278 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 29:
#line 256 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<IfThenElse> > () = std::make_unique<IfThenElse>();
        yylhs.value.as < std::unique_ptr<IfThenElse> > ()->add(std::move(yystack_[2].value.as < std::unique_ptr<BooleanExp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<StatementList> > ()));
    }
#line 1287 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 30:
#line 261 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[5].value.as < std::unique_ptr<IfThenElse> > ()->add(std::move(yystack_[2].value.as < std::unique_ptr<BooleanExp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<StatementList> > ()));
        yylhs.value.as < std::unique_ptr<IfThenElse> > ()=std::move(yystack_[5].value.as < std::unique_ptr<IfThenElse> > ());
    }
#line 1296 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 31:
#line 269 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::unique_ptr<StatementLike>(nullptr);
    }
#line 1304 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 32:
#line 273 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<StatementLike> > ()=std::move(yystack_[0].value.as < std::unique_ptr<StatementList> > ());
    }
#line 1312 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 33:
#line 280 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<WhileDo> > ()=std::make_unique<WhileDo>(std::move(yystack_[2].value.as < std::unique_ptr<BooleanExp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<StatementList> > ()));
    }
#line 1320 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 34:
#line 287 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<IdentifierExist>> > ()=std::vector<std::unique_ptr<IdentifierExist>>();
    }
#line 1328 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 35:
#line 291 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[1].value.as < std::vector<std::unique_ptr<IdentifierExist>> > ().push_back(std::make_unique<IdentifierExist>(drv,std::move(yystack_[0].value.as < std::string > ())));
        yylhs.value.as < std::vector<std::unique_ptr<IdentifierExist>> > ()=std::move(yystack_[1].value.as < std::vector<std::unique_ptr<IdentifierExist>> > ());
    }
#line 1337 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 36:
#line 299 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<Exp>> > ()=std::vector<std::unique_ptr<Exp>>();
    }
#line 1345 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 37:
#line 303 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[1].value.as < std::vector<std::unique_ptr<Exp>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<Exp> > ()));
        yylhs.value.as < std::vector<std::unique_ptr<Exp>> > ()=std::move(yystack_[1].value.as < std::vector<std::unique_ptr<Exp>> > ());
    }
#line 1354 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 38:
#line 321 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<BooleanExp> > () = std::make_unique<LiteralBoolExp>(drv,std::make_unique<BoolLiteral>(drv,yystack_[0].value.as < bool > ()));
    }
#line 1362 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 39:
#line 325 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<BooleanExp> > () = std::make_unique<BinaryArithmeticBoolExp>(drv,std::move(yystack_[2].value.as < std::unique_ptr<Exp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<Exp> > ()),yystack_[1].value.as < bool_a_op > ());
    }
#line 1370 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 40:
#line 329 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<BooleanExp> > () = std::make_unique<BinaryBoolExp>(drv,std::move(yystack_[2].value.as < std::unique_ptr<BooleanExp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<BooleanExp> > ()),yystack_[1].value.as < bool_b_op > ());
    }
#line 1378 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 41:
#line 334 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<BooleanExp> > () = std::make_unique<UnaryBoolExp>(drv,std::move(yystack_[0].value.as < std::unique_ptr<BooleanExp> > ()),yystack_[1].value.as < bool_u_op > ());
    }
#line 1386 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 42:
#line 341 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > ()= std::make_unique<IdentifierExist>(drv,std::move(yystack_[0].value.as < std::string > ()));
    }
#line 1394 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 43:
#line 345 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > ()=std::make_unique<IntegerLiteral>(drv,yystack_[0].value.as < int > ());
    }
#line 1402 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 44:
#line 349 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > ()=std::make_unique<RealLiteral>(drv,yystack_[0].value.as < double > ());
    }
#line 1410 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 45:
#line 353 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > ()=std::make_unique<BoolLiteral>(drv,yystack_[0].value.as < bool > ());
    }
#line 1418 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 46:
#line 357 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > ()=std::make_unique<CharLiteral>(drv,yystack_[0].value.as < char > ());
    }
#line 1426 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 47:
#line 361 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > () = std::make_unique<ArithmeticExp>(drv,std::move(yystack_[2].value.as < std::unique_ptr<Exp> > ()),std::move(yystack_[0].value.as < std::unique_ptr<Exp> > ()),yystack_[1].value.as < arithmetic_b_op > ());
    }
#line 1434 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 48:
#line 365 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::unique_ptr<Exp> > () = std::move(yystack_[1].value.as < std::unique_ptr<Exp> > ());
    }
#line 1442 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 49:
#line 372 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < int > ()=yystack_[0].value.as < int > ();
    }
#line 1450 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 50:
#line 376 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < int > ()=-yystack_[0].value.as < int > ();
    }
#line 1458 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 51:
#line 383 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < double > ()=yystack_[0].value.as < double > ();
    }
#line 1466 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 52:
#line 387 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < double > ()=-yystack_[0].value.as < double > ();
    }
#line 1474 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 53:
#line 394 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < arithmetic_b_op > ()=h_ast::ADD;
    }
#line 1482 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 54:
#line 398 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < arithmetic_b_op > ()=h_ast::SUB;
    }
#line 1490 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 55:
#line 402 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < arithmetic_b_op > ()=h_ast::DIV;
    }
#line 1498 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 56:
#line 406 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < arithmetic_b_op > ()=h_ast::MUL;
    }
#line 1506 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 57:
#line 410 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < arithmetic_b_op > ()=h_ast::MOD;
    }
#line 1514 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 58:
#line 418 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::GE;
    }
#line 1522 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 59:
#line 422 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::NE;
    }
#line 1530 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 60:
#line 426 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::EQ;
    }
#line 1538 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 61:
#line 430 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::LT;
    }
#line 1546 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 62:
#line 434 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::GT;
    }
#line 1554 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 63:
#line 438 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_a_op > ()=h_ast::LE;
    }
#line 1562 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 64:
#line 445 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_b_op > ()=h_ast::AND;
    }
#line 1570 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 65:
#line 449 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_b_op > ()=h_ast::OR;
    }
#line 1578 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 66:
#line 456 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < bool_u_op > ()=h_ast::NOT;
    }
#line 1586 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;


#line 1590 "/home/deal_with/CLionProjects/cse474/bison.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -39;

  const signed char
  parser::yypact_[] =
  {
     -10,   -19,    18,    62,    19,   -57,   -57,   -57,   -57,   -57,
      62,    40,    21,   -57,   -57,    45,    85,    21,   -57,   101,
     -57,    58,   -57,   -57,   -57,    22,   -57,    12,    97,    -3,
      -3,   108,    96,   -57,   -57,   -57,   100,   -57,    74,   -57,
       1,    22,   -57,   -57,   -57,   -57,   -57,    68,   -57,   -57,
     -57,   -57,   -57,   -11,    15,    63,    -3,   -13,    22,   -57,
     -57,     8,   -57,   -57,   -57,    95,   -57,   -57,   -57,   -57,
     -57,    22,    -6,    13,   -57,   -57,    19,    -3,   -57,   -57,
     -57,   -57,   -57,   -57,    22,   -57,    19,    68,    -3,   -57,
     -57,    68,   102,   -57,   103,    68,   -57,    89,    68,   -57,
      -9,   -57,   -57,    19,   -57
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     3,     0,     0,     0,     1,     9,    10,    11,    12,
       4,     0,     0,    17,     2,     0,     0,     0,     5,    13,
       7,     0,    15,     6,     8,     0,    16,     0,     0,     0,
       0,     0,     0,    18,    19,    20,     0,    23,    31,    24,
       0,     0,    42,    49,    46,    51,    45,    14,    43,    44,
      34,    36,    66,    45,     0,     0,     0,     0,     0,    21,
      22,     0,    28,    50,    52,     0,    54,    53,    56,    55,
      57,     0,     0,     0,    64,    65,     0,     0,    58,    60,
      63,    62,    61,    59,     0,    41,     0,    27,     0,    32,
      48,    47,     0,    35,     0,    37,    33,    40,    39,    29,
       0,    25,    26,     0,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,   -57,    -7,   -57,    99,   -57,   -56,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -28,   -25,   -57,   -57,   -57,   -57,   -57,   -57
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     4,    10,    11,    12,    20,    14,    15,    21,
      33,    34,    35,    36,    37,    38,    62,    39,    72,    73,
      54,    55,    48,    49,    71,    84,    77,    56
  };

  const signed char
  parser::yytable_[] =
  {
      47,    40,    57,    16,    92,    89,    41,    74,    75,   -38,
     -38,    74,    75,     1,    32,     3,    65,    40,     5,    52,
      96,    50,    41,    94,   -38,    86,    40,   -38,    85,   103,
      99,    41,    13,    87,    93,    74,    75,    42,    43,    44,
      45,    53,    63,    13,    64,    88,    91,   104,    95,    97,
      76,    17,    18,    42,    43,    44,    45,    46,    22,    98,
     100,    19,    42,    43,    44,    45,    46,    66,    67,    68,
      69,    70,    66,    67,    68,    69,    70,    78,    79,    80,
      81,    82,    83,    26,    27,    28,     6,     7,     8,     9,
       6,     7,     8,     9,    29,    30,    17,    23,    31,    66,
      67,    68,    69,    70,    25,    90,    51,    17,    59,    74,
      75,    58,    60,    61,   101,   102,    24
  };

  const signed char
  parser::yycheck_[] =
  {
      25,     4,    30,    10,    10,    61,     9,    20,    21,    20,
      21,    20,    21,    23,    21,    34,    41,     4,     0,    22,
      76,     9,     9,    10,    35,    38,     4,    38,    56,    38,
      86,     9,    24,    58,    40,    20,    21,    40,    41,    42,
      43,    44,    41,    24,    43,    37,    71,   103,    73,    77,
      35,    11,    12,    40,    41,    42,    43,    44,    13,    84,
      88,    40,    40,    41,    42,    43,    44,     4,     5,     6,
       7,     8,     4,     5,     6,     7,     8,    14,    15,    16,
      17,    18,    19,    25,    26,    27,    28,    29,    30,    31,
      28,    29,    30,    31,    36,    37,    11,    12,    40,     4,
       5,     6,     7,     8,     3,    10,     9,    11,    12,    20,
      21,     3,    12,    39,    12,    12,    17
  };

  const signed char
  parser::yystos_[] =
  {
       0,    23,    47,    34,    48,     0,    28,    29,    30,    31,
      49,    50,    51,    24,    53,    54,    50,    11,    12,    40,
      52,    55,    13,    12,    52,     3,    25,    26,    27,    36,
      37,    40,    50,    56,    57,    58,    59,    60,    61,    63,
       4,     9,    40,    41,    42,    43,    44,    67,    68,    69,
       9,     9,    22,    44,    66,    67,    73,    66,     3,    12,
      12,    39,    62,    41,    43,    67,     4,     5,     6,     7,
       8,    70,    64,    65,    20,    21,    35,    72,    14,    15,
      16,    17,    18,    19,    71,    66,    38,    67,    37,    54,
      10,    67,    10,    40,    10,    67,    54,    66,    67,    54,
      66,    12,    12,    38,    54
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    52,    52,    53,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    60,    61,
      61,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    71,    72,    72,    73
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     2,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     3,     2,     3,     0,     2,     1,
       1,     2,     2,     1,     1,     5,     5,     3,     2,     4,
       6,     0,     2,     4,     0,     2,     0,     2,     1,     3,
       3,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\":=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"%\"", "\"(\"", "\")\"", "\",\"", "\";\"", "\".\"",
  "\">=\"", "\"==\"", "\"<=\"", "\">\"", "\"<\"", "\"!=\"", "\"&&\"",
  "\"||\"", "\"!\"", "\"program\"", "BEGIN", "END", "READ", "WRITE",
  "INTEGER", "REAL", "CHAR", "BOOLEAN", "TRUE", "FALSE", "VAR", "DO",
  "WHILE", "IF", "THEN", "ELSE", "\"identifier\"", "SV_INT", "SV_CHAR",
  "SV_REAL", "SV_BOOL", "NEG", "$accept", "program", "declare_block",
  "declare_line_list", "declare_line", "type_identifier",
  "declare_statement", "main_block", "basic_block", "statement_list",
  "statement", "read_statement", "write_statement", "assignment",
  "if_then_else", "if_else_if", "else_block", "while_do",
  "identifier_list", "expression_list", "boolean_expression", "expression",
  "sv_sign_int", "sv_sign_real", "a_b_op", "b_a_op", "b_b_op", "b_u_op", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   110,   110,   119,   123,   130,   135,   142,   147,   155,
     156,   157,   158,   162,   166,   173,   180,   187,   191,   199,
     203,   207,   211,   215,   219,   226,   233,   240,   247,   255,
     260,   268,   272,   279,   286,   290,   298,   302,   320,   324,
     328,   333,   340,   344,   348,   352,   356,   360,   364,   371,
     375,   382,   386,   393,   397,   401,   405,   409,   417,   421,
     425,   429,   433,   437,   444,   448,   455
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2053 "/home/deal_with/CLionProjects/cse474/bison.cpp"

#line 461 "/home/deal_with/CLionProjects/cse474/bison.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}


