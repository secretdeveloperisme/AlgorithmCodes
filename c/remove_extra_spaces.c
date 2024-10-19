#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int empty_str(char *str, int len)
{
  for (int i = 0; i < len; i++)
  {
    if (str[i] != 32)
      return 0;
  }
  return 1;
}
char *remove_extra_spaces(char *str, int len)
{
  char *cp_str = (char *)calloc(sizeof(char), len + 1);
  int i, j = 0;
  for (i = 0; i < len; i++)
  {
    if (str[i] == 32)
    {
      if ((str[i + 1] == 32) || (j == 0 || i == len - 1))
        continue;
    }
    cp_str[j] = str[i];
    j++;
  }
  return cp_str;
}
int main()
{
  char str[255];
  scanf("%[^\n]s", str);
  int len = strlen(str);
  if (empty_str(str, len))
  {
    printf("empty string\n");
    return -1;
  }
  char *new_str = remove_extra_spaces(str, len);
  int len_new_str = strlen(new_str);
  if (len_new_str == len)
    printf("no extra spaces\n");
  else
    printf("%s\n", new_str);
  free(new_str);
  return 0;
}