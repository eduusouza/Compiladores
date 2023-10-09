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
        printf("Linha: %d, Lexema: %s, TOKEN: ", line, yytext);
        if(flag == 1)
            printf("IF\n");
        
        if(flag == 2)
            printf("THEN\n");
        
        if(flag == 3)
            printf("ELSE\n");
        
        if(flag == 4)
            printf("END\n");
        
        if(flag == 5)
            printf("REPEAT\n");
        
        if(flag == 6)
            printf("UNTIL\n");
        
        if(flag == 7)
            printf("READ\n");
        
        if(flag == 8)
            printf("WRITE\n");
        
        if(flag == 9)
            printf("SOMA\n");
        
        if(flag == 10)
            printf("SUB\n");
        
        if(flag == 11)
            printf("MULT\n");

        if(flag == 12)
            printf("DIV\n");
        
        if(flag == 13)
            printf("IGUAL\n");
        
        if(flag == 14)
            printf("MENOR\n");
        
        if(flag == 15)
            printf("ABRE_PARENTESES\n");

        if(flag == 16)
            printf("FECHA_PARENTESES\n");
        
        if(flag == 17)
            printf("PONTO_VIRG\n");

        if(flag == 18)
            printf("ATRIB\n");

        if(flag == 19)
            printf("NUM\n");

        if(flag == 20)
            printf("ID\n");

    } while (flag != 0);

    return 0;    
}