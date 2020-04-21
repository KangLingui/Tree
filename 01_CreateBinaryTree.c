#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int nValue;
	struct tree *pLeft;
	struct tree *pRight;
}BinaryTree;

BinaryTree *CreateBinaryTree()
{
	BinaryTree *pRoot = NULL;

	//根
	pRoot = (BinaryTree *)malloc(sizeof(BinaryTree));
	pRoot->nValue = 1;

	//左
	pRoot->pLeft =  (BinaryTree *)malloc(sizeof(BinaryTree));
	pRoot->pLeft->nValue = 2;

	//左的左
	pRoot->pLeft->pLeft =  (BinaryTree *)malloc(sizeof(BinaryTree));
	pRoot->pLeft->pLeft->nValue = 4;
	pRoot->pLeft->pLeft->pLeft = NULL;
	pRoot->pLeft->pLeft->pRight = NULL;

	//左的右
	pRoot->pLeft->pRight =  (BinaryTree *)malloc(sizeof(BinaryTree));
	pRoot->pLeft->pRight->nValue = 5;
	pRoot->pLeft->pRight->pLeft = NULL;
	pRoot->pLeft->pRight->pRight = NULL;

	//右
	pRoot->pRight =  (BinaryTree *)malloc(sizeof(BinaryTree));
	pRoot->pRight->nValue = 3;
	pRoot->pRight->pLeft = NULL;
	pRoot->pRight->pRight = NULL;

	return pRoot;
}

void CreateBiTree(BinaryTree **pTree)
{
	int nNum;
	scanf("%d",&nNum);
	
	if(nNum == 0)return;

	//根
	*pTree = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*pTree)->nValue = nNum;
	(*pTree)->pLeft = NULL;
	(*pTree)->pRight = NULL;

	//左
	CreateBiTree(&((*pTree)->pLeft));
	//右
	CreateBiTree(&((*pTree)->pRight));
}

void PreorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL)return;

	//根
	printf("%d ",pTree->nValue);

	//左子树
	PreorderTraversal(pTree->pLeft);
	//右子树
	PreorderTraversal(pTree->pRight);
}

void InorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL)return;

	//左子树
	InorderTraversal(pTree->pLeft);
	
	//根
	printf("%d ",pTree->nValue);

	//右子树
	InorderTraversal(pTree->pRight);
}


void LastorderTraversal(BinaryTree *pTree)
{
	if(pTree == NULL)return;

	//左子树
	LastorderTraversal(pTree->pLeft);
	
	//右子树
	LastorderTraversal(pTree->pRight);

	//根
	printf("%d ",pTree->nValue);
}

BinaryTree *ArrToTree(int arr[],int nLength)
{
	if(arr == NULL || nLength <= 0)return NULL;

	//申请结构体数组
	BinaryTree *pTree = NULL;
	pTree = (BinaryTree*)malloc(sizeof(BinaryTree)*nLength);
	
	//赋值
	int i;
	for(i = 0;i<nLength;i++)
	{
		pTree[i].nValue = arr[i];
		pTree[i].pLeft = NULL;
		pTree[i].pRight = NULL;
	}

	//左右关系
	for(i = 0;i<nLength/2;i++)
	{
		if(2*i+1<=nLength-1)
		{
			pTree[i].pLeft = &pTree[2*i+1];
		}
		if(2*i+2<=nLength-1)
		{
			pTree[i].pRight = &pTree[2*i+2];
		}
	}

	return  pTree;
}

int main()
{
	//BinaryTree *pTree = CreateBinaryTree();
	BinaryTree *pTree = NULL;
	//CreateBiTree(&pTree);
	int arr[] = {1,2,3,4,5};
	pTree = ArrToTree(arr,sizeof(arr)/sizeof(arr[0]));
	PreorderTraversal(pTree);
	printf("\n");
	InorderTraversal(pTree);
	printf("\n");
	LastorderTraversal(pTree);
	printf("\n");
	return 0;
}
