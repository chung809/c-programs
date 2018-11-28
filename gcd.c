#include <stdio.h>

int gcd(int, int); 

int main(void) {
    int m = 0;
    int n = 0; 

    printf("輸入兩數(num1 num2)：");
    scanf("%d %d", &m, &n);

    printf("GCD: %d\n", gcd(m, n));

    return 0;
}

int gcd(int m, int n) { 
    printf("m=%d, n=%d\n", m, n);
    if(n == 0) {
        return m; 
    }
    else {
        return gcd(n, m % n); 
    }
}
