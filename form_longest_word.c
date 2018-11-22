#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_STRING_NUM 200
#define LINE_FEED 10
#define SPACE 32
#define SMALL_LETTER_A 97
#define SMALL_LETTER_Z 122

int main()
{
	char ch;
	char string[INPUT_STRING_NUM][21], longest[INPUT_STRING_NUM];
	char *str_ptr;
	int i, j, len;
	int swap_flag = 0;
	
	/*  Initialize the string to NULL values */
        for (i = 0; i < INPUT_STRING_NUM; i++)
        	longest[i] = SPACE;
        	for (j = 0; j < 21; j++)
			string[i][j] = SPACE;
	i = j = len = 0;
#if 0
        while(1) {
		fgets(longest, INPUT_STRING_NUM, stdin);
		if( longest[0] == LINE_FEED)
			break;
		str_ptr = strtok(longest, " ");
		while (str_ptr != NULL) {
			strcpy(string[i++], str_ptr);
			str_ptr = strtok(NULL, " ");
		}
	}
#endif
	ch = getchar();
	while(1) {
		if ((swap_flag == 1) && (ch == LINE_FEED)) {
			swap_flag = 0;
			break;
		}	
		if ((ch != LINE_FEED) && (ch != SPACE)) {
			if (ch < SMALL_LETTER_A || ch > SMALL_LETTER_Z) {
				string[i][j++] = SPACE;
				printf("Input error, only accept small letters(a~z)!\n");
			} else {
				string[i][j++] = ch;
				swap_flag = 0;
			}
		} else {
			if (ch == LINE_FEED)
				swap_flag = 1;
			string[i++][j] = 0;
			j = 0;
		}
		ch = getchar();
	}	
	i = 0;
	strcpy(longest, string[0]);
        while(strlen(string[i]) != 0) {
        	len = strlen(longest);
        	if(len > 100)
        		break;
        	if(strlen(string[i + 1]) > strlen(longest)) {
        		str_ptr = strstr(string[i + 1], longest);
        		swap_flag = 1;
        	} else
			str_ptr = strstr(longest, string[i + 1]);

		if (str_ptr == NULL) {
			strcat(longest, string[++i]);
			swap_flag = 0;
		} else {
			if (swap_flag) {
				strcpy(longest, string[++i]);
				swap_flag = 0;
			} else
				++i;
		}
	}
	printf("%.100s\n", longest);	
	return 0;
}