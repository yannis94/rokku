#include "tui.h"
#include <stdio.h>

void tui_intro() {
  printf("######## ROKKU ########\n");
  printf("rokku or \"lock\" in japanese\n");
  printf("Generate your password now\n");
}

void tui_print_msg(char *msg) { printf("%s\n", msg); }
