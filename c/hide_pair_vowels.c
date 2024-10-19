/* write a program to hide the pair of vowels in given string.

Note:- No case-sensitive

examples:-

input                                               output

-------                                               --------

hoang linh                                       h**ng linh

linh plus                                   there is no pair of vowels to hide

ind has bEen developing                 ind has b**n developing

for me its okay                                there is no pair of vowels to hide   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_OF_VOWELS 10

int vowels[NUM_OF_VOWELS] = {'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I'};
int is_vowel(char c)
{
  for (int i = 0; i < NUM_OF_VOWELS; i++)
  {
    if (vowels[i] == c)
      return 1;
  }
  return 0;
}
char *hide_pair_of_vowels(char *str, int len)
{
  char star_char = '*';
  char *new_str = (char *)calloc(sizeof(char), len + 1);
  memcpy(new_str, str, len);
  int count = 0, i;
  for (int i = 0; i < len - 1; i++)
  {
    if (is_vowel(new_str[i]) && is_vowel(str[i + 1]))
    {
      new_str[i] = star_char;
      new_str[i + 1] = star_char;
      count++;
      i++;
    }
  }
  return count ? new_str : NULL;
}
int empty_string(char *str, int len)
{
  if (len == 0)
    return 1;
  for (int i = 0; i < len; i++)
  {
    if (str[i] != 32)
    {
      return 0;
    }
  }
  return 1;
}
int is_character(char c)
{
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
int is_valid_input(char *str, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (!is_character(str[i]) && (str[i] != 32))
      return 0;
  }
  return 1;
}
int main()
{
  char str[255] = {0};
  scanf("%[^\n]s", str);
  int len = strlen(str);
  if (empty_string(str, len))
  {
    printf("empty string\n");
    return -1;
  }
  if (!is_valid_input(str, len))
  {
    printf("invalid input\n");
    return -1;
  }
  char *new_str = hide_pair_of_vowels(str, len);
  if (new_str)
  {
    printf("%s\n", new_str);
    free(new_str);
  }
  else
    printf("there is no pair of vovels to hide\n");
  return 0;
}