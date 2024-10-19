
/* Write a program to print non-repeated elements in a array.
int arr[size]; -----> 20<= size <=50.
Note:first element in the input shown represents no.of elements and rest of the elements are input data

examples:-
input                                                                   output
------                                                                   ---------
0     5                                                                     invalid size
-3   2 5 7                                                                invalid size
5    1 2 3 4 5                                                          1 2 3 4 5
5    5 3 4 6 7 9 0                                                     Memory Overflow
6    8 2 4 8 7 9                                                        2 4 7 9
3    9 9 9                                                                 no non-repeated elements */
#include <stdio.h>
void print_non_repeated_element(int *arr, int n)
{
  int count, is_repeated = 0;
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
    if (count == 1)
    {
      printf("%d ", arr[i]);
      is_repeated = 1;
    }
  }
  if (!is_repeated)
  {
    printf("no non-repeated elements");
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
  if (n > 50)
  {
    printf("Memory Overflow");
    return -1;
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
      scanf("%c", &c);
      if (c != '\n')
      {
        printf("Memory Overflow");
        return -1;
      }
    }
  }
  print_non_repeated_element(arr, n);
  return 0;
}