#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    char buffer[100];
    int number_of_read;
    int count;
    int file_descriptor;

    file_descriptor = open("more.txt", O_RDONLY );
    
    if (file_descriptor == -1)
        return(1);
        
    number_of_read = -1;
    count = 0;

    while (number_of_read != 0)
    {
        number_of_read = read(file_descriptor, buffer, 100);
    
        if (number_of_read == -1)
	{
		printf("Error while reading the file\n");
		return (1);
	}

        buffer[number_of_read] = '\0';
        
        printf("\e[36m[\e[0m%d\e[36m]: [\e[0m%s\e[36m]\e[0m\n", count, buffer);
        count++;
    }
    close(file_descriptor);
    return 0;
}
