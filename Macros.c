#include <stdio.h>
/* simple algorithm for switching between two given ints */
#define Swap_(x, y) x ^= y; y ^= x; x ^= y;
/* advanced but more useful */
#define SWAP_ADV(x,y) while(0) {x^=y; y^=x; x^=y;}
#define CLAMP(a, x, b) ((x) < (a)) ? (a) :\
	((b) < (x)) ? (b) : (x)
/**
 * more detailed version of a advanced macro -- several operations are applied here
 * Bit manipulation using inclusive OR thrice which will allow us to fully switch the binary values of the two given param.
 * A do while loop this will make sure that the operation will be repeated more than once to ensure that all the values being compared are done upto the end.
 * ----Another macro function----
 *  Clamp math function which will always make sure that the value passed does not suppass the range of value given. Only return the value if its is within range given.
 *  If value is less than the range return the minimum value.
 *  If value is greater than the range given return the maximum value.
 */
#define PPrint(Token) printf(#Token " value is [%s]\n", Token);

/* How to use the powerof macros this gives us the actual name of the macros and their values and has an inside function from another macro */
#define Debugg(x,y) do{\
    SWAP2(x,y);\
    printf(#x " value is [%d] " #y " value is [%d] swapped\n", x , y);\
} while(0);

/* another way to play with swapp algorithm */
#define SWAP2(x, y) do {\
    typeof(x) _temp = (x);\
    (x) = (y);\
    (y) = _temp;\
}while (0);
#define ASSERT(cond) if( !(cond) )\
{printf( "assertion error line::%d, file::%s\n", \
__LINE__, __FILE__ );}
/* Added some more macro information i found on the web */
#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))
#define CSTR_(cstr_) (ARRAY_LEN(cstr_)-1) /* remove the null terminator */
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

int main(void)
{
    int a = 32;
    int b = 23;
    int x = 77;
    char *swap = "ab";
    char *Parent = "Child";
   
    printf("Len of array is : %d\n", ARRAY_LEN(Parent));
    printf("String len is : %d\n",CSTR_(Parent));
    PPrint(Parent);
    Debugg(a, b);
    printf("clampped value is : %d\n", CLAMP(a, x, b));
    Swap_(a,b);
    printf("%d swapped %d\n" , a, b);
    

    if (a < 0)
    {
        SWAP_ADV(a,b);    
        printf("%d (a,b) %d", a, b);
	/* After swapping values of a & b */
    	printf("clampped value is : %d\n", CLAMP(a, x, b));
    }
    else
    {
        SWAP_ADV(a,x);
        printf("%d (a,x) %d\n", a, x);
	ASSERT(a < 0);
	DEBUG("Somthing went wrong over here %d\n", a);
	/* After swapping values of a & x */
    	printf("clampped value is : %d\n", CLAMP(a, x, b));
    }
    return 0;
}
