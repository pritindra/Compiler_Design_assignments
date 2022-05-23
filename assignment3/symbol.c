#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mnemonic.h"
int size = 0;

struct mnemonic *first, *last;

void insert(char instr[],int opcode) {
    int n = search(instr);
    if (n == 1)
        printf("Label already exists..\n");
    else {
        struct mnemonic *p;
        p = malloc(sizeof(struct mnemonic));
        strcpy(p->instr, instr);
        p->opcode = opcode;
        p->next = NULL;
        if (size == 0) {
            first = p;
            last = p;
        }
        else {
            last->next = p;
            last = p;
        }
        size++;

        //free(p);
    }
}

int search(char instr[]) {
    int i, flag = 0;
    struct mnemonic *p;
    p = first;
    for (i = 0; i < size; i++) {
        if(strcmp(p->instr, instr) ==0)
            flag = 1;
        p = p->next;
    }
    return flag;
}

void del(char instr[]) {
    struct mnemonic *p, *q;
    int a;
    p = first;
    a = search(instr);
    if (a == 0)
        printf("Label not found..");
    else {
        if (strcmp(first->instr, instr) == 0)
            first = first->next;
        else if (strcmp(last->instr, instr) == 0) {
            q = p->next;
            while(strcmp(q->instr, instr) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            last = p;
        }
        else {
            q = p->next;
            while(strcmp(q->instr, instr) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
        }
        size--;
    }
}

void display() {
    struct mnemonic *p;
    p = first;
    printf("INSTR\t OPCODE\n");
    for (int i = 0; i <size; i++) {
        printf("%s\t%d\n", p->instr, p->opcode);
        p = p->next;
    }
}
