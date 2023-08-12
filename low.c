#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * main - simple openning and closing file with system call
 * Return - 0 success -1 otherwise
 */
size_t _strlen(const char *s)
{
	size_t len = 0;
	while(s[len])
	{
		len++;
	}
	return (len);
}
	
int main(void)
{
	int fd;
	size_t n;
	char *buff = "Added a few lines of code";

	size_t len = _strlen(buff);
	printf("%zu\n", len);

	fd = open("m.txt", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd == -1)
		exit(EXIT_FAILURE);

	n = write(fd, buff, len);
	if (n == -1)
		exit(EXIT_FAILURE);
	
	free(buff);
	close(fd);
	return (0);
}
