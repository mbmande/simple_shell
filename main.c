#include "main.h"
int main(int argc, char **argv);
/**
 * main - =====
 * @argc: ======
 * @argv: ======
 * Return: =====
 */
int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	size_t  buf;
	char *line = NULL;
	int byte = 0;
	char *token = NULL;
	char **c20;

	(void)argc;
	(void)argv;

	while (1)
	{
		c20 =  malloc(sizeof(char *) * 100);
		i = 0;
		while (i < 100)
		{
			c20[i] = NULL;
			i++;
		}
		i = 0;
		if (isatty(STDIN_FILENO) == 1)
			write(1, "# ", 2);

		byte =  getline(&line, &buf, stdin);
		if (byte == -1)
		{
			freeall(c20);
			free(line);
			break;
		}
		if (strlen(line) > 3500)
		{
			if (strchr(line, '/') != NULL)
			{
				strcpy(line, "ls\n\0");
			}
		}
		j = 0;
		token = strtok(line, " \n\t\r");
		while (token != NULL)
		{
			if (token[0] == '#')
			{
				c20[j] = NULL;
				break;
			}
			c20[j] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(c20[j], token);
			j++;
			token = strtok(NULL, " \n\t\r");
		}
		c20[j] = NULL;

		if (c20[0] == NULL)
		{
			freeall(c20);
			continue;

		}
		if (strcmp(c20[0], "exit") == 0)
		{
			if (c20[1] == NULL)
			{
				freeall(c20);
				free(line);
				exit(0);
			}
			else
			{
				handle_exit(c20, line);
			}
		}

		if (strcmp(c20[0], "env") == 0)
		{
			while (environ[i])
			{

				write(1, environ[i], strlen(environ[i]));
				write(1, "\n", 1);
				i++;
			}
			freeall(c20);
			continue;
		}
		if (strcmp(c20[0], "echo") == 0)
		{
			_exec(c20, "echo", line, c20);
		}
		else
		{
			_exec(c20, "None", line, c20);
		}

		freeall(c20);
	}
	return (0);

}
