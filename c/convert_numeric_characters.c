/* Write a program to convert all numeric characters to a word from a given string.



Example:

Input: Hello 24India                       Output: Hello TwoFourIndia

Input: Programming practice         Output: Numeric character not found.

Input: Virtual34 Prog56ramming    Output: VirtualThreeFour ProgFiveSixramming */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *numeric_chars_arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
int numeric_char_lens[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int empty_string(char *str, int len)
{
  if (len == 0)
  {
    return 1;
  }
  for (int i = 0; i < len; i++)
  {
    if (str[i] != 32)
      return 0;
  }
  return 1;
}
int is_number(char c)
{
  return c >= 48 && c <= 57;
}
unsigned char to_digit(char c)
{
  return c - 48;
}
unsigned int calculate_length_numbers(char *str, unsigned int len)
{
  unsigned int num_len = 0;
  unsigned char digit;
  for (int i = 0; i < len; i++)
  {
    if (is_number(str[i]))
    {
      digit = to_digit(str[i]);
      num_len += numeric_char_lens[digit] - 1;
    }
  }
  return num_len;
}
char *convert_numeric_characters(char *str, int len, unsigned int num_len)
{
  char *new_str = (char *)calloc(sizeof(char), len + num_len + 1);
  for (int i = 0, j = 0; i < len; i++)
  {
    if (is_number(str[i]))
    {
      unsigned char digit = to_digit(str[i]);
      memcpy(new_str + j, numeric_chars_arr[digit], numeric_char_lens[digit]);
      j += numeric_char_lens[digit];
    }
    else
    {
      new_str[j] = str[i];
      j++;
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
  unsigned int num_len = calculate_length_numbers(str, len);
  if (num_len == 0)
  {
    printf("Numeric character not found.\n");
    return -1;
  }
  char *new_str = convert_numeric_characters(str, len, num_len);
  printf("%s\n", new_str);
  free(new_str);
  return 0;
}
