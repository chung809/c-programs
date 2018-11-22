#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char s[] = "Rome was not built in a day.";
    char t = 'a';
    char *test;
     
    test = strchr(s, t);
    printf("%s\n", test);
    test = strchr(s, '-');
    if (test)
	printf("%s\n", test);
    else
	printf("No -\n");
  
    return 0;    
}
