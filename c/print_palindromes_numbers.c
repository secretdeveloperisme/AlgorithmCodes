
/* Write a c program to print all palindrome numbers in a given range.

Ex1:

input-1:  0        input-2:  30        Output:  0 1 2 3 4 5 6 7 8 9 11 22

Ex2:

input-1:  100    input-2:  300       Output:  101 111 121 131 141 151 161 171 181 191 202 212 222 232 242 252 262 272 282 292 */
#include <stdio.h>

int is_palindrome(int number)
{
  if (number >= 0 && number <= 9)
  {
    return 1;
  }
  int temp = number, reverse_number = 0, rem;
  while (temp)
  {
    rem = temp % 10;
    reverse_number = reverse_number * 10 + rem;
    temp /= 10;
  }
  return number == reverse_number;
}

int main()
{
  int min, max;
  scanf("%d %d", &min, &max);

  if (min < 0 && max < 0)
  {
    printf("both ranges invalid");
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
  for (int i = min; i <= max; i++)
  {
    if (is_palindrome(i))
    {
      printf("%d ", i);
    }
  }
}