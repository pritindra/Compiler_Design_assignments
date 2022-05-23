%{

#include "mnemonic.h"

enum 
    {
        TOK_STOP = 0,
        TOK_ADD,
        TOK_SUB,
        TOK_MULT,
        TOK_LOAD,
        TOK_STORE,
        TOK_TRANS,
        TOK_TRIM,
        TOK_DIV,
        TOK_READ,
        TOK_PRINT,
        TOK_LIR,
        TOK_IIR,
        TOK_LOOP,
        TOK_COMMA,
        TOK_ALPHA,
        TOK_ID,
        TOK_EOF,
        TOK_IDENTIFIER,
        TOK_INTEGER,
        TOK_NEWLINE
    };
int tokCount = 0;
char string[20];
%}

%%
end      {return 0;}
"LOAD" {printf("%d", TOK_LOAD);
        string[tokCount] = TOK_LOAD;
        tokCount++;
        insert("LOAD", TOK_LOAD);}

"ADD" {printf("%d ", TOK_ADD);
        string[tokCount] = TOK_ADD;
        tokCount++;
        insert("ADD", TOK_ADD);}

"SUB" {printf("%d ", TOK_SUB);
        string[tokCount] = TOK_SUB;
        tokCount++;
        insert("SUB", TOK_SUB);}
        
"STORE" {printf("%d ", TOK_STORE);
        string[tokCount] = TOK_STORE;
        tokCount++;
        insert("STORE", TOK_STORE);}

"DIV" {printf("%d ", TOK_DIV);
        string[tokCount] = TOK_DIV;
        tokCount++;
        insert("DIV", TOK_DIV);}

"READ" {printf("%d ", TOK_READ);
        string[tokCount] = TOK_READ;
        tokCount++;
        insert("READ", TOK_READ);}

"PRINT" {printf("%d ", TOK_PRINT);
        tokCount++;
        insert("PRINT", TOK_PRINT);}

"STOP" {printf("%d ", TOK_STOP);
        tokCount++;
        insert("STOP", TOK_STOP);}

"MULT" {printf("%d ", TOK_MULT);
        tokCount++;
        insert("MULT", TOK_MULT);}

"TRANS" {printf("%d ", TOK_TRANS);
        tokCount++;
        insert("TRANS", TOK_TRANS);}

"TRIM" {printf("%d ", TOK_TRIM);
        tokCount++;
        insert("TRIM", TOK_TRIM);}

"LIR" {printf("%d ", TOK_LIR);
        tokCount++;
        insert("LIR", TOK_LIR);}

"IIR" {printf("%d ", TOK_IIR);
        tokCount++;
        insert("IIR", TOK_IIR);}

"LOOP" {printf("%d ", TOK_LOOP);
        tokCount++;}
[,]     {printf("%d ", TOK_COMMA);
        tokCount++;}

[a-zA-z]    {printf("%d", TOK_ALPHA);
            tokCount++;}
[a-zA-Z][_a-zA-Z0-9]*   {printf("%d ", TOK_IDENTIFIER);
                        strcpy(string,yytext);
                        printf("(%s) ", string);
                        tokCount++;}
[1-9][0-9]* {printf("%d ", TOK_INTEGER);
            strcpy(string, yytext);
            printf("(%s) ", string);
            tokCount++;}
[ \t] ;
[\n]    {printf("%d ", TOK_NEWLINE);
        string[tokCount] = TOK_LOAD;
        tokCount++;
        }

.   {printf("Unxpected char\n");}
%%

int yywrap(){}
int main (int argc, char *argv[]) {
    FILE *fp;
    char filename[50];
    fp = fopen(argv[1], "r");
    yyin = fp;

    yylex();
    printf("Number of tokens: %d\n", tokCount);
    display();

    for (int i = 0; i < sizeof(string); i++) {
        printf("%d ", string[i]);
    }
    return 0;
}
