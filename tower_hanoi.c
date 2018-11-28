#include <stdio.h>

void hanoi(int n, char x, char y, char z)
{
//	printf("n=%d x=%c y=%c z=%c\n", n, x, y, z);
	if (n == 1) {
		printf("%c -> %c\n", x, z);
	} else {
		hanoi(n - 1, x, z, y);
		hanoi(1, x, y, z);
		hanoi(n - 1, y, x, z);
	}
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

