
/* Given a string of lowercase letters in the range ascii[a-z], determine the index of one character that can be removed to make the string a palindrome. There may be more than one solution, but any will do.

If the word is already a palindrome return -1 and if there is no solution, print "can not be a palindrome" . Otherwise, return the index of a character to remove.

Input format
string s: a string to analyze

Return value
The index of the character to remove , if there is a solution

-1 , if it is already a palindrome

print "can not be a palindrome" if no solution. */

#include <stdio.h>
#include <string.h>
int is_lowercase_str(char *str, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (str[i] < 97 || str[i] > 122)
    {
      return 0;
    }
  }
  return 1;
}
int check_palindrome(char *str, int len)
{
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - i - 1])
      return 0;
  }
  return 1;
}

int rm_to_palindrome(char *str, int len, int index)
{
  char cp_str[len];
  // string
  if (index == 0)
  {
    memcpy(cp_str, str + 1, len);
  }
  else if (index == len - 1)
  {
    memcpy(cp_str, str, len - 1);
  }
  else
  {
    memcpy(cp_str, str, index);
    memcpy(cp_str + index, str + index + 1, len - (index + 1));
  }
  return check_palindrome(cp_str, len - 1);
}

int main()
{
  char str[255];
  scanf("%[^\n]s", str);
  int len = strlen(str);
  if (!is_lowercase_str(str, len))
  {
    printf("invalid string\n");
    return -1;
  }
  if (check_palindrome(str, len))
  {
    printf("already a palindrome\n");
    return -1;
  }
  for (int i = 0; i < len; i++)
  {
    if (rm_to_palindrome(str, len, i))
    {
      printf("%d", i);
      return 0;
    }
  }
  printf("can not be a palindrome\n");
}