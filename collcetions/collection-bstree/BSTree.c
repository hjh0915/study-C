#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <collectc/treetable.h>

#define LEN_MAX 1000
char buffer[LEN_MAX];


// 应用
_Bool printStr(void *str) { return printf("%s\n", str) >= 0;}

int main() {
    TreeTable *table;
    treetable_new(NULL, &table);

    while (fgets(buffer, LEN_MAX, stdin) != NULL) {
        if (!treetable_add(table, buffer, NULL))
            break;
    }
    if (!feof(stdin)) {
        fprintf(stderr, "sortlines:"
                "Error reading or storing text input.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "sortlines:"
                "Successfull.\n");
    return 0;
}