#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t id;
    const char *message;

    id = fork();
    if (id == 0) {
        // Code only executed by child process
        message = "Inside child process";
    } else if (id < 0) {
        fprintf(stderr, "Failed to fork\n");
        exit(1);
    } else {
        // Code only executed by parent process
        message = "Inside parent process";
        wait(NULL);
    }

    for (int i = 0; i < 10; ++i) {
        printf("%s: %d\n", message, i);
    }

    return 0;
}

