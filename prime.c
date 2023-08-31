#include <stdio.h>
#include <stdlib.h>
/**
 * main - simple c function that searches for a prime number
 * Return: 1 if its prime 0 otherwise
 */
int main(void)
{
	/**
	 * prompt the user
	 * get the input
	 * handle all the small cases 1, 2, 3
	 * check whether number is divisible by 2 & 3
	 * use a for loop to handle larger cases like 5, 7 and so on
	 * use if to check if number is divisible both 5 and 7
	 * return (1) if all the above checks are passed.
	 * Math formular [6n + 1 = prime_no] == n being the input in our case.
	 */
	int input;
	int i;

	printf("\t ==[Custom prime detector]==\n\n");
	printf("\t ==[Hints]==\n\t ::PF - prime found\n\t ::NP - not prime\n\t ::RT - return value\n\n");
	/* prompt the user */
	printf("Enter number: ");
	scanf("%d", &input);
	/* check for small no */
	if (input <= 1) 
	{
		printf("%d: :NP (X _ X) Hey that's invalid\n", input);
		return (0);
	}
	/* smallest prime numbers */
	if (input == 2 || input == 3)
	{
		printf("%d: :PF, (^~^) Come on that was easy give me something big!!\n", input);
		return (1);
	}
	/* is it divisible */
	if (input % 2 == 0 || input % 3 == 0)
	{
		printf("%d: :NP Bruh! :( Really now\n", input);
		return (0);
	}
	/* check for large prime numbers */
	/* 6 + i means jump all the above steps and come back to the loop */
	for (i = 5; i * i <= input; i += 6) 
	{
		/* check for divisibility for both the 5 and 7 */
		if ((input % i) == 0 || input % (i + 2) == 0)
		{
			printf("%d: :NP Opps!! :)\n", input);
			return (0);
		}
	}
	printf("%d: :PF Finally Success\n", input);
	return (1);
}
