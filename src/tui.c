#include "../include/tui.h"
#include "../include/passphrase.h"
#include "../include/password.h"
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

void tui_password_menu() {
  tui_password_properties();
  Password pwd;
  build_password_properties(&pwd);
  char choice;
  clear_screen();
  generate_password(&pwd);

  while (choice != 'q') {
    choice = tui_get_user_char("g. Gegenerate password\nq. Quit\n\nChoice > ");

    switch (choice) {
    case 'g':
      clear_screen();
      generate_password(&pwd);
      break;
    case 'q':
      tui_print_msg("Thanks, bye.\n");
    default:
      tui_print_msg("This option does not exist. Try again\n");
      break;
    }
  }
}

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

void tui_passphrase_property() {
  clear_screen();
  printf("######## Passphrase properties #######\n");
}

void tui_print_password(char *pwd, int total_chars) {
  int tab_length = 14; // one tab = 7 chars long
  for (int i = 0; i <= total_chars + tab_length; i++) {
    printf("#");
  }
  printf("\n\n\t%s\t\n\n", pwd);
  for (int i = 0; i <= total_chars + tab_length; i++) {
    printf("#");
  }
  printf("\n\n");
}

void tui_print_passphrase(char *pp, int words, int total_chars) {
  int tab_length = 14; // one tab = 7 chars long
  printf("Passphrase generated with %d words\n\n", words);
  for (int i = 0; i <= total_chars + words + tab_length; i++) {
    printf("#");
  }
  printf("\n\n#\t%s\t#\n\n", pp);
  for (int i = 0; i <= total_chars + words + tab_length; i++) {
    printf("#");
  }
  printf("\n\n");
}

void tui_passphrase_menu() {
  tui_passphrase_property();
  Passphrase passphrase;
  build_passphrase(&passphrase);
  char choice;
  passphrase.length = tui_get_user_choice("How many words > ");
  clear_screen();
  generate_passphrase(&passphrase);

  while (choice != 'q') {
    choice = tui_get_user_char("g. Gegenerate password\nq. Quit\n\nChoice > ");

    switch (choice) {
    case 'g':
      clear_screen();
      generate_passphrase(&passphrase);
      break;
    case 'q':
      clear_screen();
      clear_passphrase(&passphrase);
      tui_print_msg("Thanks, bye.\n");
    default:
      tui_print_msg("This option does not exist. Try again\n");
      break;
    }
  }
}
