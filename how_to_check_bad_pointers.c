#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define asseRt(cond) if (!cond)\
{printf("Asserstion at line::%d of file::%s failed\n", __LINE__, __FILE__);}
/**
 * check_pointer - looks if a pointer is valid or junk
 * @ptr: pointer passed to checking
 * @bytes: number of bytes to write
 * Return: 0 success, 1 failure.
 */
int ismapped_succesfuly(void *ptr, int bytes, bool write)
{
	/* use fork to make multiple process
	 * we are only going to check by writting to memory
	 * or reading from memory.
	 */
	pid_t child;
	int status;
	pid_t result;

	child = fork();
	if (child == 0)
	{
		if (write)
		{
			/* set every byte to zero's */
			memset(ptr, 0, bytes);
		}
		else
		{
			/* if read mode just make a copy of all the data */
			void *data = malloc(bytes);
			memcopy(data, ptr, bytes);
		}
		exit(0);
	}/* child process finished with success */
	result = waitpid(child, &status, 0);/* wait for the child id to finish */
	asseRt(result >= 0);
	return (status == 0);
}
		
void testptr(void *ptr, int bytes, char *name)
{
	 printf("%s:\t%d\t%p\n", name, ismapped_succefully(ptr, bytes, true), ptr);
}
int main(void)
{
	int *junk = NULL;
	int *junk2 = (int*)((uintptr_t)0x352342524a);
	int *p = malloc(10);
	int x = 5;
	int i = 0;
	int *px = &x;
	char *buff = "Hello world";
	char *base = malloc(strlen(buff));
	
	while (i < (strlen(buff)))
	{
		base[i] = buff[i];
		i++;
	}
	base[i++] = '\0';
	printf("-> base is %s\n", base);
	
	testptr(junk, 1, "junk");
	testptr(junk2, 1, "junk");
	testptr(p, 10, "p");
	testptr(px, (sizeof(int)), "px");
	testptr(base, (strlen(buff)), "base");

	return (0);
}


