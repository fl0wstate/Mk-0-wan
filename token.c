#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strtok(char *str, char *delim)
{
    char *last_token = NULL;
    
    if (str == NULL && last_token == NULL)
        return NULL; /* nothing was passed */

    if (str == NULL)
        str = last_token; /* make the string point to the next item in the list */

    str += strspn(str, delim); /* skip all the delimiters */

    if (*str == '\0') /* if pointer point to the null terminator you have reached the end of the string */
    {
        last_token = NULL;
        return (NULL);
    }
    char *token = str + strcspn(str, delim); /* copy over  to the token */
    
    if (*token != '\0')
	    *token++ = '\0';
            
    last_token = token;
    return (str);
    
}
int main() {
    char input[] = "Hello, World!";
    char *token;
    
    token = _strtok(input, " ");
    if (token)
        printf("After skipping leading spaces: %s\n", token);
    
    return 0;
}

