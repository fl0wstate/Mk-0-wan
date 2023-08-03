#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int _strlen(char *str)
{
    unsigned int len, i = 0;

    len = 0;
    while (*str++)
    {
        len++;
    }
    return len;
}

int number2(char *str)
{
    int i = 0, s = 0, decimal = 0, j = 0, number, position, *digits;
    double iteration = 0;
    /*first make the string into a number*/
    
    if (str == NULL || (str[i] != '1' && str[i] != '0'))
    {
        printf("That's not a binary number\n");
        return 0;
    }

    digits = malloc(_strlen(str) * sizeof(int));
    if (!digits)
    {
        printf("Memory allocation failed");
        exit(98);
    }

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number = str[i] - '0';
            digits[j++] = number;
        }
        else
            break;
        i++;
    }

    for (; s < j; s++)
    {
        decimal = decimal * 2 + digits[s];
       /** 
        *position = digits[s] % 10;
        *digits[s] /= 10;
        *decimal += position * pow(2, iteration);
        *iteration++;
        */
    }
    free(digits);
    return decimal;
}

int number2(char*);
int main(void)
{
    char *str = "234";
    char *ptr = "101";
    char *mtr = "1e01";
    char *gtr = "1100010";
    char *ftr = "0000110010010";
    printf("%s\n", str);
    printf("%d\n", number2(str));
    printf("%d\n", number2(ptr));
    printf("%d\n", number2(mtr));
    printf("%d\n", number2(gtr));
    printf("%d\n", number2(ftr));

    return (0);
}
