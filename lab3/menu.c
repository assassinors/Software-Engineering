#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

void help();
void quit();
void add();
void sub();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[] =
{
    {"help","Show all command!",help,&head[1]},
    {"quit","Quit from the application!",quit,&head[2]},
    {"add","Add two intergers!",add,&head[3]},
    {"sub","Sub two intergers!",sub,NULL}
};

int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please Input a command >>");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if (p == NULL)
        {
            printf("Wrong command,please try again!\n");
            continue;
        }
        printf("%s\t - %s\n",p->cmd,p->desc );
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}

void help()
{
    ShowAllCmd(head);
}

void quit()
{
    exit(0);
}

void add()
{
    int m,n;
    printf("Please input two intergers:");
    scanf("%d,%d",&m,&n);
    printf("The answer is %d\n",m+n);
}

void sub()
{
    int m,n;
    printf("Please input two intergers:");
    scanf("%d,%d",&m,&n);
    printf("The answer is %d\n",m-n);
}
