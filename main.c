
/*************************************************************************************************/
/* Copyright (C) Cai Shuxiao, SSE@USTC, 2014-2015                                                */
/*                                                                                               */
/*  FILE NAME              :  main.c                                                             */
/*  PRINCIPAL AUTHOR       :  Cai shuxiao                                                        */
/*  SUBSYSTEM NAME         :  main                                                               */
/*  MODULE NAME            :  main                                                               */
/*  LANGUAGE               :  C                                                                  */
/*  TARGET ENVIRONMENT     :  ANY                                                                */
/*  DATE OF FIRST RELEASE  :  2014/09/16                                                         */
/*  DESCRIPTION            :  This programme shows a menu of strings                             */
/*************************************************************************************************/

/*
 * Revision Log:
 *
 * Created by Caishuxiao, 2014/9/16
 *
 */

#include<stdio.h>
#include<stdlib.h>

int Help();
int Version();
#define CMD_NUM 10
#define DESC_LEN 1024
#define CMD_MAX_LEN 128

typedef struct DataNode
{
    char* cmd;
    char* desc;
    int   (*handler)();
    struct DataNode *next;
} tDataNode;

static tDataNode head[]=
{
    {"help","This is help cmd!",Help,&head[1]},
    {"version","menu program v1.1",Version,NULL},
};

main()
{
    
    while(1)
    {
        char cmd[CMD_MAX_LEN];
	printf(">>>");
        scanf("%s",cmd);
        tDataNode *p=head;
        while(p!=NULL)
	{
            if(!strcmp(p->cmd,cmd))
            {
                /*printf("%s - %s\n",p->cmd, p->desc);*/
                if(p->handler != NULL)
                {
                      p -> handler();
                }
                break;
            }
            p = p->next;
        }
        if(p==NULL)
        {
            printf("This is a wrong cmd!\n");
        }
    }
}
    
int Help()
{
    printf("All Menu List is following:\n\n");
    tDataNode *p =head;
    while(p != NULL)
    {
        printf("    %s - %s\n",p->cmd,p->desc);
        p = p->next;
    }
    return 0;
}
int Version()
{
    tDataNode *p =head;
    p=p-> next;
    printf("%s - %s\n",p->cmd,p->desc);
}

