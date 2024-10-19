/* write a program to print number of times a given character repeated in a given string.

note: should be case sensitive

Input:                                                                                     Output:

--------                                                                                     ------------

"embedded"   'e'                                                                        3

"linh nguyen hoang"    'n'                                                     4

"linh nguyen hoang"   'X'                                                     not found



"hello     hyderabad"      ' '                                                          5 */

#include <stdio.h>

int main()
{
  char str[255];
  char c;
  int count = 0;
  scanf("%[^\n]s", str);
  // remove the \n character
  scanf("%c", &c);
  scanf("%c", &c);
  for (int i = 0; str[i]; i++)
  {
    if (c == str[i])
    {
      count++;
    }
  }
  if (count > 0)
  {
    printf("%d\n", count);
  }
  else
  {
    printf("not found");
  }
  return 0;
}