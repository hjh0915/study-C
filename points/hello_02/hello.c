#include<stdio.h>

void swap(int *px, int *py){
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int main(){
    int a = 15;
    int b = 10;

    swap(&a, &b);
    printf("%d\t%d\n", a, b); 
    return 0;
}