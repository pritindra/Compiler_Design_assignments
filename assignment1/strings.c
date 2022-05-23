#include <stdio.h>
#include <stdlib.h>

int main() {
    // char *buf = malloc(1024);
    char buf[1024];
    char c;
    // size_t nrd;
    FILE *ptr = fopen("test1.txt", "r");
    if (ptr) {
        // while (fscanf(ptr, "%s", buf) != EOF)
        while (fgets(buf, 20, ptr) ) {
            printf("%s\n", buf);
            fgets(buf, 20, ptr);
        }
        fclose(ptr);
    }
    // if (ptr) {
    //     while ((nrd == fread(buf, 1, 1024, ptr)) > 0) {
    //         fwrite(buf, 1, nrd , stdout);
    //     }
    //     fclose(ptr);
    // }
    // free(buf);
}
