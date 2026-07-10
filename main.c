#include "tui.h"
#include "input.h"

int main() 
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_GREEN);

    // WINDOW *win = newwin(36,180,0,0);
    WINDOW *chat_win = subwin(stdscr,24,180,0,0);
    WINDOW *status_win = subwin(stdscr,6,180,24,0);
    WINDOW *input_win = subwin(stdscr,6,180,30,0);

    MEVENT event;

    mousemask(ALL_MOUSE_EVENTS, 0);
    
    int c;

    draw_chat(chat_win,0,0,"");
    while(1)
    {
        refresh();
        draw_status(status_win,24,0);
        
        draw_input(input_win,30,0,"");
        input();
        // c=wgetch(input_win);
        // {
        //     if(c == KEY_MOUSE)
        //     {
        //         if(getmouse(&event) == OK)
        //         {
        //             if(event.bstate & BUTTON1_CLICKED)
        //             {
        //                 if(event.x >= 30 && event.x <= 36)
        //                 {
        //                     input();
        //                 }
        //             }
        //         }
        //     }
        // }

    }

    endwin();
    return 0;
}