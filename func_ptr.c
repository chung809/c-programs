#include <stdio.h>

static void user_run(void);
static void user_stop(void);
static void user_exit(void);

static void (*command[])(void) = {user_run, user_stop, user_exit};

void user_run() {
    printf("start\r\n");
}

void user_stop() {
    printf("stop\r\n");
}

void user_exit() {
    printf("exit\r\n");
}

int on_state_change(int state) {
       
    if (state > 2) { 
        printf("Wrong state!\n");
        return 1;
    }
    command[state]();
    return 0;
}

int main()
{
	int i;

	while (1) {
		scanf("%d", &i);
		if (on_state_change(i))
			break;
	}
	return 0;
}
	
