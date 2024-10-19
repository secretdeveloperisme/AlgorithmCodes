/*
Input Format
The first element of input consists of number of array elements i.e.., n

The second element on-wards ,  input of an array.




Constraints
1<= n <=100

0<= A[i] <=1000

Output Format
Return the array after performing the task

Example:

Input:                                                          output:

--------                                                         ----------

9   1 3 0 8 12 0 4 0 7                                   1 3 8 12 4 7 0 0 0
-5  8 4 4 2  6                                               invalid size

0   9 4                                                          invalid size

1   0 1 8 3 4  6 7                                            Memory Overflow */
#include <stdio.h>
void place_all_zero_to_the_end(int *arr, int n)
{
  int temp_arr[n], i, j = 0;
  for (i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      temp_arr[j++] = arr[i];
    }
  }
  while (j < n)
  {
    temp_arr[j++] = 0;
  }
  for (i = 0; i < n; i++)
  {
    printf("%d ", temp_arr[i]);
  }
}
int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  if (n > 100)
  {
    printf("Memory Overflow");
    return -1;
  }
  if (n < 1 || n > 100)
  {
    printf("invalid size");
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
  place_all_zero_to_the_end(arr, n);
  return 0;
}