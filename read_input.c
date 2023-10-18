#include "shell.h"

/**
 * read_command - Read a command from the user.
 * @command: The buffer to store the command.
 * @size: The size of the buffer.
 *
 * This function reads a command from the standard input (stdin) and stores
 * it in the provided buffer. It handles potential errors during input.
 */
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)

	{
		if (feof(stdin))
		{
			dom_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			dom_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\0';
}

