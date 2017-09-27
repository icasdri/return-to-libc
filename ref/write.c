#include <stdio.h>

int main(void) {
    void *z = NULL;
    void *x = (void *) 0x7fffffffffff;
    printf("Pwned!!!!!");
    fwrite(&z, sizeof(void *), 2, stdout);
    fwrite(&x, sizeof(void *), 1, stdout);
    printf("\n");
}
