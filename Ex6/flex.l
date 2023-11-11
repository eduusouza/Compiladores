%{
#include <stdio.h>
#include <stdlib.h>

enum tokens {IF = 1, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, SOMA,
            SUB, MULT, DIV, IGUAL, MENOR, ABRE_PARENTESES, FECHA_PARENTESES, PONTO_VIRG, ATRIB, NUM, ID};
int line = 1;
%}

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+

%%
"if"            {return IF;}
"then"          {return THEN;}
"else"          {return ELSE;}
"end"           {return END;}
"repeat"	    {return REPEAT;}
"until"		    {return UNTIL;}
"read"		    {return READ;}
"write"         {return WRITE;}
"+"             {return SOMA;}
"-"             {return SUB;}
"*"             {return MULT;}
"/"             {return DIV;}
"="             {return IGUAL;}
"<"             {return MENOR;}
"("             {return ABRE_PARENTESES;}
")"             {return FECHA_PARENTESES;}
";"             {return PONTO_VIRG;}
":="            {return ATRIB;}
"\n"            {line++;}
{number}        {return NUM;}
{identifier}    {return ID;}
exit            {return 0;}
<<EOF>>         {return 0;}

%%

int main(int argc, char *argv[]){

    int flag;
    if (argv > 2){
        printf("Numero de parametros esta errado\n");
        return 0;
    }

    if (argv[1] == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        printf("Lendo caracteres via terminal");
        yyin = stdin;
    } else {
        yyin = fopen(argv[1], "r");
    }
    
    do{
        flag = yylex();
        if(flag == 1)
            printf("Linha: %d, Lexema: %s, TOKEN: IF\n", line, yytext);
        
        if(flag == 2)
            printf("Linha: %d, Lexema: %s, TOKEN: THEN\n", line, yytext);
        
        if(flag == 3)
            printf("Linha: %d, Lexema: %s, TOKEN: ELSE\n", line, yytext);
        
        if(flag == 4)
            printf("Linha: %d, Lexema: %s, TOKEN: END\n", line, yytext);
        
        if(flag == 5)
            printf("Linha: %d, Lexema: %s, TOKEN: REPEAT\n", line, yytext);
        
        if(flag == 6)
            printf("Linha: %d, Lexema: %s, TOKEN: UNTIL\n", line, yytext);
        
        if(flag == 7)
            printf("Linha: %d, Lexema: %s, TOKEN: READ\n", line, yytext);
        
        if(flag == 8)
            printf("Linha: %d, Lexema: %s, TOKEN: WRITE\n", line, yytext);
        
        if(flag == 9)
            printf("Linha: %d, Lexema: %s, TOKEN: SOMA\n", line, yytext);
        
        if(flag == 10)
            printf("Linha: %d, Lexema: %s, TOKEN: SUB\n", line, yytext);
        
        if(flag == 11)
            printf("Linha: %d, Lexema: %s, TOKEN: MULT\n", line, yytext);

        if(flag == 12)
            printf("Linha: %d, Lexema: %s, TOKEN: DIV\n", line, yytext);
        
        if(flag == 13)
            printf("Linha: %d, Lexema: %s, TOKEN: IGUAL\n", line, yytext);
        
        if(flag == 14)
            printf("Linha: %d, Lexema: %s, TOKEN: MENOR\n", line, yytext);
        
        if(flag == 15)
            printf("Linha: %d, Lexema: %s, TOKEN: ABRE_PARENTESES\n", line, yytext);

        if(flag == 16)
            printf("Linha: %d, Lexema: %s, TOKEN: FECHA_PARENTESES\n", line, yytext);
        
        if(flag == 17)
            printf("Linha: %d, Lexema: %s, TOKEN: PONTO_VIRG\n", line, yytext);

        if(flag == 18)
            printf("Linha: %d, Lexema: %s, TOKEN: ATRIB\n", line, yytext);

        if(flag == 19)
            printf("Linha: %d, Lexema: %s, TOKEN: NUM\n", line, yytext);

        if(flag == 20)
            printf("Linha: %d, Lexema: %s, TOKEN: ID\n", line, yytext);

    } while (flag != 0);

    return 0;    
}