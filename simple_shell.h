#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

/* structure */

typedef struct s_shell
{
char **argv;
char **env;
char *line;
char **args;
}   t_shell;


/* prototypes */

int _putchar(char c);
int _putstr(char *str);
void cut_line(char *line);

#endif /* SIMPLE_SHELL_H */