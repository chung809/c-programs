#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	char input_str[100];
	char *p;
	char output_str[100];
	int i;

	scanf("%c %s", &c, input_str); 
	strcpy(output_str, input_str);
	
	for (i = 0, p = input_str; p = strchr(p, c); p++, i = i + 2) {
		output_str[p - input_str + i] = '(';
		output_str[p - input_str + i + 1] = *p;
		output_str[p - input_str + i + 2] = ')';
		strcpy(&output_str[p - input_str + i + 3], p + 1);
	}
	printf("%s\n", output_str);
	return 0;
}
