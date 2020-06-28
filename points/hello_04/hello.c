#include <stdio.h>
 
int max(int x, int y) {
    return x > y ? x : y;
}
 
int main() {
    int a, b, c, d;

    //定义函数指针
    int (*pmax)(int a, int b) = max;  // 也可以写作int (*pmax)(int， int)
    printf("请输入三个数字:");
    scanf("%d %d %d", &a, &b, &c);
    
    // 也可以直接调用函数
    // d = max(max(a, b), c);
    d = pmax(pmax(a, b), c); 
 
    printf("最大的数字是: %d\n", d);
}