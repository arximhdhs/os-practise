#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>

int main() {
    int x = 1;
    x = 2;
    pid_t newpid = fork();
    if (newpid == 0) {
        x = 3;
        printf("x = %d\n", x);
    } else {
        x = 4;
        printf("x = %d\n", x);
    }
    printf("this is pid = %d, x = %d\n", newpid, x);
    return 0;
}
