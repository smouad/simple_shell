#include "simple_shell.h"

/**
 * execute - Executes a command
 * @shell: Shell structure
 * Return: 0 on success, 1 on failure
 */
void execute(t_shell *shell)
{
    pid_t pid;
    int status;

    if (builtin(shell) == 0)
        return ;
    if (getpath(shell) == 1)
    {
        _putstr("./shell: No such file or directory\n");
        return ;
    }
    pid = fork();
    if (pid == 0)
    {
        if (execve(shell->args[0], shell->args, shell->env) == -1)
            return ;
    }
    else
        wait(&status);
    return ;
}
