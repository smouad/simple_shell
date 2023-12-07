#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
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

int     _putchar(char c);
int     _putstr(char *str);
void    cut_line(char *line);
size_t  _strlen(const char *s);
char    *_substr(char const *s, unsigned int start, size_t len);
char    **_split(char const *s, char c);
void    init_shell(t_shell *shell, char **argv, char **env);
int     _strncmp(const char *s1, const char *s2, size_t n);
int     _strcmp(const char *s1, const char *s2);
char    *_getenv(const char *name, char **env);
void    execute(t_shell *shell);
char    *_strjoin(char const *s1, char const *s2);
int     command_exists(char *cmd);
int     is_path(char *cmd);
int     getpath(t_shell *shell);
void    print_env(t_shell *shell);
int     builtin(t_shell *shell);

#endif
