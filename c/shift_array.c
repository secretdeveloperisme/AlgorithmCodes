/*
Write a program to shift an array left or right depends on choice.

Input Format
step-1:- The first element of input consists of number of array elements i.e.., n

step-2:- The second element on-wards ,  input of an array upto n elements.

step-3:- next input is choice for left/right shift operation. [  r --> right  ,  l --> left ]

step-4:- How many time need to shift elements

Constraints
1<= n <=100

0<= A[i] <=1000

Output Format
Print array elements after the task





Example:
Input:-

9

1 3 0 8 12 0 4 0 7

r

4

output:- 0 0 0 0 1 3 0 8 12



Input:-

-5
8 4 4 2  6
l

4

output:- "No of elements are invalid" */

#include <stdio.h>

int main()
{
  int SIZE;
  scanf("%d", &SIZE);
  if (SIZE < 1 || SIZE > 100)
  {
    printf("No of elements are invalid\n");
    return 0;
  }
  int a[100], i;
  for (i = 0; i < SIZE; i++)
  {
    scanf("%d", &a[i]);
  }
  char choice;
  scanf(" %c", &choice);
  int nOR;
  scanf("%d", &nOR);
  while (nOR > 0)
  {
    if (choice == 'r')
    {
      for (i = SIZE - 1; i > 0; i--)
      {
        a[i] = a[i - 1];
      }
      a[0] = 0;
    }
    else if (choice == 'l')
    {
      for (i = 0; i < SIZE - 1; i++)
      {
        a[i] = a[i + 1];
      }
      a[SIZE - 1] = 0;
    }
    nOR--;
  }
  for (i = 0; i < SIZE; i++)
  {
    printf("%d ", a[i]);
  }
}