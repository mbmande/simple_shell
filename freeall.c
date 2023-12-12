#include "main.h"
/**
 * freeall - ====
 * @arg: =====
 */
void freeall(char **arg)
{
	int i = 0;

	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

