#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    const char *filename;
    struct stat fs;

    if (argc < 2) {
        fprintf(stderr, "File argument is required\n");
        exit(1);
    }

    filename = argv[1];
    printf("Obtaining permission mode for '%s':\n", filename);
    if (stat(filename, &fs) == -1) {
        fprintf(stderr, "File error\n");
        exit(1);
    }

    /* File permissions are kept in the st_mode member */
    /* The S_ISREG() macro tests for regular files */
    if (S_ISREG(fs.st_mode))
        printf("Regular file\n");
    else
        printf("Not a regular file\n");

    printf("Owner permissions: ");
    if (fs.st_mode & S_IRUSR)
        printf("read ");
    if (fs.st_mode & S_IWUSR)
        printf("write ");
    if (fs.st_mode & S_IXUSR)
        printf("execute");
    printf("\n");

    printf("Group permissions: ");
    if (fs.st_mode & S_IRGRP)
        printf("read ");
    if (fs.st_mode & S_IWGRP)
        printf("write ");
    if (fs.st_mode & S_IXGRP)
        printf("execute");
    printf("\n");

    printf("Others permissions: ");
    if (fs.st_mode & S_IROTH)
        printf("read ");
    if (fs.st_mode & S_IWOTH)
        printf("write ");
    if (fs.st_mode & S_IXOTH)
        printf("execute");
    printf("\n");
  
    return(0);
}

