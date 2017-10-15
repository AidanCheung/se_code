#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linktable.h"

#define debug

typedef struct Node
{
	tLinkTableNode * pNext;
	int data;
}tNode;

tNode * Search(tLinkTable * pLinkTable);

int main()
{
	int i;
	tLinkTable *pLinkTable = CreateLinkTable();

	/*不使用断言，而应使用出错处理，断言时用于肯定的时候*/
	//assert(pLinkTable != NULL);

	if(pLinkTable == NULL)
	{
		printf("CreateLinkTable Error!\n");
		exit(0);
	}

	for(i = 0;i<10;i++)
	{
		tNode *pNode = (tNode *)malloc(sizeof(tNode));
		pNode->data = i;
		//debug("AddLinkTableNode\n");
		AddLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
	}
	
	/*search one by one*/	
	tNode * pTempNode = Search(pLinkTable);
	printf("%d\n",pTempNode->data);
	//debug("DelLinkTableNode\n");
	DelLinkTableNode(pLinkTable,(tLinkTableNode *)pTempNode);
	free(pTempNode);
	DeletelinkTable(pLinkTable);
}

tNode * Search(tLinkTable *pLinkTable)
{
	//debug("Search GetLinkTableHead\n");
	tNode * pNode = (tNode*)GetLinkTableHead(pLinkTable);
	while(pNode != NULL)
	{
		if(pNode->data == 5)
		{
			return pNode;
		}
		//debug("GetNextLinkTableNode\n");
		pNode = (tNode *)GetNextLinkTableNode(pLinkTable,(tLinkTableNode *)pNode);
	}
	return NULL;
}












