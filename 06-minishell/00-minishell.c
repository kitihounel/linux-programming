#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *buffer = NULL;
    size_t buf_size = 2048;

    // Reserve space for user input
    buffer = (char *) calloc(sizeof(char), buf_size);
    if (buffer == NULL) {
        perror("Memory allocation failure");
        return (EXIT_FAILURE);
    }

    // Show prompt
    write(1, "$> ", 3);
    while (getline(&buffer, &buf_size, stdin) > 0) {
        printf("cmd = %s\n", buffer);
        write(1, "$> ", 3);
    }

    printf("\nBye\n");
    free(buffer);

    return 0;
}
