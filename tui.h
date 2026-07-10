#ifndef TUI_H
#define TUI_H

#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void draw_path(WINDOW *win);
void draw_time(WINDOW *win,int x,int y);
void draw_status(WINDOW *win,int x,int y);
void draw_chat(WINDOW *win,int x,int y,char *txt);
void draw_input(WINDOW *win,int x,int y,char *txt);
void draw_border(int x,int y,int width,int height);

#endif