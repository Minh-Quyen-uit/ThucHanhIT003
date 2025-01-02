#include <iostream>
using namespace std;

#define MAX 1000

typedef struct TNode
{
	int data;
	TNode* pLeft;
	TNode* pRight;
	TNode(int x): data(x), pLeft(NULL), pRight(NULL) {}
}*PTNode;

typedef PTNode BTree;

PTNode createNode(int x)
{
	PTNode p = new TNode(x);
	return p;
}

int insertTNode(BTree& t, int x)
{
	if (!t)
	{
		t = new TNode(x);
		return 1;
	}
	if (x == t->data)
		return 0;
	else if (x < t->data)
		return insertTNode(t->pLeft, x);
	else
		return insertTNode(t->pRight, x);
}

int deleteTNode(BTree& t, int x)
{
	if (!t)
		return 0;
	if (x < t->data)
		return deleteTNode(t->pLeft, x);
	else if (x > t->data)
		return deleteTNode(t->pRight, x);
	else 
	{
		PTNode p = t;
		if (!p->pLeft)
			t = t->pRight;
		else if (!p->pRight)
			t = t->pLeft;
		else
		{
			PTNode parent = t, successor = t->pRight;
			while (successor->pLeft)
			{
				parent = successor;
				successor = successor->pLeft;
			}
			t->data = successor->data;
			if (parent->pLeft = successor)
				parent->pLeft = successor->pRight;
			else
				parent->pRight = successor->pRight;
			p = successor;
		}
		delete p;
	}
	return 1;
}

bool isExist(PTNode root, int x)
{
	if (!root)
		return false;
	if (root->data == x)
		return true;
	if (root->data > x)
		return isExist(root->pLeft, x);
	else
		return isExist(root->pRight, x);
}

int countLeaf(PTNode root)
{
	if (!root)
		return 0;
	return countLeaf(root->pLeft) + countLeaf(root->pRight) + 1;
}

void LNR(PTNode root)
{
	if (root)
	{
		LNR(root->pLeft);
		cout << root->data << " ";
		LNR(root->pRight);
	}
}

void inputList(BTree& t)
{
	int m, n;
	cin >> m >> n;
	insertTNode(t, 0);
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (isExist(t, x) || isExist(t, y))
		{
			insertTNode(t, x);
			insertTNode(t, y);
		}
	}
	deleteTNode(t, 0);
	if(t==NULL)
	{
		for (int i = 1; i < m; i++) 
			cout << "KHONG\n";
		return;
	}
	for (int i = 1; i < m; i++)
		if (isExist(t, i))
			cout << "CO\n";
		else
			cout << "KHONG\n";
}

int main()
{
	BTree list = NULL;
	inputList(list);
	return 0;
}