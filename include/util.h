#ifndef UTIL_H
#define UTIL_H

int get_random_int(int max);
void shuffle_string(char *str);
void clear_screen();
int append_str_in_arr(char **arr, int *arr_len, int current_idx, char *str);

#endif // !UTIL_H
