#include <stdio.h>
#include <sys/utsname.h>

int main()
{
    struct utsname info;

    uname(&info);
    printf("os name: %s - version %s\n", info.sysname, info.release);

    return 0;
}
