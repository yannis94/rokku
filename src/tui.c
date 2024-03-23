#include "../include/tui.h"
#include <stdio.h>

void tui_intro() {
  printf("############ ROKKU ############\n");
  printf("rokku or \"lock\" in japanese\n");
  printf("Generate your password now\n");
  printf("###############################\n\n\n");
}

void tui_print_msg(char *msg) { printf("%s\n", msg); }

void tui_main_menu() {
  printf("Choose an option below\n");
  printf("1. password generation\n");
  printf("2. passphrase generation\n");
  printf("3. quit\n");
}

void tui_password_menu() {
  printf("Choose an option below\n");
  printf("1. \n");
  printf("2. passphrase generation\n");
  printf("3. quit\n");
}

int tui_get_user_choice() {
  char line[256];
  int choice;
  tui_print_msg("Choice> ");
  if (fgets(line, sizeof(line), stdin)) {
    if (1 == sscanf(line, "%d", &choice)) {
      return choice;
    }
  }
  return -1;
}
