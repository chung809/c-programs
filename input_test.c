#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0, j = 0, k = 0;
	
	if (argc < 2) {
		printf("Please input 2 integer numbers!\n");
		return 1;
	} else {
		printf("argc=%d\n", argc);
		for (i=0; i < argc; i++) {
			printf("%s\n", argv[i]);
			switch (i) {
				case 1:
					j = atoi(argv[i]);
					break;
				case 2:
					k = atoi(argv[i]);
					break;
				default:;
			}
		}	
		printf("\n");
	}
	printf("i=%d j=%d k=%d\n", i, j, k);
	return 0;
}
