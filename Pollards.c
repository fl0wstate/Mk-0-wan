/**
 * first we are going to read from file
 * collect the string and turn it to an long long integer
 * perform the Pollards algorithm
 * for the gcd use the recursion method
*/
#include <stdio.h>
//#include <unistd.h> using open() system call
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_BIT 8

typedef unsigned int ui;
typedef unsigned long long int ll;


/**
 * GCD - finding the greates common divisor
 * @a: first divided
 * @b: second divided
 * Return: the greatest commond divisor of both a and b
*/
ll GCD(ll a , ll b)
{ 
    /*First find the gcd of two number using recursion*/
    ll rem = a % b;

    if (rem == 0)
        return b;

    return GCD(b, rem);
}

/**
 * generate_random - generates random number over the specified range
 * @min: smallest range value
 * @max: highest range value
 * Return: a randomly generated number value within the given range
*/
ll gen_rand(ll min, ll max)
{
    if (min > max)
    {
        fprintf(stderr, "You high! or something?\n");
        exit(EXIT_FAILURE);
    }
    srand((ui)time(NULL));

    return min + rand() % (max - (min + 1)); /* the complete explanation of this part of code can be found in the Explantion.txt*/
}

/**
 * f_seq - this is like a magic trick to find the secret of a number
 * @x: This is like a magic number that we start with.
 * @c: This is like a magic trick that we use to change our magic number.
 * @n: This is like a magic box that our magic number can be in.
 * 
 * Descriptive Info : 
 * 
 * f_seq - Part of Pollard's rho algorithm for prime factorization
 * @x: Current number in the sequence
 * @c: Constant used to modify the sequence
 * @n: Modulus used in the sequence
 *
 * This function calculates a new number in the sequence by squaring x, adding c,
 * and then taking the modulus n. It returns this new number.
 *
 * In the context of Pollard's rho algorithm, this function is used to generate
 * a sequence of numbers that eventually fall into a cycle. The algorithm then
 * looks for a non-trivial factor of the number being factored by finding the
 * greatest common divisor (GCD) of the differences between consecutive numbers
 * in the cycle.
 *
 * Return: each sequence value we find inside the range of 1 to n(Trivial values)
 */
ll f_seq(ll x, ll c, ll n)
{
    return ((x * x) + c ) % n;
}

/**
 * Pollard_rho - Implementation of Pollard's rho algorithm for prime factorization
 * @n: The number to be factored
 *
 * This function implements the Pollard's rho algorithm to find a non-trivial factor of a number.
 * It starts by checking if the number is even. If it is, it returns 2 as a factor.
 * Then it generates two random numbers x and y, and a constant c, all within the range of 1 to n.
 * The function then enters a loop where it performs the f_seq function on x and y, moving y twice as fast as x.
 * It keeps looking for the greatest common divisor (GCD) of the differences between x and y until it finds a non-trivial factor.
 * The function returns this non-trivial factor.
 *
 * This function is part of a larger algorithm for prime factorization, which can be used to break down a composite number into its prime factors.
 * 
 * Return: Non-trival factors within the range of 1 and n
 */
ll Pollard_rho(ll n)
{
    ll x = 0, y = 0, c = 0, d = 0;

    if (n % 2 == 0)
        return (2);

    /* generate random numbers */
    x = gen_rand(1, n - 1);
    y = x;
    c = gen_rand(1, n - 1);

    /* Our Trivial value this include 1 and n itself */
    d = 1;

    while (d == 1)
    {
        /* Perform the f(x1)...f(xn) sequence until they meet*/
        x = f_seq(x, c, n);
        y = f_seq(f_seq(y, c, n), c, n);

        /* Look for the Non-Trivial values */
        d = GCD(abs(x - y), n);

    }
    return (d);
}

/**
 * factors - Just a simple function that enables us to fill an array with factors of n
 * @n: The number to find its factors.
 * Return: void just prints out the factors to the stdout
*/
void factors(ll n)
{
    ll *List_array;
    ll factor = 0;
    int i = 0;
    ll n_copy = n;

    List_array = (ll *)malloc(sizeof(ll) * n);
    while (n > 1)
    {
        factor = Pollard_rho(n);
        List_array[i] = factor;
        n /= factor;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        //printf("%llu = %llu * %llu\n", n_copy, List_array[j], List_array[j+1]);
        printf("%llu ", List_array[j]);
    }
    printf("\n");

    free(List_array);
}

int main(void)
{
   factors(239809320265259);
   printf("Done\n");

   return (0);
}