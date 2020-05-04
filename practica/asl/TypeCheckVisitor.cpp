//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
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


#include "TypeCheckVisitor.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
       SymTable       & Symbols,
       TreeDecoration & Decorations,
       SemErrors      & Errors) :
  Types{Types},
  Symbols {Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) {
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  if(ctx->type()) {
    visit(ctx->type());
    TypesMgr::TypeId tRet = getTypeDecor(ctx->type());
    Symbols.setCurrentFunctionTy(tRet);
  }
  else {
    TypesMgr::TypeId tRet = Types.createVoidTy();
    Symbols.setCurrentFunctionTy(tRet);
  }
  /*std::string ident = ctx->ID()->getText();
  TypesMgr::TypeId tFunc = Symbols.getType(ident);
  Symbols.setCurrentFunctionTy(tFunc);*/
  // Symbols.print();
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
  //std::cout << Types.to_string(t1) << ' ' << Types.to_string(t2) << std::endl << std::endl;
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  if(ctx->ELSE()) {
      visit(ctx->statements(0));
      visit(ctx->statements(1));
  }
  else {
      visit(ctx->statements(0));
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitForStmt(AslParser::ForStmtContext *ctx) {
  DEBUG_ENTER();
  int nRange = ctx->expr().size();
  if(nRange == 0 or nRange > 3) {
      Errors.numberOfRangeExpressions(ctx);
  }
  for(int i = 0; i < nRange; ++i) {
      visit(ctx->expr(i));
  }
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if ((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1)))
    Errors.forRequireIntegerVar(ctx->ident());
  TypesMgr::TypeId t;
  for(int i = 0; i < nRange; ++i) {
      t = getTypeDecor(ctx->expr(i));
      if ((not Types.isErrorTy(t)) and (not Types.isIntegerTy(t)))
        Errors.forRequireIntegerExpr(ctx->expr(i));
  }
  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  // Mirem si és funció
  if ((not Types.isErrorTy(t1)) and (not Types.isFunctionTy(t1))) {
    Errors.isNotCallable(ctx->ident());
  }
  else if (Types.isFunctionTy(t1)){
    uint nParams = ctx->expr().size();
    if(nParams != Types.getNumOfParameters(t1)) {
      Errors.numberOfParameters(ctx->ident());
      for(uint i = 0; i < nParams; ++i)
        visit(ctx->expr(i));
    } else {
      for(uint i = 0; i < nParams; ++i) {
        visit(ctx->expr(i));
        TypesMgr::TypeId tParam = getTypeDecor(ctx->expr(i));
        TypesMgr::TypeId tCheck = Types.getParameterType(t1, i);
        if((not Types.copyableTypes(tCheck,tParam)) and (not Types.isErrorTy(tParam))) {
          Errors.incompatibleParameter(ctx->expr(i),i+1,ctx->ident());
        }
      }
    }
  }
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId tRet = Symbols.getCurrentFunctionTy();
  TypesMgr::TypeId tTry = Types.createErrorTy();
  if(ctx->expr()) {
    //intent de retornar quelcom
    visit(ctx->expr());
    tTry = getTypeDecor(ctx->expr());
    if((not Types.equalTypes(tRet, tTry)) and (not Types.isErrorTy(tTry)) and (not Types.isErrorTy(tRet))) {
      if(not (Types.isIntegerTy(tTry) and Types.isFloatTy(tRet)))
        Errors.incompatibleReturn(ctx->RETURN());
    }
  }
  else {
    //void return?
    if(not Types.isVoidTy(tRet)) {
      Errors.incompatibleReturn(ctx->RETURN());
    }
  }
  //std::cout << Types.to_string(tRet) << ' ' << Types.to_string(tTry) << std::endl;
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  //std::cout << Types.to_string(t1) << std::endl;
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  bool b = getIsLValueDecor(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if(ctx->expr()) {
    b = true;
    if ((not Types.isErrorTy(t1)) and (not Types.isArrayTy(t1))) {
      Errors.nonArrayInArrayAccess(ctx->ident());
      t1 = Types.createErrorTy();
    }
    else if(Types.isArrayTy(t1))
        t1 = Types.getArrayElemType(t1);
    visit(ctx->expr());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))
      Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  }
  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if (ctx->MOD() and (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))))
      Errors.incompatibleOperator(ctx->op);
  else if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t;
  if(Types.isFloatTy(t1) or Types.isFloatTy(t2)) {
      t = Types.createFloatTy();
  }
  else {
    t = Types.createIntegerTy();
  }
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArrayAccess(AslParser::ArrayAccessContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1)))
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->ident());
  if ((not Types.isErrorTy(t2)) and (not Types.isArrayTy(t2))) {
    Errors.nonArrayInArrayAccess(ctx->ident());
    TypesMgr::TypeId t = Types.createErrorTy();
    putTypeDecor(ctx, t);
  }
  else if (Types.isArrayTy(t2)){
    TypesMgr::TypeId t = Types.getArrayElemType(t2);
    putTypeDecor(ctx, t);
  }
  /*
  else {
      t2 es error i assignar-hi tipus random
  }
  */
  putIsLValueDecor(ctx, true);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitMax(AslParser::MaxContext *ctx) {
  DEBUG_ENTER();
  int nParams = ctx->expr().size();
  bool charv = 0;
  bool floatv = 0;
  bool numericv = 0;
  TypesMgr::TypeId t;
  for(int i = 0; i < nParams; i++) {
    visit(ctx->expr(i));
  }
  if(nParams < 2) {
      Errors.numberOfMaxArguments(ctx);
      t = Types.createErrorTy();
  }
  else {
      TypesMgr::TypeId t1;
      for(int i = 0; i < nParams; i++) {
        t1 = getTypeDecor(ctx->expr(i));
        if(Types.isNumericTy(t1)) numericv = 1;
        if(Types.isFloatTy(t1)) floatv = 1;
        if(Types.isCharacterTy(t1)) charv = 1;
      }
      if((numericv and charv) or (!numericv and !charv)) {
          Errors.incompatibleMaxArguments(ctx);
          t = Types.createErrorTy();
      }
      else if(charv) {
          t = Types.createCharacterTy();
      }
      else if(floatv) {
          t = Types.createFloatTy();
      }
      else {
          t = Types.createIntegerTy();
      }
  }
  //t = getTypeDecor(ctx->expr(0));
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);
  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  TypesMgr::TypeId t;
  if (ctx->INTVAL()) {
      t = Types.createIntegerTy();
  }
  else if (ctx->FLOATVAL()) {
    t = Types.createFloatTy();
  }
  else if (ctx->CHARVAL()) {
    t = Types.createCharacterTy();
  }
  else if (ctx->BOOLVAL()) {
    t = Types.createBooleanTy();
  }
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFuncIdent(AslParser::FuncIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  if ((not Types.isErrorTy(t1)) and (not Types.isFunctionTy(t1))) {
    Errors.isNotCallable(ctx->ident());
    TypesMgr::TypeId t = Types.createErrorTy();
    putTypeDecor(ctx, t);
  }
  else if (Types.isFunctionTy(t1)){
    uint nParams = ctx->expr().size();
    for(uint i = 0; i < nParams; ++i)
      visit(ctx->expr(i));
    TypesMgr::TypeId t = Types.getFuncReturnType(t1);
    putTypeDecor(ctx, t);
    if(nParams != Types.getNumOfParameters(t1)) {
      Errors.numberOfParameters(ctx->ident());
    } else {
      for(uint i = 0; i < nParams; ++i) {
        //visit(ctx->expr(i));
        TypesMgr::TypeId tParam = getTypeDecor(ctx->expr(i));
        TypesMgr::TypeId tCheck = Types.getParameterType(t1, i);
        if(not Types.copyableTypes(tCheck,tParam) and (not Types.isErrorTy(tParam))) {
          Errors.incompatibleParameter(ctx->expr(i),i+1,ctx->ident());
        }
      }
    }
    //Ja es funcio, ara mirem que no sigui void
    if((not Types.isErrorTy(t1)) and Types.isVoidFunction(t1)) {
      Errors.isNotFunction(ctx->ident());
      TypesMgr::TypeId t = Types.createErrorTy();
      putTypeDecor(ctx, t);
    }
  }
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t = getTypeDecor(ctx->expr());
  putTypeDecor(ctx, t);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
