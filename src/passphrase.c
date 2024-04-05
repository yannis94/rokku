#include "../include/passphrase.h"
#include "../include/tui.h"
#include "../include/util.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define INIT_CAPACITY 2
#define WORD_MAX_LENGTH 40

void generate_passphrase(Passphrase *passphrase) {
  int total_passphrase_chars = 0;
  char *result = (char *)malloc(sizeof(char *));
  for (int i = 0; i < passphrase->length; i++) {
    int random = get_random_int(passphrase->word_list_length);
    char *word = passphrase->word_list[random];
    char *temp =
        (char *)realloc(result, strlen(result) + strlen(word) * sizeof(char *));
    if (temp == NULL) {
      printf("Memory reallocation failed\n");
      return;
    }
    result = temp;
    int l = strlen(word);
    total_passphrase_chars += l;
    if (i < passphrase->length - 1) {
      word[l] = '-';
    }
    strcat(result, word);
  }
  tui_print_passphrase(result, passphrase->length, total_passphrase_chars);
  free(result);
}

void add_word_in_list(char *word, char ***list, int *size, int *cap) {
  if (*size >= *cap) {
    (*cap) *= 2;
    *list = realloc(*list, *cap * sizeof(char *));

    if (*list == NULL) {
      printf("Memory reallocation failed\n");
      (*size) = -1;
      return;
    }
  }
  (*list)[*size] = malloc(sizeof(char *));
  if ((*list)[*size] == NULL) {
    printf("Memory allocation failed\n");
    (*size) = -1;
    return;
  }
  (*list)[*size] = strdup(word);
  *size = *size + 1;
}

void build_passphrase(Passphrase *passphrase) {
  int fd = open("./words.txt", O_RDONLY);

  if (fd == -1) {
    perror("open");
    return;
  }

  char *line;
  char letter;
  char word[WORD_MAX_LENGTH];
  int capacity = INIT_CAPACITY;
  char **word_list;
  int size = 0;
  ssize_t byte_read;
  ssize_t total_byte_read = 0;
  int l = 0;

  word_list = malloc(capacity * sizeof(char *));

  if (word_list == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  do {
    byte_read = pread(fd, &letter, sizeof(letter), total_byte_read);
    if (byte_read == -1) {
      perror("read");
      close(fd);
      return;
    }
    if (letter != '\n') {
      word[l] = letter;
      l++;
    } else if (letter == '\n') {
      word[l] = '\0';
      l = 0;
      add_word_in_list(word, &word_list, &size, &capacity);
      if (size == -1) {
        printf("Error adding a word in list\n");
        return;
      }
    }
    total_byte_read += byte_read;
  } while (byte_read > 0);
  close(fd);
  passphrase->word_list = word_list;
  passphrase->word_list_length = size;
}

void clear_passphrase(Passphrase *passphrase) {
  for (int i = 0; i < passphrase->word_list_length; i++) {
    free(passphrase->word_list[i]);
  }
  free(passphrase->word_list);
}
