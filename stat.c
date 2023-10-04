#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

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
		printf("ID of containing device:  [%x,%x]\n",
                  major(file_info_stat.st_dev),
                  minor(file_info_stat.st_dev));

           	printf("File type:                ");
           	switch (file_info_stat.st_mode & S_IFMT)
		{
			case S_IFBLK:  printf("block device\n");            break;
			case S_IFCHR:  printf("character device\n");        break;
			case S_IFDIR:  printf("directory\n");               break;
			case S_IFIFO:  printf("FIFO/pipe\n");               break;
			case S_IFLNK:  printf("symlink\n");                 break;
			case S_IFREG:  printf("regular file\n");            break;
			case S_IFSOCK: printf("socket\n");                  break;
			default:       printf("unknown?\n");                break;
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: file not found nor executable -> %s\n", av[1]);
		return (1);
	}

	return (0);
}
