/*
Write  a program to implement user defined function of atoi

Ex:-

input=12345

output=12345"



input=12a45

output=invalid



input=1234.5

output=invalid

Web service */

#include <stdio.h>
#include <string.h>

char to_number(char c)
{
  return c - '0';
}
int is_numeric(char c)
{
  return c >= 48 && c <= 57;
}
void my_atoi(char *number_str, int len)
{
  int is_number = 1, i = 0, is_negative = 0;
  int number = 0;
  if (number_str[0] == '-')
  {
    i = 1;
    is_negative = 1;
  }
  for (; i < len; i++)
  {
    if (is_numeric(number_str[i]))
    {
      number = number * 10 + to_number(number_str[i]);
    }
    else
    {
      is_number = 0;
      break;
    }
  }
  if (is_number)
  {
    if (is_negative)
      number = -number;
    printf("%d\n", number);
  }
  else
    printf("invalid\n");
}

int main()
{
  char number_str[255];
  scanf("%[^\n]s", number_str);
  int len = strlen(number_str);
  my_atoi(number_str, len);

  return 0;
}