#include <stdio.h>

int fib (int n) {
    if ( n==0) return 0;
    else if (n==1) return 1;
    else return fib(n-1)+ fib(n-2);
}
int main() {
    int num = 5;
    printf("\nO %d termo de Fibonacci é %d", num , fib(num));
    return 0;
}
