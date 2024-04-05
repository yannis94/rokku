#include "../include/tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int action;
  tui_intro();
  do {
    tui_main_menu();
    action = tui_get_user_choice("\n>>> ");

    switch (action) {
    case 1:
      tui_password_menu();
      break;
    case 2:
      tui_passphrase_menu();
      break;
    case 3:
      tui_print_msg("Quitting.");
      break;
    default:
      tui_print_msg("Option invalid. Try again\n");
      break;
    }
  } while (action != 3);

  return 0;
}
