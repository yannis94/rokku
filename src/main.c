#include "../include/tui.h"
#include "../include/util.h"
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
      clear_screen();
      tui_password_menu();
      break;
    case 2:
      clear_screen();
      tui_passphrase_menu();
      break;
    case 3:
      clear_screen();
      tui_print_msg("Quitting.");
      break;
    default:
      clear_screen();
      tui_print_msg("Option invalid. Try again\n");
      break;
    }
  } while (action != 3);

  return 0;
}
