/*
Write a program to print the product of the digits of a given integer.
For below code add the loop to print the product of the digits of a given integer.
int main()
{
int num,prod=1,rem=0;
scanf(“%d”,&num);
while()
{
// fill the while loop
}
printf(“ %d\n”,prod);
}
 */

#include <stdio.h>

int main()
{
  int num, prod = 1, rem = 0;
  scanf("%d", &num);
  if (num == 0)
  {
    printf("0\n");
    return 0;
  }
  while (num != 0)
  {
    rem = num % 10;
    prod *= rem;
    num /= 10;
  }
  printf("%d\n", prod);
  return 0;
}