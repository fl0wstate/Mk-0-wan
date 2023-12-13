#include <stdio.h>

/**
 * draw - simple draw function that uses recursion to draw a pyramid
 * @n: size of the pyramid or also known as number of rows for the pyramid
 * Return: void
*/
void draw(int n)
{
    if (n <= 0)
        return;
    /* you should be loving recursion the whole time your are coding in c*/
    for(int i = 0; i < n; i++)
        printf("*");
    printf("\n");

    draw(n - 1);

    for(int i = 0; i < n; i++)
        printf("*");
    printf("\n");

    /* its going to store all the value of n into the stack the repeatedly call the for loop starting with the smallest */

}

/* Another more efficient way to calculate fibonnacci */

/**
 * fibonnacci - a better and most reliable linear time complexity and O(1) for the space complexity
 * @input: number to calculate the fibonnacci value
 * Return: returns an long long int value which is the fib value of the input number
*/
long long int fibonnacci(long long int input)
{
    if (input <= 1)
        return input;

    /* variables to hold the current and the previous fib value */
    long long int cur = 1, prev = 0, temp = 0, i = 2;

    for (; i <= input; i++)
    {
        temp = cur;
        cur += prev;
        prev = temp;
         
    }
    /* once you are done with the total calculation return the cur */
    return cur;
}

int main(void)
{
    
    int x;
    long long res = 0;
    long long y = 0;

    printf("Height of the pyramid: ");
    scanf("%d", &x);

    draw(x);

    printf("Enter a large number: ");
    scanf("%lld", &y);

    res = fibonnacci(y);

    printf("%lld", res);
    return (0);
}