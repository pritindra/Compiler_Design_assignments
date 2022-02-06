#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

int getlines(char *line, FILE *fptr);

int main(int argc, char **argv) {
    FILE *fptr = fopen(argv[1], "r");
    int field = atoi(argv[2]);
    
    char lines[MAX];
    int len;
    int i;

    while ((len = getlines(lines, fptr)) > 0) {
        i = 1;   
        char* token = NULL, *s = lines;
        while((token = strtok(s, " ")) != NULL) {
            if (i != field)
            {   s = NULL;
                i++;
            }
            else 
                printf("%s\n", token);
            
        }
    }
    
    fclose(fptr);
}

int getlines (char *line, FILE *fptr) {
    if (fgets(line, MAX, fptr) == NULL)
        return 0;
    else
        return strlen(line);
}
