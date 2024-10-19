/*
Write a program to print repeated elements in an integer array. Array size must contain 20 elements size.
Note:- First data in input represents the number of elements and then remaining elements are the inputs
to the array.


ex:-

--------

input                                              output

-------                                            ----------

5     1 2 3 4 5                              no repeated elements

10   2 2 2 3 4 5 2 5 6 2                     2 5

11   -2 -1 0 -1 9 5 3 2 6 8 -2            -2 -1

-3     2 3 5                                    invalid size

0       0                                           invalid size
 */
#include <stdio.h>

int array_contain(int *arr, int n, int target)
{
  if (n == 0)
    return 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == target)
      return 1;
  }
  return 0;
}
void print_repeated_element(int *arr, int n)
{
  int count, k = 0;
  int non_repeated_arr[n];
  for (int i = 0; i < n; i++)
  {
    count = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    if (count > 1)
    {
      if (!array_contain(non_repeated_arr, k + 1, arr[i]))
      {
        non_repeated_arr[k++] = arr[i];
      }
    }
  }
  if (k == 0)
  {
    printf("no repeated elements");
  }
  else
  {
    for (int i = 0; i < k; i++)
    {
      printf("%d ", non_repeated_arr[i]);
    }
  }
}
int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("invalid size");
    return -1;
  }
  if (n == 1)
  {
    printf("no repeated elements");
    return 0;
  }
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", arr + i);
  }
  char c;
  if (scanf("%c", &c))
  {
    if (c != '\n')
    {
      if (scanf("%c", &c))
      {
        if (c != '\n')
        {
          printf("Memory Overflow");
          return -1;
        }
      }
    }
  }
  print_repeated_element(arr, n);
  return 0;
}
