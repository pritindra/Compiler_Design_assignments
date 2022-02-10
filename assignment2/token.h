#ifndef _TOKEN_H
#define _TOKEN_H

#include <stdio.h>

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
    TOK_NUM,
    TOK_ALPHA,
    TOK_ID,
    TOK_EOF
};

#endif
