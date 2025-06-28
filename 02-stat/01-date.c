#include <stdio.h>
#include <sys/stat.h>
#include <time.h>


int main(int argc, char *argv[])
{
    struct stat filestat;

    stat(argv[1], &filestat);
    printf("File access time %s", ctime(&filestat.st_atime));
    printf("File modify time %s", ctime(&filestat.st_mtime));
    printf("File changed time %s", ctime(&filestat.st_ctime));

    return 0;
}

