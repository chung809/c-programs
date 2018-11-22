#include <stdio.h>
#include <string.h>

int main()
{
	char input[100][15];
	char c[100][15];
	int i = 0, j = 0, k = 0, m = 0;
	int word_num;
	int word_len;

	while(scanf("%s", input[i]) != EOF) {
		i++;
	}
	word_num = i;
	for (i = 0; i < 100; i++) {
		for(j = 0; j < 15; j++) {
			c[i][j] = '\0';
		}
	}
	for (i = 0; i < word_num; i++) {
		word_len = strlen(input[i]);
		for (k = 0; k < word_len; k = k + 2) {
			if (((word_len % 2) == 1) && (k == (word_len - 1))) {
				c[i][k] = input[i][k];
				break;
			}
			if ((input[i][k] >= 65) && (input[i][k] <= 90)) {
				if ((input[i][k + 1] >= 65) && (input[i][k + 1] <= 90)) {
					c[i][k] = (((input[i][k] - 64) + 3 * (input[i][k + 1] - 64)) % 26) + 64;
					c[i][k + 1] = ((2 * (input[i][k] - 64) + 7 * (input[i][k + 1] - 64)) % 26) + 64;
				}
				if ((input[i][k + 1] >= 97) && (input[i][k + 1] <= 122)) {
					c[i][k] = (((input[i][k] - 64) + 3 * (input[i][k + 1] - 96)) % 26) + 64;
					c[i][k + 1] = ((2 * (input[i][k] - 64) + 7 * (input[i][k + 1] - 96)) % 26) + 96;
				}
				continue;
			}
			if ((input[i][k] >= 97) && (input[i][k] <= 122)) {
				if ((input[i][k + 1] >= 65) && (input[i][k + 1] <= 90)) {
					c[i][k] = (((input[i][k] - 96) + 3 * (input[i][k + 1] - 64)) % 26) + 96;
					c[i][k + 1] = ((2 * (input[i][k] - 96) + 7 * (input[i][k + 1] - 64)) % 26) + 64;
				}
				if ((input[i][k + 1] >= 97) && (input[i][k + 1] <= 122)) {
					c[i][k] = (((input[i][k] - 96) + 3 * (input[i][k + 1] - 96)) % 26) + 96;
					c[i][k + 1] = ((2 * (input[i][k] - 96) + 7 * (input[i][k + 1] - 96)) % 26) + 96;
				}
			}
		}
		printf("%s ", c[i]);
	}
	printf("\n");
	return 0;
}		
