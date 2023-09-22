#include <stdio.h>
#include <string.h>

/**
 * hexadecimal - converts integers to hexadecimal numbers.
 * @decimal - decimal number
 * Return: pointer to the newly created hexadecimla array
 */
int hexadecimal(int decimal, char hex[])
{
	int rem = 0, i = 0, j;
	char temp;

	if (decimal == 0)
		return (0);
	if (decimal < 0)
		return (-1);

	while (decimal > 0)
	{
		rem = decimal % 16;
		if (rem < 10)
			hex[i++] = '0' + rem;
		else
			hex[i++] = 'a' + (rem - 10);
		decimal /= 16;
	}
	j = 0;
	for (; j < i / 2; j++)
	{
		temp = hex[j];
		hex[j] = hex[i - 1 - j];
		hex[i - 1 - j] = temp;
	}
	hex[i] = '\0';
	return (i);
}
/**
 * octal - converts integer to octal values
 * Return: 0 success
 */
int octal(int digit)
{

	int rem = 0, octal = 0;
	int pos = 1;
  
	if (digit == 0)
		return (0);
	if (digit < 0)
		return (-1);
	while (digit > 0)
	{
		rem = digit % 8;
		digit /= 8;
		octal += (rem * pos);
		pos *= 10;
	}
	return (octal);
  
}

int _strlen(int digit)
{
	int len = 0, temp = 0;

	temp = digit;
	len = (temp == 0) ? 1 : 0;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return len;
}
/**
 * binary - simple c program for converting decimal to binary
 * @num: placeholder for the passed function
 * Return: binary number
 */
int binary(int num)
{
	int pos = 1, bin = 0, rem = 0;

	if (num == 0)
		return (0);
	if (num < 0)
		return (-1);
	while (num > 0)
	{
		rem = num % 2;
		num /= 2;
		bin += (rem * pos);
		pos *= 10;
	}
	return (bin);
}
int main(void)
{
	int decimal, len = 0;
	char hex[100];

	printf("x||x Hello user input a digit for conversion to binary && Octal\n");
	scanf("%d", &decimal);
	printf("Binary no. is: %d \nBinary length: %d\n", binary(decimal), _strlen(binary(decimal)));
	printf("Octal no. is: %d \nOctal length: %d\n", octal(decimal), _strlen(octal(decimal)));
	printf("Hexadecimal no. is: %c \nHexadecimal length: %d\n", hexadecimal(decimal, hex), len = (hexadecimal(decimal, hex)));
	return (0);
}
