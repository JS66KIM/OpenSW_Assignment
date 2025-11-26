#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = getpid();
    printf("My PID: %d\n", (int)pid);
    return 0;
}
