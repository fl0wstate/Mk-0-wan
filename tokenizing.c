#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strtok(char *str, char *delim)
{
    static char *last_token = NULL;
    char *token;
    
    if (str == NULL && last_token == NULL) // reached the end
        return NULL;
    if (str == NULL) // then move to the next one in line
        str = last_token;
    str += strspn(str, delim); // remove all the trailing delimiters
    if (*str == '\0') // check whether we've reached the end of the string
    {
        last_token = NULL;
        return (NULL);
    }
    token = str + strcspn(str, delim); // update the token
    if (*token != '\0') /* while token copy doesn't point to a null terminator */
	    *token++ = '\0'; /* make it point there */
	    /* *token_copy++; move to the next char in line */
    last_token = token;  /* update the last token */
    return (str);
}
int main() {
    char *input = strdup("Hello, World I did it finally");
    char *token = NULL;
    
    token = _strtok(input, " ");
    if(token)
    {
    	printf("After skipping leading spaces: %s\n", token);
   	free(input);
    }
   return 0;
}
