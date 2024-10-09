%{
#include "globals.h"

char tokenValue[MAX_TOKEN_LEN];
void printToken(int, char*);
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
id          {letter}+
newline     \n
whitespace  [ \t]+

%%

"/*"            { char c;
                  do {
                    c = input();
                    if (c == EOF) break;
                    if (c == '\n') yyline++;
                    if (c == '*') {
                        if (input() == '/') break;
                    }
                  } while (1);
                }
"int"           {return INT;}
"if"            {return IF;}
"else"          {return ELSE;}
"return"        {return RETURN;}
"void"		    {return VOID;}
"while"		    {return WHILE;}
"="             {return ASSIGN;}
"=="            {return EQ;}
"<"             {return LESS_THAN;}
">"		        {return GREATER_THAN;}
"<="		    {return LESS_THAN_EQ;}
">="		    {return GREATER_THAN_EQ;}
"!="	        {return NOT_EQ;}
"["		        {return OPEN_BRACKET;}
"]"		        {return CLOSE_BRACKET;}
"{"		        {return OPEN_KEYS;}
"}"		        {return CLOSE_KEYS;}
"+"             {return SUM;}
"-"             {return SUBTRACT;}
"*"             {return MULTIPLY;}
"/"             {return DIVIDE;}
"("             {return OPEN_PARENTHESES;}
")"             {return CLOSE_PARENTHESES;}
","		        {return COMMA;}
";"             {return SEMICOLON;}
{number}        {return NUM;}
{id}            {return ID;}
{whitespace}    {         }
{newline}       {yyline++;}
.               {return ERROR;}

%%

int main(int argc, char *argv[]){
    int token;
    if (argc > 0){
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    token = yylex();
    strncpy(tokenValue, yytext, MAX_TOKEN_LEN);

    if (token >= 0 && token < 27){
        printToken(token, tokenValue);
    } else if (token == 27 ){
        printf("ERRO LEXICO: %s, linha: %d", tokenValue, yyline);
    }
    fclose(yyin);
    return 0;
}

void printToken(int token, char* lexema){
    switch (token){
        case INT:
            printf("LEXEMA: %s, TOKEN: INT, linha: %d\n", lexema, yyline);
            break;

        case IF:
            printf("LEXEMA: %s, TOKEN: IF, linha: %d\n", lexema, yyline);
            break;

        case ELSE:
            printf("LEXEMA: %s, TOKEN: ELSE, linha: %d\n", lexema, yyline);
            break;

        case RETURN:
            printf("LEXEMA: %s, TOKEN: RETURN, linha: %d\n", lexema, yyline);
            break;
        
        case VOID:
            printf("LEXEMA: %s, TOKEN: VOID, linha: %d\n", lexema, yyline);
            break;

        case WHILE:
            printf("LEXEMA: %s, TOKEN: WHILE, linha: %d\n", lexema, yyline);
            break;
        
        case ASSIGN:
            printf("LEXEMA: %s, TOKEN: ASSIGN, linha: %d\n", lexema, yyline);
            break;
        
        case EQ:
            printf("LEXEMA: %s, TOKEN: EQ, linha: %d\n", lexema, yyline);
            break;
        
        case LESS_THAN:
            printf("LEXEMA: %s, TOKEN: LESS_THAN, linha: %d\n", lexema, yyline);
            break;
        
        case GREATER_THAN:
            printf("LEXEMA: %s, TOKEN: GREATER_THAN, linha: %d\n", lexema, yyline);
            break;
        
        case LESS_THAN_EQ:
            printf("LEXEMA: %s, TOKEN: LESS_THAN_EQ, linha: %d\n", lexema, yyline);
            break;
        
        case GREATER_THAN_EQ:
            printf("LEXEMA: %s, TOKEN: GREATER_THAN_EQ, linha: %d\n", lexema, yyline);
            break;
        
        case NOT_EQ:
            printf("LEXEMA: %s, TOKEN: NOT_EQ, linha: %d\n", lexema, yyline);
            break;
        
        case OPEN_BRACKET:
            printf("LEXEMA: %s, TOKEN: OPEN_BRACKET, linha: %d\n", lexema, yyline);
            break;
        
        case CLOSE_BRACKET:
            printf("LEXEMA: %s, TOKEN: CLOSE_BRACKET, linha: %d\n", lexema, yyline);
            break;
        
        case OPEN_KEYS:
            printf("LEXEMA: %s, TOKEN: OPEN_KEYS, linha: %d\n", lexema, yyline);
            break;
        
        case CLOSE_KEYS:
            printf("LEXEMA: %s, TOKEN: CLOSE_KEYS, linha: %d\n", lexema, yyline);
            break;
        
        case SUM:
            printf("LEXEMA: %s, TOKEN: SUM, linha: %d\n", lexema, yyline);
            break;
        
        case SUBTRACT:
            printf("LEXEMA: %s, TOKEN: SUBTRACT, linha: %d\n", lexema, yyline);
            break;
        
        case MULTIPLY:
            printf("LEXEMA: %s, TOKEN: MULTIPLY, linha: %d\n", lexema, yyline);
            break;
        
        case DIVIDE:
            printf("LEXEMA: %s, TOKEN: DIVIDE, linha: %d\n", lexema, yyline);
            break;
        
        case OPEN_PARENTHESES:
            printf("LEXEMA: %s, TOKEN: OPEN_PARENTHESES, linha: %d\n", lexema, yyline);
            break;
        
        case CLOSE_PARENTHESES:
            printf("LEXEMA: %s, TOKEN: CLOSE_PARENTHESES, linha: %d\n", lexema, yyline);
            break;

        case COMMA:
            printf("LEXEMA: %s, TOKEN: COMMA, linha: %d\n", lexema, yyline);
            break;
        
        case SEMICOLON:
            printf("LEXEMA: %s, TOKEN: SEMICOLON, linha: %d\n", lexema, yyline);
            break;
        
        case NUM:
            printf("LEXEMA: %s, TOKEN: NUM, linha: %d\n", lexema, yyline);
            break;
        
        case ID:
            printf("LEXEMA: %s, TOKEN: ID, linha: %d\n", lexema, yyline);
            break;
        
        default:
            printf("Token Desconhecido: %s, linha: %d", lexema, yyline);
            break;
    }
}