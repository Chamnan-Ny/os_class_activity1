#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024
int main() {
    int src_fd, dest_fd;
    ssize_t nread;
    char buffer[BUFFER_SIZE];

    // Open source file
    src_fd = open("result.txt", O_RDONLY);
    if (src_fd < 0) {
        write(2, "Error opening result.txt\n", 25);
        return 1;
    }

    // Open destination file
    dest_fd = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        write(2, "Error opening copyresult.txt\n", 29);
        close(src_fd);
        return 1;
    }

    // Copy file content
    while ((nread = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        write(dest_fd, buffer, nread);
    }

    // Close files
    close(src_fd);
    close(dest_fd);
    return 0;
}
