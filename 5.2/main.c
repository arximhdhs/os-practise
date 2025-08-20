#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
	fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0640);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    char pid_str[10];

    pid_t pid = fork();
    if (pid == 0) {
        sprintf(pid_str, "%d", getpid());
        write(fd, "Hello, kappa! this is pid = ", 12);
        write(fd, pid_str, strlen(pid_str));
        write(fd, "\n", 1);

    } else {
        sprintf(pid_str, "%d", getpid());
        write(fd, "Hello, World! this is pid = ", 30);
        write(fd, pid_str, strlen(pid_str));
        write(fd, "\n", 1);    
    }
    close(fd);

    return 0;
}
