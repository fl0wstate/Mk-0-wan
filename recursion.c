#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * factorial - a recursive function which performs math factorial function
 * @x: value passed to get its factorial value
 * Return: an int result of factorial value
 */
int factorial(int x)
{
    int rec_;
    /* we need a stopping point */
    if (x == 0)
    {
        return (1);
    }
    return (x * factorial(x - 1)); /* reducing the values to get the smallest instance and then you push all the way through down back to where you begin. */
}
/**
 * main - simple mathfunction for factorial calculations
 * Reads the inputs from the user
 * Does some string tokenization
 * Transforms the input into a unsigned int
 * Performes the factorial function
 * Return: 0 success (Factorial value of the input given)
 */
int main() {
    int x;
    size_t f = 0;
    char *buff = NULL, *token;
    
    printf("\t==Factorial Function in C==\n");
    while (1)
    {
	    printf("\nEnter an unsigned int: ");
	    /* store the value typed by the user */
	    if (getline(&buff, &f, stdin) == -1)
	    {
		    perror("Ooops!! program crashed");
		    free(buff); /* since the value was already assigned null. */
		    exit(EXIT_FAILURE);
	    }
	    buff[strcspn(buff, "\n")] = '\0'; /* remove all the newline chars at the end of the input placed by getline */
	    /* look for the exit word */
	    if (strcmp(buff, "exit") == 0) /* simple exit statment */
	    {
		    printf("Bye");
		    free(buff);
		    exit(EXIT_SUCCESS);
	    }
	    /* start tokenizing */
	    token = strtok(buff, " ");
	    if (token)
	    {
		    x = atoi(token); /* transform the value of token to int */
		    printf("!%d = %d\n",x ,factorial(x));
	    }
	    else
		    perror("Invalid input");
    }
    free(buff);
    return (0);
}
