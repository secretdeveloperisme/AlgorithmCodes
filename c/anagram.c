/* verify two given strings are anagrams or not.

Example:

Input1:                                 Input2:                                       Input3:

silent                                         Cat                                                  cat

listen                                         Act                                                  act

Output: Anagram string.         Output: Not an anagram string.     Output: Anagram string.
 */
#include <stdio.h>
#include <string.h>
#define NUM_OF_CHARS 256
int main()
{
  int num_of_char_arr0[NUM_OF_CHARS] = {0};
  int num_of_char_arr1[NUM_OF_CHARS] = {0};
  char str0[255], str1[255];
  scanf("%s", str0);
  scanf("%s", str1);
  unsigned int len0 = strlen(str0), len1 = strlen(str1);
  if (len0 != len1)
  {
    printf("Not an anagram strings\n");
    return 0;
  }
  for (int i = 0; i < len0; i++)
  {
    num_of_char_arr0[str0[i]]++;
    num_of_char_arr1[str1[i]]++;
  }
  int is_anagram = 1;
  for (int i = 0; i < NUM_OF_CHARS; i++)
  {
    if (num_of_char_arr0[i] != num_of_char_arr1[i])
    {
      is_anagram = 0;
      break;
    }
  }
  if (is_anagram)
  {
    printf("Anagram strings\n");
  }
  else
  {
    printf("Not an anagram strings\n");
  }
  return 0;
}