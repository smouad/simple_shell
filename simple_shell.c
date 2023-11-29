#include "simple_shell.h"



/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * @env: Environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    (void)env;
    char *line;
    // char **args;
    size_t len = 0;

    line = NULL;
    while (true)
    {
        _putstr("shell~$> ");
        if (getline(&line, &len, stdin) == -1)
        {
            _putstr("\n");
            break;
        }
        if (line[0] == '\n')
            continue;
    }
}