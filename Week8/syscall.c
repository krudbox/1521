#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
  // Open System call
  int fd = syscall(SYS_open, "hello.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

  // Write System call
  char toWrite[6] = "bing";
  syscall(SYS_write, fd, toWrite, 5);

  // Close System call
  syscall(SYS_close, fd);

  return 0;
}