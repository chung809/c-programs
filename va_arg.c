#include <stdio.h>
#include <stdarg.h>

void va_arg_test(int, ...);

int main(void)
{
    int x = 1, y = 2, z = 3;
    int a = 4, b = 5, c = 6;

    printf("3 arguments:\n");
    va_arg_test(3, x, y, z);

    printf("6 arguments:\n");
    va_arg_test(6, x, y, z, a, b, c);

    return 0;
}

void va_arg_test(int len, ...)
{
    va_list args;
    va_start(args, len);
    int i;
    char input[20];

    for(i = 0; i < len; i++) {
        input[i] = va_arg(args, int) + 64;
    }
    for(i = 0; i < len; i++) {
   	printf("%c ", input[i]);
    }
    printf("\n"); 
    va_end(args);
}
