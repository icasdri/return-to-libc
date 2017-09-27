#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_input(char *buf) {
    int i = 0;  // index into buf
    int c;  // character read from stdin

    // read one char at a time until newline or end-of-stream
    do {
        c = fgetc(stdin);
        buf[i++] = c;
    } while (c != '\n' && c != EOF);

    buf[i - 1] = '\0';  // null-terminate
}

char *make_copy(char *src, int n) {
    char *copy = malloc(n);
    memcpy(copy, src, n);

    copy[n - 1] = '\0';  // null-terminate
    return copy;
}

int get_input_length(void) {
    char buf[10];  // input buffer
    read_input(buf);

    // make a copy just for fun
    char *copy = make_copy(buf, 10);
    return strlen(copy);
}

int main() {
    printf("Enter some input...\n");
    printf("Length of your input: %d\n", get_input_length());
}
