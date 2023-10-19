#include "shell.h"
/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.
 *
 * This function creates a child process using `fork()` and attempts to execute
 * the specified command using `execve()`. The parent process waits for the
 * child to complete. If the command is not found or an error occurs, it prints
 * an error message and returns to the shell prompt.
 */
void execute_command(const char *command)
{
	pid_t child_pid = fork();
	char *args[2];
	char *envp[] = { NULL };
	int status;
	int exit_status = WEXITSTATUS(status);

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		args[0] = (char *)command;
		args[1] = NULL;

		if (execve(command, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{
			if (exit_status != 0)
			{
				dom_print("Command execution failed with exit status ");
				dom_print(".\n");
			}
		}
		else if (WIFSIGNALED(status))
		{
			dom_print("Command terminated by signal ");
			dom_print(".\n");
		}
	}
}
