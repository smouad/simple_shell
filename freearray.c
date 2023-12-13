#include "simple_shell.h"

/**
 * free_array - Frees an array of strings
 * @array: Array to free
*/

void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;
	while (array[i])
		free(array[i++]);
	free(array);
}
