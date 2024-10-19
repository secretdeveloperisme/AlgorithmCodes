/* Write a program to replace all occurrences of sub string in main string with opposite case of every  alphabet.

Example:-

input:-  s1= "thABis is hoanglinh"     ,  s2= "AB"

output:- s1= "thabis is hoanglinh"


input:-  s1= "this is abc hoanglinh"     ,  s2= "abc"

output:- s1= "this is ABC hoanglinh"



input:-  s1= "this is AbC hoanglinh"     ,  s2= "AbC"

output:- s1= "this is aBc hoanglinh"


input:- s1="this is hoanglinh"     ,   s2="program"
output:- "sub string not found"  */
#include <stdio.h>
void convert_case_string(char *, int);
char *my_str_str(char *, char *, int, int);
int compare_character(char, char);
int my_strlen(char *);
int is_uppercase(char);
int is_lowercase(char);
char to_lowercase(char);
char to_uppercase(char);
int main()
{
  char str[255], sub_str[255];
  scanf("%[^\n]s", str);
  // ignore the \n character
  getchar();
  scanf("%[^\n]s", sub_str);
  int len_str = my_strlen(str);
  int len_sub_str = my_strlen(sub_str);
  char *result = my_str_str(str, sub_str, len_str, len_sub_str);
  if (result)
  {
    convert_case_string(result, len_sub_str);
    printf("%s\n", str);
  }
  else
  {
    printf("sub string not found\n");
  }

  return 0;
}
void convert_case_string(char *str, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (is_uppercase(str[i]))
      str[i] = to_lowercase(str[i]);
    else if (is_lowercase(str[i]))
      str[i] = to_uppercase(str[i]);
  }
}
char *my_str_str(char *str, char *sub_str, int n, int m)
{
  int j;
  for (int i = 0; i <= n - m; i++)
  {
    j = 0;
    while (compare_character(str[i + j], sub_str[j]) == 0)
    {
      j++;
    }
    if (j == m)
      return str + i;
  }
  return NULL;
}
int compare_character(char s, char d)
{
  return to_lowercase(s) - to_lowercase(d);
}
int my_strlen(char *str)
{
  int count = 0;
  for (int i = 0; str[i]; i++)
  {
    count++;
  }
  return count;
}
int is_uppercase(char c)
{
  return c >= 65 && c <= 90;
}
int is_lowercase(char c)
{
  return c >= 97 && c <= 122;
}
char to_uppercase(char c)
{
  return is_lowercase(c) ? c - 32 : c;
}
char to_lowercase(char c)
{
  return is_uppercase(c) ? c + 32 : c;
}