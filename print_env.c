#include "simple_shell.h"

/**
 * print_env - Prints the environment
 * @shell: Shell structure
*/
void print_env(void)
{
    size_t i;
    char **env = environ;

    i = 0;
    while (env[i])
    {
        _putstr_fd(env[i], 1);
        _putchar('\n', 1);
        i++;
    }
}
