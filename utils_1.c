#include "simple_shell.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 * @fd: File descriptor
 * Return: 1 on success, -1 on error
 */
int _putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _putstr_fd - Prints a string
 * @str: String to print
 * @fd: File descriptor
 * Return: Number of characters printed
 */
void _putstr_fd(char *str, int fd)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i], fd);
		i++;
	}
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
