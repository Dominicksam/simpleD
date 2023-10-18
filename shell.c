#include "shell.h"
#include <stdbool.h>

/**
 * main - The entry point of the program.
 *
 * This function contains the main loop for your shell. It repeatedly
 * displays a prompt, reads a command, and executes it.
 *
 * Return: 0 on success.
 */
int main(void)
{
    char command[150];

    while (true)
    {
        prompt_display();
        read_command(command, sizeof(command));
        execute_command(command);
    }

    return 0; 
}

/**
 * prompt_display - Display the shell prompt.
 *
 * This function displays the prompt for the shell, typically indicating
 * that the user can input a command.
 */
void prompt_display(void)
{
    dom_print("Domnick_shell$ ");
}

