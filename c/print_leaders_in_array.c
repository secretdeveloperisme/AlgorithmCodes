/*
Write a program to print all the LEADERS in the int array. An element is a leader if it is greater than all the elements to its right side and the rightmost element is always a leader.

For example int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.



Example:

Input: 6

16 17 4 3 5 2



Output:

17 5 2
 */
#include <stdio.h>

void print_leaders_of_array(int *arr, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        break;
      }
    }
    if (j == n)
    {
      printf("%d ", arr[i]);
    }
  }
}
int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  if (n > 100)
  {
    printf("Memory Overflow\n");
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
  print_leaders_of_array(arr, n);
  return 0;
}