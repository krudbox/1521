#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char *argv[]) {
    char *dateArgs[] = {"/bin/date", "+%d-%m-%Y", NULL};
    char *dateTimeArgs[] = {"/bin/date", "+%T", NULL};

    pid_t pidBuffer;
    int *returnBuffer;

    int returnV = posix_spawn(&pidBuffer, "/bin/date", NULL, NULL, dateArgs, environ);
    waitpid(&pidBuffer, returnBuffer, 0);

    pid_t pidBuffer2;
    int *returnBuffer2;

    int returnV2 = posix_spawn(&pidBuffer2, "/bin/date", NULL, NULL, dateTimeArgs, environ);
    waitpid(&pidBuffer, returnBuffer2, 0);

}
