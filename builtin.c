#include "simple_shell.h"



/**
 * builtin - Checks if a command is a builtin
 * @shell: Shell structure
 * Return: 0 on success, 1 on failure
*/
int builtin(t_shell *shell)
{
    if (_strcmp(shell->args[0], "exit") == 0)
        exit(0);
    if (_strcmp(shell->args[0], "env") == 0)
    {
        print_env();
        return (0);
    }
    return (1);
}
