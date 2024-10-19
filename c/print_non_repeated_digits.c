/* Write a program to print non-repeated digits in a number.

example:

Input:                                                 Output:

--------                                               -----------

1223                                                  3 1

 233                                                    2

3443                                                  no non-repeated numbers

 55248                                                8 4 2

 0                                                        0

-12254                                               4 5 1 */
#include <stdio.h>

void print_non_repeated_digits(int number)
{
  int temp = number, temp1, rem, count, amount = 0;
  while (temp)
  {
    count = 0;
    rem = temp % 10;
    temp1 = number;
    while (temp1)
    {
      if (temp1 % 10 == rem)
      {
        count++;
      }
      temp1 = temp1 / 10;
    }
    if (count == 1)
    {
      printf("%d ", rem);
      amount++;
    }
    temp = temp / 10;
  }
  if (amount == 0)
  {
    printf("no non-repeated numbers\n");
  }
}
int main()
{
  int number;
  scanf("%d", &number);
  if (number < 0)
    number = -number;
  if (number >= 0 && number <= 9)
  {
    printf("%d", number);
    return 0;
  }
  print_non_repeated_digits(number);
  return 0;
}