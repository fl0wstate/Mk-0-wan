#include <stdio.h>
#include <stdlib.h>
typedef unsigned long int ul;
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

typedef struct nodes
{
    int value; // an int value to store at each node
    struct nodes *next; // pointer to the next node
} node;
// simple way to make sure you have less collision

// making an array with a struct
typedef struct simple_array
{
    int size; // number of nodes in the array
    node **entry; // single node
} array;

void print_struct_array(int size)
{
    array *array = malloc(sizeof(array)); // the whole array

    array->size = size; // number of node to dynamically create
    array->entry = calloc(array->size, sizeof(node *)); // for all the single entry allocate memory to it

    for (int i = 0; i < array->size; i++)
    {
        
        printf("nodes -> %d -> data %p\n", i, array->entry[i]);
    }
    
}

int main(void)
{
    char *x ="Don't forget to tweet today";
    
    char *a ="Don't forget to tweet today";
    int z;
    ul y = 5381;

    while ((z = *x++)) // while the value inside is true
    {
        y = y * 33 + z;
    }


    printf("Hashed value:-> [%lu]\n", y);
    
    printf("Hashed value -> [%lu]\n", hash_djb2(x));

    print_struct_array(3);

    return (0);
}