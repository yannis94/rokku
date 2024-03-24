#ifndef TUI_H
#define TUI_H

void tui_intro();
void tui_print_msg(char *msg);
void tui_main_menu();
void tui_password_menu();
void tui_password_properties();
int tui_get_user_choice(char *question);
char tui_get_user_char(char *question);

#endif // !TUI_H
