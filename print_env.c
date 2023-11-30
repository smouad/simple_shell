#include "simple_shell.h"

/**
 * print_env - Prints the environment
 * @shell: Shell structure
*/
void print_env(t_shell *shell)
{
    size_t i;

    i = 0;
    while (shell->env[i])
    {
        _putstr(shell->env[i]);
        _putchar('\n');
        i++;
    }
}
