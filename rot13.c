/*
Keep on looking for the null byte once  you find it the while loop stops:
Store the value you found at the current position to c: this is done due to the power of dereferencing pointers in our case *(s + i)
M stores and in value which is pretty much neat of how you did it : since  what ever is stored there has an ASCII value you divide it with 32 and get an in value.
here comes the complex part but here is how i understood it:
we are checking for values within a range from { A ~ Z }  or { a ~ z }:
the first calculation will return the char value according to the ASCII value found: something like this lets say m = 65 / 32; which is 2 then this will convert it back to 65 which is A:
The second one took me a little bit of time to figure it out here is how though i found it out.
First we collect whatever is returned from the calculations. So basically we are changing the value which was currently set there. *(s + i) = New value
First we return the value back to its original state but in an int format m = *(s + i) / 32 -> stores the int value of the character. { but we need to set it back to its original state but in int format } here we do this (m * 32) + 1
Now here is where the real magic is happening we first subtract the char value with its int value which will return a 0 and we need that to happen in order for our rot concept to work.
Finally while doing a modulus which returns 13 this will help us cipher the value and change the original value to 13 characters ahead. (m * 32 + 1) + 13 { in a case of 'A' -> ASCII value 65 this will be 65 + 13 = 78 which is a char value of N and there you have it your new ciphered value.
Again the whole idea is to switch it with the 13th character from its origin.
This will keep on repeating again and again until i reaches the null byte of the character. (edited) 
*/
#include <stdio.h>

char *rot13(char *s)
{
	int i = 0, m = 0;
	char c; /* store chars found in the string */

	while (s[i] != '\0')
	{
		c = s[i];
		m = s[i] / 32; /* transforms char to int */
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			s[i] = ((m * 32) + 1) + ((s[i] - ((m * 32) + 1) + 13) % 26);
		}
		i++;
	}
	return (s);
}

int main(void)
{
	char ss[] = "Hello World";
	char *s = rot13(ss);

	printf("%s\n", s);
	printf("%s\n", rot13(s));
	return (0);
}
/**
Awesome guys! I'm loving the engagement! Just to add to your explanations, which are well detailed, the final step in the rot13 encoding, the % 26 ensures that even if we're offsetting our character value by 13, we are not overflowing beyond the limits of the alphabetical characters, so for example if we are to add 13 to Z the 25th index of the alphabet, which has an ascii value of 90:
the part  *(s + i) - (m * 32 + 1) + 13  will be 90 - 65 + 13 = 38.  What we want it to give is 12. And modding the result by 26 (the number of characters of the alphabet) ensures that it effectively acts like we want and it "loops"  back to A  and adds the rest from there . In this case 38 % 26 = 12, which resolves to L, the 12th indexed letter
*/
