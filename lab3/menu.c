#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"
int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

/*
typedef struct DataNode
{
	char* cmd;
	char* desc;
	int (*handler)();
	struct DataNode *next;
}tDataNode;

tDataNode* FindCmd(tDataNode* head,char* cmd)
{
	if(head == NULL || cmd == NULL)
	{
		return NULL;
	}
	tDataNode *p = head;
	while(p != NULL)
	{
		if(!strcmp(p->cmd,cmd))
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

int ShowAllCmd(tDataNode * head)
{
	printf("Menu List:\n");
	tDataNode *p = head;
	while(p != NULL)
	{
		printf("%s - %s\n",p->cmd,p->desc);
		p = p->next;
	}
	return 0;
}
*/
static tDataNode head[] = 
{
	{"help","this is help cmd!",Help,&head[1]},
	{"version","menu program v1.0",NULL,NULL}
};

int main()
{
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number ->");
		scanf("%s",cmd);
		tDataNode *p = FindCmd(head,cmd);
		if(p == NULL)
		{
			printf("This is a wrong cmd!\n");
			continue;
		}
		printf("%s - %s\n",p->cmd,p->desc);
		if(p->handler != NULL)
		{
			p->handler();
		}
	}
}

int Help()
{
	ShowAllCmd(head);
	return 0;
}












