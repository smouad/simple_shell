#include "simple_shell.h"

/**
 * init_shell - Initializes the shell
 * @shell: Shell structure
 * @argv: Arguments
 * @env: Environment variables
 */
void init_shell(t_shell *shell, char **argv, char **env)
{
	shell->argv = argv;
	shell->env = env;
	shell->line = NULL;
	shell->args = NULL;
}

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * @env: Environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	t_shell shell;
	size_t len = 0;

	init_shell(&shell, argv, env);
	while (true)
	{
		if (isatty(STDIN_FILENO))
			_putstr_fd("shell~$> ", 1);
		free(shell.line);
		if (getline(&shell.line, &len, stdin) == -1)
		{
			free(shell.line);
			break;
		}
		if (shell.line[0] == '\n')
			continue;
		cut_line(shell.line);
		shell.args = _split(shell.line, " \t\n");
		execute(&shell);
		free_array(shell.args);
	}
	return (0);
}
