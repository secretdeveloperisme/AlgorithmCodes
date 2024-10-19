/* Write a program to check given string is palindrome or not.



ex:-

------

input           output

--------       ---------

madam           palindrome

noon              palindrome

kill                 not palindrome
*/
#include <stdio.h>
#include <string.h>
int main()
{
  char str[255];

  scanf("%s", str);
  int is_palindrome = 1;
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - i - 1])
    {
      is_palindrome = 0;
      break;
    }
  }
  if (is_palindrome)
  {
    printf("palindrome\n");
  }
  else
  {
    printf("not palindrome\n");
  }
  return 0;
}