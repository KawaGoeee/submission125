#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

int concat_ints(int n1, int n2) {
  int digit=0;
  int zeros=1;

  int num1 = n1;// local
  int num2 = n2;// local
  // printf("num1: %d\nnum2: %d\n", num1, num2);

  int count = num2;// local

  // count digits of second number
  while(count!=0) {
    count = count / 10;
    ++digit;
  }

  // shift value of num1 "count" digits to left
  for(int i=0; i<digit; i++) {
    zeros *= 10;
  }

  // add shifted num1 and num2
  int res = num1*zeros + num2;

  return res;
}

void upper2lowercase(char* c) {
  char ch = *c;
  // printf("%c\n", ch);
  // printf("%c\n", *c);

  if(ch>=65 && ch<=90) {// A-Z: 65-90 by ASCII code
    ch = ch+32;// a-z: 97-122 by ASCII
    *c = ch;
  }
}

void left_rotate(char* str, unsigned int n) {
  if(n) {
    for(int j=0; j<n; j++) {

      // count the length of array
      int index=0;
      while(*(str+index) != '\0') {
        index++;
      }
      // index = (length of array)-1

      // create pointer for iterating in the programme
      char* ptr = str;

      // copy first element in array
      char copy = *ptr;

      // shift every elemnt up to last element from '\0'
      for(int i=0; i<index-1; i++) {
        *(ptr+i) = *(ptr + i+1);
      }
      // put copied element in last position
      *(ptr + index-1) = copy;

    }
  }
}

bool contains_equal_columns(int height, int width, const int array[height][width]) {
  bool res;
  int count=0;// increment when a column is same

  // interation[i]: width(column)
  for(int i=0; i<width; i++) {
    // iteration[k]: column to compare with column[i]
    for(int k=i+1; k<width; k++) {
      // iteration[j]: height(row)
      for(int j=0; j<height; j++) {
        // compare element in column[i] and column[k]
        if(array[j][i] != array[j][k]) {
          break;
        }
        if(j==height-1) {
          count++;
        }
      }
    }
  }
  // if no column is the same, res=false
  if(count==0) {
    res = false;
  }else {
    res = true;
  }
  return res;
}

char* str_compute_sum(const char* num1, const char* num2) {
  
  int index1=0, index2=0, addup=0;
  int len, len1, len2, lenBigger, lenSmaller;

  char* sum;

  // count the length of array1
  while(*(num1+index1) != '\0') {
    index1++;
  }
  len1 = index1+1;

  // count the length of array2
  while(*(num2+index2) != '\0') {
    index2++;
  }
  len2 = index2+1;

  // set variables for bigger array and smaller array
  if(len1>=len2) {
    lenBigger = len1;
    lenSmaller = len2;
  }else {
    lenBigger = len2;
    lenSmaller = len1;
  }


  // reserve memory enough for array of length bigger array
  len=lenBigger+1;
  sum = malloc(sizeof(char)*len);
  *sum = '0';
  *(sum+len-1) = '\0';
  char intBigger, intSmaller;
  char elementSum;


  // add elements starting from end of both arrays
  for(int i=0; i<len-1; i++) {

    if(i==len-2) {
      if(addup==1) {
        *sum = '1';
      }else {
        *sum = '0';
      }
      // printf("*sum = %c\n", *sum);

    }else if(i>=lenSmaller-1) {

      if(len1>=len2) {
        intBigger = *( num1+(lenBigger-2)-i);
      }else {
        intBigger = *( num2+(lenBigger-2)-i);
      }
      intSmaller = '0' - 48;
      // printf("[%d] %c+%d  +%d\n", len-2-i, intBigger, intSmaller, addup);


      elementSum = intBigger + intSmaller + addup;
      // printf("elementSum:%d\n", elementSum);

      if(elementSum>'9') {
        *( sum+(len-2)-(i) ) = elementSum - 10;
        addup=1;
      }else {
        *( sum+(len-2)-(i) ) = elementSum;
        addup=0;
      }

    }else {
      if(len1>=len2) {
        intBigger = *( num1+(lenBigger-2)-i);
        intSmaller = *(num2+(lenSmaller-2)-i) - 48;
      }else {
        intBigger = *( num2+(lenBigger-2)-i);
        intSmaller = *(num1+(lenSmaller-2)-i) - 48;
      }
      // printf("[%d] %c+%d  +%d\n", len-2-i, intBigger, intSmaller, addup);


      elementSum = intBigger + intSmaller + addup;
      // printf("elementSum:%d\n", elementSum);

      if(elementSum>'9') {
        *( sum+(len-2)-i ) = elementSum - 10;
        addup=1;
      }else {
        *( sum+(len-2)-i ) = elementSum;
        addup=0;
      }
      
    }
  }
  
  
  // if 0 remains in first element, shift element
  if(*sum=='0') {
    for(int i=0; i<len-1; i++) {
      sum[i] = sum[i+1];
    }
    sum = realloc(sum, sizeof(char) * (len-1));
  }

  return sum;
}