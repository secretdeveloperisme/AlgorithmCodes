/* Write a program to check whether the user input is  integer or float data type.

note:- read input in string format

Example:

input: 82          Output: Integer number

input: 80.83    Output: Floating number

input: 8&0.83    Output: invalid input
 */

#include <stdio.h>
#include <string.h>

#define DOT_CHAR_NUMBER 46

int is_number(char);
int check_number_type(char *);
int main()
{
  char number_str[255];
  scanf("%[^\n]s", number_str);
  switch (check_number_type(number_str))
  {
  case 0:
    printf("Integer number\n");
    break;
  case 1:
    printf("Float number\n");
    break;
  default:
    printf("invalid input\n");
  }
  return 0;
}
int is_number(char c)
{
  return c >= 48 && c <= 57;
}

int check_number_type(char *number_str)
{
  int len, dot_count = 0;
  len = strlen(number_str);
  if (number_str[0] == DOT_CHAR_NUMBER || number_str[len - 1] == DOT_CHAR_NUMBER)
  {
    return -1;
  }
  for (int i = 0; i < len; i++)
  {
    if (number_str[i] == DOT_CHAR_NUMBER)
      dot_count++;
    else if (!is_number(number_str[i]))
    {
      return -1;
    }
  }
  if (dot_count == 1)
    return 1;
  else if (dot_count > 1)
    return -1;
  else
    return 0;
}