#include "tui.h"

extern char His[10][100];
extern int a;
int cur_x=1;
void draw_time(WINDOW *win,int x,int y)
{
    int h,n,s;
    time_t t;
    t=time(NULL);
    struct tm *ptm;
    ptm = localtime(&t);
    h = ptm->tm_hour;
    n = ptm->tm_min;
    s = ptm->tm_sec;

    mvwprintw(win,x,y,"%2d:%2d:%2d",h,n,s);
}

void draw_path(WINDOW *win)
{
    char path[100];
    char result[100]="~";
    char *p;
    getcwd (path, sizeof(path));
    char home[]="home";
    p=strstr(path,home);
    strcat(result,p+4);
    mvwprintw(win,1,1,result);
}

void draw_status(WINDOW *win,int x,int y)
{
    attron(COLOR_PAIR(1));
    draw_path(win);
    attroff(COLOR_PAIR(1));
    draw_time(win,2,2);
    draw_border(x,y,180,6);
}

void draw_chat(WINDOW *win,int x,int y,char *txt)
{
    draw_border(x,y,180,24);
    if(His[0][0]!='\0')
    {
        mvwprintw(win,cur_x++,y+1,"%s",txt);
        mvwprintw(win,cur_x++,y+1,"**The server is busy, please try again later.**");
    }
    
}

void draw_input(WINDOW *win,int x,int y,char *txt)
{
    mvaddch(31,1,'>');
    draw_border(x,y,180,6);
    mvaddch(x+1,y+1,'>');
    mvwprintw(win,x+1,y+2,"%s",txt);
}

void draw_border(int x,int y,int width,int height)
{
    int i;
    for(i=0;i<width;i++)
    {
        mvaddch(x,y+i,'-');
        mvaddch(x+height,y+i,'-');
    }
    for(i=0;i<height-1;i++)
    {
        mvaddch(x+i+1,y,'|');
        mvaddch(x+i+1,y+width-1,'|');
    }
}

