#include "main.h"
/**
 * main - more and more use of structers
 * Return: 0 successful
 */
int global_val = 0;

int main(void)
{
	bot *ptr = MALLOC_CHECK(malloc(sizeof(bot)));
	double x = 1.23, y = 12.3443;
	//assign values to a pointer struct
	bot p =  { 2.456, 32.56 };
	Point_print(&p);

	increment_it();
	use_it(global_val);

	//change or assign values to a struct
	Point_translate(&p, x, y);
	//assign values to a pointer struct
	Point_translate(ptr, x, y);
	Point_print(ptr);
	free(ptr);
	return (0);
}
// safe no mutation is happening
void Point_print(const bot *s) // use this for more efficiency
{
	printf("Point : (%g, %g)\n", s->x, s->y);
}
// not safe mutation is happening
void Point_prints(bot *s)
{
	printf("Point : (%g, %g)\n", s->x, s->y);
	s->x += 1.0; // Mutating a value
}
void Point_translate(bot *x, double w, double z)
{
	x->x = w;
	x->y = z;
}
void *MALLOC_CHECK(void *p)
{
	if ( p == NULL )
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}
	return (p);
}
/**
 * use_it - increments the global variable and prints it
 * @a: param for the func which is of int type
 * Return: void
 */
void use_it(int a)
{
	printf("global_variable -> %d\n", a++);
}
//you should only use pointer struct parameters for no copies willbe made
//safe and unable to make more expensive mistakes
//note that a struct pointer should be freed and will not need an address of operator while calling it
//you are responsible of freeing the dynamically allocated memory in the heap
//allways make sure to use a helper function in all your c file to check for allocation failure.


