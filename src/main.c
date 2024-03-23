#include "../include/password.h"
#include "../include/tui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  tui_intro();
  tui_password_properties();
  Password pwd;
  build_password_properties(&pwd);
  generate_password(&pwd);
  return 0;
}
