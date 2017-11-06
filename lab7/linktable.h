#ifndef _LINK_TABLE_H //防止重复include
#define _LINK_TABLE_H

#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)

/*LinkTable Node Type*/

typedef struct LinkTableNode
{
	struct LinkTableNode *pNext;

}tLinkTableNode;


/*LinkTable Type*/

typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int  		SumOfNode;
	pthread_mutex_t mutex;

}tLinkTable;



/*Creat a LinkTable*/

tLinkTable * CreateLinkTable();


/*Delete a LinkTable*/

int DeleteLinkTable (tLinkTable *pLinkTable);


/*Add a LinkTableNode to LinkTable*/

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);


/*Delete a LinkTableNode from LinkTabnle*/

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);


/*get LinkTableHead*/

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);


/*get next LinkTableNode*/

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);


/*
*search a linktablenode from linktable
*int condition(tlinktablenode *pnode)
*/
tLinkTableNode *SearchLinkTableNode(tLinkTable *pLinkTable,int Condition(tLinkTableNode *pNode,void *args),void *args);


#endif  /*_LINK_TABLE_H*/



