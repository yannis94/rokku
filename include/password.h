#ifndef PASSWORD_H
#define PASSWORD_H

typedef struct {
  int letter;
  int spec_char;
  int digit;
} Password;

void generate_password(Password *pwd);
void build_password_properties(Password *pwd);

#endif // !PASSWORD_H
