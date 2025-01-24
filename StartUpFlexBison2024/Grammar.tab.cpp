// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 11 "Grammar.y"

using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Tree.h"
#include "grammar.tab.h"
#include <cmath>
extern int yylex(yy::parser::value_type *val, yy::parser::location_type* loc);
extern FILE *yyin;

#line 52 "Grammar.tab.cpp"


#include "Grammar.tab.h"




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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 149 "Grammar.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



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

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
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

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

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
  case 2: // translation_unit: declarations function_declarations statements
#line 51 "Grammar.y"
                                                                { root = (yylhs.value.node) = new CTranslationUnit(3,(yystack_[2].value.node),(yystack_[1].value.node),(yystack_[0].value.node));}
#line 621 "Grammar.tab.cpp"
    break;

  case 3: // translation_unit: declarations statements
#line 52 "Grammar.y"
                                                  { root = (yylhs.value.node) = new CTranslationUnit(2,(yystack_[1].value.node),(yystack_[0].value.node));}
#line 627 "Grammar.tab.cpp"
    break;

  case 4: // translation_unit: function_declarations statements
#line 53 "Grammar.y"
                                                           { root = (yylhs.value.node) = new CTranslationUnit(2,(yystack_[1].value.node),(yystack_[0].value.node));}
#line 633 "Grammar.tab.cpp"
    break;

  case 5: // translation_unit: statements
#line 54 "Grammar.y"
                                     { root = (yylhs.value.node) = new CTranslationUnit(1,(yystack_[0].value.node));}
#line 639 "Grammar.tab.cpp"
    break;

  case 6: // declarations: declarations declaration
#line 57 "Grammar.y"
                                       { (yylhs.value.node) = new CDeclarations(2,(yystack_[1].value.node),(yystack_[0].value.node)); }
#line 645 "Grammar.tab.cpp"
    break;

  case 7: // declarations: declaration
#line 58 "Grammar.y"
                                      { (yylhs.value.node) = new CDeclarations(1,(yystack_[0].value.node)); }
#line 651 "Grammar.tab.cpp"
    break;

  case 8: // declaration: type_specifier IDENTIFIER ';'
#line 61 "Grammar.y"
                                                { (yylhs.value.node) = new CDeclaration(2,(yystack_[2].value.node),(yystack_[1].value.node)); }
#line 657 "Grammar.tab.cpp"
    break;

  case 9: // function_declarations: function_declarations function_declaration
#line 64 "Grammar.y"
                                                                  { (yylhs.value.node) = new CFunctionDeclarations(2,(yystack_[1].value.node),(yystack_[0].value.node)); }
#line 663 "Grammar.tab.cpp"
    break;

  case 10: // function_declarations: function_declaration
#line 65 "Grammar.y"
                                               { (yylhs.value.node) = new CFunctionDeclarations(1,(yystack_[0].value.node)); }
#line 669 "Grammar.tab.cpp"
    break;

  case 11: // function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations statements '}'
#line 69 "Grammar.y"
                                                                                                       { (yylhs.value.node) = new CFunctionDeclaration(5,(yystack_[8].value.node),(yystack_[7].value.node),(yystack_[5].value.node),(yystack_[2].value.node),(yystack_[1].value.node)); }
#line 675 "Grammar.tab.cpp"
    break;

  case 12: // function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations '}'
#line 70 "Grammar.y"
                                                                                                                { (yylhs.value.node) = new CFunctionDeclaration(4,(yystack_[7].value.node),(yystack_[6].value.node),(yystack_[4].value.node),(yystack_[1].value.node)); }
#line 681 "Grammar.tab.cpp"
    break;

  case 13: // function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' statements '}'
#line 71 "Grammar.y"
                                                                                                              { (yylhs.value.node) = new CFunctionDeclaration(4,(yystack_[7].value.node),(yystack_[6].value.node),(yystack_[4].value.node),(yystack_[1].value.node)); }
#line 687 "Grammar.tab.cpp"
    break;

  case 14: // function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' '}'
#line 72 "Grammar.y"
                                                                                                   { (yylhs.value.node) = new CFunctionDeclaration(3,(yystack_[6].value.node),(yystack_[5].value.node),(yystack_[3].value.node)); }
#line 693 "Grammar.tab.cpp"
    break;

  case 15: // parameter_list: parameter_list ',' parameter
#line 74 "Grammar.y"
                                             { (yylhs.value.node) = new CParameterList(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 699 "Grammar.tab.cpp"
    break;

  case 16: // parameter_list: parameter
#line 75 "Grammar.y"
                                    { (yylhs.value.node) = new CParameterList(1,(yystack_[0].value.node)); }
#line 705 "Grammar.tab.cpp"
    break;

  case 17: // parameter: type_specifier IDENTIFIER
#line 77 "Grammar.y"
                                     { (yylhs.value.node) = new CParameter(2,(yystack_[1].value.node),(yystack_[0].value.node)); }
#line 711 "Grammar.tab.cpp"
    break;

  case 18: // type_specifier: INT
#line 80 "Grammar.y"
                     { (yylhs.value.node) = new CTypeSpecifier(INT); }
#line 717 "Grammar.tab.cpp"
    break;

  case 19: // type_specifier: FLOAT
#line 81 "Grammar.y"
                                 { (yylhs.value.node) = new CTypeSpecifier(FLOAT); }
#line 723 "Grammar.tab.cpp"
    break;

  case 20: // type_specifier: DOUBLE
#line 82 "Grammar.y"
                                 { (yylhs.value.node) = new CTypeSpecifier(DOUBLE); }
#line 729 "Grammar.tab.cpp"
    break;

  case 21: // type_specifier: CHAR
#line 83 "Grammar.y"
                               { (yylhs.value.node) = new CTypeSpecifier(CHAR); }
#line 735 "Grammar.tab.cpp"
    break;

  case 22: // statements: statements statement
#line 86 "Grammar.y"
                                 { (yylhs.value.node) = new CStatements(2,(yystack_[1].value.node),(yystack_[0].value.node)); }
#line 741 "Grammar.tab.cpp"
    break;

  case 23: // statements: statement
#line 87 "Grammar.y"
                                    { (yylhs.value.node) = new CStatements(1,(yystack_[0].value.node)); }
#line 747 "Grammar.tab.cpp"
    break;

  case 24: // statement: expression ';'
#line 90 "Grammar.y"
                           { (yylhs.value.node) = new CExpressionStatement(1,(yystack_[1].value.node)); }
#line 753 "Grammar.tab.cpp"
    break;

  case 25: // statement: do_while_statement
#line 91 "Grammar.y"
                                       { (yylhs.value.node) = new CDoWhileStatement(1,(yystack_[0].value.node)); }
#line 759 "Grammar.tab.cpp"
    break;

  case 26: // statement: while_statement
#line 92 "Grammar.y"
                                    { (yylhs.value.node) = new CWhileStatement(1,(yystack_[0].value.node)); }
#line 765 "Grammar.tab.cpp"
    break;

  case 27: // statement: if_statement
#line 93 "Grammar.y"
                                 { (yylhs.value.node) = new CIfStatement(1,(yystack_[0].value.node)); }
#line 771 "Grammar.tab.cpp"
    break;

  case 28: // statement: for_statement
#line 94 "Grammar.y"
                                  { (yylhs.value.node) = new CForStatement(1,(yystack_[0].value.node)); }
#line 777 "Grammar.tab.cpp"
    break;

  case 29: // statement: return_statement
#line 95 "Grammar.y"
                                     { (yylhs.value.node) = new CReturnStatement(1,(yystack_[0].value.node));}
#line 783 "Grammar.tab.cpp"
    break;

  case 30: // statement: break_statement
#line 96 "Grammar.y"
                                     { (yylhs.value.node) = new CBreakStatement(); }
#line 789 "Grammar.tab.cpp"
    break;

  case 31: // statement: continue_statement
#line 97 "Grammar.y"
                                       { (yylhs.value.node) = new CContinueStatement(); }
#line 795 "Grammar.tab.cpp"
    break;

  case 32: // statement: ';'
#line 98 "Grammar.y"
                          { (yylhs.value.node) = new CEmptyStatement(); }
#line 801 "Grammar.tab.cpp"
    break;

  case 33: // statement: compound_statement
#line 99 "Grammar.y"
                                       { (yylhs.value.node) = new CCompoundStatement(1,(yystack_[0].value.node)); }
#line 807 "Grammar.tab.cpp"
    break;

  case 34: // compound_statement: '{' statements '}'
#line 102 "Grammar.y"
                                       { (yylhs.value.node) = new CCompoundStatement(1,(yystack_[1].value.node)); }
#line 813 "Grammar.tab.cpp"
    break;

  case 35: // compound_statement: '{' '}'
#line 103 "Grammar.y"
                                            { (yylhs.value.node) = new CCompoundStatement(0); }
#line 819 "Grammar.tab.cpp"
    break;

  case 36: // while_statement: WHILE '(' expression ')' statement
#line 106 "Grammar.y"
                                                     { (yylhs.value.node) = new CWhileStatement(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 825 "Grammar.tab.cpp"
    break;

  case 37: // do_while_statement: DO statement WHILE '(' expression ')' ';'
#line 108 "Grammar.y"
                                                              { (yylhs.value.node) = new CDoWhileStatement(2,(yystack_[5].value.node),(yystack_[2].value.node)); }
#line 831 "Grammar.tab.cpp"
    break;

  case 38: // for_statement: FOR '(' expression ';' expression ';' expression ')' statement
#line 110 "Grammar.y"
                                                                              { (yylhs.value.node) = new CForStatement(4,(yystack_[6].value.node),(yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 837 "Grammar.tab.cpp"
    break;

  case 39: // for_statement: FOR '(' expression ';' expression ';' ')' statement
#line 111 "Grammar.y"
                                                                               { (yylhs.value.node) = new CForStatement(3,(yystack_[5].value.node),(yystack_[3].value.node),(yystack_[0].value.node)); }
#line 843 "Grammar.tab.cpp"
    break;

  case 40: // for_statement: FOR '(' expression ';' ';' expression ')' statement
#line 112 "Grammar.y"
                                                                               { (yylhs.value.node) = new CForStatement(3,(yystack_[5].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 849 "Grammar.tab.cpp"
    break;

  case 41: // for_statement: FOR '(' expression ';' ';' ')' statement
#line 113 "Grammar.y"
                                                                    { (yylhs.value.node) = new CForStatement(2,(yystack_[4].value.node),(yystack_[0].value.node)); }
#line 855 "Grammar.tab.cpp"
    break;

  case 42: // for_statement: FOR '(' ';' expression ';' expression ')' statement
#line 114 "Grammar.y"
                                                                               { (yylhs.value.node) = new CForStatement(3,(yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 861 "Grammar.tab.cpp"
    break;

  case 43: // for_statement: FOR '(' ';' expression ';' ')' statement
#line 115 "Grammar.y"
                                                                    { (yylhs.value.node) = new CForStatement(2,(yystack_[3].value.node),(yystack_[0].value.node)); }
#line 867 "Grammar.tab.cpp"
    break;

  case 44: // for_statement: FOR '(' ';' ';' expression ')' statement
#line 116 "Grammar.y"
                                                                    { (yylhs.value.node) = new CForStatement(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 873 "Grammar.tab.cpp"
    break;

  case 45: // for_statement: FOR '(' ';' ';' ')' statement
#line 117 "Grammar.y"
                                                         { (yylhs.value.node) = new CForStatement(0); }
#line 879 "Grammar.tab.cpp"
    break;

  case 46: // if_statement: IF '(' expression ')' statement
#line 119 "Grammar.y"
                                                            { (yylhs.value.node)= new CIfStatement(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 885 "Grammar.tab.cpp"
    break;

  case 47: // if_statement: IF '(' expression ')' statement ELSE statement
#line 120 "Grammar.y"
                                                                  { (yylhs.value.node) = new CIfStatement(3,(yystack_[4].value.node),(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 891 "Grammar.tab.cpp"
    break;

  case 48: // continue_statement: CONTINUE ';'
#line 123 "Grammar.y"
                                 { (yylhs.value.node) = new CContinueStatement(); }
#line 897 "Grammar.tab.cpp"
    break;

  case 49: // break_statement: BREAK ';'
#line 125 "Grammar.y"
                           { (yylhs.value.node) = new CBreakStatement(); }
#line 903 "Grammar.tab.cpp"
    break;

  case 50: // return_statement: RETURN expression ';'
#line 127 "Grammar.y"
                                        { (yylhs.value.node) = new CReturnStatement(1,(yystack_[1].value.node)); }
#line 909 "Grammar.tab.cpp"
    break;

  case 51: // return_statement: RETURN ';'
#line 128 "Grammar.y"
                                             { (yylhs.value.node) = new CReturnStatement(0); }
#line 915 "Grammar.tab.cpp"
    break;

  case 52: // expression: expression '+' expression
#line 132 "Grammar.y"
                                { (yylhs.value.node) = new CAddition(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 921 "Grammar.tab.cpp"
    break;

  case 53: // expression: expression '-' expression
#line 133 "Grammar.y"
                                { (yylhs.value.node) = new CSubtraction(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 927 "Grammar.tab.cpp"
    break;

  case 54: // expression: expression '*' expression
#line 134 "Grammar.y"
                                { (yylhs.value.node) = new CMultiplication(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 933 "Grammar.tab.cpp"
    break;

  case 55: // expression: expression '/' expression
#line 135 "Grammar.y"
                                { (yylhs.value.node) = new CDivision(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 939 "Grammar.tab.cpp"
    break;

  case 56: // expression: expression '%' expression
#line 136 "Grammar.y"
                                { (yylhs.value.node) = new CModulo(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 945 "Grammar.tab.cpp"
    break;

  case 57: // expression: IDENTIFIER '=' expression
#line 137 "Grammar.y"
                                { (yylhs.value.node) = new CAssignment(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 951 "Grammar.tab.cpp"
    break;

  case 58: // expression: '-' expression
#line 138 "Grammar.y"
                        { (yylhs.value.node) = new CNegation(1,(yystack_[0].value.node)); }
#line 957 "Grammar.tab.cpp"
    break;

  case 59: // expression: '+' expression
#line 139 "Grammar.y"
                        { (yylhs.value.node) = new CIdentity(1,(yystack_[0].value.node)); }
#line 963 "Grammar.tab.cpp"
    break;

  case 60: // expression: expression '^' expression
#line 140 "Grammar.y"
                                { (yylhs.value.node) = new CPower(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 969 "Grammar.tab.cpp"
    break;

  case 61: // expression: '(' expression ')'
#line 141 "Grammar.y"
                        { (yylhs.value.node) = (yystack_[1].value.node); }
#line 975 "Grammar.tab.cpp"
    break;

  case 62: // expression: expression '>' expression
#line 142 "Grammar.y"
                              { (yylhs.value.node) = new CGreaterThan(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 981 "Grammar.tab.cpp"
    break;

  case 63: // expression: expression '<' expression
#line 143 "Grammar.y"
                              { (yylhs.value.node) = new CLessThan(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 987 "Grammar.tab.cpp"
    break;

  case 64: // expression: expression EQ expression
#line 144 "Grammar.y"
                             { (yylhs.value.node) = new CEqual(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 993 "Grammar.tab.cpp"
    break;

  case 65: // expression: expression NE expression
#line 145 "Grammar.y"
                             { (yylhs.value.node) = new CNotEqual(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 999 "Grammar.tab.cpp"
    break;

  case 66: // expression: expression GE expression
#line 146 "Grammar.y"
                             { (yylhs.value.node) = new CGreaterEqual(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 1005 "Grammar.tab.cpp"
    break;

  case 67: // expression: expression LE expression
#line 147 "Grammar.y"
                             { (yylhs.value.node) = new CLessEqual(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 1011 "Grammar.tab.cpp"
    break;

  case 68: // expression: expression AND expression
#line 148 "Grammar.y"
                              { (yylhs.value.node) = new CAnd(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 1017 "Grammar.tab.cpp"
    break;

  case 69: // expression: expression OR expression
#line 149 "Grammar.y"
                             { (yylhs.value.node) = new COr(2,(yystack_[2].value.node),(yystack_[0].value.node)); }
#line 1023 "Grammar.tab.cpp"
    break;

  case 70: // expression: '!' expression
#line 150 "Grammar.y"
                   { (yylhs.value.node) = new CNot(1,(yystack_[0].value.node)); }
#line 1029 "Grammar.tab.cpp"
    break;

  case 71: // expression: IDENTIFIER
#line 151 "Grammar.y"
               { (yylhs.value.node)=(yystack_[0].value.node); }
#line 1035 "Grammar.tab.cpp"
    break;

  case 72: // expression: IDENTIFIER '(' argument_list ')'
#line 152 "Grammar.y"
                                     { (yylhs.value.node) = new CFunctionCall(2,(yystack_[3].value.node),(yystack_[1].value.node)); }
#line 1041 "Grammar.tab.cpp"
    break;

  case 73: // expression: INTEGER
#line 153 "Grammar.y"
                { (yylhs.value.node)=(yystack_[0].value.node); }
#line 1047 "Grammar.tab.cpp"
    break;

  case 74: // expression: FLOAT
#line 154 "Grammar.y"
                        { (yylhs.value.node)=(yystack_[0].value.node); }
#line 1053 "Grammar.tab.cpp"
    break;

  case 75: // argument_list: argument_list ',' expression
#line 157 "Grammar.y"
                                              { (yylhs.value.node) = new CArgumentList(2,(yystack_[2].value.node),(yystack_[0].value.node));  }
#line 1059 "Grammar.tab.cpp"
    break;

  case 76: // argument_list: expression
#line 158 "Grammar.y"
                                                { root= (yylhs.value.node) = new CArgumentList(1,(yystack_[0].value.node)); }
#line 1065 "Grammar.tab.cpp"
    break;


#line 1069 "Grammar.tab.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -70;

  const signed char parser::yytable_ninf_ = -20;

  const short
  parser::yypact_[] =
  {
     334,   -70,   -16,   -70,     0,   -70,   -70,   -25,   361,    -4,
       1,   418,    -6,    12,   457,   457,   457,   -70,   457,   214,
      47,   334,   -70,   334,   -70,    46,   361,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   668,   457,   457,   457,
     -70,    39,   436,   457,   -70,   679,   -70,   -70,    -9,    -9,
     -70,   488,   -70,   242,   -70,   -70,   334,   361,   -70,    50,
     361,     9,   -70,   457,   457,   457,   457,   457,   457,   457,
     457,   457,   457,   457,   457,   457,   457,   -70,   761,   761,
     -28,   501,    16,   445,   709,   533,   -70,   -70,   -70,   361,
      20,   -70,    14,   -15,   -15,   -15,   789,   798,   -15,   -15,
     -15,    -9,    -9,    27,    27,    27,   -70,   -70,   457,   361,
     457,    37,   720,   454,   361,   -70,    -7,   -70,    56,   761,
     -70,   546,   361,   578,   380,   398,   750,    45,    29,    14,
     -70,    33,   -70,   361,   361,   591,   361,   623,   408,   361,
     150,   -70,   -70,   -70,   -70,   361,   -70,   361,   361,   636,
     -70,   -70,   186,    64,   270,   -70,   -70,   -70,   361,   -70,
     298,    35,   -70,   -70,   -70
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    73,    71,    18,    74,    21,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     7,     0,    10,     0,     5,    23,    33,    26,
      25,    28,    27,    31,    30,    29,     0,     0,     0,     0,
      74,     0,     0,     0,    51,     0,    49,    48,    59,    58,
      70,     0,    35,     0,     1,     6,     0,     3,     9,     0,
       4,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    57,    76,
       0,     0,     0,     0,     0,     0,    50,    61,    34,     2,
       0,     8,     0,    65,    66,    67,    68,    69,    62,    63,
      64,    52,    53,    54,    55,    56,    60,    72,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    16,     0,    75,
      36,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      17,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    37,    44,    43,     0,    41,     0,     0,     0,
      47,    14,     0,     0,     0,    42,    40,    39,     0,    12,
       0,     0,    13,    38,    11
  };

  const signed char
  parser::yypgoto_[] =
  {
     -70,   -70,   -69,   -19,    53,   -14,   -70,   -53,   -17,   -18,
      -8,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    19,
     -70
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    20,    21,    22,    23,    24,   116,   117,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      80
  };

  const short
  parser::yytable_[] =
  {
      41,    53,    55,    57,   -19,    60,    59,    37,   107,    58,
      39,   108,    71,    72,    73,    74,    75,    76,    62,    38,
      73,    74,    75,    76,     3,   115,     5,     6,    46,   128,
      45,    42,   129,    48,    49,    50,    43,    51,    89,    59,
       1,     2,    58,    91,    92,    62,    47,    54,    40,    62,
      61,   110,    62,    82,    90,    92,    78,    79,    81,    76,
     130,    84,    85,   139,    14,    15,   140,   142,   161,    91,
      16,   152,    18,   122,    56,   118,   141,     0,     0,     0,
       0,    62,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,     0,
       0,   120,   112,     0,     0,     0,   127,     0,     0,     0,
       0,     0,   118,     0,   132,     0,     0,     0,     0,     0,
       0,     0,   154,   153,     0,   143,   144,   119,   146,   121,
     123,   150,   126,    55,   160,   153,     0,   155,     0,   156,
     157,     0,     0,   135,   137,     0,    62,     0,     0,     0,
     163,     0,    62,     1,     2,     0,     0,   149,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,   151,     1,
       2,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,     0,
       0,     0,     0,    14,    15,     0,     0,     1,     2,    16,
      17,    18,     0,    19,   159,    40,     0,     0,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     1,     2,    16,    17,    18,
       0,    19,    52,    40,     0,     0,     7,     8,     9,    10,
       0,    11,    12,    13,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     1,     2,    16,    17,    18,     0,    19,
      88,    40,     0,     0,     7,     8,     9,    10,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     1,     2,    16,    17,    18,     0,    19,   162,    40,
       0,     0,     7,     8,     9,    10,     0,    11,    12,    13,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,   164,     1,     2,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     1,     2,     0,    16,    17,    18,
       0,    19,    40,     0,     0,     7,     8,     9,    10,     0,
      11,    12,    13,     1,     2,     0,     0,     0,    14,    15,
       0,    40,     0,     0,    16,    17,    18,     0,    19,     0,
       0,     1,     2,     0,     0,     0,     0,    14,    15,    40,
       0,     1,     2,    16,     0,    18,   134,     0,     0,    40,
       0,     1,     2,     0,     0,    14,    15,     0,     0,    40,
       0,    16,     0,    18,   136,    14,    15,     0,     0,     1,
       2,    16,     0,    18,   148,    14,    15,    40,     1,     2,
       0,    16,    44,    18,     0,     0,    40,     1,     2,     0,
       1,     2,     0,    14,    15,    40,     0,     0,    40,    16,
      83,    18,    14,    15,     0,     0,     0,     0,    16,   111,
      18,    14,    15,     0,    14,    15,     0,    16,   125,    18,
      16,     0,    18,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    87,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,   109,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,   114,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,   131,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,     0,   133,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,     0,   145,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,   147,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,   158,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,     0,    77,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,    86,    63,    64,    65,    66,    67,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,   113,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,   124,    63,    64,    65,    66,    67,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,     0,   138,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    63,    64,    65,     0,    67,     0,
       0,     0,     0,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    68,    69,    70,    71,    72,    73,    74,    75,
      76
  };

  const short
  parser::yycheck_[] =
  {
       8,    19,    21,    21,     4,    23,    23,    23,    36,    23,
      35,    39,    27,    28,    29,    30,    31,    32,    26,    35,
      29,    30,    31,    32,    10,    11,    12,    13,    34,    36,
      11,    35,    39,    14,    15,    16,    35,    18,    56,    56,
       3,     4,    56,    34,    35,    53,    34,     0,    11,    57,
       4,    35,    60,    14,     4,    35,    37,    38,    39,    32,
       4,    42,    43,    18,    27,    28,    37,    34,     4,    34,
      33,   140,    35,    36,    21,    92,   129,    -1,    -1,    -1,
      -1,    89,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,   109,    83,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   129,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   140,    -1,   133,   134,   108,   136,   110,
     111,   139,   113,   152,   152,   152,    -1,   145,    -1,   147,
     148,    -1,    -1,   124,   125,    -1,   154,    -1,    -1,    -1,
     158,    -1,   160,     3,     4,    -1,    -1,   138,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,     3,
       4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,     3,     4,    33,
      34,    35,    -1,    37,    38,    11,    -1,    -1,    14,    15,
      16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,     3,     4,    33,    34,    35,
      -1,    37,    38,    11,    -1,    -1,    14,    15,    16,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,     3,     4,    33,    34,    35,    -1,    37,
      38,    11,    -1,    -1,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,     3,     4,    33,    34,    35,    -1,    37,    38,    11,
      -1,    -1,    14,    15,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,     3,     4,    -1,    33,    34,    35,
      -1,    37,    11,    -1,    -1,    14,    15,    16,    17,    -1,
      19,    20,    21,     3,     4,    -1,    -1,    -1,    27,    28,
      -1,    11,    -1,    -1,    33,    34,    35,    -1,    37,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    27,    28,    11,
      -1,     3,     4,    33,    -1,    35,    36,    -1,    -1,    11,
      -1,     3,     4,    -1,    -1,    27,    28,    -1,    -1,    11,
      -1,    33,    -1,    35,    36,    27,    28,    -1,    -1,     3,
       4,    33,    -1,    35,    36,    27,    28,    11,     3,     4,
      -1,    33,    34,    35,    -1,    -1,    11,     3,     4,    -1,
       3,     4,    -1,    27,    28,    11,    -1,    -1,    11,    33,
      34,    35,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    27,    28,    -1,    27,    28,    -1,    33,    34,    35,
      33,    -1,    35,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,     8,     9,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     5,     6,     7,    -1,     9,    -1,
      -1,    -1,    -1,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    24,    25,    26,    27,    28,    29,    30,    31,
      32
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,    10,    11,    12,    13,    14,    15,    16,
      17,    19,    20,    21,    27,    28,    33,    34,    35,    37,
      41,    42,    43,    44,    45,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    23,    35,    35,
      11,    50,    35,    35,    34,    59,    34,    34,    59,    59,
      59,    59,    38,    49,     0,    43,    44,    49,    45,    48,
      49,     4,    50,     5,     6,     7,     8,     9,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    34,    59,    59,
      60,    59,    14,    34,    59,    59,    34,    36,    38,    49,
       4,    34,    35,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    36,    39,    36,
      35,    34,    59,    34,    36,    11,    46,    47,    48,    59,
      50,    59,    36,    59,    34,    34,    59,    50,    36,    39,
       4,    36,    50,    36,    36,    59,    36,    59,    34,    18,
      37,    47,    34,    50,    50,    36,    50,    36,    36,    59,
      50,    38,    42,    48,    49,    50,    50,    50,    36,    38,
      49,     4,    38,    50,    38
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    40,    41,    41,    41,    41,    42,    42,    43,    44,
      44,    45,    45,    45,    45,    46,    46,    47,    48,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     2,     2,     1,     2,     1,     3,     2,
       1,     9,     8,     8,     7,     3,     1,     2,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     5,     7,     9,     8,
       8,     7,     8,     7,     7,     6,     5,     7,     2,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     4,     1,     1,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "IDENTIFIER", "NE", "GE", "LE", "AND", "OR", "INT", "FLOAT", "CHAR",
  "DOUBLE", "WHILE", "DO", "FOR", "IF", "ELSE", "RETURN", "BREAK",
  "CONTINUE", "IFPREC", "'='", "'>'", "'<'", "EQ", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "'!'", "';'", "'('", "')'", "'{'", "'}'", "','",
  "$accept", "translation_unit", "declarations", "declaration",
  "function_declarations", "function_declaration", "parameter_list",
  "parameter", "type_specifier", "statements", "statement",
  "compound_statement", "while_statement", "do_while_statement",
  "for_statement", "if_statement", "continue_statement", "break_statement",
  "return_statement", "expression", "argument_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    51,    51,    52,    53,    54,    57,    58,    61,    64,
      65,    69,    70,    71,    72,    74,    75,    77,    80,    81,
      82,    83,    86,    87,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   102,   103,   106,   108,   110,   111,
     112,   113,   114,   115,   116,   117,   119,   120,   123,   125,
     127,   128,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   157,   158
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    31,     2,     2,
      35,    36,    29,    27,    39,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      25,    23,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    26
    };
    // Last valid token kind.
    const int code_max = 278;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1824 "Grammar.tab.cpp"

#line 161 "Grammar.y"



void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << msg << " at "<< loc <<  std::endl;
}
