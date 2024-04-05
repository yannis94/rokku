#include "../include/util.h"
#include <stdio.h>
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

void clear_screen() { system("clear"); }

int append_str_in_arr(char **arr, int *arr_len, int current_idx, char *str) {
  if (current_idx == *arr_len) {
    *arr_len *= 2;

    char **temp = (char **)realloc(arr, *arr_len * sizeof(char *));

    if (temp == NULL) {
      printf("Memory reallocation failed.\n");
      return 1;
    }

    arr = temp;
  }

  arr[current_idx] = str;
  return 0;
}
