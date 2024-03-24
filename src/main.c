#include "../include/password.h"
#include "../include/tui.h"
#include "../include/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  tui_intro();
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
      return 0;
    default:
      tui_print_msg("This option does not exist. Try again\n");
      break;
    }
  }
  return 0;
}
