%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \r?\n
whitespace  [ \t]+

%%

"else"          {return ELSE;}
"if"            {return IF;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"while"         {return WHILE;}
"+"             {return ADD;}
"-"             {return SUB;}
"*"             {return MULT;}
"/"             {return DIV;}
"<"             {return MENOR;}
"<="            {return MENORIG;}
">"             {return MAIOR;}
">="            {return MAIORIG;}
"=="            {return COMP;}
"!="            {return DIF;}
"="             {return IGUAL;}
";"             {return SEMI;}
","             {return VIRG;}
"("             {return ESQPARENT;}
")"             {return DIRPARENT;}
"["             {return ESQCOL;}
"]"             {return DIRCOL;}
"{"             {return ESQCHAV;}
"}"             {return DIRCHAV;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
"/*"            { char c;
                  do
                  { c = input();
                    if (c == EOF) break;
                    if (c == '\n') lineno++;
                    if (c == '*') {
                    	if(input() == '/') break;
                    }
                  } while (1);
                }
<<EOF>>	 {return FIM;}
.               {return ERROR;}

%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    printf("\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}
