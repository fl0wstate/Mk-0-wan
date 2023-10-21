#include "shell.h"
#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define buffsize 1002
char **parser(char *cmd, int len);
/**
 * main - test for the simple shell implementation
 *
 * @ac: argument count
 * @av: argument vector
 * @envp: environment pointer
 *
 * Return: 0 success, 1 fail
 */
int main(int ac __attribute__((unused)),
		char **av __attribute__((unused)), char **envp)
{
	pid_t proc; /* working with child */
	uli size = 0; /* getline is gettting to my nerves */
	int token_len = 0;
	char **token = {NULL};
	char *cmd_hld = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("[%s]@$ ", getenv("LOGNAME"));
			/* handling getline errors */
			while((getline(&cmd_hld, &size, stdin)) == -1)
			{
				perror("getline");
				free(cmd_hld);
				exit(EXIT_FAILURE);
			}
			/* string tokenizing */
			token_len = strcspn(cmd_hld, " ");
			token = parser(cmd_hld, token_len);
			printf("%s\n", token[0]);
			proc = fork();
			if (proc == 0)
			{
				if (execve(token[0], token, envp) == -1)
				{
					perror("exec");
					free(cmd_hld);
					free(token);
					exit(EXIT_FAILURE);
				}
			}
			wait(NULL);
		}
		else
		{
			print("Not sure how to go about it");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

char **parser(char *cmd, int len)
{
	char **token_array = NULL;
	char *token = NULL;
	int index = 0;

	/*Both we are going to use them to store commands and args */
	token_array = malloc(sizeof(char *) * len);
	malloc_check(token_array);

	token = strtok(cmd, " ");
	if (len)
	{
		while (token)
		{
			token_array[index++] = token;
			token = strtok(NULL, " ");
		}
	}
	else
		token_array[index] = token;

	token_array[index] = NULL;
	return (token_array);
}
