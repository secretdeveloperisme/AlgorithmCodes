
/*
find second highest digit in given number


examples:-

input                                                  output

--------                                                ---------

12345                                                     4

12321                                                     2

99999                                                 all digits are same

6                                                          you have supplied single digit olny

-59216                                                     6
#include<stdio.h>
*/
int main(int argc, char *argv[])
{
  int number;
  scanf("%d", &number);
  if (number < 0)
  {
    number = -number;
  }
  if (number >= 0 && number <= 9)
  {
    printf("you have supplied single digit only");
    return 0;
  }
  int temp_num = number;
  int highest_num = -1, second_highest = -1;
  int digit;
  while (temp_num != 0)
  {
    digit = temp_num % 10;
    if (digit > highest_num)
    {
      second_highest = highest_num;
      highest_num = digit;
    }
    if (digit > second_highest && digit < highest_num)
    {
      second_highest = digit;
    }
    temp_num = temp_num / 10;
  }
  if (second_highest == -1)
  {
    printf("all digits are same");
  }
  else
  {
    printf("%d", second_highest);
  }
  return 0;
}