#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("My PID : %d\n", (int)pid);
    printf("My PPID: %d\n", (int)ppid);
    return 0;
}
