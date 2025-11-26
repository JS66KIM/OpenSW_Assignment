#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#define BUF_SIZE 32

static int write_all(int fd, const char *buf, ssize_t n) {
    ssize_t w = 0;
    while (w < n) {
        ssize_t r = write(fd, buf + w, n - w);
        if (r < 0) {
            if (errno == EINTR) continue;
            return -1;
        }
        w += r;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ...\n", argv[0]);
        return 0;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror(argv[1]);
        return 1;
    }

    int n_d = argc - 2;
    int *fds = (int*)malloc(sizeof(int) * n_d);
    if (!fds) { perror("malloc"); close(src); return 1; }

    for (int i = 0; i < n_d; i++) {
        fds[i] = open(argv[i + 2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fds[i] == -1) perror(argv[i + 2]);
    }

    char buf[BUF_SIZE];
    for (;;) {
        ssize_t n = read(src, buf, BUF_SIZE);
        if (n == 0) break;
        if (n < 0) {
            if (errno == EINTR) continue;
            perror("read");
            break;
        }
        if (write_all(STDOUT_FILENO, buf, n) == -1) { perror("stdout"); break; }
        for (int i = 0; i < n_d; i++) {
            if (fds[i] != -1)
                if (write_all(fds[i], buf, n) == -1) perror(argv[i + 2]);
        }
    }

    close(src);
    for (int i = 0; i < n_d; i++) if (fds[i] != -1) close(fds[i]);
    free(fds);
    return 0;
}
