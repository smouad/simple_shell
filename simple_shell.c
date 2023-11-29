#include "simple_shell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}


/**
 * _putstr - Prints a string
 * @str: String to print
 * Return: Number of characters printed
 */
int _putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return (i);
}


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