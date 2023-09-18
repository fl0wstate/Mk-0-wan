#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct format_specifier
{
    char form;
    void (*call)(va_list *);
} format_x;

void _char_arg(va_list *ap)
{
    char c;

    c = va_arg(*ap, int);
    printf("%c", c);
}

void _int_arg(va_list *ap)
{
    int i;

    i = va_arg(*ap, int);
    printf("%d", i);
}

void _float_arg(va_list *ap)
{
    float f;

    f = va_arg(*ap, double);
    printf("%f", f);
}

void _string_arg(va_list *ap)
{
    char *s;

    s = va_arg(*ap, char *);

    /* check for empty strings */
    if (!s || *s == '\0')
        s = "(nil)";

    printf("%s", s);
}



int _printf(const char *format, ...)
{
  va_list ap;
  int index_arr_no, i = 0, len = strlen(format);
  format_x data[] = {
    {'c', _char_arg},
    {'i', _int_arg},
    {'s', _string_arg},
    {'f', _float_arg},
    {0, NULL}
  };
  
  if (!format)
    return (1);
  
  va_start(ap, format);
  
  while (format && i < len)
  {
    if (format[i] == '%')
    {
      index_arr_no = 0;
      if (format[i + 1] == '%')
      {
        putchar('%');
      }
      else
      {
        i++; /* move to the next char */
        while (data[index_arr_no].form)
        {
          if (format[i] == data[index_arr_no].form)
          {
            data[index_arr_no].call(&ap);
            break;
          }
          index_arr_no++;
        }
        if (!data[index_arr_no].form)
        {
            printf("Invalid format specifier");
        }
      }
    }
    else
      putchar(format[i]);
    i++;
  }
  va_end(ap);
  putchar('\n');
  return (len);
}
    




int main() {

  _printf("%c, %i, %s, %f", 'c', 32, "Hello", 32.3232);
  return 0;
}
