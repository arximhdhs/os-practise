#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("hello\n");
        fflush(stdout); // Ensure output is immediately visible
        
        // Create a signal file to indicate child is done
        int fd = open("child_done.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd >= 0) {
            write(fd, "done", 4);
            close(fd);
        }
        
    } else if (pid > 0) {
        // Parent process
        struct stat st;
        
        // Wait for the signal file to exist and have content
        do {
            usleep(1000); // Sleep 1ms to avoid busy waiting
        } while (stat("child_done.txt", &st) != 0 || st.st_size == 0);
        
        printf("goodbye\n");
        
        // Clean up the signal file
        unlink("child_done.txt");
        
    } else {
        // Fork failed
        perror("fork");
        return 1;
    }
    
    return 0;
}
