#include <fcntl.h>
#include <unistd.h>

int main(void) {
  // Open System call
  int fd = open("hello.txt", O_CREAT | O_WRONLY, 0644);

  // Write System call
  char toWrite[6] = "bong";
  write(fd, toWrite, 5);

  // Close System call
  close(fd);

  return 0;
}