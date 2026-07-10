#include "input.h"

char His[10][100];
int a=0;

void input()
{
    Msg msg;
    msg.len=0;
    int x=1,y =2;
    
    while(1)
    {
        char ch = getch();
        msg.txt[++msg.len-1]=ch;
        msg.txt[msg.len]='\0';
        draw_input(stdscr,30,0,msg.txt);
        refresh();
        if(y>=178)
        {
            y=1;
            x++;
        }
        if(ch == '\n')
        {
            msg.txt[msg.len-1]='\0';
            if(msg.txt[0]=='\\')
            {
                
            }
            strcpy(His[a], msg.txt);
            a++;
            msg.len=0;
            x=1;
            y=2;
            draw_input(stdscr,30,0,"                                                                                   ");
            draw_chat(stdscr,0,0,msg.txt);
            msg.txt[0]='\0';
            break;
        }
        if(ch == 127)
        {
            msg.txt[--msg.len-1]='\0';
            y--;
            if(y<=1)
            {
                y=178;
                x--;
            }
            mvaddch(x,y,' ');
        }
    }
}