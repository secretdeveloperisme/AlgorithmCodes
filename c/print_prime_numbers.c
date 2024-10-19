/* Print the prime numbers between MAX to MIN whose last digit(one's place digit) is either 3 or 7.
Below code prints prime numbers between the MAX to MIN.
Modify the code such that it prints only prime numbers between MAX to MIN whose
last digit(one's place digit) is either 3 or 7. */
#include <stdio.h>
#include <math.h>
int main()
{
  int max, min, i, num, flag;
  scanf("%d %d", &min, &max);

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
  for (num = max; num >= min; num--)
  {
    flag = 0;
    for (i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      unsigned char last_digit = num % 10;
      if (last_digit == 3 || last_digit == 7)
        printf("%d \n", num);
    }
  }
}