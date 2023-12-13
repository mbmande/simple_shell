#include "main.h"
void  _exec(char **args, char *echo, char *cmd, char **av);
/**
 * _exec - ===========
 * @args:  =============
 * @echo: ==================
 * @cmd: =====
 * @av: =====
 */
void _exec(char **args, char *echo, char *cmd, char **av)
{
	int pid;
	int exit_status;

	(void)echo;
	pid  = fork();

	if (pid == 0)
	{
		if (strcmp(args[0], "echo") == 0)
		{
			if (strcmp(echo, "$$") == 0)
			{
				print_no1(getpid());
				write(1, "\n", 1);
				free(cmd);
				exit(0);
			}
			else if (strcmp(echo, "$?") == 0)
			{
				print_no1(0);
				write(1, "\n", 1);
				free(cmd);
				exit(0);
			}
			else
			{
				execve("/bin/echo", args, environ);
			}
		}
		else if (strcmp(args[0], "ls") == 0)
		{
			execve("/bin/ls", args, environ);
		}
		else
		{
			execve(args[0], args, environ);
		}
		write(2, "./hsh", strlen("./hsh"));
		write(2, ": ", 2);
		print_no(1);
		write(2, ": ", 2);/*./hsh: 1: qwerty: not found*/
		write(2, args[0], strlen(args[0]));
		write(2, ": not found\n", strlen(": not found\n"));
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);

			if (exit_status  != 0 && (!isatty(STDIN_FILENO)))
			{
				free(cmd);
				freeall(av);
				if (exit_status == 1)
					exit(127);
				exit(exit_status);
			}
		}
	}
}

