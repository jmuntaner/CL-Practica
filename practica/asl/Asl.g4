//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' parameters ')' (':' type)? declarations statements ENDFUNC
        ;

declarations
        : (variable_decl)*
        ;

parameters
        : (parameter_decl (COMMA parameter_decl)* | )
        ;

parameter_decl
        : ID ':' type
        ;

variable_decl
        : VAR ID (COMMA ID)* ':' type
        ;

type    : basic_type
        | ARRAY LCLAU INTVAL RCLAU OF basic_type //#array
        ;

basic_type
        : INT       //# int
        | BOOL      //# bool
        | FLOAT     //# float
        | CHAR
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF  # ifStmt
          // while-do-endwhile statement
        | WHILE expr DO statements ENDWHILE   # whileStmt
        // while-do-endwhile statement
        | FOR ident IN RANGE '(' (expr (COMMA expr)* | ) ')' DO statements ENDFOR   # forStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' (expr (COMMA expr)* | )  ')' ';' # procCall
          // Return statement
        | RETURN expr? ';'                    # returnStmt
          // Read a variable
        | READ left_expr ';'                  # readStmt
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
        ;
// Grammar for left expressions (l-values in C++)
left_expr
        : ident (LCLAU expr RCLAU)?
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    : //MAX '(' (expr (COMMA expr)* | ) ')' # max
          '(' expr ')'                        # parenthesis
        | ident LCLAU expr RCLAU              # arrayAccess
        | op=(NOT|SUB|PLUS) expr              # unary
        | expr op=(MUL|DIV|MOD) expr          # arithmetic
        | expr op=(PLUS|SUB) expr             # arithmetic
        | expr op=(EQUAL | LT | GT | NEQ | GEQ | LEQ) expr  # relational
        | expr op=AND expr                    # boolean
        | expr op=OR expr                     # boolean
        | INTVAL                              # value
        | CHARVAL                             # value
        | FLOATVAL                            # value
        | BOOLVAL                             # value
        | ident '(' (expr (COMMA expr)* | ) ')' # funcIdent
        | ident                               # exprIdent
        ;

ident   : ID
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQUAL     : '==' ;
NEQ       : '!=' ;
PLUS      : '+' ;
SUB       : '-' ;
MUL       : '*' ;
DIV       : '/' ;
MOD       : '%' ;
LT        : '<' ;
GT        : '>' ;
GEQ       : '>=' ;
LEQ       : '<=' ;
COMMA     : ',' ;
LCLAU     : '[' ;
RCLAU     : ']' ;
AND       : 'and';
OR        : 'or';
NOT       : 'not';
VAR       : 'var';
ARRAY     : 'array' ;
OF        : 'of' ;
INT       : 'int';
BOOL      : 'bool';
FLOAT     : 'float';
CHAR      : 'char';
IF        : 'if' ;
WHILE     : 'while' ;
FOR       : 'for' ;
IN        : 'in' ;
RANGE     : 'range' ;
DO        : 'do' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
ENDWHILE  : 'endwhile' ;
ENDFOR    : 'endfor' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
RETURN    : 'return' ;
READ      : 'read' ;
WRITE     : 'write' ;
//MAX       : 'max' ;
BOOLVAL   : TRUE | FALSE;
TRUE      : 'true' ;
FALSE     : 'false';
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : ('0'..'9')+ '.' ('0'..'9')+;
CHARVAL   : '\'' ( ESC_SEQ | ~('\\'|'\'') ) '\'' ;

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
