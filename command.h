#ifndef COMMAND_H
#define COMMAND_H

#include <string.h>
#include <stdio.h>
#include <ncurses.h>

void choose(WINDOW *win,char *lcmd);
int read_command(char *path);


#endif