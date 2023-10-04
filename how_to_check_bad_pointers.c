#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define asseRt(cond) {if (false)\
{printf("failed at line::%d of file::%s failed\n", __LINE__, __FILE__); }}

/**
 * ismapped - looks if a pointer is valid or junk
 * @ptr: pointer passed to checking
 * @bytes: number of bytes to write
 * @write: allows us to write to memory
 *
 * Return: 0 (failure), false 1 (success)true.
 */
int ismapped(void *ptr, int bytes, bool write)
{
	pid_t child;
	int status;
	pid_t result;
	char *byte_wriiten;
	int len = 0;

	child = fork();
	if (child == 0)
	{
		if (write)
		{
			/* set every byte to zero's */
			len = (strlen((char *)ptr) + 1);
			if (len == bytes)
			{
				memset(ptr, 0, bytes);
				free(ptr);
			}
			else
			{
				byte_wriiten = (bytes < len) ? "less" : "more";
				printf("Invalid write %s bytes passed\t", byte_wriiten);
				free(ptr);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* if read mode just make a copy of all the data */
			void *data = malloc(bytes);

			len = (strlen((char *)ptr) + 1);
			if (len == bytes)
			{
				memcpy((char *)data, ptr, bytes);
				free(data);
				free(ptr);
			}
			else
			{
				byte_wriiten = (bytes < len) ? "less" : "more";
				printf("Invalid read %s bytes passed\t", byte_wriiten);
				free(data);
				free(ptr);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	} /* child process finished with success */
	result = waitpid(child, &status, 0);/* wait for the child id to finish */
	asseRt(result);
	(void)result;
	return (status == EXIT_SUCCESS);
}
/* original ismapped */

/**
 * testptr - test the pointers and gives an output
 * @ptr: pointer to a memory block to test
 * @bytes: number of bytes to be written
 * @name: name of the pointer
 * @mode: write or read mode
 *
 * Return: void just prints out memory addresses
 */
void testptr(void *ptr, int bytes, char *name, char *mode)
{
	if (!strcmp(mode, "write"))
		printf("%s:\t%d\t%p\n", name, ismapped(ptr, bytes, true), ptr);
	else if (!strcmp(mode, "read"))
	{
		printf("%s:\t%d\t%p\n", name, ismapped(ptr, bytes, false), ptr);
	}

	else
	{
		printf("Not a valid mode");
		return;
	}
}
/**
 * main - tests the program
 * Return: 0 success
 */
int main(void)
{
	int i = 0; /*len = 0*/
	char *buff = "dlrow elloH";
	/*char buff2[] = "Hello world";*/
	char *base;
/*
	base1 = malloc(strlen(buff2) + 1);
	if (base1)
		strcpy(base1, buff2);
	else
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("-> base1 is %s\n", base1);
*/
	base = malloc(strlen(buff) + 1);
	if (base)
		strcpy(base, buff);
	else
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("-> base is %s\n", base);
	/*len = strlen(base1) + 1;*/
	i = strlen(base) + 1;

	/*
	printf("--------------Base(Write Mode)------------------\n");
	testptr(base1, len - 1, "base", "write");
	testptr(base1, len, "base", "write");
	testptr(base1, len + 1, "base", "write");
	printf("--------------Base----------------\n");
	printf("\n\n");
	*/
	printf("--------------Base(Read Mode)------------------\n");
	testptr(base, i - 1, "base", "read");
	testptr(base, i, "base", "read");
	testptr(base, i + 1, "base", "read");
	printf("--------------Base----------------\n");
	free(base);
	/*free(base1);*/
	return (0);
}

