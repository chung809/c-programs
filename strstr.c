#include <stdio.h>
#include <string.h>

int main(void)
{
   char *str1 = "testing", *str2 = "testing", *ptr;

   ptr = strstr(str1, str2);
   printf("The substring is: %s\n", ptr);
   return 0;
}