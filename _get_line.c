/**
 * Hello here i am going to try and make getline replica
 * Since we are all doing the low level staff
 * And also alx checker really is upto this one
 * Thanks for reading and opening the file
 * Let's begin
 *
 * :: AUTHOR :: Mk-0-wan[https://github.com/Mk-0-wan]
 */

typedef unsigned long int uli;
typedef unsigned int ui;
/**
 * _get_line - a simple implementation of the getline function.
 * @buff: double pointer to a another NULL pointer.
 * @buff_size: size required by the user
 * @fd: where our stream is comming from [STDOUT_FILENO, STDIN_FILENO]
 * Return: number of chars read from the stream
 */
int _get_line(char **buf, unsigned int buff_size, int fd)
{
	uli reads = 0;
	
	reads = read(fd, buff_size, 
