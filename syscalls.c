#include <errno.h>

// Dummy exit function
void _exit(int status) {
    while (1); // Infinite loop to simulate program termination
}

// Dummy sbrk function
void *_sbrk(ptrdiff_t incr) {
    errno = ENOMEM;
    return (void *)-1;
}

// Dummy kill function
int _kill(int pid, int sig) {
    errno = EINVAL;
    return -1;
}

// Dummy getpid function
int _getpid(void) {
    return 1;
}

// Dummy isatty function
int _isatty(int file) {
    return 1;
}

// Dummy fstat function
int _fstat(int file, void *st) {
    return 0; // Return success as there's no actual file system
}

// Dummy close function
int _close(int file) {
    return -1;
}

// Dummy lseek function
int _lseek(int file, int ptr, int dir) {
    return 0;
}

// Dummy read function
int _read(int file, char *ptr, int len) {
    return 0;
}

// Dummy write function
int _write(int file, char *ptr, int len) {
    return len;
}
