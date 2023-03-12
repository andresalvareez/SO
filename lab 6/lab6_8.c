#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd[2];
    pid_t childpid;
    pipe(fd);
    if ((childpid = fork()) == 0)
    { /* ls es el hijo */
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/ls", "ls", "-l", NULL);
        perror("Exec fallo en ls");
    }
    else
    { /* sort es el padre */
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execl("/usr/bin/sort", "sort", "-n", "+4", NULL);
        perror("Exec fallo en sort");
    }
    exit(0);
}
