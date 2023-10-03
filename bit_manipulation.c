#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define CHAR_BIT 8
#define Swap(a, b) (((a) == (b)) || (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))))
#define Swap2(a, b) (((a) ^ (b)) && ((b) ^= (a) ^= (b), (a) ^= (b)))

int _binary_arg(unsigned int n);
int binTodec(unsigned int binary);
unsigned int _flip_bits(unsigned int a, unsigned int b);
void print_binary(unsigned int digit);
char *create_special_heap(int num, bool sign);
int main()
{
  int v = +21;
  int y = 0;
  int h = 5;
  int z = 64;
  int x = -2;
  // Checks whether the value passed is a negative integer
  y = -(int)((unsigned int)((int)v) >> (sizeof(int) * 8 - 1));
  
  printf("y is %d\n", (y < 0) ? -1 : 1);
  
  //gets the least significant bit
  printf("LSB -> %d\n", x >> 1);
  //gets the most significant bit which represents the signed value of an int
  printf("MSB -> %d\n", x >> 31);
  // two results will come out of this line either (0 if int is positive) (-1 if int is negative)
  // does the same thing but not portable
  
  y = (v != 0) | (v >> (sizeof(int) * 8 - 1));
  
  printf("(Modified output)[ -1(-1), 0(0), 1(+1)] :: y -> %d\n", y);
  
  // Compute the absolute value of a value without branching
  unsigned int result;
  int const mask = x >> (sizeof(int) * CHAR_BIT - 1); // checks if the bit is negative or positive
  
  result = (x + mask) ^ mask;
  // or
  result = (x ^ mask) - mask;
  
  printf("Abs(x)-> %d\n", result);
  // for positive number it will still repeat the same value.
  int const mask1 = z >> (sizeof(int) * CHAR_BIT - 1);
  result = (z + mask1) ^ mask1;
  printf("Abs(z)-> %d\n", result);
  
  
  // detect two integers have opposite signs
  bool f = ((z ^ x) < 0 );
  printf("1(true):: 0(false) -> %d\n", f);
  
  // Getting the maximum and minimum value
  result = 0;
  result = z ^ ((z ^ h) & -(h < z));
  printf("Min -> %d\n", result);
  
  result = h ^ ((z ^ h) & -(h < z));
  printf("Max -> %d\n", result);
  //Same as (x < h)
  result = h ^ ((z ^ h) & -(h ^ z ^ h));
  
  printf("Max -> %d\n", result);
  //Getting deeper
  result = z + ((h - z) & ((h - z) >> (sizeof(int) * CHAR_BIT - 1)));
  printf("Min -> %d\n", result);
  
   result = h - ((h - z) & ((h - z) >> (sizeof(int) * CHAR_BIT - 1)));
  printf("Max -> %d\n", result);
  
  //Is divisible by 2
  //first compare the values by itself if true then it is divisible
  f = v && !(z & (z - 1));
  printf("1(true) :: 0(false) -> [%d]\n", f);
  
  //Counting bits
  v = 5;
  while (v)
  {
    v &= v - 1;
    _binary_arg(v);
    y++;
  }
  printf("n_bits -> %d\n", y);
  
  //Swapping between two related values
  char arr[3] = "YW";
  char arr2[3] = "AB";
  
  Swap(arr[0], arr[1]);
  Swap2(arr2[0], arr2[1]);
  
  printf("arr -> %s\n", arr);
  printf("arr2 -> %s\n", arr2);

  //Reversing the bits the obvious way
  // h is the input bit to be reversed.
  h = 3;
  int s = sizeof(h) * CHAR_BIT - 1; // extra shift needed
  unsigned int r = 0;
  r = h; // r will be reversed bit of v; first get the LSB of v
  _binary_arg(h);
  _binary_arg(s);
  for (h >>= 1; h; h >>= 1)
  {
    r <<= 1;
    r |= h & 1;
    s--;
  }
  r <<= s; // shift when v's highest bit are zero
  int b = _binary_arg(r);
  printf("reversed bit -> %d\n", b);
  // lets test out all this functions
  int ret = binTodec(s);
  printf("decimal val -> %d\n", ret);
  
  print_binary(3);
  print_binary(2);
  print_binary(10);
  print_binary(31);
  print_binary(98);
  
  int j = 98 & (1 << 1);
  print_binary (j);
  
  printf("Bits to flip -> %d\n", _flip_bits(3, 2));
  printf("Bits to flip -> %d\n", _flip_bits(10, 42));
  printf("Bits to flip -> %d\n", _flip_bits(3, 12));
  printf("Bits to flip -> %d\n", _flip_bits(100, 33));
  printf("Bits to flip -> %d\n", _flip_bits(23, 32));
  printf("The end\n");
    return 0;
}

//Now playing with bits
//function that transforms binary to bits
// steps first get the list significant bit grap it and store it in a variable
// truncate the last bit.
// call another function which will be used to store the actual value after r * ( 2 ^ [position]);
// keep on repeating until the value of the binary no is zero

int binTodec(unsigned int binary)
{
	unsigned int rp = 0;
	unsigned int dec = 0;
	unsigned int pos = 0;

	while (binary != 0)
	{
		rp = binary % 10;
		binary /= 10;

		dec += rp * pow( 2, pos);
		pos++;
	}
	return (dec);
}

// bit shifting and use of mask value.
void print_binary(unsigned int digit)
{
	unsigned int mask = 1 << (sizeof(int) * CHAR_BIT - 1); // same as 31;

	//remove all the trailing 0
	while ((digit & mask) == 0)
		mask = mask >> 1;

	while (mask != 0)
	{
		if (digit & mask) // found the first match of a non-zero value
		{
			putchar('1');
		}
		else
			putchar('0');
		//or 
		//write(STDOUT_FILENO, ((digit & mask) == 0) ? "1" : "0", 1);
		mask >>= 1;
	}
	printf("\n");
}

unsigned int _flip_bits(unsigned int a, unsigned int b)
{
	//we need a mask which will be shifting from the left
	//Get the xor of the two digits which will toggle the bits found matching
	//As you shift through each bit you will see the ones which are matching and count the number.
	unsigned int bits_to_flip;
	unsigned int x0r_val = (a ^ b); // toggle all matching bits.

	while (x0r_val > 0)
	{
		bits_to_flip += (x0r_val & 1);
		x0r_val = x0r_val >> 1; // right shift by one bit the same as dividing or also getting the LSB
	}
	return (bits_to_flip);
}
int _binary_arg(unsigned int num)
{

    unsigned int temp = 0;
    char *binary;
    int len = 0, i = 0, n_bytes = 0;
    bool is_negative = false;

    if (num == 0)
        return (write(1, "0", 1));
    if (num < 0)
    {
        num = -num;
        is_negative = true;
    }
    temp = num;
    while (temp > 0)
    {
        temp /= 2;
        len++;
    }
    binary = create_special_heap(len, is_negative);
    while (num > 0)
    {
        binary[i++] = num % 2 + '0';
        num /= 2;
    }
    if (is_negative)
        binary[i++] = '1';
    binary[i] = '\0';
    while (i > 0)
    {
        i--;
        write(STDOUT_FILENO, &binary[i], 1);
        n_bytes++;
    }
    write(STDOUT_FILENO, "\n", 1);
    free(binary);
    return (n_bytes);
}

char *create_special_heap(int num, bool sign)
{
    char *s;

    s = malloc(sizeof(char) * (num + ((sign) ? 1 : 0) + 1));
    if (!s)
    {
        puts("Memory allocation failed");
        return (NULL);
    }
    return (s);
}
