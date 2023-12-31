#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


void prompt_display(void);
void dom_print(const char *text);
void read_command(char *command, size_t size);
void execute_command(const char *command);
void dom_print_int(int value);

#endif
