#include "simple_shell.h"

/**
 * _getenv - Gets an environment variable
 * @name: Name of the variable
 * @env: Environment
 * Return: Pointer to the variable, NULL if not found
*/
char *_getenv(const char *name, char **env)
{
    char *var, *value;
    size_t i, j;

    i = 0;
    while (env[i])
    {
        j = 0;
        var = env[i];
        while (var[j] && var[j] != '=')
            j++;
        if (var[j] != '=')
            return (NULL);
        value = var + j + 1;
        var = _substr(var, 0, j);
        if (_strcmp(var, name) == 0)
        {
            free(var);
            return (value);
        }
        free(var);
        i++;
    }
    return (NULL);
}

/**
 * command_exists - Checks if a command exists
 * @cmd: Command to check
 * Return: 0 on success, 1 on failure
*/
int command_exists(char *cmd)
{
    if (access(cmd, X_OK) == 0)
        return (0);
    return (1);
}

/**
 * is_path - Checks if a command is a path
 * @cmd: Command to check
 * Return: 0 on success, 1 on failure
*/
int is_path(char *cmd)
{
    if (cmd[0] == '/' || cmd[0] == '.')
        return (0);
    return (1);
}

/**
 * getpath - Gets the path of a command
 * @shell: Shell structure
 * Return: 0 on success, 1 on failure
*/
int getpath(t_shell *shell)
{
    char *path, **token, *tmp;
    int i = 0;

    if (is_path(shell->args[0]) == 0)
    {
        if (command_exists(shell->args[0]) == 0)
            return (0);
        return (1);
    }
    path = _getenv("PATH", shell->env);
    if (!path)
        return (1);
    token = _split(path, ':');
    while (token[i])
    {
        tmp = _strjoin(token[i], "/");
        tmp = _strjoin(tmp, shell->args[0]);
        if (command_exists(tmp) == 0)
        {
            shell->args[0] = tmp;
            return (0);
        }
        free(tmp);
        i++;
    }
    return (1);
}
