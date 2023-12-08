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
        _putstr_fd(shell->env[i], 1);
        _putchar('\n', 1);
        i++;
    }
}
