#include "../include/util.h"
#include <stdlib.h>
#include <string.h>

int get_random_int(int max) { return rand() % (max + 1); }

void shuffle_string(char *str) {
  int max = strlen(str) - 1;

  for (int i = 0; i < strlen(str); i++) {
    int r = get_random_int(max);
    char temp = str[i];
    str[i] = str[r];
    str[r] = temp;
  }
}
