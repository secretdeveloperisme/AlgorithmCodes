/*
write a program to convert  first and last char's to upper case in all words  in given string

note:- all elements must contain alphabets only

examples:-

input                                          output

------                                          ---------

abc kmv rgrD                             AbC KmV RgrD

34 KNkjkKA fefk                      ERROR

HOANG LINH                        HOANG LINH
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_character(char c)
{
  return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
int is_lowercase(char c)
{
  return c >= 97 && c <= 122;
}
int is_uppercase(char c)
{
  return c >= 65 && c <= 90;
}
char to_uppercase(char c)
{
  return is_lowercase(c) ? c - 32 : c;
}
char to_lowercase(char c)
{
  return is_uppercase(c) ? c + 32 : c;
}
int empty_string(char *str, int len)
{
  if (len == 0)
  {
    return 1;
  }
  for (int i = 0; i < len; i++)
  {
    if (str[i] != 32)
    {
      return 0;
    }
  }
  return 1;
}
char *convert_first_and_last_char(char *str, int len)
{
  char *new_str = (char *)calloc(sizeof(char), len + 1);
  strcpy(new_str, str);

  for (int i = 0; i < len; i++)
  {
    if (!is_character(str[i]) && str[i] != 32)
    {
      return NULL;
    }
    if (i == 0 || i == len - 1)
    {
      new_str[i] = to_uppercase(new_str[i]);
    }
    else if (str[i + 1] == 32 || str[i - 1] == 32)
    {
      new_str[i] = to_uppercase(new_str[i]);
    }
  }
  return new_str;
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
  char *new_str = convert_first_and_last_char(str, len);
  if (new_str != NULL)
  {
    printf("%s\n", new_str);
    free(new_str);
  }
  else
  {
    printf("ERROR\n");
  }

  return 0;
}