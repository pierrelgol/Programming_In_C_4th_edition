/*
 *
 *   Title of project :
 *   Date of creation :
 *   Author(s) : PierreLgol
 *   github : https://github.com/pierrelgol
 *
 *   More on the project :
 *
 *   #TODO(s) :
 *
 *
 */

//--------------------[     DEPENDENCIES DECLARATION     ]--------------------//

#include <stdio.h>
#include <stdlib.h>

//--------------------[     MAIN METHOD     ]--------------------------------//

// Program to copy one file to another
int main(void) {
  char inName[64], outName[64];
  FILE *in, *out;
  int c;
  // get file names from user
  printf("Enter name of file to be copied: ");
  scanf("%63s", inName);
  printf("Enter name of output file: ");
  scanf("%63s", outName);
  // open input and output files
  if ((in = fopen(inName, "r")) == NULL) {
    printf("Can't open %s for reading.\n", inName);
    return 1;
  }
  if ((out = fopen(outName, "w")) == NULL) {
    printf("Can't open %s for writing.\n", outName);
    return 2;
  }
  // copy in to out
  while ((c = getc(in)) != EOF)
    putc(c, out);
  // Close open files
  fclose(in);
  fclose(out);
  printf("File has been copied.\n");
  return 0;
}
