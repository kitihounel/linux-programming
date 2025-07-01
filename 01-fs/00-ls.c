#include <dirent.h> 
#include <stdio.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    const char *path;

    path = argc >= 2 ? argv[1] : ".";
    dir = opendir(path);
    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.')
                printf("%s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        printf("unable to open directory %s\n", path);
    }

    return 0;
}
