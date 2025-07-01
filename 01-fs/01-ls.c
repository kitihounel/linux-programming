#include <dirent.h> 
#include <stdio.h>

void ls(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir) {
        printf("%s:\n", path);
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.')
                printf("|- %s\n", entry->d_name);
        }
        closedir(dir);
    } else {
        fprintf(stderr, "unable to open directory %s\n", path);
    }
}


int main(int argc, char *argv[])
{
    
    const char *path;

    if (argc >= 2) {
        for (int i = 1; i < argc; ++i) {
            ls(argv[i]);
            printf("\n");
        }
    } else {
        ls(".");
    }

    return 0;
}
