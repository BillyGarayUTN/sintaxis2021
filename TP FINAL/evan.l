%{
    #include "y.tab.h"
    void yyerror (char *cadena);
    int yylex();
%}

%%

"escribir"          { return imprimir; }
"fin"		    { return comando_salir; }
"leer"		    { return leer; }


[a-zA-Z]            { yylval.id = yytext[0]; return identificador; }
[0-9]+              { yylval.num = atoi(yytext); return numero; }
[-+*/=;()]          { return yytext[0]; }
[ \t\n]             ;
.                   { ECHO; yyerror ("Caracter No Reconocido"); }

%%
 
int yywrap (void) { return 1;}


