/* WAP to insert STRING_2 at specific location in STRING_1.
By using user defined STRCPY function.

for example:-
input1:-  s1="program" , s2="XYZ" , n=3.
output1:-  "proXYZgram" ( STRING_1 data )

input2:-  s1="program" , s2="XYZ" , n=9.
output2:- invalid location */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_STR_LEN 255

int empty_string(char *str, int len)
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
int insert_string(char *des, char *src, int index)
{
  int src_len = strlen(src);
  int des_len = strlen(des);
  int i;

  for (i = des_len - 1; i >= index; i--)
  {
    des[i + src_len] = des[i];
  }
  for (i = 0; i < src_len; i++)
  {
    des[i + index] = src[i];
  }
  return 1;
}

int main()
{
  int index;
  char *des = (char *)calloc(sizeof(char), DEFAULT_STR_LEN);
  if (des == NULL)
  {
    printf("can not allocate memory\n");
    return -1;
  }
  char src[DEFAULT_STR_LEN];
  scanf("%[^\n]s", des);
  getchar();
  scanf("%[^\n]s", src);
  scanf("%d", &index);
  int des_len = strlen(des);
  if (empty_string(des, des_len))
  {
    printf("empty string\n");
    return -1;
  }
  if (index < 0 || index > des_len)
  {
    printf("invalid location\n");
    free(des);
    return -1;
  }
  insert_string(des, src, index);
  printf("%s\n", des);
  free(des);
  return 0;
}