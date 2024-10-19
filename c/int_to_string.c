/* --> Implement a user-defined itoa function.

Notes:

You should take an integer type variable to collect an integer value from the user input. Then convert the input integer number to a string.
You should take a character array and store the converted integer string to that array.
Example:

       Input:    -----Converting to a string------->     Output
       12563    ------------------------------------------->    "12563"
       -2345     ------------------------------------------>     "-2345" */

#include <stdio.h>
#include <stdlib.h>
char to_number_char(unsigned char num)
{
  return num + 48;
}
unsigned int num_len(int number)
{
  if (number >= 0 && number <= 9)
  {
    return 1;
  }
  int count = 0;
  while (number)
  {
    number /= 10;
    count++;
  }
  return count;
}
char *my_itoa(int number)
{
  unsigned int len = num_len(number);
  char *number_str;
  if (number < 0)
  {
    len++;
    number_str = (char *)calloc(sizeof(char), len + 1);
    number_str[0] = '-';
    number = -number;
  }
  else
  {
    number_str = (char *)calloc(sizeof(char), len + 1);
  }
  if (number == 0)
  {
    number_str[0] = '0';
    return number_str;
  }
  unsigned short rem, i = len - 1;
  while (number)
  {
    rem = number % 10;
    number_str[i] = to_number_char(rem);
    number /= 10;
    i--;
  }
  return number_str;
}

int main()
{
  int number;
  scanf("%d", &number);
  char *number_str = my_itoa(number);
  printf("%s", number_str);
  free(number_str);
  return 0;
}