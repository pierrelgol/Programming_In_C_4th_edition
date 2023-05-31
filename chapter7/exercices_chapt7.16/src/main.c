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

int convertedNumber[64];
long int numberToConvert;
int base;
int digit = 0;

void getNumberAndBase(void) {
  HERE :
  base = 0;
  printf("Number to be converted? ");
  scanf("%li", &numberToConvert);
  printf("Base? ");
  scanf("%i", &base);
  if (base < 2 || base > 16) {
    if (base == 0){
     exit(0); 
    }else{
      printf("Bad base - must be between 2 and 16\n");
      base = 10;
      goto HERE;
    }
  }
}

void convertNumber(void) {
  do {
    convertedNumber[digit] = numberToConvert % base;
    ++digit;
    numberToConvert /= base;
  } while (numberToConvert != 0);
}

void displayConvertedNumber(void) {
  const char baseDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                               '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  int nextDigit;
  printf("Converted number = ");
  for (--digit; digit >= 0; --digit) {
    nextDigit = convertedNumber[digit];
    printf("%c", baseDigits[nextDigit]);
  }
  printf("\n");
}

int main(void) {
  void getNumberAndBase(void), convertNumber(void),displayConvertedNumber(void);
  while(1){
    getNumberAndBase();
    convertNumber();
    displayConvertedNumber();
  }
  return 0;
}
