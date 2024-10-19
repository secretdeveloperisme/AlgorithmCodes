/*
Write a program to reverse all occurrences of sub string in main string



Example:-

input:-  s1= "this is hoanglinh"     ,  s2= "is"

output:- s1= "thsi si hoanglinh"





input:- s1="this is hoanglinh"     ,   s2="program"

output:- "sub string not found"

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *reverse_string(char *str, int len)
{
  char temp;
  char *cp_str = (char *)malloc(len + 1);
  strcpy(cp_str, str);
  if (len == 1)
    return cp_str;
  for (int i = 0; i < len / 2; i++)
  {
    temp = cp_str[i];
    cp_str[i] = cp_str[len - i - 1];
    cp_str[len - i - 1] = temp;
  }
  return cp_str;
}
char *my_str_str(char *str, char *sub_str, int n, int m)
{
  int j;
  for (int i = 0; i <= n - m; i++)
  {
    j = 0;
    while (str[i + j] == sub_str[j])
    {
      j++;
    }
    if (j >= m)
      return str + i;
  }
  return NULL;
}
void replace_reverse_str(char *str, char *sub_str)
{
  int len_str = strlen(str);
  int len_sub_str = strlen(sub_str);
  char *reverse_sub_str = reverse_string(sub_str, len_sub_str);
  char *p_sub_str = my_str_str(str, sub_str, len_str, len_sub_str);
  if (p_sub_str == NULL)
  {
    printf("sub string not found\n");
    return;
  }
  while (p_sub_str)
  {
    memmove(p_sub_str, reverse_sub_str, len_sub_str);
    p_sub_str = my_str_str(p_sub_str + len_sub_str, sub_str, len_str, len_sub_str);
  }
  printf("%s\n", str);

  free(reverse_sub_str);
}
int main()
{
  char str[255];
  char sub_str[255];

  scanf("%[^\n]s", str);
  getchar();
  scanf("%[^\n]s", sub_str);
  replace_reverse_str(str, sub_str);
  return 0;
}