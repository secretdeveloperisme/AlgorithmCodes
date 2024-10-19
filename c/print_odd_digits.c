/* Write a program to print the odd digits in a given integer.
Below code prints the digits of a given integer.
Modify the code such that it prints only odd digits of  an integer.  */
#include <stdio.h>

int main()
{
  int num, rem = 0, has_odd = 0;
  scanf("%d", &num);
  if (num < 0)
  {
    num = -num;
  }
  if (num == 0)
  {
    printf("you have supplied zero\n");
    return 0;
  }
  while (num)
  {
    rem = num % 10;
    if (rem % 2 != 0)
    {
      printf("%d ", rem);
      has_odd = 1;
    }
    num /= 10;
  }
  if (!has_odd)
  {
    printf("no odd digits\n");
  }
  return 0;
}