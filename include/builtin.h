#ifndef BUILTIN_H
#define BUILTIN_H

int builtin_cd(char **argv);
int builtin_pwd(void);
int builtin_echo(char **argv);
int builtin_exit(char **argv);

#endif
