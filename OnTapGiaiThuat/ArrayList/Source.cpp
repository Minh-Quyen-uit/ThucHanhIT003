#include <iostream>
using namespace std;

const int MAX = 50; //giới hạn 10 phần tử

int max(int a, int b)
{
	return (a > b) ? a : b;
}

#pragma region ListDon

#pragma region  struct

typedef struct Node
{
	int data;
	struct Node* nextNode;
};

typedef struct List
{
	Node* nHead;
	Node* nTail;
};

#pragma endregion

#pragma region createAndInsert

void createList(List& arr)
{
	arr.nHead = NULL;
	arr.nTail = NULL;
}

Node* createNode(int x)
{
	Node* p;
	p = new Node;
	if (p == NULL) return NULL;
	p->data = x;
	p->nextNode = NULL;
	return p;
}

void addHeadList(List& arr, Node* p)
{
	if (arr.nHead == NULL)
	{
		arr.nHead = p;
		arr.nTail = arr.nHead;
	}
	else {
		p->nextNode = arr.nHead;
		arr.nHead = p;
	}
}

void addTailList(List& arr, Node* p)
{
	if (arr.nHead == NULL)
	{
		arr.nHead = p;
		arr.nTail = arr.nHead;
	}
	else
	{
		arr.nTail->nextNode = p;
		arr.nTail = p;
	}
}

//them phan tu vao sau 1 phan tu q
void addAfterQ(List& arr, int q, Node* p)
{
	Node* cur = arr.nHead;
	while (cur != NULL)
	{
		if (cur->data == q)
		{
			p->nextNode = cur->nextNode;
			cur->nextNode = p;
			if (p->nextNode == NULL)
			{
				arr.nTail = p;
			}
		}

		cur = cur->nextNode;
	}
}

#pragma endregion

#pragma region removeFunction

void removeHead(List& arr)
{
	Node* p;
	if (arr.nHead != NULL)
	{
		p = arr.nHead;
		arr.nHead = arr.nHead->nextNode;
		delete p;
		if (arr.nHead == NULL)
			arr.nTail = NULL;
	}
}

void removeAfterNodeQ(List& arr, Node* q)
{
	if (q != NULL)
	{
		Node* p = q->nextNode;
		if (p != NULL)
		{
			q->nextNode = p->nextNode;
			if (p == arr.nTail)
				arr.nTail = q;
		}
		delete p;
	}
}

void removeX(List& arr, int x)
{
	Node* p = arr.nHead;
	Node* q = NULL;
	while ((p != NULL) && (p->data != x))
	{
		q = p;
		p = p->nextNode;
	}
	if (p == NULL) return;
	if (q != NULL)
		removeAfterNodeQ(arr, q);
	else
		removeHead(arr);
}

void removeList(List& arr)
{
	Node* p;
	while (arr.nHead) {
		p = arr.nHead;
		arr.nHead = p->nextNode;
		delete p;
	}
}
#pragma endregion

#pragma region Sorts

void quickSortList(List& arr)
{
	Node* p, * x;
	List l1, l2;

	//chuỗi có 1 phần từ => đã sắp xếp.
	if (arr.nHead == arr.nTail) return;

	createList(l1);
	createList(l2);

	//loại phần tử đầu tiên ra khỏi list
	x = arr.nHead;
	arr.nHead = x->nextNode;

	//chia list thành 2 list con 
	//l1 gồm các phần tử bé hơn hoặc bằng x
	//l2 gồm các phần tử lớn hơn x
	while (arr.nHead != NULL)
	{
		p = arr.nHead;
		arr.nHead = p->nextNode;
		p->nextNode = NULL; // loại bỏ dạy sau phần tử
		if (p->data <= x->data)
			addHeadList(l1, p);
		else
			addHeadList(l2, p);
	}

	//đệ quy 2 list con để sắp xếp 
	quickSortList(l1);
	quickSortList(l2);

	//nối l1, x, l2 thành list 
	if (l1.nHead != NULL)
	{
		arr.nHead = l1.nHead;
		l1.nTail->nextNode = x;
	}
	else // nếu l1 rỗng thì phần tử x là phần tử đầu của list
	{
		arr.nHead = x;
	}

	x->nextNode = l2.nHead;

	if (l2.nHead != NULL)
	{
		arr.nTail = l2.nTail;
	}
	else // nếu l2 rỗng thì x là phần tử đuôi của list
	{
		arr.nTail = x;
	}
}

#pragma endregion


Node* searchX(List arr, int x)
{
	Node* cur = arr.nHead;
	while ((cur != NULL) && (cur->data != x))
	{
		cur = cur->nextNode;
	}
	return cur;
}

void inputList(List& arr)
{
	int n, x;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		addTailList(arr, createNode(x));
	}
}

void printList(List arr)
{
	Node* cur = arr.nHead;
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->nextNode;
	}
	cout << endl;
}

#pragma endregion

#pragma region ListKep

#pragma region Struct

typedef struct DNode
{
	int data;
	struct DNode* PreNode;
	struct DNode* NextNode;
};

typedef struct DList
{
	DNode* DNHead;
	DNode* DNTail;
};

#pragma endregion

#pragma region CreateAndInsert

DNode* createDNode(int x) 
{
	DNode* p;
	p = new DNode;
	if (p == NULL) return NULL;
	p->data = x;
	p->NextNode = NULL;
	p->PreNode = NULL;
	return p;
}

void createDList(DList& l)
{
	l.DNHead = NULL;
	l.DNTail = NULL;
}
void addHeadDList(DList& l, DNode* x)
{
	if (l.DNHead == NULL)
	{
		l.DNHead = x;
		l.DNTail = l.DNHead;
	}
	else
	{
		x->NextNode = l.DNHead;
		l.DNHead->PreNode = x;
		l.DNHead = x;
	}
}

void addTailDList(DList& l, DNode* x)
{
	if (l.DNHead == NULL) 
	{
		l.DNHead = x;
		l.DNTail = l.DNHead;
	}
	else
	{
		l.DNTail->NextNode = x;
		x->PreNode = l.DNTail;
		l.DNTail = x;
	}
}

void addAfterQDList(DList& l, DNode* q, DNode* x)
{
	DNode* p;
	p = q->NextNode;
	if (q != NULL)
	{
		x->NextNode = p;
		x->PreNode = q;
		q->NextNode = x;
		if (p != NULL)
			p->PreNode = x;
		if (q == l.DNTail)
			l.DNTail = x;
	}
	else
		addHeadDList(l, x);
}

void addBeforeQDList(DList& l, DNode* q, DNode* x) 
{
	DNode* p;
	p = q->PreNode;
	if (q != NULL)
	{
		x->PreNode = p;
		x->NextNode = q;
		q->PreNode = x;
		if (p != NULL)
			p->NextNode = x;
		if (q == l.DNHead)
			l.DNHead = x;
	}
	else
		addTailDList(l, x);
}

#pragma endregion

#pragma region DeleteDlist

void deleteHeadDList(DList& l)
{
	DNode* p;
	if (l.DNHead != NULL)
	{
		p = l.DNHead;
		l.DNHead = l.DNHead->NextNode;
		if (l.DNHead != NULL) 
			l.DNHead->PreNode = NULL; 
		else
			l.DNTail = NULL;
		delete p;
	}
}

void deleteTailDList(DList& l)
{
	DNode* p;
	if (l.DNHead != NULL)
	{
		p = l.DNTail;
		l.DNTail = l.DNTail->PreNode;
		l.DNTail->NextNode = NULL;
		delete p;
		if (l.DNTail == NULL)
			l.DNHead = NULL;
	}
}

void deleteAfterQDList(DList& l, DNode* q)
{
	DNode* p;
	if (q != NULL)
	{
		p = q->NextNode;
		if (p != NULL)
		{
			q->NextNode = p->NextNode;
			if (p == l.DNTail)
				l.DNTail = q;
			else
				p->NextNode->PreNode = q;
			delete p;
		}
	}
	else
		deleteHeadDList(l);
}

void deleteBeforeQDList(DList& l, DNode* q)
{
	DNode* p;
	if (q != NULL)
	{
		p = q->PreNode;
		if (p != NULL)
		{
			p->PreNode = q->PreNode;
			if (p == l.DNHead)
				l.DNHead = q;
			else
				p->PreNode->NextNode = q;
		}
	}
	else
		deleteTailDList(l);
}

int deleteXDList(DList& l, int x)
{
	DNode* p;
	DNode* q;
	q = NULL;
	p = l.DNHead;
	while (p != NULL)
	{
		if (p->data == x)
			break;
		q = p;
		p = p->NextNode;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		deleteAfterQDList(l, q);//lúc này q đứng trc DNode cần xóa
	else
		deleteHeadDList(l);
	return 1;
}

#pragma endregion

#pragma region SortDList

void SwapDNode(DNode* a, DNode* b)
{
	int c = a->data;
	a->data = b->data;
	b->data = c;
}

void insertionSortDList(DList& l)
{
	DNode* p, * q;
	p = l.DNHead;
	while (p != l.DNTail)
	{
		q = p->NextNode;
		while (q != NULL)
		{
			if (p->data > q->data)
				SwapDNode(p, q);
			q = q->NextNode;
		}
		p = p->NextNode;
	}
}

#pragma endregion



void inputDList(DList& l)
{
	int n, x;
	cout << "Nhap so luong phan tu cua List kep: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao list kep: ";
		cin >> x;
		addTailDList(l, createDNode(x));
	}
}

void printDList(DList l)
{
	DNode* p;
	p = l.DNHead;
	while(p!=NULL) 
	{
		cout << p->data << " ";
		p = p->NextNode;
	}
	cout << endl;
}

#pragma endregion
			
#pragma region Mystack

#pragma region CreateStack

typedef struct Stack
{
	List list;
};

void createStack(Stack& st)
{
	createList(st.list);
}

#pragma endregion

#pragma region Empty

int stackisEmpty(Stack st)
{
	return(st.list.nHead == NULL) ? 1 : 0;
}

#pragma endregion

#pragma region PushOrPop

void StackPush(Stack& st, Node* x)
{
	if (st.list.nHead == NULL)
	{
		st.list.nHead = x;
		st.list.nTail = st.list.nHead;
	}
	else 
	{
		x->nextNode = st.list.nHead;
		st.list.nHead = x;
	}
}

int stackPop(Stack& st, int& x)
{
	Node* p;
	if (stackisEmpty(st) != 1)
	{
		p = st.list.nHead;
		x = p->data;
		st.list.nHead = st.list.nHead->nextNode;
		delete p;
		if (st.list.nHead == NULL)
			st.list.nTail = NULL;
		return 1;
	}
	return 0;
}

//trả về phần tử đầu stack, nếu stack rỗng thì trả về -1
int TopStack(Stack& st) {
	int x = -1;
	Node* p = st.list.nHead;
	while (p != NULL) 
	{
		x = p->data;
		p = p->nextNode;
	}
	return x;
}

#pragma endregion

void inputStack(Stack& st)
{
	int n, x;
	cout << "Nhap so phan tu cua stack: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao stack: ";
		cin >> x;
		StackPush(st, createNode(x));
	}
}

void printStack(Stack st)
{
	printList(st.list);
}

#pragma endregion

#pragma region MyQueue

#pragma region createQueue

typedef struct Queue
{
	List list;
};

void createQueue(Queue& queue)
{
	createList(queue.list);
}

#pragma endregion

#pragma region Empty

int queueEmpty(Queue& queue)
{
	return (queue.list.nHead == NULL) ? 1 : 0;
}

#pragma endregion

//queue thêm vào đuôi và lấy ra ở đầu list
#pragma region EnQueueAndDeQueue

void EnQueue(Queue& queue, Node* x)
{
	if (queue.list.nHead == NULL) 
	{
		queue.list.nHead = x;
		queue.list.nTail = queue.list.nHead;
	} 
	else
	{
		queue.list.nTail->nextNode = x;
		queue.list.nTail = x;
	}
}

int DeQueue(Queue& queue, int& x)
{
	Node* p;
	if (queueEmpty(queue) != 1)
	{
		p = queue.list.nHead;
		x = p->data;
		queue.list.nHead = p->nextNode;
		if (queue.list.nHead == NULL)
			queue.list.nTail = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int FrontQueue(Queue queue)
{
	return (queue.list.nHead == NULL) ? -1 : queue.list.nHead->data;
}

#pragma endregion

void inputQueue(Queue& queue)
{
	int n, x;
	cout << "Nhap so luong phan tu cua Queue: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao Queue: ";
		cin >> x;
		EnQueue(queue, createNode(x));
	}
}

void printQueue(Queue queue)
{
	printList(queue.list);
}

#pragma endregion

//Cây Nhị phân tìm kiếm
#pragma region BinaryTree 

#pragma region Create

typedef struct TNode
{
	int data;
	struct TNode* TNLeft;
	struct TNode* TNRight;
};

typedef TNode* BinaryTree;

void createBinaryTree(BinaryTree& T)
{
	T = NULL;
}

TNode* createTNode(int x)
{
	TNode* p;
	p = new TNode;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->TNLeft = NULL;
	p->TNRight = NULL;
	return p;
}

#pragma endregion

#pragma region Insert

int insertTNode(BinaryTree& T, int x)
{
	if (T != NULL)
	{
		if (T->data == x)
			return 0;
		if (T->data > x)
			return insertTNode(T->TNLeft, x);
		else
			return insertTNode(T->TNRight, x);
	}
	T = new TNode;
	if (T == NULL) return 0;
	T->data = x;
	T->TNLeft = NULL;
	T->TNRight = NULL;
	return 1;
}

#pragma endregion

#pragma region Search

TNode* searchTNodeWhile(BinaryTree Root, int x)
{
	TNode* p = Root;
	while (p != NULL)
	{
		if (x == p->data)
			return p;
		else if (x < p->data)
			p = p->TNLeft;
		else
			p = p->TNRight;
	}
	return NULL;
}

TNode* searchTNodeRecursion(BinaryTree Root, int x)
{
	if (Root != NULL)
	{
		if (x == Root->data)
			return Root;
		else if (x < Root->data)
			return searchTNodeRecursion(Root->TNLeft, x);
		else
			return searchTNodeRecursion(Root->TNRight, x);
	}
	return NULL;
}

#pragma endregion

#pragma region Delete

//thay bằng nút nhỏ nhất bên cây con bên phải
void replaceTNode(BinaryTree& p, BinaryTree& T)
{
	if (T->TNLeft != NULL)
		replaceTNode(p, T->TNLeft);
	else
	{
		p->data = T->data;
		p = T;
		T = T->TNRight;
	}
}

void delelteTNodeX(BinaryTree& T, int x)
{
	if (T != NULL)
	{
		if (x < T->data)
			delelteTNodeX(T->TNLeft, x);
		else if (x > T->data)
			delelteTNodeX(T->TNRight, x);
		else
		{
			TNode* p;
			p = T;
			if (p->TNLeft == NULL)
				T = T->TNRight;
			else
			{
				if (p->TNRight == NULL)
					T = T->TNLeft;
				else
					replaceTNode(p, T);
			}
			delete p;
		}
	}
	else
		cout << "Khong tim thay phan tu chua " << x << " trong cay!!!" << endl;
}

#pragma endregion


#pragma region BrowseBTree

void NLRBinaryTree(BinaryTree Root)
{
	if (Root != NULL)
	{
		cout << Root->data << " ";
		NLRBinaryTree(Root->TNLeft);
		NLRBinaryTree(Root->TNRight);
	}
}

void LNRBinaryTree(BinaryTree Root)
{
	if (Root != NULL)
	{
		LNRBinaryTree(Root->TNLeft);
		cout << Root->data << " ";
		LNRBinaryTree(Root->TNRight);
	}
}

void LRNBinaryTree(BinaryTree Root)
{
	if (Root != NULL)
	{
		LRNBinaryTree(Root->TNLeft);
		LRNBinaryTree(Root->TNRight);
		cout << Root->data << " ";
	}
}

#pragma endregion

void inputBinaryTree(BinaryTree& T)
{
	int n, x;
	cout << "Nhap so luong phan tu cua cay nhi phan: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao cay nhi phan: ";
		cin >> x;
		while (insertTNode(T, x) == 0)
		{
			cout << "Da ton tai phan tu nay!!!" << endl;
			cout << "Nhap lai phan tu thu " << i << " vao cay nhi phan: ";
			cin >> x;
		}
	}
}

void printBinaryTree(BinaryTree T)
{
	int n;
	cout << "Chon loai duyet cay nhi phan (1-NLR, 2-LNR, 3-LRN): ";
	cin >> n;
	switch (n)
	{
		case 1: NLRBinaryTree(T); break;
		case 2: LNRBinaryTree(T); break;
		case 3: LRNBinaryTree(T); break;
		default:
			break;
	}
}

int heightOfTree(TNode* t)
{
	if (t == NULL) return 0;
	int leftHeight = heightOfTree(t->TNLeft);
	int rightHeight = heightOfTree(t->TNRight);
	return max(leftHeight, rightHeight) + 1;
}

#pragma endregion

#pragma region BalanceTree

#pragma region BalFactor
const int LH = -1; // cây con trái cao hơn
const int EH = 0;  // cây con trái bằng cây con phải
const int RH = 1;  // cây con phải cao hơn
#pragma endregion

#pragma region create

typedef struct AVLNode
{
	int data;
	struct AVLNode* AVLLeftNode;
	struct AVLNode* AVLRightNode;
	int balFactor; // chỉ số cân bằng
};

typedef AVLNode* AVLTree;

void createAVLTree(AVLTree& T)
{
	T = NULL;
}

AVLNode* createAVLNode(int x)
{
	AVLNode* p;
	p = new AVLNode;
	if (p == NULL) return NULL;
	p->data = x;
	p->AVLLeftNode = NULL;
	p->AVLRightNode = NULL;
	p->balFactor = EH;
	return p;
}

#pragma endregion

//các phép quay 
#pragma region Rotations

void LL(AVLTree& T)
{
	AVLNode* T1 = T->AVLLeftNode;
	T->AVLLeftNode = T1->AVLRightNode;
	T1->AVLRightNode = T;
	switch (T1->balFactor)
	{
	case LH: T->balFactor = EH; T1->balFactor = EH; break;
	case EH: T->balFactor = LH; T1->balFactor = RH; break;
	}
	T = T1;
}

void LR(AVLTree& T) {
	AVLNode* T1, * T2;
	T1 = T->AVLLeftNode;
	T2 = T1->AVLRightNode;
	T1->AVLRightNode = T2->AVLLeftNode;
	T->AVLLeftNode = T2->AVLRightNode;
	T2->AVLLeftNode = T1;
	T2->AVLRightNode = T;
	switch (T2->balFactor)
	{
	case LH: T->balFactor = RH; T1->balFactor = EH; break;
	case EH: T->balFactor = EH; T1->balFactor = EH; break;
	case RH: T->balFactor = EH; T1->balFactor = LH; break;
	}
	T2->balFactor = EH;
	T = T2;
}

void RR(AVLTree& T)
{
	AVLNode* T1 = T->AVLRightNode;
	T->AVLRightNode = T1->AVLLeftNode;
	T1->AVLLeftNode = T;
	switch (T1->balFactor)
	{
	case EH: T->balFactor = RH; T1->balFactor = LH; break;
	case RH: T->balFactor = EH; T1->balFactor = EH; break;
	}
	T = T1;
}

void RL(AVLTree& T)
{
	AVLNode* T1, * T2;
	T1 = T->AVLRightNode;
	T2 = T1->AVLLeftNode;
	T->AVLRightNode = T2->AVLLeftNode;
	T2->AVLLeftNode = T;
	T1->AVLLeftNode = T2->AVLRightNode;
	T2->AVLRightNode = T1;
	switch (T2->balFactor)
	{
	case LH: T->balFactor = EH; T1->balFactor = RH; break;
	case EH: T->balFactor = EH; T1->balFactor = EH; break;
	case RH: T->balFactor = LH; T1->balFactor = EH; break;
	}
	T2->balFactor = EH;
	T = T2;
}

#pragma endregion 

#pragma region Insert

bool insertAVLNode(AVLTree& T, int x, bool& taller)
{
	if (T == NULL)
	{
		T = createAVLNode(x);
		if (T == NULL) return false;
		taller = true;
		return true;
	}

	if (x < T->data)
	{
		//chèn qua nhánh con bên trái 
		//nếu chèn không được thì trả về false
		if (!insertAVLNode(T->AVLLeftNode, x, taller))
			return false;
		//sau khi chèn xong thì cân bằng cây 
		if (taller)
		{
			switch (T->balFactor)
			{
			case LH: //nếu ban đầu cây con trái cao hơn => giữ nguyên chỉ số
				if (T->AVLLeftNode->balFactor == LH) //bên trái của cây con cao hơn
					LL(T); // quay LL
				else
					LR(T); // quay RL
				taller = false;
				break;
			case EH: // nếu ban đầu cây đã cân bằng 
				T->balFactor = LH; // sau khi thêm node mới thì cây con bên trái cao hơn
				taller = true;
				break;
			case RH: //nếu ban đầu cây con bên phải cao hơn
				T->balFactor = EH; // sau khi thêm node mới thì cây đã cân bằng
				taller = false;
				break;
			}
		}
	}
	else if (x > T->data)
	{
		//chèn qua cây con bên phải
		//nếu chèn không được thì trả vê false
		if (!insertAVLNode(T->AVLRightNode, x, taller))
			return false;
		if (taller) {
			switch (T->balFactor)
			{
			case RH: //nếu ban đầu cây con bên phải cao hơn => giữ nguyên chỉ số
				if (T->AVLRightNode->balFactor == RH) //bên phải của cây con phải cao hơn
					RR(T); // quay RR
				else
					RL(T); // quay RL
				taller = false;
				break;
			case EH: //ban đầu cây đã cân bằng
				T->balFactor = RH;
				taller = true;
				break;
			case LH: //nếu ban đầu cây con trái cao hơn
				T->balFactor = EH;
				taller = false;
				break;
			}
		}
	}
	else
	{
		taller = false;
		return false;
	}
	return true;
}

#pragma endregion

#pragma region Delete

//thay bằng node nhỏ nhất bên cây con bên phải
void replaceAVLNode(AVLTree& p, AVLTree& T)
{
	if (T->AVLLeftNode != NULL)
		replaceAVLNode(p, T->AVLLeftNode);
	else
	{
		p->data = T->data;
		p = T;
		T = T->AVLRightNode;
	}
}

bool deleteAVLNode(AVLTree& T, int x, bool& shorter)
{
	if (T == NULL)
	{
		shorter = false;
		return false;
	}

	if (x < T->data)
	{
		if (!deleteAVLNode(T->AVLLeftNode, x, shorter)) return false;

		if (shorter)
		{
			switch (T->balFactor)
			{
			case LH: //Nếu ban đầu cây con trái cao hơn
				T->balFactor = EH;
				shorter = true;
				break;
			case EH: //nếu ban đầu cây đã cân bằng => cây con phải sẽ cao hơn
				T->balFactor = RH;
				shorter = false;
				break;
			case RH: // nếu ban đầu cây con phải cao hơn
				if (T->AVLRightNode->balFactor == RH)
					RR(T);
				else
					RL(T);
				shorter = true;
			}
		}
	}
	else if (x > T->data)
	{
		if (!deleteAVLNode(T, x, shorter))
			return false;

		if (shorter)
		{
			switch (T->balFactor)
			{
			case RH: //nếu cây con bên phải cao hơn => sau khi xóa node thì cây cân bằng
				T->balFactor = EH;
				shorter = true;
				break;
			case EH: //nếu ban đầu cây cân bằng => sau khi xóa node thì cây con bên trái cao hơn
				T->balFactor = LH;
				shorter = false;
				break;
			case LH: // nếu ban đầu cây con trái cao hơn => cần cân bằng lại bằng các phép quay trái 
				if (T->AVLLeftNode->balFactor == LH)
					LL(T);
				else
					LR(T);
				shorter = true;
				break;
			}
		}
	}
	else
	{
		if (T->AVLLeftNode == NULL) // TH không có cây con trái
		{
			T = T->AVLRightNode;
			shorter = true;
		}
		else if (T->AVLRightNode == NULL)
		{
			T = T->AVLLeftNode;
			shorter = true;
		} 
		else
		{
			AVLNode* p;
			p = T;
			replaceAVLNode(p, T->AVLRightNode);//tìm phần tử thay thế và thế vào chỗ đã xóa
			deleteAVLNode(T->AVLRightNode, p->data, shorter);//xóa phần tử thay thế

			if (shorter)
			{
				switch (T->balFactor)
				{
				case RH: //nếu ban đầu cây con bên phải cao hơn => sau khi xóa node bên phải thì cây cân bằng
					T->balFactor = EH;
					shorter = true;
					break;
				case EH: //nếu ban đầu cây cân bằng => sau khi xóa node bên phải thì cây con trái cao hơn
					T->balFactor = LH;
					shorter = false;
				case LH: // nếu cây con bên trái cao hơn => sau khi xóa node bên phải thì cần quay trái để cân bằng cây
					if (T->AVLLeftNode->balFactor == LH)
						LL(T);
					else
						LR(T);
					shorter = true;
					break;
				}

			}
		}

		
	}
	return true;
}

#pragma endregion


#pragma region BrowseBalanceTree

void NLRAVLTree(AVLTree T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		NLRAVLTree(T->AVLLeftNode);
		NLRAVLTree(T->AVLRightNode);
	}
	return;
}

void LNRAVLTree(AVLTree T)
{
	if (T != NULL)
	{
		LNRAVLTree(T->AVLLeftNode);
		cout << T->data << " ";
		LNRAVLTree(T->AVLRightNode);
	}
}

void LRNAVLTree(AVLTree T)
{
	if (T != NULL)
	{
		LRNAVLTree(T->AVLLeftNode);
		LRNAVLTree(T->AVLRightNode);
		cout << T->data << " ";
	}
}

#pragma endregion

void inputAVLTree(AVLTree& T)
{
	int n, x;
	cout << "Nhap so luong phan tu cua cay nhi phan can bang: ";
	cin >> n;
	bool taller;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao cay: ";
		cin >> x;
		insertAVLNode(T, x, taller);
	}
}

void printAVLTree(AVLTree T)
{
	int n;
	cout << "Chon loai duyet cay nhi phan (1-NLR, 2-LNR, 3-LRN): ";
	cin >> n;
	switch (n)
	{
		case 1: NLRAVLTree(T); break;
		case 2: LNRAVLTree(T); break; 
		case 3: LRNAVLTree(T); break;
		default:
			break;
	}
}

#pragma endregion

#pragma region HashingTable

typedef Node* HashTable[MAX];

void initHashTable(HashTable& H)
{
	for (int i = 0; i < MAX; i++)
		H[i] = NULL;
}

int Hash(int key, int M)
{
	return (key % M);
}

void addTailHSList(Node*& HT, int k)
{
	Node* newNode = new Node;
	newNode->data = k;
	newNode->nextNode = NULL;
	if (HT == NULL) {
		HT = newNode;
	} 
	else
	{
		Node* p = HT;
		while (p != NULL && p->nextNode != NULL)
			p = p->nextNode;
		p->nextNode = newNode;
	}
}

void insertHTNode(HashTable& HT, int k)
{
	int i = Hash(k, MAX);
	addTailHSList(HT[i], k);
}

Node* searchNodeHS(HashTable& HT, int k)
{
	int i = Hash(k, MAX);
	Node* p = HT[i];
	while (p != NULL && p->data != k)
		p = p->nextNode;
	if (p == NULL)
		return NULL;
	return p;
}

void inputHS(HashTable& HT)
{
	int n, k;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap phan tu thu " << i << " vao HashTable: ";
		cin >> k;
		insertHTNode(HT, k);
	}
}

#pragma endregion




int main() 
{

	return 1;
}