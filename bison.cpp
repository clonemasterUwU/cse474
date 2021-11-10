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
#line 25 "/home/deal_with/CLionProjects/cse474/bison.yy"

# include "driver.h"


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
      case 29: // SV_BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 27: // SV_CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case 28: // SV_REAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 26: // SV_INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 37: // declare_statement
      case 39: // identifier_exist
      case 45: // expression
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case 25: // "identifier"
      case 35: // type_identifier
      case 38: // identifier_not_exist
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 36: // declare_statement_list
      case 43: // identifier_exist_list
      case 44: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (that.value));
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
      case 29: // SV_BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 27: // SV_CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case 28: // SV_REAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 26: // SV_INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case 37: // declare_statement
      case 39: // identifier_exist
      case 45: // expression
        value.move< std::pair<std::string,std::string> > (YY_MOVE (that.value));
        break;

      case 25: // "identifier"
      case 35: // type_identifier
      case 38: // identifier_not_exist
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 36: // declare_statement_list
      case 43: // identifier_exist_list
      case 44: // expression_list
        value.move< std::vector<std::pair<std::string,std::string>> > (YY_MOVE (that.value));
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
      case 29: // SV_BOOL
        value.copy< bool > (that.value);
        break;

      case 27: // SV_CHAR
        value.copy< char > (that.value);
        break;

      case 28: // SV_REAL
        value.copy< double > (that.value);
        break;

      case 26: // SV_INT
        value.copy< int > (that.value);
        break;

      case 37: // declare_statement
      case 39: // identifier_exist
      case 45: // expression
        value.copy< std::pair<std::string,std::string> > (that.value);
        break;

      case 25: // "identifier"
      case 35: // type_identifier
      case 38: // identifier_not_exist
        value.copy< std::string > (that.value);
        break;

      case 36: // declare_statement_list
      case 43: // identifier_exist_list
      case 44: // expression_list
        value.copy< std::vector<std::pair<std::string,std::string>> > (that.value);
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
      case 29: // SV_BOOL
        value.move< bool > (that.value);
        break;

      case 27: // SV_CHAR
        value.move< char > (that.value);
        break;

      case 28: // SV_REAL
        value.move< double > (that.value);
        break;

      case 26: // SV_INT
        value.move< int > (that.value);
        break;

      case 37: // declare_statement
      case 39: // identifier_exist
      case 45: // expression
        value.move< std::pair<std::string,std::string> > (that.value);
        break;

      case 25: // "identifier"
      case 35: // type_identifier
      case 38: // identifier_not_exist
        value.move< std::string > (that.value);
        break;

      case 36: // declare_statement_list
      case 43: // identifier_exist_list
      case 44: // expression_list
        value.move< std::vector<std::pair<std::string,std::string>> > (that.value);
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
      case 29: // SV_BOOL
        yylhs.value.emplace< bool > ();
        break;

      case 27: // SV_CHAR
        yylhs.value.emplace< char > ();
        break;

      case 28: // SV_REAL
        yylhs.value.emplace< double > ();
        break;

      case 26: // SV_INT
        yylhs.value.emplace< int > ();
        break;

      case 37: // declare_statement
      case 39: // identifier_exist
      case 45: // expression
        yylhs.value.emplace< std::pair<std::string,std::string> > ();
        break;

      case 25: // "identifier"
      case 35: // type_identifier
      case 38: // identifier_not_exist
        yylhs.value.emplace< std::string > ();
        break;

      case 36: // declare_statement_list
      case 43: // identifier_exist_list
      case 44: // expression_list
        yylhs.value.emplace< std::vector<std::pair<std::string,std::string>> > ();
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
#line 83 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.output << "halt\n";
    }
#line 740 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 4:
#line 90 "/home/deal_with/CLionProjects/cse474/bison.yy"
                              {}
#line 746 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 7:
#line 99 "/home/deal_with/CLionProjects/cse474/bison.yy"
        {
            for(auto p:yystack_[1].value.as < std::vector<std::pair<std::string,std::string>> > ()){
                if( p.second == "any"){
                    p.second = yystack_[2].value.as < std::string > ();
                    drv.symbol_table[p.first]=yystack_[2].value.as < std::string > ();
                } else if(p.second != yystack_[2].value.as < std::string > () && yystack_[2].value.as < std::string > () != drv.REAL ){
                    throw yy::parser::syntax_error (drv.location,"conversion from " + p.second + " to " + yystack_[2].value.as < std::string > () + " is not allowed");
                }
            }
            for(auto p:yystack_[1].value.as < std::vector<std::pair<std::string,std::string>> > ()){
                drv.output << "declare " << p.first << "," << (yystack_[2].value.as < std::string > ()==drv.REAL?"real":"integer") << '\n';
            }
            drv.output << drv.buffer.rdbuf();
            drv.buffer.clear();
        }
#line 766 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 8:
#line 117 "/home/deal_with/CLionProjects/cse474/bison.yy"
                {yylhs.value.as < std::string > ()=drv.INT;}
#line 772 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 9:
#line 118 "/home/deal_with/CLionProjects/cse474/bison.yy"
             {yylhs.value.as < std::string > ()=drv.REAL;}
#line 778 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 10:
#line 119 "/home/deal_with/CLionProjects/cse474/bison.yy"
             {yylhs.value.as < std::string > ()=drv.CHAR;}
#line 784 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 11:
#line 120 "/home/deal_with/CLionProjects/cse474/bison.yy"
                {yylhs.value.as < std::string > ()=drv.BOOL;}
#line 790 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 12:
#line 125 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > ()=std::vector<std::pair<std::string,std::string>>{std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ())};
    }
#line 798 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 13:
#line 129 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ().push_back(std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ()));
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > () = std::move(yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ());
    }
#line 807 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 14:
#line 137 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > ()=make_pair(yystack_[0].value.as < std::string > (),"any");
    }
#line 815 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 15:
#line 141 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.buffer << "store " << yystack_[0].value.as < int > () << ", " << yystack_[2].value.as < std::string > () << '\n';
        drv.symbol_table[yystack_[2].value.as < std::string > ()]=drv.INT;
        yylhs.value.as < std::pair<std::string,std::string> > ()=std::make_pair(yystack_[2].value.as < std::string > (),drv.INT);
    }
#line 825 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 16:
#line 147 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.buffer << "store " << yystack_[0].value.as < double > () << ", " << yystack_[2].value.as < std::string > () << '\n';
        drv.symbol_table[yystack_[2].value.as < std::string > ()]=drv.REAL;
        yylhs.value.as < std::pair<std::string,std::string> > ()=std::make_pair(yystack_[2].value.as < std::string > (),drv.REAL);
    }
#line 835 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 17:
#line 153 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.buffer << "store '" << yystack_[0].value.as < char > () << "', " << yystack_[2].value.as < std::string > () << '\n';
        drv.symbol_table[yystack_[2].value.as < std::string > ()]=drv.CHAR;
        yylhs.value.as < std::pair<std::string,std::string> > ()=std::make_pair(yystack_[2].value.as < std::string > (),drv.CHAR);
    }
#line 845 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 18:
#line 159 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.buffer << "store " << yystack_[0].value.as < bool > () << ", " << yystack_[2].value.as < std::string > () << '\n';
        drv.symbol_table[yystack_[2].value.as < std::string > ()]=drv.BOOL;
        yylhs.value.as < std::pair<std::string,std::string> > ()=std::make_pair(yystack_[2].value.as < std::string > (),drv.BOOL);
    }
#line 855 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 19:
#line 165 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.buffer << "store " << yystack_[0].value.as < std::pair<std::string,std::string> > ().first << ", " << yystack_[2].value.as < std::string > () << '\n';
        drv.symbol_table[yystack_[2].value.as < std::string > ()]=yystack_[0].value.as < std::pair<std::string,std::string> > ().second;
        yylhs.value.as < std::pair<std::string,std::string> > ()=std::make_pair(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::pair<std::string,std::string> > ().second);
    }
#line 865 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 20:
#line 174 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        drv.symbol_not_exist(yystack_[0].value.as < std::string > ());
        yylhs.value.as < std::string > ()=std::move(yystack_[0].value.as < std::string > ());
    }
#line 874 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 21:
#line 182 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > ()=drv.find_symbol(yystack_[0].value.as < std::string > ());
    }
#line 882 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 22:
#line 188 "/home/deal_with/CLionProjects/cse474/bison.yy"
                                     {}
#line 888 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 25:
#line 198 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        for(auto& p:yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ()){
            drv.output << "read " << p.first << ", " << p.second << '\n';
        }
    }
#line 898 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 26:
#line 204 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        for(auto& p:yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ()){

            std::cerr << p.first << ' ' << p.second << '\n';
            drv.output << "write " << p.first << ", " << p.second << '\n';
        }
    }
#line 910 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 27:
#line 212 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        if(yystack_[1].value.as < std::pair<std::string,std::string> > ().second != yystack_[3].value.as < std::pair<std::string,std::string> > ().second){
            if(yystack_[3].value.as < std::pair<std::string,std::string> > ().second!=drv.INT && yystack_[3].value.as < std::pair<std::string,std::string> > ().second!=drv.REAL){
                throw yy::parser::syntax_error(drv.location,"cannot assign "+yystack_[1].value.as < std::pair<std::string,std::string> > ().second+" to a "+yystack_[3].value.as < std::pair<std::string,std::string> > ().second+" variables");
            }
            auto temp = drv.get_temp_name();
            drv.output << (yystack_[3].value.as < std::pair<std::string,std::string> > ().second == drv.INT ? "rtoi ":"itor ") << yystack_[1].value.as < std::pair<std::string,std::string> > ().first << ", " << temp << '\n';
            yystack_[1].value.as < std::pair<std::string,std::string> > ().first = std::move(temp);
        }
        drv.output << "store " << yystack_[1].value.as < std::pair<std::string,std::string> > ().first << ", " << yystack_[3].value.as < std::pair<std::string,std::string> > ().first << '\n';
    }
#line 926 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 28:
#line 227 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > ()=std::vector<std::pair<std::string,std::string>>{std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ())};
    }
#line 934 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 29:
#line 231 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ().push_back(std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ()));
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > ()=std::move(yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ());
    }
#line 943 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 30:
#line 239 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > ()=std::vector<std::pair<std::string,std::string>>{std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ())};
    }
#line 951 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 31:
#line 243 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ().push_back(std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ()));
        yylhs.value.as < std::vector<std::pair<std::string,std::string>> > () = std::move(yystack_[2].value.as < std::vector<std::pair<std::string,std::string>> > ());
    }
#line 960 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 32:
#line 253 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = drv.op(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),"add");
    }
#line 968 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 33:
#line 257 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = drv.op(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),"sub");
    }
#line 976 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 34:
#line 261 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = drv.op(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),"mul");
    }
#line 984 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 35:
#line 265 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = drv.op(yystack_[2].value.as < std::pair<std::string,std::string> > (),yystack_[0].value.as < std::pair<std::string,std::string> > (),"div");
    }
#line 992 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 36:
#line 269 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = std::move(yystack_[1].value.as < std::pair<std::string,std::string> > ());
    }
#line 1000 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 37:
#line 273 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = std::move(yystack_[0].value.as < std::pair<std::string,std::string> > ());
    }
#line 1008 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 38:
#line 277 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = make_pair(std::to_string(yystack_[0].value.as < int > ()),drv.INT);
    }
#line 1016 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 39:
#line 281 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = make_pair("'"+yystack_[0].value.as < char > ()+'\'',drv.CHAR);
    }
#line 1024 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 40:
#line 285 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = make_pair(std::to_string(yystack_[0].value.as < double > ()),drv.REAL);
    }
#line 1032 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;

  case 41:
#line 289 "/home/deal_with/CLionProjects/cse474/bison.yy"
    {
        yylhs.value.as < std::pair<std::string,std::string> > () = make_pair(std::to_string((yystack_[0].value.as < bool > ()?1:0)),drv.BOOL);
    }
#line 1040 "/home/deal_with/CLionProjects/cse474/bison.cpp"
    break;


#line 1044 "/home/deal_with/CLionProjects/cse474/bison.cpp"

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


  const signed char parser::yypact_ninf_ = -31;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -3,   -10,    18,    34,    23,   -31,   -31,   -31,   -31,   -31,
      34,   -31,    14,    -8,   -31,   -31,   -31,    -4,   -31,    42,
      55,    56,   -31,    59,   -12,   -31,    14,   -31,    22,    40,
      -6,    -6,    57,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,    15,    -6,   -31,   -31,   -31,   -31,   -31,    26,    52,
      27,   -31,    60,    40,    37,    61,    -6,    -6,    -6,    -6,
      -6,   -31,   -31,   -31,   -31,   -31,    52,    54,    54,   -31,
     -31
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     3,     0,     0,     0,     1,     8,     9,    10,    11,
       4,     5,     0,     0,     2,     6,    20,     0,    12,    14,
       0,     0,    21,     0,     0,    23,     0,     7,     0,     0,
       0,     0,     0,    24,    13,    15,    17,    16,    18,    19,
      28,     0,     0,    38,    39,    40,    41,    37,     0,    30,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    25,    29,    36,    26,    31,    33,    32,    34,
      35
  };

  const signed char
  parser::yypgoto_[] =
  {
     -31,   -31,   -31,   -31,    58,   -31,   -31,    41,   -31,   -13,
     -31,   -31,    46,   -31,   -31,   -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     4,    10,    11,    12,    17,    18,    19,    47,
      14,    24,    25,    41,    48,    49
  };

  const signed char
  parser::yytable_[] =
  {
      23,    50,    42,    32,    20,    21,    26,    27,    20,    21,
       1,    23,    54,    22,     3,    39,    40,    22,     5,    22,
      43,    44,    45,    46,    52,    53,    66,    67,    68,    69,
      70,    57,    58,    59,    60,    55,    56,    13,    61,    16,
      63,    57,    58,    59,    60,    28,    64,    22,    35,    36,
      37,    38,     6,     7,     8,     9,    57,    58,    59,    60,
      59,    60,    31,    29,    30,    22,     0,    34,    15,    51,
      33,    62,    65
  };

  const signed char
  parser::yycheck_[] =
  {
      13,    31,     8,    15,    16,    17,    10,    11,    16,    17,
      13,    24,    42,    25,    24,    28,    29,    25,     0,    25,
      26,    27,    28,    29,     9,    10,    56,    57,    58,    59,
      60,     4,     5,     6,     7,     9,    10,    14,    11,    25,
      53,     4,     5,     6,     7,     3,     9,    25,    26,    27,
      28,    29,    18,    19,    20,    21,     4,     5,     6,     7,
       6,     7,     3,     8,     8,    25,    -1,    26,    10,    12,
      24,    11,    11
  };

  const signed char
  parser::yystos_[] =
  {
       0,    13,    31,    24,    32,     0,    18,    19,    20,    21,
      33,    34,    35,    14,    40,    34,    25,    36,    37,    38,
      16,    17,    25,    39,    41,    42,    10,    11,     3,     8,
       8,     3,    15,    42,    37,    26,    27,    28,    29,    39,
      39,    43,     8,    26,    27,    28,    29,    39,    44,    45,
      45,    12,     9,    10,    45,     9,    10,     4,     5,     6,
       7,    11,    11,    39,     9,    11,    45,    45,    45,    45,
      45
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    30,    31,    32,    32,    33,    33,    34,    35,    35,
      35,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      38,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       1,     1,     4,     1,     2,     5,     5,     4,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\":=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"(\"", "\")\"", "\",\"", "\";\"", "\".\"",
  "\"program\"", "BEGIN", "END", "READ", "WRITE", "INTEGER", "REAL",
  "CHAR", "BOOLEAN", "TRUE", "FALSE", "VAR", "\"identifier\"", "SV_INT",
  "SV_CHAR", "SV_REAL", "SV_BOOL", "$accept", "program", "declare_block",
  "declare_line_list", "declare_line", "type_identifier",
  "declare_statement_list", "declare_statement", "identifier_not_exist",
  "identifier_exist", "main_block", "statement_list", "statement",
  "identifier_exist_list", "expression_list", "expression", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    82,    82,    89,    90,    94,    95,    98,   117,   118,
     119,   120,   124,   128,   136,   140,   146,   152,   158,   164,
     173,   181,   188,   192,   193,   197,   203,   211,   226,   230,
     238,   242,   252,   256,   260,   264,   268,   272,   276,   280,
     284,   288
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
#line 1478 "/home/deal_with/CLionProjects/cse474/bison.cpp"

#line 293 "/home/deal_with/CLionProjects/cse474/bison.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << "\n";
}


