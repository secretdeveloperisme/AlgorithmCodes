/* Write a program to print all numbers in the range ,  whose sum of digits is equal to 9 after reducing to single digit.

input                                               output

10   100                                    18 27  36  45  54 63  72  81  90  99

-10 100                                     invalid range

1000 90                                   invalid range
 */

#include <stdio.h>

int sum_of_digits(int number)
{
  unsigned int sum = 0;
  while (number)
  {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int min, max;
  scanf("%d%d", &min, &max);
  if (min < 0 || max < 0)
  {
    printf("invalid range");
    return -1;
  }
  if (min > max)
  {
    printf("invalid range");
    return -1;
  }
  for (int i = min; i <= max; i++)
  {
    int sum = sum_of_digits(i);
    while (sum > 9)
    {
      sum = sum_of_digits(sum);
    }
    if (sum == 9)
    {
      printf("%d ", i);
    }
  }
}