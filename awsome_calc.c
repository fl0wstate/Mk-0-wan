#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct op
{
  char *op;
  int (*f)(int a, int b);
}op_t;

/* operations functions */
int op_add( int a, int b)
{
  return ( a + b);
}
int op_sub(int a, int b)
{
  return (a - b);
}
int op_mul(int a, int b)
{
  return (a * b);
}
int op_div(int a, int b)
{
  return (a / b);
}
int op_mod(int a, int b)
{
  return (a % b);
}

/* get_op_func */
int (*get_op_func(char *s))(int x, int y)
{
  int i = 0;
  int x = x;
  int y = y;
  /* initalize the structure */
  op_t ops[] = {
    {"+", op_add},
    {"-", op_sub},
    {"*", op_mul},
    {"/", op_div},
    {"%", op_mod},
    {NULL, NULL}
    };
  /* array of operations */
  while (ops[i].op != NULL)
  {
    if (strcmp(s, ops[i].op) == 0)
    {
      return (ops[i].f);
    }
    i++;
  }
  printf("Error\n");
  return (NULL);
}
int main(void)
{
  char opx[] = "+";
  int x = 6;
  int y = 4;
  int result;
  op_t oxp;
  
  oxp.f = get_op_func(opx);
  
  if (oxp.f != NULL)
  {
	  result = oxp.f(x,y);
	  printf("%d\n",result);
  }
 /* change the main function */ 
  return 0;
}
