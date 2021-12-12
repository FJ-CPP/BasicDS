#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;
//创建树节点
BTNode* CreateBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	else
	{
		newnode->_data = x;
		newnode->_left = newnode->_right = NULL;
		return newnode;
	}
	
}
//前序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//广度优先遍历:先将根节点入队,出队时每次出一个，出的同时将它的左右节点入队；当队空时，遍历结束
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			printf("NULL ");
		}
		else
		{
			printf("%c ", front->_data);
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
	}
	QueueDestroy(&q);
}
//求树的节点个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->_left) + TreeSize(root->_right) + 1;
}
//求树的叶子结点个数
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root->_left == NULL && root->_right == NULL ? 1 : TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
	}
}
//求树的第k层节点个数
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	return k == 1 ? 1 : TreeKLevelSize(root->_left, k - 1) + TreeKLevelSize(root->_right, k - 1);
}
//查找树里面值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = TreeFind(root->_left, x);
	if (ret != NULL)
	{
		return ret;
	}
	ret = TreeFind(root->_right, x);
	if (ret != NULL)
	{
		return ret;
	}
	return NULL;
}
//判断一棵树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);//根入队
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)//当出队的是NULL时，如果是完全二叉树，那么后序队列元素应当也全为空
		{
			while (!QueueEmpty(&q))
			{
				if (QueueFront(&q) != NULL)
					return false;
				QueuePop(&q);
			}
		}
		else
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
	}
	QueueDestroy(&q);
	return true;
}

//树的销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	//必须采取后序遍历的方式销毁
	free(root);
}
int main()
{
	BTNode* A = CreateBTNode('A');
	BTNode* B = CreateBTNode('B');
	BTNode* C = CreateBTNode('C');
	BTNode* D = CreateBTNode('D');
	BTNode* E = CreateBTNode('E');
	BTNode* F = CreateBTNode('F');
	
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	D->_left = F;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	int sz = TreeSize(A);
	printf("%d\n", sz);

	int sz2 = TreeLeafSize(A);
	printf("%d\n", sz2);

	int sz3 = TreeKLevelSize(A, 2);
	printf("%d\n", sz3);

	BTNode* res = TreeFind(A, 'G');
	if (res != NULL)
	{
		printf("%c\n", res->_data);
	}
	else
	{
		printf("NULL\n");
	}

	LevelOrder(A);
	printf("\n");
	
	int ret = BinaryTreeComplete(A);
	printf("%d\n", ret);

	BinaryTreeDestory(A);
	return 0;
}
