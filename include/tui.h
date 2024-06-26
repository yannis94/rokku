#ifndef TUI_H
#define TUI_H

void tui_intro();
void tui_print_msg(char *msg);
void tui_print_password(char *pwd, int total_chars);
void tui_print_passphrase(char *pp, int words, int total_chars);
void tui_main_menu();
void tui_password_menu();
void tui_password_properties();
void tui_passphrase_menu();
void tui_passphrase_property();
int tui_get_user_choice(char *question);
char tui_get_user_char(char *question);

#endif // !TUI_H
