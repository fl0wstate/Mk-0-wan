#include "main.h"
/**
 * main - print double value from a struct
 * Return: 0 successfull
 */
int main(void) 
{
	//bot b = { .x = 1.3, .list[0] = 12, .list[2] = 12, .list[1] = 11 };

	//call the values of the struct
	//b.x = 1.3;
	//b.list[0] = 14;
	//after assigning them the values
	//print them out
	//printf("list is : %d->%d->%d\n", b.list[0], b.list[1], b.list[2]);
	//printf("x is : %g\n", b.x);
	//call the struct name with the new variabel name
	bot b = { 1.0, 2.4 };
	bot c = { 2.0, 3.4 };
	bot d = add( b, c );
	//the above curly braces will always make sure you are declaring and initializing the struct value.
	Point_print(&b);
	Point_print(&d);
	Point_print(&b);
	return (0);
}
void Point_print(const bot *self) //function which takes in a struct pointer.
{
	//printf("(%f, %f)\n", (*self).x, (*self).y);
	printf("(%f, %f)\n", self->x, self->y);
}
bot add(bot a , bot b)
{
	a.x += b.x; //updating the first struct a
	a.y += b.y;
	return (a);
}

