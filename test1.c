#include <stdio.h>

int A[100];

int func(int x, int n)
{
	int i;
	if (x == n + 1) {
		for (i = 0; i < (x - 1); i++) 
			printf("%d", A[i]);
		printf("\n");
		return 0;
	} else {
		i = 1;
		A[x-1] = i;
		func(x + 1, n);
		i++;
		A[x-1] = i;
		func(x + 1, n);
	}
	return 0;	
}

int main()
{
	int n;
	scanf("%d", &n);
	func(1, n);
	return 0;
}
