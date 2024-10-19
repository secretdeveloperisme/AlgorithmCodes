/*
Convert all lower case chars into upper case and vice versa

examples:-

input                                      output

------                                      ---------

"linh"                                    LINH

"12ve NZl$"                              12 VE nzL$

"      "                                          ERROR
 */

#include <stdio.h>
#include <string.h>
int is_upper_character(char);
int is_lower_charater(char);
char to_uppercase(char);
char to_lowercase(char);

int main()
{
  char str[255];
  scanf("%[^\n]s", str);
  unsigned int len = strlen(str), space_count = 0;
  for (int i = 0; i < len; i++)
  {
    if (is_upper_character(str[i]))
    {
      str[i] = to_lowercase(str[i]);
    }
    else if (is_lower_charater(str[i]))
    {
      str[i] = to_uppercase(str[i]);
    }
    else if (str[i] == ' ')
    {
      space_count++;
    }
  }
  if (space_count == len)
  {
    printf("ERROR\n");
    return -1;
  }
  else
  {
    printf("%s\n", str);
  }
  return 0;
}

int is_upper_character(char c)
{
  return (c >= 65 && c <= 90);
}
int is_lower_charater(char c)
{
  return (c > 97 && c <= 122);
}
char to_uppercase(char c)
{
  return c - 32;
}
char to_lowercase(char c)
{
  return c + 32;
}