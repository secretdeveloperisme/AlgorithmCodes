/* Input:                                                                       Output:

---------                                                                     ------------

"racecar drivers enjoy radar."                                      2

"madam, in Eden, I am bob."                                       3

"elle is a teacher, as I am."                                          3

 "linh    nguyen    hoang"                                       no palindromes in the given string

"             "                                                                 empty string

 */

#include <stdio.h>
#include <string.h>

#define WORD_DELIMITER " ,."

int empty_string(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    if (str[i] != 32)
    {
      return 0;
    }
  }
  return 1;
}

int is_palindrome(char *str)
{
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++)
  {
    if (str[i] != str[len - i - 1])
      return 0;
  }
  return 1;
}
int count_palindromes(char *str)
{
}

int main()
{
  char str[255];
  scanf("%[^\n]s", str);
  if (empty_string(str))
  {
    printf("empty string\n");
    return -1;
  }
  char *token = strtok(str, WORD_DELIMITER);
  int count = 0;
  while (token != NULL)
  {
    if (is_palindrome(token))
      count++;
    token = strtok(NULL, WORD_DELIMITER);
  }
  if (count != 0)
  {
    printf("%d\n", count);
  }
  else
  {
    printf("no palindromes in the given string\n");
  }

  return 0;
}
