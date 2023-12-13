#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  <unistd.h>
#include <stdio.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/wait.h>

extern char **environ;
void freeall(char **arg);
void handle_exit(char **arg, char *cmd);
void _exec(char **args, char *echo, char *cmd, char **av);
void _writechar(char c);
void _writechar1(char c);
void print_no(long num);
void print_no1(long num);
#endif
