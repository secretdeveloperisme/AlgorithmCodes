/* Problem Statement

  Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.



Example 1:
Input: [2, 1, 5, 1, 3, 2], k=3
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].
Example 2:
Input: [2, 3, 4, 1, 5], k=2
Output: 7
Explanation: Subarray with maximum sum is [3, 4].
Input Format

step-1:- The first element of input consists of number of array elements i.e.., n

step-2:- The second element on-wards ,  input of an array upto n elements.

step-3:- Next input is size/no.of elements of sub array i.e.., k

step-4:- Find maximum sum of sub array in main array

Constraints
1<= n <=100

0<= A[i] <=1000



Output Format
Print sum-of that sub array */

#include <stdio.h>
void max_sum_of_sub_array(int *arr, int n, int k)
{
  int i, j;
  int max_index = -1;
  unsigned int sum, max_sum = 0;
  for (i = 0; i <= n - k; i++)
  {
    sum = 0;
    for (j = 0; j < k; j++)
    {
      sum += arr[i + j];
    }
    if (max_sum < sum)
    {
      max_sum = sum;
      max_index = i;
    }
  }
  printf("%d\n", max_sum);
}
int main(int argc, char const *argv[])
{
  int n, k;
  scanf("%d", &n);
  if (n > 100)
  {
    printf("Memory Overflow\n");
    return -1;
  }
  if (n < 1 || n > 100)
  {
    printf("invalid main array size\n");
    return -1;
  }
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", arr + i);
  }
  scanf("%d", &k);
  if (k > n)
  {
    printf("invalid sub array size\n");
    return -1;
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0 || arr[i] > 1000)
    {
      printf("invalid element: %d\n", arr[i]);
      return -1;
    }
  }
  max_sum_of_sub_array(arr, n, k);
  return 0;
}
