#include "simple_shell.h"

/**
 * execute - Executes a command
 * @shell: Shell structure
 * Return: 0 on success, 1 on failure
 */
void execute(t_shell *shell)
{
	pid_t pid;

	if (builtin(shell) == 0)
		return ;
	if (getpath(shell) == 1)
	{
		_putstr_fd("./hsh: 1: ", 2);
		_putstr_fd(shell->args[0], 2);
		_putstr_fd(": not found\n", 2);
		shell->status = 127;
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(shell->args[0], shell->args, shell->env) == -1)
		{
			return ;
		}
	}
	else
		wait(&shell->status);
	return ;
}
