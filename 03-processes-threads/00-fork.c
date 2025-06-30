#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t id;

    id = fork();
    if (id == 0) {
        // Code only executed by child process
        printf("Inside child process - PID: %d\n", getpid());
    } else if (id < 0) {
        fprintf(stderr, "Failed to fork\n");
        exit(1);
    } else {
        // Code only executed by parent process
        printf("Inside parent process - PID: %d - child PID: %d\n", getpid(), id);
    }

    return 0;
}

