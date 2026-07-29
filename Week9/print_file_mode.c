#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Incorrect number of args\n");
        return 1;
    }

    struct stat s;

    if (stat(argv[1], &s) != 0) {
        perror("");
        exit(1);
    }

    if (S_ISREG(s.st_mode)) {
        printf("-");
    } else if (S_ISDIR(s.st_mode)) {
        printf("d");
    } else {
        printf("-");
    }

    (s.st_mode & S_IRUSR) ? printf("r") : printf("-");
    (s.st_mode & S_IWUSR) ? printf("w") : printf("-");
    (s.st_mode & S_IXUSR) ? printf("x") : printf("-");

    (s.st_mode & S_IRGRP) ? printf("r") : printf("-");
    (s.st_mode & S_IWGRP) ? printf("w") : printf("-");
    (s.st_mode & S_IXGRP) ? printf("x") : printf("-");

    (s.st_mode & S_IROTH) ? printf("r") : printf("-");
    (s.st_mode & S_IWOTH) ? printf("w") : printf("-");
    (s.st_mode & S_IXOTH) ? printf("x") : printf("-");


    return 0;
}
