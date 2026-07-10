#include "command.h"

extern int cur_x;

void choose(WINDOW *win,char *lcmd)
{
    char *cmd;
    char *instruction;
    cmd = strtok(lcmd, " ");
    instruction = strtok(NULL, " ");

    if (cmd == NULL)
    {
        return;
    }

    if (strcmp(cmd, "/read") == 0)
    {
        if (instruction == NULL)
        {
            mvwprintw(win,cur_x+1,1,"文件路径                                                                        ");
            return;
        }

        int line_count = read_command(instruction);
        if (line_count < 0)
        {
            mvwprintw(win,cur_x+1,1,"读取失败: %s                                                                     ",instruction);
        }
        else
        {
            mvwprintw(win,cur_x+1,1,"读取完成,文件共有%d行                                                             ",line_count);
        }
    }
    else if (strcmp(cmd, "/write") == 0)
    {
        printf("write command\n");
    }
    else if (strcmp(cmd, "/exec") == 0)
    {
        printf("exec command\n");
    }
    else
    {
        printf("default command\n");
    }
}

int read_command(char *path)
{
    FILE *fp;
    char buffer[256];
    int line_count = 0;

    fp = fopen(path,"r");
    if (fp == NULL)
    {
        printf("无法打开文件: %s\n", path);
        return -1;
    }
    else
    {
        printf("文件打开成功: %s\n", path);
        while (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            line_count++;
        }
        printf("文件共有 %d 行\n", line_count);
    }
    
    
    fclose(fp);
    return line_count;
}