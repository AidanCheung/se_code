#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"


/*create linklist*/

tLinkTable * CreateLinkTable()
{
	tLinkTable *head = (tLinkTable*)malloc(sizeof(tLinkTable));
	if(head == NULL)
	{
		return NULL;
	}
	head->pHead = NULL;
	head->pTail = NULL;
	head->SumOfNode = 0;
	return head;
}

/*Delete a LinkTable*/

int DeleteLinkTable (tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
	}
	while(pLinkTable->pHead !=NULL)
	{
		tLinkTableNode *pNode = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		free(pNode);
		pLinkTable->SumOfNode -= 1;
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	free(pLinkTable);
	return SUCCESS;
}


/*Add a LinkTableNode to LinkTable*/

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	pNode->pNext = NULL;
	if(pLinkTable->pHead == NULL)
	{
		pLinkTable->pHead = pNode;
	}
	if(pLinkTable->pTail == NULL)
	{
		pLinkTable->pTail = pNode;
	}
	else
	{
		pLinkTable->pTail->pNext = pNode;
		pLinkTable->pTail = pNode;
	}
	return SUCCESS;
}


/*Delete a LinkTableNode from LinkTabnle*/

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pNode == NULL)
	{
		return FAILURE;
	}
	if(pLinkTable->pHead == pNode)
	{
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1;
		if(pLinkTable->SumOfNode == 0)
		{
			pLinkTable->pTail = NULL;
		}
		return SUCCESS;
	}
	tLinkTableNode *p =pLinkTable->pHead;
	while(p != NULL)
	{
		if(p->pNext == pNode)
		{
			p->pNext = p->pNext->pNext;
			pLinkTable->SumOfNode -= 1;
			if(pLinkTable->SumOfNode == 0)
			{
				pLinkTable->pTail = NULL;
			}
			return SUCCESS;
		}
	}
}


/*get LinkTableHead*/

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL || pLinkTable->pHead == NULL)
	{
		return NULL;
	}
	tLinkTableNode *pNode = pLinkTable->pHead;
	return pNode;
}


/*get next LinkTableNode*/

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
	if(pLinkTable == NULL || pLinkTable->pHead == NULL)
	{
		return NULL;
	}
	return pNode->pNext;
}













