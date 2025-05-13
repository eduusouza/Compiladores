/*Definições*/
%{
#include "globals.h"

char tokenString[MAXTOKENLEN+1];

%}

letra [a-zA-Z]
digito [0-9]
espaco [ \t]+

/*regras*/
%%
"else"          {return ELSE;}
"if"            {return IF;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"while"         {return WHILE;}
"+"             {return SUM;}
"-"             {return SUB;}
"*"             {return MULT;}
"/"             {return DIV;}
"<"             {return LT;}
"<="            {return LET;}
">"             {return GT;}
">="            {return GET;}
"=="            {return EQ;}
"!="            {return NEQ;}
"="             {return ATTR;}
";"             {return SEMI;}
","             {return COMMA;}
"("             {return OP;}
")"             {return CP;}
"["             {return OSB;}
"]"             {return CSB;}
"{"             {return OCB;}
"}"             {return CCB;}
\n              {line_number++;
                printf("\n");
                }
"/*"            { 
                while (1) {
                    char c = input();
                    if (c == '\n') {
                        line_number++;  // Increment line number on newline
                    } else if (c == '*') {
                        // Check if the next character is '/'
                        c = input();
                        if (c == '/') break;  // End of comment, break the loop
                    } else if (c == 0) {
                        // End of file before comment closed
                        fprintf(stderr, "Unterminated comment at line %d\n", line_number);
                        exit(1);
                    }
                }
            }
{letra}+        {return ID;}
{digito}+       {return NUM;}
{espaco}        {}
.               {return ERROR;}

%%

TokenType getToken(void){
  static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime){ 
    firstTime = FALSE;
    line_number++;
    yyin = inputFile;
    yyout = outputFile;
  }
  
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    printToken(currentToken,tokenString);
  }
  return currentToken;
}