#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int nValue;
	struct node *pNext;
}MyQueue;

typedef struct queue
{
	int nCount;
	MyQueue *pHead;
	MyQueue *pTail;
}Queue;

void q_Init(Queue **pQueue)
{
	*pQueue = (Queue*)malloc(sizeof(Queue));
	(*pQueue)->nCount = 0;
	(*pQueue)->pHead = NULL;
	(*pQueue)->pTail = NULL;
}

void q_Push(Queue *pQueue,int nNum)
{
	if(pQueue == NULL)
	{
		exit(1);
	}

	MyQueue *pTemp = NULL;
	pTemp = (MyQueue*)malloc(sizeof(MyQueue));
	pTemp->nValue = nNum;
	pTemp->pNext = NULL;

	//尾添加
	if(pQueue->pHead == NULL)
	{
		pQueue->pHead = pTemp;
	}
	else
	{
		pQueue->pTail->pNext = pTemp;
	}
	pQueue->pTail = pTemp;

	pQueue->nCount++;
}

int q_Pop(Queue *pQueue)
{
	if(pQueue == NULL)
	{
		exit(1);
	}

	if(pQueue->nCount == 0)return -1;

	MyQueue *pDel = pQueue->pHead;
	int nNum = pDel->nValue;

	pQueue->pHead = pQueue->pHead->pNext;
	free(pDel);
	pDel = NULL;
	pQueue->nCount--;

	if(pQueue->nCount == 0)
	{
		pQueue->pTail = NULL;
	}
	return nNum;
}

int q_IsEmpty(Queue *pQueue)
{
	if(pQueue == NULL)
	{
		exit(1);
	}

	return pQueue->nCount == 0?1:0;
}

int main()
{
	Queue *pQueue = NULL;
	q_Init(&pQueue);
	q_Push(pQueue,1);
	q_Push(pQueue,2);
	q_Push(pQueue,3);
	q_Push(pQueue,4);

	printf("%d\n",q_Pop(pQueue));
	printf("%d\n",q_Pop(pQueue));
	printf("%d\n",q_Pop(pQueue));
	printf("%d\n",q_Pop(pQueue));
	return 0;
}
