#include <stdio.h>
#include <stdbool.h>

bool countChar(char * filename, int * counts, int size)
{
  FILE * fid;
  fid = fopen(filename, "r");

  // open a file whose name is filename for reading
  if (fid == NULL)
  {
    printf("Come on you guys, there it is right there in front of you the whole time. You're dereferencing a null pointer! Open your eyes!");
    return false;
  }

  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file

  int onechar;
  while((onechar = fgetc(fid)) != EOF)
  {
    if (onechar >= 0 && onechar <= size - 1)
    {
      counts[onechar] += 1;
    }
  }
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  fclose(fid);
  //remove(filename);
  
  return true;
}


void printCounts(int * counts, int size)
{
  int ind;
  int onechar;

  for(ind = 0; ind <= size - 1; ind++)
  {
    if (counts[ind] != 0)
    {
      onechar = ((ind >= 65 && ind <= 90 )|| (ind >= 97 && ind <= 122)) ? ind : 32;
      printf("%d, %c, %d\n", ind, onechar, counts[ind]);
    }
  }
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
