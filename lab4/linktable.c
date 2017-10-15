#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
/*
typedef struct DataNode
{
	tLinkTableNode *pNext;
	char* cmd;
	char* desc;
	int (*handler)();
}tDataNode;
*/
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
