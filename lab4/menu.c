#include <stdlib.h>
#include <stdio.h>
#include "linktable.h"
int Help();
int Quit();
#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10


typedef struct DataNode
{
	tLinkTableNode *pNext;
	char* cmd;
	char* desc;
	int (*handler)();
}tDataNode;


tDataNode* FindCmd(tLinkTable* head,char* cmd)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		//if判断的时候不能使用两个bool型的变量比较
		if(strcmp(pNode->cmd,cmd) == 0)
		{
			return pNode;
		}
		pNode = (tDataNode *)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
	}
	return NULL;
}

/*show all cmd in linklist*/
int ShowAllCmd(tLinkTable * head)
{
	tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
	while(pNode != NULL)
	{
		printf("%s - %s\n",pNode->cmd,pNode->desc);
		pNode = (tDataNode *)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
	}
	return 0;
}



int InitMenuData(tLinkTable ** ppLinkTable)
{
	*ppLinkTable = CreateLinkTable();
	tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "help";
	pNode->desc = "Menu List:";
	pNode->handler = Help;
	AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "version";
	pNode->desc = "Menu Program v1.0";
	pNode->handler = NULL;
	AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
	pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = "quit";
	pNode->desc = "Quit from Menu Program v1.0";
	pNode->handler = Quit;
	AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);

	return 0;
}



/*static tDataNode head[] = 
{
	{"Help","this is help cmd!",Help,&head[1]},
	{"Version","menu program v1.0",NULL,NULL},
	{"Quit","thie is quit cmd!",Quit,&head[2]}
};
*/


/*menu program*/

tLinkTable * head = NULL;

int main()
{
	InitMenuData(&head);
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

int Quit()
{
	exit(0);
}


