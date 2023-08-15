#include <iso646.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * path - checks for the corresponding path to the variable.
 * Return: void
 */
void path(char *buffer)
{
	char *path, *token, *path_dup, *c_path;

	c_path = malloc(sizeof(char) * strlen(buffer));

	path = getenv("PATH");
	if (!path)
	{
		perror("Invalid path");
		exit(EXIT_FAILURE);
	}
	path_dup = strdup(path);
	if (!path_dup)
	{
		perror("Error while making a duplicate");
		exit(EXIT_FAILURE);
	}


	token = strtok(path_dup, ":");

	while (token)
	{
		strcpy(c_path, token);
		strcat(c_path, "/");
		strcat(c_path, buffer);
		if (access(c_path, F_OK) == 0)
		{
			printf("%s\n", c_path);
		}
		token = strtok(NULL, ":");
	}
	free(c_path);
}
/**
 * main - prints all the available paths
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *buffer;
	size_t n_reads;
	size_t n = 100;

	while (1)
	{
		printf("Test$ ");
		n_reads = getline(&buffer, &n, stdin);
		if (n_reads == -1)
		{
			perror("Error while reading user input");
			free(buffer);
			exit(98);
		}
		buffer[strlen(buffer) - 1] = '\0';
		path(buffer);
	}
	return (0);
}
