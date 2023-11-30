#include "simple_shell.h"

/**
 * execute - Executes a command
 * @shell: Shell structure
 * Return: 0 on success, 1 on failure
 */
int execute(t_shell *shell)
{
    pid_t pid;
    int status;

    if (builtin(shell) == 0)
        return (0);
    if (getpath(shell) == 1)
        return (1);
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }
    if (pid == 0)
    {
        if (execve(shell->args[0], shell->args, shell->env) == -1)
            return (1);
    }
    else
        wait(&status);
    return (0);
}