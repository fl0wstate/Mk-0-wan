#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int ac, char **av) /* argument vector */
{
	/* we need a copy of the struct in our function */
	struct stat file_info_stat;
	
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: must provide valid argument\n");
		return (1);
	}
	if ((stat(av[1]), &file_info_stat) == 0)
	{
		printf("Inode numbern: %d", file_info_stat.st_ino);
		printf("Access mode: %lu", file_info_stat.st_mode);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: file not found nor executable -> %s\n", av[1]);
		return (1);
	}

	return (0);
}
