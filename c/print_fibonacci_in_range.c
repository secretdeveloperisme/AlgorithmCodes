/* WAP to print Fibonacci series in the range by following integer sequence.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation

Fn = Fn-1 + Fn-2

with seed values

F0= 0 and F1 = 1

Examples:

Input: min = 5 , max=100

Output: 5 8 13 21 34 55 89



Input: min = -5 , max=100

Output: min range is invalid



Input: min = 5 , max=-1000

Output: max range is invalid



Input: min = -5 , max=-100

Output: both inputs invalid */

#include <stdio.h>
void print_fibonacci(int min, int max)
{
  int next = 1, current = 1, previous = 0, temp;
  while (previous <= max)
  {
    if (previous >= min)
    {
      printf("%d ", previous);
    }
    previous = current;
    current = next;
    next = current + previous;
  }
}

int main()
{
  int min, max;
  scanf("%d %d", &min, &max);
  if (min < 0 && max < 0)
  {
    printf("both inputs invalid");
    return -1;
  }
  if (min < 0)
  {
    printf("min range is invalid");
    return -1;
  }
  if (max < 0)
  {
    printf("max range is invalid");
    return -1;
  }
  if (min > max)
  {
    printf("invalid range");
    return -1;
  }
  print_fibonacci(min, max);
  return 0;
}