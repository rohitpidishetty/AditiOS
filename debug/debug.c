#include <stdio.h>
#include <stdlib.h>

const char* append(const char **a, const char *b) {
  const char *a_ptr = *a;
  const char *b_ptr = b;
  int len = 0;

  while(*a_ptr) {
    (a_ptr)++;
    len++;
  }

  while(*b_ptr) {
    (b_ptr)++;
    len++;
  }

  char *temp =  malloc(sizeof(char) * (len+1));

  if (temp == NULL) return '\0';
  
  char *temp_ptr = temp;

    
  while(**a) {
    *temp_ptr++ = (**a);
    (*a)++;
  }

  while(*b) {
    *temp_ptr++ = (*b);
    (b)++;
  }

  *temp_ptr = '\0';

  return temp;
}


void main(void) {
  const char *content = "data payload\0";
  const char *new = append(&content, " extend\n");
  printf("%s", new);
   
}
