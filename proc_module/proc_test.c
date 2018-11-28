#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "proc_test.h"
 
void main(void)
{
	char buf[BUFSIZE];
	int fd = open("/proc/proc_test", O_RDWR);
	int irq, mode;
	char tmp[10];

	scanf("%d %d", &irq, &mode);
	sprintf(tmp, "%d %d", irq, mode);

	lseek(fd, 0 , SEEK_SET);
	write(fd, tmp, strlen(tmp));

	lseek(fd, 0 , SEEK_SET);
	read(fd, buf, BUFSIZE);
	printf("%s", buf);	
}
