#ifndef INPUT_H
#define INPUT_H

typedef struct Msg
{
    char txt[100];
    int len;
}Msg;
#include<ncurses.h>

void input(WINDOW *win);

#endif