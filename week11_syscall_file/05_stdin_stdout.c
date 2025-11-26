#include <unistd.h>   // read, write, STDIN_FILENO, STDOUT_FILENO
#include <stdio.h>    // printf
#include <stdlib.h>   // exit
#include <errno.h>    // errno

#define BUF_SIZE 128

int main(int argc, char *argv[]) {
    // (선택) 인자 체크: 이 프로그램은 인자를 받지 않음
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char buf[BUF_SIZE];

    while (1) {
        ssize_t n = read(STDIN_FILENO, buf, BUF_SIZE);

        if (n == 0) {
            printf("Detected EOF (Ctrl + D)\n");
            break;
        }
        if (n < 0) {
            if (errno == EINTR) continue;
            perror("read");
            break;
        }
        ssize_t written = 0;
        while (written < n) {
            ssize_t w = write(STDOUT_FILENO, buf + written, n - written);
            if (w < 0) {
                if (errno == EINTR) continue;
                perror("write");
                exit(1);
            }
            written += w;
        }
    }

    return 0;
}
