#include "../include/tui.h"
#include "../include/util.h"
#include <stdio.h>

void tui_intro() {
  printf("############ ROKKU ############\n");
  printf("rokku or \"lock\" in japanese\n");
  printf("Generate your password now\n");
  printf("###############################\n\n\n");
}

void tui_print_msg(char *msg) { printf("%s", msg); }

void tui_main_menu() {
  printf("Choose an option below\n");
  printf("1. password generation\n");
  printf("2. passphrase generation\n");
  printf("3. quit\n");
}

void tui_password_menu() { printf("Build your new password\n"); }

int tui_get_user_choice(char *question) {
  char line[256];
  int choice;
  tui_print_msg(question);
  if (fgets(line, sizeof(line), stdin)) {
    if (1 == sscanf(line, "%d", &choice)) {
      return choice;
    }
    printf("Incorrect, it should be a digit.\nTry again\n\n");
  }
  return -1;
}

char tui_get_user_char(char *question) {
  char line[256];
  char input;
  tui_print_msg(question);
  scanf(" %c", &input);
  return input;
}

void tui_password_properties() {
  clear_screen();
  printf("######## Password properties #######\n");
}
