// S->w(C)bAe
// O->p
// C->iOi
// A->L;A
// A->f
// L->i=E
// E->T*F
// T->i
// F->n

#include <stdio.h>
#include <string.h>

void trailfirst(char, int, int);
void findtrail(char c);

void findlead(char, int, int);

int count, m = 0, n = 0;
char calc_lead[10][100], calc_trail[10][100];

// rules
char production[10][10];
char f[10], lead[10];
int k, e;
char ck;

int main() {
    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;
    count = 9;
    
    strcpy(production[0], "S=w(C)bAe");
    strcpy(production[1], "O=p");
    strcpy(production[2], "C=iOi");
    strcpy(production[3], "A=L;A");
    strcpy(production[4], "A=f");
    strcpy(production[5], "L=i=E");
    strcpy(production[6], "E=T*F");
    strcpy(production[7], "T=i");
    strcpy(production[8], "F=n");

    int kay, ptr = -1;
    char done[count];
    
    // calc_lead
    for(k = 0; k < count; k++) {
        for(kay = 0; k < 100; kay++) 
            calc_lead[k][kay] = '!';
    }

    int pt1 = 0, pt2, x;
    for (k = 0; k < count; k++) {
        c = production[k][0];
        pt2 = 0;
        x = 0;

        for (kay = 0; kay <= ptr; kay++) {
            if (c == done[kay]) x = 1;
        }
        if (x == 1)
            continue;

        findlead(c, 0, 0);
        ptr += 1;
        
        done[ptr] = c;
        printf("\n First(%c) = { ", c);
        calc_lead[pt1][pt2++] = c;

        for(i = 0+jm; i < n; i++) {
            int lark = 0, chk = 0;

            for(lark = 0; lark <pt2; lark++) {
                if (lead[i] == calc_lead[pt1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0){
                printf("%c ", lead[i]);
                calc_lead[pt1][pt2++] = lead[i];
            }
        }
        printf("}\n");
        jm = n;
        pt1++;
    }
    printf("\n");
    printf("-----------------------------------------------\n\n");
    char donee[count];
    ptr = -1;
    
    // calc_trail
    for (k = 0; k < count; k++){
        for (kay = 0; kay < 100; kay++)
            calc_trail[k][kay] == "!";
    }
    pt1 = 0;
    int land = 0;
    for(e = 0; e < count; e++) {
        ck = production[e][0];
        pt2 = 0;
        x = 0;

        for (kay = 0; k <= ptr; kay++)
            if(ck == donee[kay]) x = 1;
        if (x == 1)
            continue;
        land += 1;
        
        trail(ck);
        ptr += 1;

        donee[ptr] = ck;
        printf(" Trail(%c) = { ", ck);
        calc_trail[pt1][pt2++] = ck;
        for(i = 0 + km; i < m; i++) {
            int lark = 0, chk = 0;
            for(lark = 0; lark < pt2; lark++)
            {
                if (f[i] == calc_trail[pt1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
            {
                printf("%c, ", f[i]);
                calc_trail[pt1][pt2++] = f[i];
            }
        }
        printf(" }\n\n");
        km = m;
        pt1++;
    }
}

void trail(char c) {

    int i, j;
    if(production[0][0] == c)
        f[m++] = "$";

    for (i = 0; i < 10; i++) {
        for (j = 2; j < 10; j++) {
            if(production[i][j] == c) {
                if (production[i][j] != '\0')
                    trailfirst(production[i][j+1], i, (j+2));
                if (production[i][j+1]=='\0' && c!=production[i][0])
                    trail(production[i][0]);
            }
        }
    }
}

void findlead(char c, int q1, int q2) {
    int j;

    if(!(isupper(c))) {
        lead[n++] = c;
    }
    for (j = 0; j < count; j++){
        if(production[j][0] == c) {
            if(production[j][2] == "#"){
                if (production[q1][q2] == '\0')
                    lead[n++] = "#";
                else if(production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                    findlead(production[q1][q2], q1, (q2+1));
            }
            else
                lead[n++] = "#";
        }  
        else if(!isupper(production[j][2]))
            lead[n++] = production[j][2];
        else
            findlead(production[j][2], j, 3);
    }
}

void trailfirst (char c; int c1; int c2) {
    int k;
     
    // The case where we encounter
    // a Terminal
    if(!(isupper(c)))
        f[m++] = c;
    else
    {
        int i = 0, j = 1;
        for(i = 0; i < count; i++)
        {
            if(calc_lead[i][0] == c)
                break;
        }
        while(calc_lead[i][j] != '!')
        {
            if(calc_lead[i][j] != '#')
            {
                f[m++] = calc_lead[i][j];
            }
            else
            {
                if(production[c1][c2] == '\0')
                {
                    // Case where we reach the
                    // end of a production
                    trail(production[c1][0]);
                }
                else
                {
                    // Recursion to the next symbol
                    // in case we encounter a "#"
                    trailfirst(production[c1][c2], c1, c2+1);
                }
            }
            j++;
        }
    }

}
