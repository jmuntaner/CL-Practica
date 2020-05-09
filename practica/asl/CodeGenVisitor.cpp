//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2019  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
//#define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr       & Types,
                               SymTable       & Symbols,
                               TreeDecoration & Decorations) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations} {
}

// Methods to visit each kind of node:
//
antlrcpp::Any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  code my_code;
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) {
    subroutine subr = visit(ctxFunc);
    my_code.add_subroutine(subr);
  }
  Symbols.popScope();
  DEBUG_EXIT();
  return my_code;
}

antlrcpp::Any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  subroutine subr(ctx->ID()->getText());
  codeCounters.reset();
  if(ctx->type()) {
    subr.add_param("_result");
  }
  std::vector<var> && lparams = visit(ctx->parameters());
  for (auto & onepar : lparams) {
    subr.add_param(onepar.name);
  }
  std::vector<var> && lvars = visit(ctx->declarations());
  for (auto & onevar : lvars) {
    subr.add_var(onevar);
  }
  instructionList && code = visit(ctx->statements());
  if(!ctx->type()) {
    code = code || instruction::RETURN();
  }
  subr.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
  return subr;
}

antlrcpp::Any CodeGenVisitor::visitParameters(AslParser::ParametersContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lparams;
  for (auto & varDeclCtx : ctx->parameter_decl()) {
    var oneparam = visit(varDeclCtx);
    lparams.push_back(oneparam);
  }
  DEBUG_EXIT();
  return lparams;
}

antlrcpp::Any CodeGenVisitor::visitParameter_decl(AslParser::Parameter_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  DEBUG_EXIT();
  return var{ctx->ID()->getText(), size};
}

antlrcpp::Any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
  std::vector<var> lvars;
  for (auto & varDeclCtx : ctx->variable_decl()) {
    std::vector<var> vars = visit(varDeclCtx);
    for (auto onevar : vars) {
      lvars.push_back(onevar);
    }
  }
  DEBUG_EXIT();
  return lvars;
}

antlrcpp::Any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId   t1 = getTypeDecor(ctx->type());
  std::size_t      size = Types.getSizeOfType(t1);
  std::vector<var> vars;
  for(unsigned int i = 0; i < ctx->ID().size(); i++)
    vars.push_back(var{ctx->ID(i)->getText(), size});
  DEBUG_EXIT();
  return vars;
}

antlrcpp::Any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    instructionList && codeS = visit(stCtx);
    code = code || codeS;
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  if(ctx->expr()) {
    CodeAttribs     && codAts = visit(ctx->expr());
    std::string           addr = codAts.addr;
    instructionList &     codeExpr = codAts.code;
    code = codeExpr || instruction::LOAD("_result",addr);
  }
  code = code || instruction::RETURN();
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE1 = visit(ctx->left_expr());
  std::string           addr1 = codAtsE1.addr;
  std::string           offs1 = codAtsE1.offs;
  instructionList &     code1 = codAtsE1.code;
  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  CodeAttribs     && codAtsE2 = visit(ctx->expr());
  std::string           addr2 = codAtsE2.addr;
  //std::string           offs2 = codAtsE2.offs;
  instructionList &     code2 = codAtsE2.code;
  std::string temp = "%"+codeCounters.newTEMP();
  code = code1 || code2;
  if (offs1 == "") {
    code = code || instruction::LOAD(addr1, addr2);
  }
  else {
    code = code || instruction::XLOAD(addr1, offs1, addr2);
  }
  // TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements(0));
  std::string label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  CodeAttribs     && codAtsE = visit(ctx->expr());
  std::string          addr1 = codAtsE.addr;
  instructionList &    code1 = codAtsE.code;
  instructionList &&   code2 = visit(ctx->statements());
  std::string label = codeCounters.newLabelWHILE();
  std::string labelCondWhile = "condwhile"+label;
  std::string labelEndWhile = "endwhile"+label;
  code = instruction::LABEL(labelCondWhile) || code1 || instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(labelCondWhile) || instruction::LABEL(labelEndWhile);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  instructionList codepop;
  instructionList codepush;
  std::string name = ctx->ident()->getText();
  TypesMgr::TypeId tFunc = getTypeDecor(ctx->ident());
  uint nParams = ctx->expr().size();
  for(uint i = 0; i < nParams; ++i) {
    CodeAttribs     && codParams = visit(ctx->expr(i));
    std::string          addr = codParams.addr;
    instructionList &    codeParam = codParams.code;
    code = code || codeParam;
    TypesMgr::TypeId tParam = getTypeDecor(ctx->expr(i));
    TypesMgr::TypeId tCheck = Types.getParameterType(tFunc, i);
    if(Types.isIntegerTy(tParam) and Types.isFloatTy(tCheck)) {
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp, addr);
      codepush = codepush || instruction::PUSH(temp);
    }
    else {
      codepush = codepush || instruction::PUSH(addr);
    }
    codepop = codepop || instruction::POP();
  }
  if(not Types.isVoidFunction(tFunc)) {
    code = code || instruction::PUSH();
    codepop = codepop || instruction::POP();
  }
  code = code || codepush || instruction::CALL(name) || codepop;
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitFuncIdent(AslParser::FuncIdentContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  instructionList codepop;
  instructionList codepush;
  // std::string name = ctx->ident()->ID()->getSymbol()->getText();
  TypesMgr::TypeId tFunc = getTypeDecor(ctx->ident());
  std::string name = ctx->ident()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  uint nParams = ctx->expr().size();
  for(uint i = 0; i < nParams; ++i) {
    CodeAttribs     && codParams = visit(ctx->expr(i));
    std::string          addr = codParams.addr;
    instructionList &    codeParam = codParams.code;
    code = code || codeParam;
    TypesMgr::TypeId tParam = getTypeDecor(ctx->expr(i));
    TypesMgr::TypeId tCheck = Types.getParameterType(tFunc, i);
    if(Types.isIntegerTy(tParam) and Types.isFloatTy(tCheck)) {
      std::string temp = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp, addr);
      codepush = codepush || instruction::PUSH(temp);
    }
    else {
      codepush = codepush || instruction::PUSH(addr);
    }
    codepop = codepop || instruction::POP();
  }
  code = code || instruction::PUSH() || codepush || instruction::CALL(name) || codepop || instruction::POP(temp);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAtsE = visit(ctx->left_expr());
  std::string          addr1 = codAtsE.addr;
  std::string          offs1 = codAtsE.offs;
  instructionList &    code1 = codAtsE.code;
  instructionList &     code = code1;
  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr()->ident());
  bool array = Types.isArrayTy(tid1);
  if (array) {
    tid1 = Types.getArrayElemType(tid1);
  }
  if (Types.isFloatTy(tid1)) {
    if (array) {
      code = code || instruction::READF(temp) || instruction::XLOAD(addr1, offs1, temp);
    }
    else {
      code = code || instruction::READF(addr1);
    }
  }
  else if (Types.isCharacterTy(tid1)) {
    if (array) {
      code = code || instruction::READC(temp) || instruction::XLOAD(addr1, offs1, temp);
    }
    else {
      code = code || instruction::READC(addr1);
    }
  }
  else {//if (Types.isIntegerTy(tid1)) {
    if (array) {
      code = code || instruction::READI(temp) || instruction::XLOAD(addr1, offs1, temp);
    }
    else {
      code = code || instruction::READI(addr1);
    }
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr());
  std::string         addr1 = codAt1.addr;
  // std::string         offs1 = codAt1.offs;
  instructionList &   code1 = codAt1.code;
  instructionList &    code = code1;
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  if(Types.isCharacterTy(tid1))
    code = code1 || instruction::WRITEC(addr1);
  else if(Types.isFloatTy(tid1))
    code = code1 || instruction::WRITEF(addr1);
  else //if(Types.isIntegerTy(tid1))
    code = code1 || instruction::WRITEI(addr1);
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }
  DEBUG_EXIT();
  return code;
}

antlrcpp::Any CodeGenVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  std::string         addr = codAts.addr;
  instructionList &   code = codAts.code;
  std::string offs = "";
  //array access
  if (ctx->expr()) {
    CodeAttribs && codExpr = visit(ctx->expr());
    std::string         addrE = codExpr.addr;
    instructionList &   codeE = codExpr.code;
    code = codeE || code;
    offs = addrE;
  }
  CodeAttribs codRes(addr, offs, code);
  DEBUG_EXIT();
  return codRes;
}

antlrcpp::Any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  TypesMgr::TypeId  t = getTypeDecor(ctx);
  bool floatOper = Types.isFloatTy(t);
  bool intExpr0 = Types.isIntegerTy(t1);
  bool intExpr1 = Types.isIntegerTy(t2);
  std::string temp = "%"+codeCounters.newTEMP();
  std::string tempCast = "%"+codeCounters.newTEMP();
  if (ctx->MUL()) {
    if (floatOper) {
      if(intExpr0)
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FMUL(temp, tempCast, addr2);
      else if(intExpr1)
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FMUL(temp, addr1, tempCast);
      else
        code = code || instruction::FMUL(temp, addr1, addr2);
    }
    else {
      code = code || instruction::MUL(temp, addr1, addr2);
    }
  } else if (ctx->PLUS()) {
    if (floatOper) {
          if(intExpr0)
            code = code || instruction::FLOAT(tempCast, addr1) || instruction::FADD(temp, tempCast, addr2);
          else if(intExpr1)
            code = code || instruction::FLOAT(tempCast, addr2) || instruction::FADD(temp, addr1, tempCast);
          else
            code = code || instruction::FADD(temp, addr1, addr2);
      }
      else {
          code = code || instruction::ADD(temp, addr1, addr2);
      }
  }
  else if (ctx->SUB()) {
    if (floatOper) {
      if(intExpr0)
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FSUB(temp, tempCast, addr2);
      else if(intExpr1)
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FSUB(temp, addr1, tempCast);
      else
        code = code || instruction::FSUB(temp, addr1, addr2);
    }
    else {
        code = code || instruction::SUB(temp, addr1, addr2);
    }
  }
  else if (ctx->DIV()) {
    if (floatOper) {
      if(intExpr0)
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FDIV(temp, tempCast, addr2);
      else if(intExpr1)
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FDIV(temp, addr1, tempCast);
      else
        code = code || instruction::FDIV(temp, addr1, addr2);
    }
    else {
        code = code || instruction::DIV(temp, addr1, addr2);
    }
  }
  else if (ctx->MOD()) {
    // a%b = a - b*(a/b)
    code = code || instruction::DIV(temp, addr1, addr2) ||
    instruction::MUL(temp, addr2, temp) || instruction::SUB(temp, addr1, temp);
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs     && codAt1 = visit(ctx->expr(0));
  std::string         addr1 = codAt1.addr;
  instructionList &   code1 = codAt1.code;
  CodeAttribs     && codAt2 = visit(ctx->expr(1));
  std::string         addr2 = codAt2.addr;
  instructionList &   code2 = codAt2.code;
  instructionList &&   code = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  bool intExpr0 = Types.isIntegerTy(t1);
  bool intExpr1 = Types.isIntegerTy(t2);
  bool floatOper = Types.isFloatTy(t1) or Types.isFloatTy(t2);
  // TypesMgr::TypeId  t = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  std::string tempCast = "%"+codeCounters.newTEMP();
  // EQUAL | LT | GT | NEQ | GEQ | LEQ
  if (ctx->EQUAL() or ctx->NEQ()) {
    if (floatOper) {
      if(intExpr0) {
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FEQ(temp, tempCast, addr2);
      } else if(intExpr1) {
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FEQ(temp, addr1, tempCast);
      } else
        code = code || instruction::FEQ(temp, addr1, addr2);
    }
    else {
      code = code || instruction::EQ(temp, addr1, addr2);
    }
    if (ctx->NEQ())
      code = code || instruction::NOT(temp, temp);
  }
  else if (ctx->LT()) {
    if (floatOper) {
      if(intExpr0) {
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FLT(temp, tempCast, addr2);
      } else if(intExpr1) {
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FLT(temp, addr1, tempCast);
      } else
        code = code || instruction::FLT(temp, addr1, addr2);
    }
    else
      code = code || instruction::LT(temp, addr1, addr2);
  }
  else if (ctx->GT()) {
    if (floatOper) {
      if(intExpr0) {
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FLT(temp, addr2, tempCast);
      } else if(intExpr1) {
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FLT(temp, tempCast, addr1);
      } else
        code = code || instruction::FLT(temp, addr2, addr1);
    }
    else
      code = code || instruction::LT(temp, addr2, addr1);
  }
  else if (ctx->GEQ()) {
    if (floatOper) {
      if(intExpr0) {
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FLE(temp, addr2, tempCast);
      } else if(intExpr1) {
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FLE(temp, tempCast, addr1);
      } else
        code = code || instruction::FLE(temp, addr2, addr1);
    }
    else
      code = code || instruction::LE(temp, addr2, addr1);
  }
  else if (ctx->LEQ()) {
    if (floatOper) {
      if(intExpr0) {
        code = code || instruction::FLOAT(tempCast, addr1) || instruction::FLE(temp, tempCast, addr2);
      } else if(intExpr1) {
        code = code || instruction::FLOAT(tempCast, addr2) || instruction::FLE(temp, addr1, tempCast);
      } else
        code = code || instruction::FLE(temp, addr1, addr2);
    }
    else
      code = code || instruction::LE(temp, addr1, addr2);
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitArrayAccess(AslParser::ArrayAccessContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  CodeAttribs && codId = visit(ctx->ident());
  std::string         addr1 = codId.addr;
  instructionList &   code1 = codId.code;
  CodeAttribs && codE = visit(ctx->expr());
  std::string         addr2 = codE.addr;
  instructionList &   code2 = codE.code;
  code = code1 || code2 || instruction::LOADX(temp, addr1, addr2);
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->BOOLVAL()) {
    if (ctx->getText() == "true")
      code = instruction::ILOAD(temp, "1");
    else
      code = instruction::ILOAD(temp, "0");
  }
  else if (ctx->FLOATVAL()) {
    code = instruction::FLOAD(temp, ctx->getText());
  }
  else if (ctx->CHARVAL()) {
    code = instruction::CHLOAD(temp, ctx->getText());
  }
  else {//if(ctx->INTVAL())
    code = instruction::ILOAD(temp, ctx->getText());
  }
  CodeAttribs codAts(temp, "", code);
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs && codAts = visit(ctx->ident());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  CodeAttribs codAts(ctx->ID()->getText(), "", instructionList());
  DEBUG_EXIT();
  return codAts;
}

antlrcpp::Any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx) {
    DEBUG_ENTER();
    CodeAttribs && codAts = visit(ctx->expr());
    DEBUG_EXIT();
    return codAts;
}

antlrcpp::Any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx) {
    DEBUG_ENTER();
    CodeAttribs     && codAt = visit(ctx->expr());
    std::string         addr = codAt.addr;
    instructionList &   code = codAt.code;
    TypesMgr::TypeId  t = getTypeDecor(ctx);
    bool floatOper = Types.isFloatTy(t);
    std::string temp = "%"+codeCounters.newTEMP();
    if (ctx->NOT()) {
      code = code || instruction::NOT(temp, addr);
    }
    else if (ctx->SUB()) {
      if(floatOper)
        code = code || instruction::FNEG(temp, addr);
      else
        code = code || instruction::NEG(temp, addr);
    }
    else if (ctx->PLUS()) {
      DEBUG_EXIT();
      return codAt;
    }
    CodeAttribs codAts(temp, "", code);
    DEBUG_EXIT();
    return codAts;
}

antlrcpp::Any CodeGenVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
    DEBUG_ENTER();
    CodeAttribs     && codAt1 = visit(ctx->expr(0));
    std::string         addr1 = codAt1.addr;
    instructionList &   code1 = codAt1.code;
    CodeAttribs     && codAt2 = visit(ctx->expr(1));
    std::string         addr2 = codAt2.addr;
    instructionList &   code2 = codAt2.code;
    instructionList &&   code = code1 || code2;
    // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    // TypesMgr::TypeId  t = getTypeDecor(ctx);
    std::string temp = "%"+codeCounters.newTEMP();
    if (ctx->AND()) {
      code = code || instruction::AND(temp, addr1, addr2);
    }
    else if (ctx->OR()) {
      code = code || instruction::OR(temp, addr1, addr2);
    }
    CodeAttribs codAts(temp, "", code);
    DEBUG_EXIT();
    return codAts;
}

// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const {
  return Decorations.getType(ctx);
}


// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
					 const std::string & offs,
					 instructionList & code) :
  addr{addr}, offs{offs}, code{code} {
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string & addr,
					 const std::string & offs,
					 instructionList && code) :
  addr{addr}, offs{offs}, code{code} {
}
