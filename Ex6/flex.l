%{
#include <stdio.h>
#include <stdlib.h>

enum tokens {IF = 1, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, SOMA,
            SUB, MULT, DIV, IGUAL, MENOR, ABRE_PARENTESES, FECHA_PARENTESES, PONTO_VIRG, ATRIB, NUM, ID}
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
    if (argv != 1){
        printf("Numero de parametros esta errado\n");
        return 0;
    }

    if (argv[0] == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        printf("Lendo caracteres via terminal");
        yyin = stdin;
    } else {
        yyin = fopen(argv[0], "r");
    }
    
    do{
        flag = yylex();
        printf("Linha: %d, Lexema: %s, TOKEN: ", line, yytext);
    } while (flag != 0);

    return 0;    
}