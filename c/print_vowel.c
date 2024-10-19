/* Write a program to print a word which is start with vowel and end with vowel in a given string.

input                                                                               output

-------------------------------------------------------------------------------------------

india is my country                                                            india

back to india once                                                          india once

i m using my brain once                                                  i once

all the best                                                                     not found */
#include <stdio.h>
#include <string.h>

#define NUM_OF_VOWELS 10

char vowels[NUM_OF_VOWELS] = {'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I'};
int check_empty_string(char *str, int len)
{
  if (len == 0)
    return 1;
  for (int i = 0; i < len; i++)
  {
    if (str[i] != 32)
      return 0;
  }
  return 1;
}
int is_vowel(char c)
{
  for (int i = 0; i < NUM_OF_VOWELS; i++)
  {
    if (vowels[i] == c)
    {
      return 1;
    }
  }
  return 0;
}
int check_start_end_vowel(char *word)
{
  int len = strlen(word);
  if (is_vowel(word[0]) && is_vowel(word[len - 1]))
  {
    return 1;
  }
  return 0;
}
void print_vowel_word(char *str)
{
  const char *delimiters = " ";
  char *token = strtok(str, delimiters);
  int count = 0;
  while (token != NULL)
  {
    if (check_start_end_vowel(token))
    {
      printf("%s ", token);
      count++;
    }
    token = strtok(NULL, delimiters);
  }
  if (count == 0)
  {
    printf("there is no words to print\n");
  }
}
int main()
{
  char str[255] = {0};
  scanf("%[^\n]s", str);
  int len = strlen(str);
  if (check_empty_string(str, len))
  {
    printf("empty string\n");
    return -1;
  }
  print_vowel_word(str);
  return 0;
}