%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int simbolos[70];

void yyerror (char *cadena);
int yylex();
int valorSimbolo(char simbolo);
void actualizarValorSimbolo(char simbolo, int valor);
%}

/* Definicion de los elementos que seran considerados y evaluados en el archivo */

%union {int num; char id;}

%start linea

%token imprimir
%token leer
%token comando_salir


%token <num> numero
%token <id> identificador
%type  <num> linea expresion termino
%type  <id> asignacion

%%
/* Producciones generadas para cubrir las gramatica definidas
Ademas se tierne el codigo en C que le corresponde a cada produccion */




linea : leer asignacion ';'                   { ; }
      | comando_salir ';'                     { printf("Terminando programa\n");exit(0); }
      | leer expresion ';'	              { ; }
      | imprimir expresion ';'                { printf("El valor es %d\n",$2); }
	
      | linea leer expresion ';' 	              { ; }
      | linea leer asignacion ';'                  { ; }
      | linea imprimir expresion ';'          { printf("El valor es %d\n",$3); }
      | linea comando_salir ';'               { printf("Terminando programa\n");exit(0); }
      ;

asignacion : identificador '=' expresion      { actualizarValorSimbolo($1,$3); }
           ;

expresion : termino                           { $$ = $1; }
          | expresion '+' expresion           { $$ = $1 + $3; }
          | expresion '-' expresion           { $$ = $1 - $3; }
          | expresion '*' expresion           { $$ = $1 * $3; }
          | expresion '/' expresion           { $$ = $1 / $3; }
	  | '(' expresion ')'		      { $$ = $2; }
          ;

termino : numero                              { $$ = $1; }
        | identificador                       { $$ = valorSimbolo($1); }

%% 

/* Codigo C que permite evaluar las expresiones */

int simboloIndex(char token)
{
    int idx = -1;
    if(islower(token)){
        idx = token - 'a' + 26;
    }else if (isupper(token)){
        idx = token - 'A';
    }
    return idx;
}

/* regresara el valor del simbolo leido */

int valorSimbolo(char simbolo)
{
    int index = simboloIndex(simbolo);
    return simbolos[index];
}

/* se actualiza el valor de un simbolo dado */

void actualizarValorSimbolo(char simbolo, int valor)
{
    int index = simboloIndex(simbolo);
    simbolos[index] = valor;
}

int main (void){
    /* tabla de simbolo */
    int i;
    for(i=0; i<52; i++){
        simbolos[i] = 0;
    }
    return yyparse();
}

void yyerror ( char *cadena) { fprintf (stderr, "%s\n",cadena);}


