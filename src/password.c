#include "../include/password.h"
#include "../include/tui.h"
#include "../include/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_password(Password *pwd) {
  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  char spec_chars[] = "!@#$%^*()_-+={}[]:;\"'|\\<>,.?/";
  char digits[] = "1234567890";

  int pwd_length = pwd->letter + pwd->spec_char + pwd->digit;
  char *result = (char *)malloc(sizeof(char) * pwd_length);

  if (result == NULL) {
    printf("Memory allocation failed.\nQuitting program.");
    return;
  }

  printf("Password generation with %d letter(s), %d digit(s) and %d special "
         "character(s)...\n\n",
         pwd->letter, pwd->digit, pwd->spec_char);

  int char_counter = 0;

  for (int i = 0; i < pwd->letter; i++) {
    int max = strlen(letters) - 1;
    int random_index = get_random_int(max);
    result[char_counter] = letters[random_index];
    char_counter++;
  }

  for (int i = 0; i < pwd->spec_char; i++) {
    int max = strlen(spec_chars) - 1;
    int random_index = get_random_int(max);
    result[char_counter] = spec_chars[random_index];
    char_counter++;
  }

  for (int i = 0; i < pwd->digit; i++) {
    int max = strlen(digits) - 1;
    int random_index = get_random_int(max);
    result[char_counter] = digits[random_index];
    char_counter++;
  }

  result[char_counter] = '\0';

  shuffle_string(result);
  printf("\n\nYour password > %s\n", result);
  free(result);
}

void build_password_properties(Password *pwd) {
  int letter, spec_char, digit;

  do {
    letter = tui_get_user_choice("How many letter > ");
  } while (letter < 0);

  do {
    digit = tui_get_user_choice("How many digit > ");
  } while (digit < 0);

  do {
    spec_char = tui_get_user_choice("How many special character > ");
  } while (spec_char < 0);

  pwd->letter = letter;
  pwd->spec_char = spec_char;
  pwd->digit = digit;
}
