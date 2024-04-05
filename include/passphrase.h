#ifndef PASSPHRASE_H
#define PASSPHRASE_H

typedef struct {
  int length;
  char **word_list;
  int word_list_length;
} Passphrase;

void generate_passphrase(Passphrase *passphrase);
void build_passphrase(Passphrase *passphrase);
void clear_passphrase(Passphrase *passphrase);
void tui_print_passphrase(char *pp, int words, int total_chars);

#endif // !PASSPHRASE_H
