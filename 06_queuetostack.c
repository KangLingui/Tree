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

typedef struct stack
{
	int nCount;
	Queue *pQueue1;
	Queue *pQueue2;
}Stack;

void s_Init(Stack **pStack)
{
	*pStack = (Stack*)malloc(sizeof(Stack));
	(*pStack)->nCount = 0;
	q_Init(&((*pStack)->pQueue1));
	q_Init(&((*pStack)->pQueue2));
}

void s_Push(Stack *pStack,int nNum)
{
	if(pStack == NULL||pStack->pQueue1 == NULL || pStack->pQueue2 == NULL)exit(1);

	if(pStack->pQueue1->nCount != 0)
	{
		q_Push(pStack->pQueue1,nNum);
	}
	else
	{
		q_Push(pStack->pQueue2,nNum);
	}
	pStack->nCount++;
}

int s_Pop(Stack *pStack)
{
	if(pStack == NULL || pStack->pQueue1 == NULL || pStack->pQueue2 == NULL)exit(1);

	if(pStack->nCount == 0)return -1;
	
	int nNum;
	//队1非空
	if(pStack->pQueue1->nCount != 0)
	{
		//尾留下 其余元素入队2
		while(pStack->pQueue1->nCount > 1)
		{
			q_Push(pStack->pQueue2,q_Pop(pStack->pQueue1));
		}
		nNum = q_Pop(pStack->pQueue1);
	}
	else
	{
		//尾留下 其余元素入队1
		while(pStack->pQueue2->nCount > 1)
		{
			q_Push(pStack->pQueue1,q_Pop(pStack->pQueue2));
		}
		nNum = q_Pop(pStack->pQueue2);
	}

	pStack->nCount--;
	return nNum;
}


int main()
{
	Stack *pStack = NULL;
	s_Init(&pStack);
	s_Push(pStack,1);
	s_Push(pStack,2);
	s_Push(pStack,3);
	s_Push(pStack,4);

	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));
	printf("%d\n",s_Pop(pStack));
	return 0;
}
