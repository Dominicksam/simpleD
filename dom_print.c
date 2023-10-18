#include "shell.h"

/**
 * dom_print - Prints a string to the standard output.
 * @text: The string to be printed.
 *
 * This function writes the specified string to the standard output.
 * It uses the `write` system call to do so.
 *
 * Return: None (void).
 */


void dom_print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}

