#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/**
 * execute_command - Execute a shell command with arguments and PATH handling.
 * @command: The command to be executed.
 *
 * This function creates a child process using `fork()` and attempts to execute
 * the specified command with PATH handling using `execve()`. The parent process
 * waits for  child to complete. If the command doesn't exist, it prints an
 * error message. If  command is a built-in (e.g., exit or env), it's handled
 * within the shell.
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();
	char *args[150];
	char *token = strtok((char *)command, " ");
	int arg_count = 0;
	char **env = environ;


if (child_pid == -1)
{
	dom_print("Error while forking process.\n");
	exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (*env != NULL)
		{
			dom_print(*env);
			dom_print("\n");
			env++;
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (access(args[0], X_OK) == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			dom_print("Command not found.\n");
			exit(EXIT_FAILURE);
		}
	}
}
else
{
	wait(NULL);
}
}
