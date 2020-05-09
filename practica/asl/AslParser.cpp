
// Generated from Asl.g4 by ANTLR 4.7.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}


antlrcpp::Any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      function();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(31);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::ParametersContext* AslParser::FunctionContext::parameters() {
  return getRuleContext<AslParser::ParametersContext>(0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}


antlrcpp::Any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(AslParser::FUNC);
    setState(34);
    match(AslParser::ID);
    setState(35);
    match(AslParser::T__0);
    setState(36);
    parameters();
    setState(37);
    match(AslParser::T__1);
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__2) {
      setState(38);
      match(AslParser::T__2);
      setState(39);
      type();
    }
    setState(42);
    declarations();
    setState(43);
    statements();
    setState(44);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}


antlrcpp::Any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(46);
      variable_decl();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

AslParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Parameter_declContext *> AslParser::ParametersContext::parameter_decl() {
  return getRuleContexts<AslParser::Parameter_declContext>();
}

AslParser::Parameter_declContext* AslParser::ParametersContext::parameter_decl(size_t i) {
  return getRuleContext<AslParser::Parameter_declContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::ParametersContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::ParametersContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}


size_t AslParser::ParametersContext::getRuleIndex() const {
  return AslParser::RuleParameters;
}


antlrcpp::Any AslParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ParametersContext* AslParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::ID: {
        setState(52);
        parameter_decl();
        setState(57);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::COMMA) {
          setState(53);
          match(AslParser::COMMA);
          setState(54);
          parameter_decl();
          setState(59);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case AslParser::T__1: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_declContext ------------------------------------------------------------------

AslParser::Parameter_declContext::Parameter_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Parameter_declContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::TypeContext* AslParser::Parameter_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Parameter_declContext::getRuleIndex() const {
  return AslParser::RuleParameter_decl;
}


antlrcpp::Any AslParser::Parameter_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameter_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Parameter_declContext* AslParser::parameter_decl() {
  Parameter_declContext *_localctx = _tracker.createInstance<Parameter_declContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleParameter_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(AslParser::ID);
    setState(64);
    match(AslParser::T__2);
    setState(65);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::Variable_declContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}


antlrcpp::Any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(AslParser::VAR);
    setState(68);
    match(AslParser::ID);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::COMMA) {
      setState(69);
      match(AslParser::COMMA);
      setState(70);
      match(AslParser::ID);
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(AslParser::T__2);
    setState(77);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Basic_typeContext* AslParser::TypeContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}

tree::TerminalNode* AslParser::TypeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::TypeContext::LCLAU() {
  return getToken(AslParser::LCLAU, 0);
}

tree::TerminalNode* AslParser::TypeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::TypeContext::RCLAU() {
  return getToken(AslParser::RCLAU, 0);
}

tree::TerminalNode* AslParser::TypeContext::OF() {
  return getToken(AslParser::OF, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}


antlrcpp::Any AslParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::BOOL:
      case AslParser::FLOAT:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        basic_type();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        match(AslParser::ARRAY);
        setState(81);
        match(AslParser::LCLAU);
        setState(82);
        match(AslParser::INTVAL);
        setState(83);
        match(AslParser::RCLAU);
        setState(84);
        match(AslParser::OF);
        setState(85);
        basic_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_typeContext ------------------------------------------------------------------

AslParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Basic_typeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::Basic_typeContext::getRuleIndex() const {
  return AslParser::RuleBasic_type;
}


antlrcpp::Any AslParser::Basic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasic_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Basic_typeContext* AslParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleBasic_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}


antlrcpp::Any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::FOR)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(90);
      statement();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ForStmtContext::FOR() {
  return getToken(AslParser::FOR, 0);
}

AslParser::IdentContext* AslParser::ForStmtContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ForStmtContext::IN() {
  return getToken(AslParser::IN, 0);
}

tree::TerminalNode* AslParser::ForStmtContext::RANGE() {
  return getToken(AslParser::RANGE, 0);
}

tree::TerminalNode* AslParser::ForStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::ForStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::ForStmtContext::ENDFOR() {
  return getToken(AslParser::ENDFOR, 0);
}

std::vector<AslParser::ExprContext *> AslParser::ForStmtContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::ForStmtContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::ForStmtContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}

AslParser::ForStmtContext::ForStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::ProcCallContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::ProcCallContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(96);
      left_expr();
      setState(97);
      match(AslParser::ASSIGN);
      setState(98);
      expr(0);
      setState(99);
      match(AslParser::T__3);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(101);
      match(AslParser::IF);
      setState(102);
      expr(0);
      setState(103);
      match(AslParser::THEN);
      setState(104);
      statements();
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(105);
        match(AslParser::ELSE);
        setState(106);
        statements();
      }
      setState(109);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(111);
      match(AslParser::WHILE);
      setState(112);
      expr(0);
      setState(113);
      match(AslParser::DO);
      setState(114);
      statements();
      setState(115);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ForStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(117);
      match(AslParser::FOR);
      setState(118);
      ident();
      setState(119);
      match(AslParser::IN);
      setState(120);
      match(AslParser::RANGE);
      setState(121);
      match(AslParser::T__0);
      setState(131);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AslParser::T__0:
        case AslParser::PLUS:
        case AslParser::SUB:
        case AslParser::NOT:
        case AslParser::BOOLVAL:
        case AslParser::ID:
        case AslParser::INTVAL:
        case AslParser::FLOATVAL:
        case AslParser::CHARVAL: {
          setState(122);
          expr(0);
          setState(127);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == AslParser::COMMA) {
            setState(123);
            match(AslParser::COMMA);
            setState(124);
            expr(0);
            setState(129);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case AslParser::T__1: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(133);
      match(AslParser::T__1);
      setState(134);
      match(AslParser::DO);
      setState(135);
      statements();
      setState(136);
      match(AslParser::ENDFOR);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(138);
      ident();
      setState(139);
      match(AslParser::T__0);
      setState(149);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AslParser::T__0:
        case AslParser::PLUS:
        case AslParser::SUB:
        case AslParser::NOT:
        case AslParser::BOOLVAL:
        case AslParser::ID:
        case AslParser::INTVAL:
        case AslParser::FLOATVAL:
        case AslParser::CHARVAL: {
          setState(140);
          expr(0);
          setState(145);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == AslParser::COMMA) {
            setState(141);
            match(AslParser::COMMA);
            setState(142);
            expr(0);
            setState(147);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case AslParser::T__1: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(151);
      match(AslParser::T__1);
      setState(152);
      match(AslParser::T__3);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(154);
      match(AslParser::RETURN);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0)) {
        setState(155);
        expr(0);
      }
      setState(158);
      match(AslParser::T__3);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(159);
      match(AslParser::READ);
      setState(160);
      left_expr();
      setState(161);
      match(AslParser::T__3);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(163);
      match(AslParser::WRITE);
      setState(164);
      expr(0);
      setState(165);
      match(AslParser::T__3);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(167);
      match(AslParser::WRITE);
      setState(168);
      match(AslParser::STRING);
      setState(169);
      match(AslParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Left_exprContext::LCLAU() {
  return getToken(AslParser::LCLAU, 0);
}

AslParser::ExprContext* AslParser::Left_exprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::Left_exprContext::RCLAU() {
  return getToken(AslParser::RCLAU, 0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}


antlrcpp::Any AslParser::Left_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeft_expr(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleLeft_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    ident();
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::LCLAU) {
      setState(173);
      match(AslParser::LCLAU);
      setState(174);
      expr(0);
      setState(175);
      match(AslParser::RCLAU);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::FuncIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::FuncIdentContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::FuncIdentContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> AslParser::FuncIdentContext::COMMA() {
  return getTokens(AslParser::COMMA);
}

tree::TerminalNode* AslParser::FuncIdentContext::COMMA(size_t i) {
  return getToken(AslParser::COMMA, i);
}

AslParser::FuncIdentContext::FuncIdentContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::FuncIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFuncIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NEQ() {
  return getToken(AslParser::NEQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GEQ() {
  return getToken(AslParser::GEQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LEQ() {
  return getToken(AslParser::LEQ, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAccessContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ArrayAccessContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ArrayAccessContext::LCLAU() {
  return getToken(AslParser::LCLAU, 0);
}

AslParser::ExprContext* AslParser::ArrayAccessContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::ArrayAccessContext::RCLAU() {
  return getToken(AslParser::RCLAU, 0);
}

AslParser::ArrayAccessContext::ArrayAccessContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArrayAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(211);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(180);
      match(AslParser::T__0);
      setState(181);
      expr(0);
      setState(182);
      match(AslParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayAccessContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      ident();
      setState(185);
      match(AslParser::LCLAU);
      setState(186);
      expr(0);
      setState(187);
      match(AslParser::RCLAU);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(189);
      dynamic_cast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::PLUS)
        | (1ULL << AslParser::SUB)
        | (1ULL << AslParser::NOT))) != 0))) {
        dynamic_cast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(190);
      expr(12);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(191);
      match(AslParser::INTVAL);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(192);
      match(AslParser::CHARVAL);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(193);
      match(AslParser::FLOATVAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(194);
      match(AslParser::BOOLVAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<FuncIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(195);
      ident();
      setState(196);
      match(AslParser::T__0);
      setState(206);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AslParser::T__0:
        case AslParser::PLUS:
        case AslParser::SUB:
        case AslParser::NOT:
        case AslParser::BOOLVAL:
        case AslParser::ID:
        case AslParser::INTVAL:
        case AslParser::FLOATVAL:
        case AslParser::CHARVAL: {
          setState(197);
          expr(0);
          setState(202);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == AslParser::COMMA) {
            setState(198);
            match(AslParser::COMMA);
            setState(199);
            expr(0);
            setState(204);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case AslParser::T__1: {
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(208);
      match(AslParser::T__1);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(210);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(230);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(228);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(214);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::MUL)
            | (1ULL << AslParser::DIV)
            | (1ULL << AslParser::MOD))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(215);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(216);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(217);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::SUB)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(218);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(219);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(220);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::NEQ)
            | (1ULL << AslParser::LT)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::GEQ)
            | (1ULL << AslParser::LEQ))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(221);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(223);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::AND);
          setState(224);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(226);
          dynamic_cast<BooleanContext *>(_localctx)->op = match(AslParser::OR);
          setState(227);
          expr(8);
          break;
        }

        } 
      }
      setState(232);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}


antlrcpp::Any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "declarations", "parameters", "parameter_decl", 
  "variable_decl", "type", "basic_type", "statements", "statement", "left_expr", 
  "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "')'", "':'", "';'", "'='", "'=='", "'!='", "'+'", "'-'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'>='", "'<='", "','", "'['", "']'", "'and'", 
  "'or'", "'not'", "'var'", "'array'", "'of'", "'int'", "'bool'", "'float'", 
  "'char'", "'if'", "'while'", "'for'", "'in'", "'range'", "'do'", "'then'", 
  "'else'", "'endif'", "'endwhile'", "'endfor'", "'func'", "'endfunc'", 
  "'return'", "'read'", "'write'", "", "'true'", "'false'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "ASSIGN", "EQUAL", "NEQ", "PLUS", "SUB", "MUL", "DIV", 
  "MOD", "LT", "GT", "GEQ", "LEQ", "COMMA", "LCLAU", "RCLAU", "AND", "OR", 
  "NOT", "VAR", "ARRAY", "OF", "INT", "BOOL", "FLOAT", "CHAR", "IF", "WHILE", 
  "FOR", "IN", "RANGE", "DO", "THEN", "ELSE", "ENDIF", "ENDWHILE", "ENDFOR", 
  "FUNC", "ENDFUNC", "RETURN", "READ", "WRITE", "BOOLVAL", "TRUE", "FALSE", 
  "ID", "INTVAL", "FLOATVAL", "CHARVAL", "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x39, 0xee, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x6, 0x2, 0x1e, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1f, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x7, 0x4, 0x32, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x35, 0xb, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3a, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x3d, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0x4a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x4d, 0xb, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x59, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x7, 0xa, 0x5e, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x61, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x6e, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0x80, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x83, 0xb, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x86, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0x92, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x95, 0xb, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x98, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x9f, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xad, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0xb4, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xcb, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xce, 0xb, 0xd, 0x3, 0xd, 0x5, 0xd, 0xd1, 0xa, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0xd6, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xe7, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0xea, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x2, 0x3, 0x18, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x2, 0x7, 0x3, 0x2, 0x1c, 0x1f, 0x4, 0x2, 0xa, 
    0xb, 0x18, 0x18, 0x3, 0x2, 0xc, 0xe, 0x3, 0x2, 0xa, 0xb, 0x4, 0x2, 0x8, 
    0x9, 0xf, 0x12, 0x2, 0x106, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x33, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x58, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x14, 0xac, 0x3, 0x2, 0x2, 0x2, 0x16, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xeb, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x22, 0x7, 0x2, 0x2, 0x3, 0x22, 0x3, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x24, 0x7, 0x2b, 0x2, 0x2, 0x24, 0x25, 0x7, 0x33, 0x2, 0x2, 0x25, 0x26, 
    0x7, 0x3, 0x2, 0x2, 0x26, 0x27, 0x5, 0x8, 0x5, 0x2, 0x27, 0x2a, 0x7, 
    0x4, 0x2, 0x2, 0x28, 0x29, 0x7, 0x5, 0x2, 0x2, 0x29, 0x2b, 0x5, 0xe, 
    0x8, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x6, 0x4, 0x2, 
    0x2d, 0x2e, 0x5, 0x12, 0xa, 0x2, 0x2e, 0x2f, 0x7, 0x2c, 0x2, 0x2, 0x2f, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x5, 0xc, 0x7, 0x2, 0x31, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3b, 0x5, 0xa, 0x6, 
    0x2, 0x37, 0x38, 0x7, 0x13, 0x2, 0x2, 0x38, 0x3a, 0x5, 0xa, 0x6, 0x2, 
    0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3b, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x9, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x33, 0x2, 
    0x2, 0x42, 0x43, 0x7, 0x5, 0x2, 0x2, 0x43, 0x44, 0x5, 0xe, 0x8, 0x2, 
    0x44, 0xb, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x19, 0x2, 0x2, 0x46, 
    0x4b, 0x7, 0x33, 0x2, 0x2, 0x47, 0x48, 0x7, 0x13, 0x2, 0x2, 0x48, 0x4a, 
    0x7, 0x33, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x7, 0x5, 0x2, 0x2, 0x4f, 0x50, 0x5, 0xe, 0x8, 0x2, 
    0x50, 0xd, 0x3, 0x2, 0x2, 0x2, 0x51, 0x59, 0x5, 0x10, 0x9, 0x2, 0x52, 
    0x53, 0x7, 0x1a, 0x2, 0x2, 0x53, 0x54, 0x7, 0x14, 0x2, 0x2, 0x54, 0x55, 
    0x7, 0x34, 0x2, 0x2, 0x55, 0x56, 0x7, 0x15, 0x2, 0x2, 0x56, 0x57, 0x7, 
    0x1b, 0x2, 0x2, 0x57, 0x59, 0x5, 0x10, 0x9, 0x2, 0x58, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x52, 0x3, 0x2, 0x2, 0x2, 0x59, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x9, 0x2, 0x2, 0x2, 0x5b, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5e, 0x5, 0x14, 0xb, 0x2, 0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x13, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x63, 0x5, 0x16, 0xc, 0x2, 0x63, 0x64, 0x7, 0x7, 
    0x2, 0x2, 0x64, 0x65, 0x5, 0x18, 0xd, 0x2, 0x65, 0x66, 0x7, 0x6, 0x2, 
    0x2, 0x66, 0xad, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x20, 0x2, 0x2, 
    0x68, 0x69, 0x5, 0x18, 0xd, 0x2, 0x69, 0x6a, 0x7, 0x26, 0x2, 0x2, 0x6a, 
    0x6d, 0x5, 0x12, 0xa, 0x2, 0x6b, 0x6c, 0x7, 0x27, 0x2, 0x2, 0x6c, 0x6e, 
    0x5, 0x12, 0xa, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x28, 
    0x2, 0x2, 0x70, 0xad, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x21, 0x2, 
    0x2, 0x72, 0x73, 0x5, 0x18, 0xd, 0x2, 0x73, 0x74, 0x7, 0x25, 0x2, 0x2, 
    0x74, 0x75, 0x5, 0x12, 0xa, 0x2, 0x75, 0x76, 0x7, 0x29, 0x2, 0x2, 0x76, 
    0xad, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x22, 0x2, 0x2, 0x78, 0x79, 
    0x5, 0x1a, 0xe, 0x2, 0x79, 0x7a, 0x7, 0x23, 0x2, 0x2, 0x7a, 0x7b, 0x7, 
    0x24, 0x2, 0x2, 0x7b, 0x85, 0x7, 0x3, 0x2, 0x2, 0x7c, 0x81, 0x5, 0x18, 
    0xd, 0x2, 0x7d, 0x7e, 0x7, 0x13, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x18, 0xd, 
    0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x4, 
    0x2, 0x2, 0x88, 0x89, 0x7, 0x25, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x12, 0xa, 
    0x2, 0x8a, 0x8b, 0x7, 0x2a, 0x2, 0x2, 0x8b, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x8d, 0x5, 0x1a, 0xe, 0x2, 0x8d, 0x97, 0x7, 0x3, 0x2, 0x2, 0x8e, 
    0x93, 0x5, 0x18, 0xd, 0x2, 0x8f, 0x90, 0x7, 0x13, 0x2, 0x2, 0x90, 0x92, 
    0x5, 0x18, 0xd, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x98, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8e, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0x4, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x6, 0x2, 0x2, 0x9b, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x2d, 0x2, 0x2, 0x9d, 0x9f, 0x5, 
    0x18, 0xd, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xad, 0x7, 0x6, 0x2, 
    0x2, 0xa1, 0xa2, 0x7, 0x2e, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x16, 0xc, 0x2, 
    0xa3, 0xa4, 0x7, 0x6, 0x2, 0x2, 0xa4, 0xad, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa6, 0x7, 0x2f, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x18, 0xd, 0x2, 0xa7, 0xa8, 
    0x7, 0x6, 0x2, 0x2, 0xa8, 0xad, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 
    0x2f, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x37, 0x2, 0x2, 0xab, 0xad, 0x7, 0x6, 
    0x2, 0x2, 0xac, 0x62, 0x3, 0x2, 0x2, 0x2, 0xac, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0x71, 0x3, 0x2, 0x2, 0x2, 0xac, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0x8c, 0x3, 0x2, 0x2, 0x2, 0xac, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0x15, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb3, 0x5, 
    0x1a, 0xe, 0x2, 0xaf, 0xb0, 0x7, 0x14, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0x18, 
    0xd, 0x2, 0xb1, 0xb2, 0x7, 0x15, 0x2, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x8, 0xd, 0x1, 0x2, 0xb6, 
    0xb7, 0x7, 0x3, 0x2, 0x2, 0xb7, 0xb8, 0x5, 0x18, 0xd, 0x2, 0xb8, 0xb9, 
    0x7, 0x4, 0x2, 0x2, 0xb9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x5, 
    0x1a, 0xe, 0x2, 0xbb, 0xbc, 0x7, 0x14, 0x2, 0x2, 0xbc, 0xbd, 0x5, 0x18, 
    0xd, 0x2, 0xbd, 0xbe, 0x7, 0x15, 0x2, 0x2, 0xbe, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0x9, 0x3, 0x2, 0x2, 0xc0, 0xd6, 0x5, 0x18, 0xd, 0xe, 
    0xc1, 0xd6, 0x7, 0x34, 0x2, 0x2, 0xc2, 0xd6, 0x7, 0x36, 0x2, 0x2, 0xc3, 
    0xd6, 0x7, 0x35, 0x2, 0x2, 0xc4, 0xd6, 0x7, 0x30, 0x2, 0x2, 0xc5, 0xc6, 
    0x5, 0x1a, 0xe, 0x2, 0xc6, 0xd0, 0x7, 0x3, 0x2, 0x2, 0xc7, 0xcc, 0x5, 
    0x18, 0xd, 0x2, 0xc8, 0xc9, 0x7, 0x13, 0x2, 0x2, 0xc9, 0xcb, 0x5, 0x18, 
    0xd, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 
    0x4, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x1a, 
    0xe, 0x2, 0xd5, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0xc, 
    0xd, 0x2, 0x2, 0xd8, 0xd9, 0x9, 0x4, 0x2, 0x2, 0xd9, 0xe7, 0x5, 0x18, 
    0xd, 0xe, 0xda, 0xdb, 0xc, 0xc, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x5, 0x2, 
    0x2, 0xdc, 0xe7, 0x5, 0x18, 0xd, 0xd, 0xdd, 0xde, 0xc, 0xb, 0x2, 0x2, 
    0xde, 0xdf, 0x9, 0x6, 0x2, 0x2, 0xdf, 0xe7, 0x5, 0x18, 0xd, 0xc, 0xe0, 
    0xe1, 0xc, 0xa, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x16, 0x2, 0x2, 0xe2, 0xe7, 
    0x5, 0x18, 0xd, 0xb, 0xe3, 0xe4, 0xc, 0x9, 0x2, 0x2, 0xe4, 0xe5, 0x7, 
    0x17, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x18, 0xd, 0xa, 0xe6, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x33, 0x2, 0x2, 0xec, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x1f, 0x2a, 0x33, 0x3b, 0x3f, 0x4b, 0x58, 0x5f, 
    0x6d, 0x81, 0x85, 0x93, 0x97, 0x9e, 0xac, 0xb3, 0xcc, 0xd0, 0xd5, 0xe6, 
    0xe8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
