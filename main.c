#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main() {
    printf("=== Process Information ===\n\n");
    
    // Process ID information
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t pgid = getpgrp();
    pid_t sid = getsid(0);
    
    printf("Process ID (PID): %d\n", pid);
    printf("Parent Process ID (PPID): %d\n", ppid);
    printf("Process Group ID (PGID): %d\n", pgid);
    printf("Session ID (SID): %d\n", sid);
    printf("\n");
    
    // User and Group information
    uid_t uid = getuid();
    uid_t euid = geteuid();
    gid_t gid = getgid();
    gid_t egid = getegid();
    
    printf("Real User ID (UID): %d\n", uid);
    printf("Effective User ID (EUID): %d\n", euid);
    printf("Real Group ID (GID): %d\n", gid);
    printf("Effective Group ID (EGID): %d\n", egid);
    printf("\n");
    
    // Get user and group names
    struct passwd *pw = getpwuid(uid);
    struct group *gr = getgrgid(gid);
    
    if (pw != NULL) {
        printf("Username: %s\n", pw->pw_name);
    }
    if (gr != NULL) {
        printf("Group name: %s\n", gr->gr_name);
    }
    printf("\n");
    
    // Working directory
    char *cwd = getcwd(NULL, 0);
    if (cwd != NULL) {
        printf("Current Working Directory: %s\n", cwd);
        free(cwd);
    }
    printf("\n");
    
    // Resource usage information
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("=== Resource Usage ===\n");
        printf("User CPU time: %ld.%06d seconds\n", 
               usage.ru_utime.tv_sec, (int)usage.ru_utime.tv_usec);
        printf("System CPU time: %ld.%06d seconds\n", 
               usage.ru_stime.tv_sec, (int)usage.ru_stime.tv_usec);
        printf("Maximum resident set size: %ld KB\n", usage.ru_maxrss);
        printf("Page reclaims: %ld\n", usage.ru_minflt);
        printf("Page faults: %ld\n", usage.ru_majflt);
        printf("Voluntary context switches: %ld\n", usage.ru_nvcsw);
        printf("Involuntary context switches: %ld\n", usage.ru_nivcsw);
    }
    
    return 0;
}
