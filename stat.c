#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>

/**
 * main - simple stat file extracter
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, otherwise 1 failure
 */
int main(int ac, char **av) /* argument vector */
{
	/* we need a copy of the struct in our function */
	struct stat file_info_stat;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: must provide valid argument\n");
		return (1);
	}
	if (stat((av[1]), &file_info_stat) == 0)
	{
		printf("Inode number: %lu\n", file_info_stat.st_ino);
		printf("Access mode: %u\n", file_info_stat.st_mode);
		printf("Group ID: %u\n", file_info_stat.st_gid);
		printf("User ID: %u\n", file_info_stat.st_uid);
		printf("File size: %lu\n", file_info_stat.st_size);
		printf("Last status change: %s", ctime(&file_info_stat.st_ctime));
		printf("Last file access: %s", ctime(&file_info_stat.st_ctime));
		printf("Last file modification: %s", ctime(&file_info_stat.st_ctime));
		printf("Link no: %lu\n", file_info_stat.st_nlink);
		printf("ID of containing device:  [%x,%x]\n", major(file_info_stat.st_dev),
				minor(file_info_stat.st_dev));
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: file not found: %s\n", av[1]);
		return (1);
	} return (0);
}
