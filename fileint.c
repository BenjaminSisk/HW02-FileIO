#include <stdio.h>
#include <stdbool.h>

bool addFile(char * filename, int * sum)
{
  FILE * fid;
  * sum = 0;
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  fid = fopen(filename, "r");
  // open a file whose name is filename for reading
  if (fid == NULL)
  {
    printf("Come on you guys, there it is right there in front of you the whole time. You're dereferencing a null pointer! Open your eyes!");
    return false;
  }
  // if fopen fails, return false. Do NOT fclose
  int temp;
  int total;
  int error;

  total = 0;
  temp = 0;
  error = 0;

  while((error = fscanf(fid, "%d\n", &temp)) != EOF)
  {
    total += temp;
  }

  *sum = total;
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  fclose(fid);
  return true;
}

bool writeSum(char * filename, int sum)
{
  FILE * fid;
  // open a file whose name is filename for writing
  fid = fopen(filename, "w");
  if (fid == NULL)
  {
    printf("Come on you guys, there it is right there in front of you the whole time. You're dereferencing a null pointer! Open your eyes!");
    return false;
  }
  fprintf(fid, "%d\n", sum);

  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  fclose(fid);
  return true;
}