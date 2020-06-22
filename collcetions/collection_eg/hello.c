#include <stdio.h>
#include <collectc/array.h>

int main(int argc, char **argv) {
    // Create a new array
    Array *ar;
    array_new(&ar);

    // Add a string to the array
    array_add(ar, "Hello World!\n");
    array_add(ar, "你好 中国!\n");

    // Retreive the string and print it
    char *str;
    for (int i=0; i<2; i++) {
        array_get_at(ar, i, (void*) &str);
        printf("%s", str);
    }
    
    return 0;
}