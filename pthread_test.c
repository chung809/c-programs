#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* child(void* data) {
	char *str = (char*) data;	// get input data
	for(int i = 0;i < 10;++i) {
		printf("%s\n", str);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t t;
	pthread_create(&t, NULL, child, "Child");
	for(int i = 0;i < 10;++i) {
		printf("Master\n");
		usleep(100000);	// 0.1sec
	}
	pthread_join(t, NULL);
	return 0;
}
