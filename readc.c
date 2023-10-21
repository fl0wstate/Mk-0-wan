#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int read_string(int fd)
{

    unsigned int count = 0; int n_reads = -1;
    char prev_line[100] = ""; // Store the previous line
    char buff[100];

    while (n_reads != 0) {
        n_reads = read(fd, buff, sizeof(buff) - 1);

        if (n_reads == -1) {
            perror("Read error");
            exit(1);
        }

        buff[n_reads] = '\0'; // Null-terminate the read data

        // Split the read data into lines and process them
        char *line = strtok(buff, "\n");
        while (line != NULL) {
            if (strcmp(line, prev_line) != 0) { // Compare with the previous line
                printf("\e[36m%d : [\e[0m%s\e[36m]\e[0m\n", count, line);
            }
            strcpy(prev_line, line); // Store the current line as the previous line
            line = strtok(NULL, "\n"); // Move to the next line
            count++;
        }
    }
    return (count);
}
int main() {
    int fd;

    fd = open("m.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    read_string(fd);
    lseek(fd, 0, SEEK_SET);

    lseek(fd, 10, SEEK_SET);
    read_string(fd);
    
    lseek(fd, 0, SEEK_CUR);
    read_string(fd);

    lseek(fd, 0, SEEK_END);
    read_string(fd);

    lseek(fd, 10, SEEK_CUR);
    read_string(fd);

    lseek(fd, 2, SEEK_SET);
    read_string(fd);

    close(fd);
    return 0;
}

