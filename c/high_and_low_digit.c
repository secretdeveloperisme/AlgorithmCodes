/*
write a program to find the highest and lowest digit in a given integer.


               input                                                            output

-----------------------------------------------------------------------------------------------------------------------------

1. input:98431                                                            highest=9

                                                                        lowest=1

2.   input : 678301                                                      highest=8

                                                                         lowest=0
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
  int number;
  scanf("%d", &number);
  int temp_num = number;
  int highest_num = -1, lowest_num = 10;
  int digit;
  while (temp_num != 0)
  {
    digit = temp_num % 10;
    if (digit > highest_num)
      highest_num = digit;
    if (digit < lowest_num)
      lowest_num = digit;
    temp_num = temp_num / 10;
  }
  if (highest_num == lowest_num)
  {
    printf("all digits are same\n");
  }
  else
  {
    printf("highest=%d\n", highest_num);
    printf("lowest=%d", lowest_num);
  }
}