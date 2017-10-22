#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"


/*create linklist*/

tLinkTable * CreateLinkTable()
{
    tLinkTable * pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    return pLinkTable;
}

/*Delete a LinkTable*/

int DeleteLinkTable (tLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
	{
		return FAILURE;
	}
	while(pLinkTable->pHead != NULL)
	{
		tLinkTableNode *pNode = pLinkTable->pHead;
		pLinkTable->pHead = pLinkTable->pHead->pNext;
		pLinkTable->SumOfNode -= 1;
		free(pNode);
	}
	pLinkTable->pHead = NULL;
	pLinkTable->pTail = NULL;
	pLinkTable->SumOfNode = 0;
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
	pLinkTable->SumOfNode += 1;
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
		p = p->pNext;
	}
	return FAILURE;
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
	if(pLinkTable == NULL || pNode == NULL)
	{
		return NULL;
	}
	tLinkTableNode *pTempNode = pLinkTable->pHead;
	while(pTempNode != NULL)
	{
		if(pTempNode == pNode)
		{
			return pTempNode->pNext;
		}
		pTempNode = pTempNode->pNext;
	}
	return NULL;
}


/*search a linktablenode from linktable ,int condition(tlinktablenode * pnode)*/

tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable,int Condition(tLinkTableNode *pNode,void *args),void *args)
{
	if(pLinkTable == NULL || Condition == NULL)
	{
		return NULL;
	}
	tLinkTableNode *pNode = pLinkTable->pHead;
	while(pNode != pLinkTable->pTail)
	{
		if(Condition(pNode,args) == SUCCESS)
		{
			return pNode;
		}
		pNode = pNode->pNext;
	}
	return NULL;
}













