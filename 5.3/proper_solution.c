#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipefd[2];
    char buffer[1];
    
    // Create a pipe before fork
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        close(pipefd[0]); // Close unused read end
        
        printf("hello\n");
        fflush(stdout); // Ensure output is immediately visible
        
        // Signal parent that child is done
        write(pipefd[1], "x", 1);
        close(pipefd[1]);
        
    } else if (pid > 0) {
        // Parent process
        close(pipefd[1]); // Close unused write end
        
        // Wait for child's signal (this will block until child writes)
        read(pipefd[0], buffer, 1);
        close(pipefd[0]);
        
        printf("goodbye\n");
        
    } else {
        // Fork failed
        perror("fork");
        return 1;
    }
    
    return 0;
}
