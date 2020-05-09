
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, ASSIGN = 5, EQUAL = 6, NEQ = 7, 
    PLUS = 8, SUB = 9, MUL = 10, DIV = 11, MOD = 12, LT = 13, GT = 14, GEQ = 15, 
    LEQ = 16, COMMA = 17, LCLAU = 18, RCLAU = 19, AND = 20, OR = 21, NOT = 22, 
    VAR = 23, ARRAY = 24, OF = 25, INT = 26, BOOL = 27, FLOAT = 28, CHAR = 29, 
    IF = 30, WHILE = 31, FOR = 32, IN = 33, RANGE = 34, DO = 35, THEN = 36, 
    ELSE = 37, ENDIF = 38, ENDWHILE = 39, ENDFOR = 40, FUNC = 41, ENDFUNC = 42, 
    RETURN = 43, READ = 44, WRITE = 45, BOOLVAL = 46, TRUE = 47, FALSE = 48, 
    ID = 49, INTVAL = 50, FLOATVAL = 51, CHARVAL = 52, STRING = 53, COMMENT = 54, 
    WS = 55
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

