#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    char **tmp = envp;

    printf("number of arguments: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    printf("======================\n");
    printf("environment variables:\n");
    while (*tmp != NULL) {
        printf("%s\n", *tmp);
        ++tmp;
    }

    return 0;
}
