#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_number)
{
    if (signal_number == SIGINT) {
        printf("Received SIGINT\n");
    }
}

int main(void)
{
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        printf("\nCan't catch SIGINT\n");
    }

    printf("Start processing...\n");
    // A long long wait so that we can easily issue a signal to this process
    while (1) {
        sleep(1);
    }

    return 0;
}
