#include "simple_shell.h"

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
 * _strlen - Computes the length of a string
 * @s: String to compute length of
 * Return: Length of string
 */
size_t _strlen(const char *s)
{
    size_t len = 0;

    while (s[len])
        len++;
    return (len);
}

/**
 * cut_line - Cuts a line when a # is found
 * @line: Line to cut
*/
void cut_line(char *line)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] == '#' || line[i] == '\n')
        {
            line[i] = '\0';
            break;
        }
        i++;
    }
}
