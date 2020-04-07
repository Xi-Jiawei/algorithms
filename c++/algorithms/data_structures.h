#pragma once
// data_structures.h
//

#include <iostream>
#include <queue>
using namespace std;

#include "strings.h"

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��20��
*����: ʵ��ջ����ӡ�ɾ������
*/
#pragma region ջ���Ƚ������
class Stack {
private:
	int *a;//����
	int maxSize;//ջ����
	int top;//��ջ��������ʾջʵ�ʴ洢��������-1��ʾû�д������ݣ�Ϊ��ջ

public:
	Stack(int maxSize) {
		this->maxSize = maxSize;
		this->a = new int[this->maxSize];
		this->top = -1;//-1��ʾ��ջ
	}

	/*��ջ*/
	void push(int value) {
		if (this->top == this->maxSize - 1) {
			cout << "stack is full!" << endl;
			return;
		}
		a[++top] = value;
	}

	/*���ض�ջ�����Ƴ�֮*/
	int pop() {
		if (this->top == -1) {
			cout << "stack is empty!" << endl;
			return 0;
		}
		return a[top--];
	}

	/*���ض�ջ�������Ƴ�*/
	int peek() {
		if (this->top == -1) {
			cout << "stack is empty!" << endl;
			return 0;
		}
		return a[top];
	}

	/*����ʵ�ʴ洢����*/
	int size() {
		return this->top + 1;
	}
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��20��
*����: ʵ��˳��ѭ�����е���ӡ�ɾ������
*/
#pragma region ���У��Ƚ��ȳ���
/*˳��ѭ������
  ˵������˳��ṹ�洢�Ķ��г�Ϊ˳����У���Ϊһ���˳����еĶ���������this->end=this->maxSize������ּ���������
        Ϊ�˷����������⣬��˳����еĻ�������Ƴ�˳��ѭ�����У����Ϊѭ�����У�����һ����β��ӵĻ���
        ʵ����һ��ʹ��˳��ѭ������
        ѭ�����ж���ʱԪ�ظ���ΪmaxSize-1*/
class RoundQueue {
private:
	long *a;//����
	int maxSize;//��������
	int m_size; //ʵ�ʴ洢����
	int start;//��ʼ����
	int end;//��������

public:
	RoundQueue(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize];
		this->start = 0;
		this->end = 0;//this->start=this->end��ʾ����Ϊ��,this->start=(this->end+1)%this->maxSize��ʾ������
		this->m_size = 0;
	}

	/*�������*/
	void push(long value) {
		/*if (this->m_size == this->maxSize) {
			cout << "queue is full!" << endl;
			return;
		}*/
		if (this->start == (this->end + 1) % this->maxSize) {
			cout << "queue is full!" << endl;
			return;
		}
		a[end] = value;
		end = ++end%maxSize;
		this->m_size++;
	}

	/*���ض���ͷ�����Ƴ�֮*/
	long pop() {
		/*if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}*/
		if (this->start == this->end) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		long result = a[start];
		start = ++start%maxSize;
		this->m_size--;
		return result;
	}

	/*���ض���ͷ�������Ƴ�*/
	long peek() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[start];
	}

	/*����ʵ�ʴ洢����*/
	int size() {
		return this->m_size;
	}
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��21��
*����: ʵ�����ѡ���С�ѵ�������ݼ�ɾ���Ѷ�����
*/
#pragma region ��
/*�ѵ��߼��ṹΪ��ȫ���������洢�ṹ���������飺
����ȫ�������У�����ǰ�ڵ���±�Ϊ i�� ���丸�ڵ���±�Ϊ i / 2�������ӽڵ���±�Ϊ i * 2�������ӽڵ���±�Ϊi * 2 + 1��*/
class MaxHeap
{
private:
	long *a;//����
	int maxSize;//��������
	int m_size; //ʵ�ʴ洢����
public:
	MaxHeap(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize+1];//Ԫ��������1��ʼ��a[0]����Ԫ��
		this->m_size = 0;
	}

	void push(int value) {
		this->a[++m_size] = value;
		//adjust();//�ϸ�+�³�
		shift_up();//�ϸ�
	}

	long pop() {
		int top = this->a[1];
		this->a[1] = this->a[this->m_size--];
		shift_down();//�³�
		return top;
	}

	long peek() { return this->a[1]; }

	static void insert(long *a, long value, int &size) {
		a[++size] = value;
	}
	static void adjust(long *a, int size) {
		//�ϸ�����m_size / 2��㿪ʼ���ȱȽ������ӽ�㣬�����нϴ�����븸����û������αȽϣ�ֱ������㣻
		//�³����������ӽ�����бȸ������������ô�ӽ����ӽ�����Ҳ���д��ڸ��������������ٽ��ӽ����ӽ���븸���Ƚ�
		for (int i = size / 2; i > 0; i--)
		{
			a[0] = a[i];//�ݴ游���
			int childIndex = i * 2;
			while (childIndex <= size)
			{
				if (childIndex < size && a[childIndex] < a[childIndex + 1])
					childIndex++;
				if (a[childIndex] < a[0])break;
				else
				{
					a[childIndex / 2] = a[childIndex];//�ϸ�����
					childIndex *= 2;//�³�����
				}
			}
			a[childIndex / 2] = a[0];
		}
	}
	static void shift_up(long *a, int size) {
		int childIndex = size;
		while (childIndex > 1)
		{
			a[0] = a[childIndex / 2];//�ݴ游���
			if (a[childIndex] < a[0])
				break;
			else {
				a[childIndex / 2] = a[childIndex];
				a[childIndex] = a[0];
				childIndex /= 2;
			}
		}
	}
	static void shift_down(long *a, int size) {
		int parentIndex = 1, maxIndex;
		while (parentIndex <= size / 2)
		{
			a[0] = a[parentIndex];//�ݴ游���
			if (parentIndex * 2 < size&&a[parentIndex * 2] < a[parentIndex * 2 + 1])
				maxIndex = parentIndex * 2 + 1;
			else maxIndex = parentIndex * 2;
			if (a[maxIndex] < a[0])break;
			else {
				a[parentIndex] = a[maxIndex];
				a[maxIndex] = a[0];
			}
			parentIndex = maxIndex;
		}
	}

	/*�ϸ�+�³�*/
	void adjust(){
		//�ϸ�����m_size / 2��㿪ʼ���ȱȽ������ӽ�㣬�����нϴ�����븸����û������αȽϣ�ֱ������㣻
		//�³����������ӽ�����бȸ������������ô�ӽ����ӽ�����Ҳ���д��ڸ��������������ٽ��ӽ����ӽ���븸���Ƚ�
		for (int i = this->m_size / 2; i > 0; i--)
		{
			this->a[0] = this->a[i];//�ݴ游���
			int childIndex = i * 2;
			while (childIndex <= this->m_size)
			{
				if (childIndex < this->m_size && this->a[childIndex] < this->a[childIndex + 1])
					childIndex++;
				if (this->a[childIndex] < this->a[0])break;
				else
				{
					this->a[childIndex / 2] = this->a[childIndex];//�ϸ�����
					childIndex *= 2;//�³�����
				}
			}
			this->a[childIndex / 2] = this->a[0];
		}
	}

	/*�ϸ�*/
	void shift_up() {
		int childIndex = this->m_size;
		while (childIndex > 1)
		{
			this->a[0] = this->a[childIndex / 2];//�ݴ游���
			if (this->a[childIndex] < this->a[0])
				break;
			else {
				this->a[childIndex / 2] = this->a[childIndex];
				this->a[childIndex] = this->a[0];
				childIndex /= 2;
			}
		}
	}

	/*�³�*/
	void shift_down() {
		int parentIndex = 1, maxIndex;
		while (parentIndex <= this->m_size / 2)
		{
			this->a[0] = this->a[parentIndex];//�ݴ游���
			if (parentIndex * 2 < this->m_size&&this->a[parentIndex * 2] < this->a[parentIndex * 2 + 1])
				maxIndex = parentIndex * 2 + 1;
			else maxIndex = parentIndex * 2;
			if (this->a[maxIndex] < this->a[0])break;
			else {
				this->a[parentIndex] = this->a[maxIndex];
				this->a[maxIndex] = this->a[0];
			}
			parentIndex = maxIndex;
		}
	}

	int size() { return this->m_size; }

	void print(){
		cout << "heap.a: " << endl;
		for (int i = 1; i <= this->m_size; i++)
			cout << this->a[i] << endl;
	}
};

class MinHeap
{
private:
	long *a;//����
	int maxSize;//��������
	int m_size; //ʵ�ʴ洢����
public:
	MinHeap(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize + 1];//Ԫ��������1��ʼ��a[0]����Ԫ��
		this->m_size = 0;
	}

	void push(int value) {
		this->a[++m_size] = value;
		//adjust();//�ϸ�+�³�
		shift_up();//�ϸ�
	}

	long pop() {
		int top = this->a[1];
		this->a[1] = this->a[this->m_size--];
		shift_down();//�³�
		return top;
	}

	long peek() { return this->a[1]; }

	static void insert(long *a, long value, int &size) {
		a[++size] = value;
	}
	static void adjust(long *a, int size) {
		//�ϸ�����m_size / 2��㿪ʼ���ȱȽ������ӽ�㣬�����нϴ�����븸����û������αȽϣ�ֱ������㣻
		//�³����������ӽ�����бȸ������������ô�ӽ����ӽ�����Ҳ���д��ڸ��������������ٽ��ӽ����ӽ���븸���Ƚ�
		for (int i = size / 2; i > 0; i--)
		{
			a[0] = a[i];
			int childIndex = i * 2;
			while (childIndex <= size)
			{
				if (childIndex < size && a[childIndex] > a[childIndex + 1])
					childIndex++;
				if (a[childIndex] > a[0])break;
				else
				{
					a[childIndex / 2] = a[childIndex];//�ϸ�����
					childIndex *= 2;//�³�����
				}
			}
			a[childIndex / 2] = a[0];
		}
	}
	static void shift_up(long *a, int size) {
		int childIndex = size;
		while (childIndex > 1)
		{
			a[0] = a[childIndex / 2];//�ݴ游���
			if (a[childIndex] > a[0])
				break;
			else {
				a[childIndex / 2] = a[childIndex];
				a[childIndex] = a[0];
				childIndex /= 2;
			}
		}
	}
	static void shift_down(long *a, int size) {
		int parentIndex = 1, minIndex;
		while (parentIndex <= size / 2)
		{
			a[0] = a[parentIndex];//�ݴ游���
			if (parentIndex * 2 < size&&a[parentIndex * 2] > a[parentIndex * 2 + 1])
				minIndex = parentIndex * 2 + 1;
			else minIndex = parentIndex * 2;
			if (a[minIndex] > a[0])break;
			else {
				a[parentIndex] = a[minIndex];
				a[minIndex] = a[0];
			}
			parentIndex = minIndex;
		}
	}

	/*�ϸ�+�³�*/
	void adjust() {
		//�ϸ�����m_size / 2��㿪ʼ���ȱȽ������ӽ�㣬�����нϴ�����븸����û������αȽϣ�ֱ������㣻
		//�³����������ӽ�����бȸ������������ô�ӽ����ӽ�����Ҳ���д��ڸ��������������ٽ��ӽ����ӽ���븸���Ƚ�
		for (int i = this->m_size / 2; i > 0; i--)
		{
			this->a[0] = this->a[i];//�ݴ游���
			int childIndex = i * 2;
			while (childIndex <= this->m_size)
			{
				if (childIndex < this->m_size && this->a[childIndex] > this->a[childIndex + 1])
					childIndex++;
				if (this->a[childIndex] > this->a[0])break;
				else
				{
					this->a[childIndex / 2] = this->a[childIndex];//�ϸ�����
					childIndex *= 2;//�³�����
				}
			}
			this->a[childIndex / 2] = this->a[0];
		}
	}

	/*�ϸ�*/
	void shift_up() {
		int childIndex = this->m_size;
		while (childIndex > 1)
		{
			this->a[0] = this->a[childIndex / 2];//�ݴ游���
			if (this->a[childIndex] > this->a[0])
				break;
			else {
				this->a[childIndex / 2] = this->a[childIndex];
				this->a[childIndex] = this->a[0];
				childIndex /= 2;
			}
		}
	}

	/*�³�*/
	void shift_down() {
		int parentIndex = 1, minIndex;
		while (parentIndex <= this->m_size / 2)
		{
			this->a[0] = this->a[parentIndex];//�ݴ游���
			if (parentIndex * 2 < this->m_size&&this->a[parentIndex * 2] > this->a[parentIndex * 2 + 1])
				minIndex = parentIndex * 2 + 1;
			else minIndex = parentIndex * 2;
			if (this->a[minIndex] > this->a[0])break;
			else {
				this->a[parentIndex] = this->a[minIndex];
				this->a[minIndex] = this->a[0];
			}
			parentIndex = minIndex;
		}
	}

	int size() { return this->m_size; }

	void print() {
		//cout << "heap.a: " << endl;
		for (int i = 1; i <= this->m_size; i++)
			cout << this->a[i] << endl;
	}
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��22��
*����: ʵ�����ȶ��е�������ݼ�ɾ������ֵ����
*/
#pragma region ���ȶ���
/*�ֳ����ȼ����У���һ��������У�����С�ź���Ķ��У�������������ʵ�֡�
��Ϊ�����Ѿ�д�˶ѵ�ʵ�֣�����չʾ����������ʵ��������ȶ��С�
���������ʵ�֣�����С˳�����δ洢��a[0]�����ȼ���͵ģ�a[size-1]�����ȼ���ߵ�*/
class MaxPriorityQueue {
private:
	long *a;//����
	int maxSize;//��������
	int m_size; //ʵ�ʴ洢����

public:
	MaxPriorityQueue(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize];
		this->m_size = 0;
	}

	/*�������*/
	void push(long value) {
		if (this->m_size == this->maxSize) {
			cout << "queue is full!" << endl;
			return;
		}
		if (this->m_size == 0) {
			this->a[this->m_size++] = value; 
			return;
		}
		//�����ȼ���ߵ�����ʼ�Ƚϣ�������Ƚ������ڲ��������򱻱Ƚ���������һλ��Ҳ����˵�����������������ĩλ�ã��������󲻴���ԭ��˳��
		int index;
		for (int i = this->m_size - 1; i >= 0; i--) {
			if (this->a[i] > value) {
				this->a[i + 1] = this->a[i];
				index = i;
			}
			else {
				index = i + 1;
				break;
			}
		}
		this->a[index] = value;
		this->m_size++;
	}

	/*���ض���ͷ�����Ƴ�֮*/
	long pop() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[--m_size];
	}

	/*���ض���ͷ�������Ƴ�*/
	long peek() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[m_size - 1];
	}

	/*����ʵ�ʴ洢����*/
	int size() {
		return this->m_size;
	}

	void print() {
		cout << "queue.a: " << endl;
		for (int i = 0; i < this->m_size; i++)
			cout << this->a[i] << endl;
	}
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��22��
*����: ʵ�ֵ�����������Ĳ��롢ɾ�������ҹ���
*/
#pragma region ����������������
struct Node {
	int data;
	Node* next;

	Node() {
		this->data = 0;
		this->next = NULL;
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
class SortedList {
private:
	Node *first=NULL;//��ʼ�ڵ�
	int m_size=0;//�ڵ�����

public:
	/*����*/
	void insert(int value);

	/*�Ƴ�*/
	void remove(int value);

	/*����*/
	Node* find(int value);

	/*����*/
	int size();
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��22��
*����: ʵ��˫����������Ĳ��롢ɾ�������ҹ���
*/
#pragma region ����˫����������
struct DoublyNode {
	int data;
	DoublyNode* previous;
	DoublyNode* next;

	DoublyNode(int data) {
		this->data = data;
		this->previous = NULL;
		this->next = NULL;
	}
};
class DoublySortedList {
private:
	DoublyNode *first = NULL;//��ʼ�ڵ�
	DoublyNode *last = NULL;//��ֹ�ڵ�
	int m_size = 0;//�ڵ�����

public:
	/*����*/
	void insert(int value);

	/*�Ƴ�*/
	void remove(int value);

	/*����*/
	DoublyNode* find(int value);

	/*����*/
	int size();
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��23��
*����: ʵ����ͨ�����������ӡ�ɾ�������ҹ���
*/
#pragma region ������ͨ��������
class List {
private:
	Node *first = NULL;//��ʼ�ڵ�
	int m_size = 0;//�ڵ�����

public:
	/*������ʼ�ڵ�*/
	void insertFirst(int value);

	/*ɾ����ʼ�ڵ�*/
	Node* removeFirst();

	/*����*/
	void insert(int value);

	/*�Ƴ�*/
	void remove(int value);

	/*����*/
	Node* find(int value);

	/*����*/
	int size();
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��23��
*����: ʵ����ͨ˫���������ӡ�ɾ�������ҹ���
*/
#pragma region ������ͨ˫������
class DoublyList {
private:
	DoublyNode *first = NULL;//��ʼ�ڵ�
	DoublyNode *last = NULL;//��ֹ�ڵ�
	int m_size = 0;//�ڵ�����

public:
	/*������ʼ�ڵ�*/
	void insertFirst(int value);

	/*ɾ����ʼ�ڵ�*/
	DoublyNode* removeFirst();

	/*������ֹ�ڵ�*/
	void insertLast(int value);

	/*ɾ����ֹ�ڵ�*/
	DoublyNode* removeLast();

	/*����*/
	void insert(int value);

	/*�Ƴ�*/
	void remove(int value);

	/*����*/
	DoublyNode* find(int value);

	/*����*/
	int size();
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��24��
*����: ʵ��һ����ͨ�������Ĺ���������
*/
#pragma region ��ͨ������
enum LeftOrRight {
	left = 0,
	right = 1
};
template <class Type>
struct TreeNode {
	Type data;
	TreeNode<Type> *leftchild, *rightchild;
};
template <class Type>
class BinaryTree {
private:
	TreeNode<Type> *root;
	int m_size;
	void release(TreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			release(treeNode->leftchild);
			release(treeNode->rightchild);
			delete treeNode;
		}
	}
	bool insertNode(Type data, Type parent, int leftOrRight, TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return false;
		if (treeNode->data == parent) {
			TreeNode<Type> *newNode = new TreeNode<Type>();
			newNode->data = data;
			if (leftOrRight == LeftOrRight::left&&treeNode->leftchild == NULL) {
				treeNode->leftchild = newNode; 
				return true;
			}
			else if (leftOrRight == LeftOrRight::right&&treeNode->rightchild == NULL) {
				treeNode->rightchild = newNode;
				return true;
			}
			else return false;
		}
		if (insertNode(data, parent, leftOrRight, treeNode->leftchild) || insertNode(data, parent, leftOrRight, treeNode->rightchild))
			return true;
		else return false;
	}
	void preOrderTraverse(TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			cout << treeNode->data << " ";
			preOrderTraverse(treeNode->leftchild);
			preOrderTraverse(treeNode->rightchild);
		}
	}
	void inOrderTraverse(TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			inOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
			inOrderTraverse(treeNode->rightchild);
		}
	}
	void postOrderTraverse(TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			postOrderTraverse(treeNode->rightchild);
			postOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
		}
	}
	/*��α������ǵݹ�*/
	void levelOrderTraverse(TreeNode<Type> *root) {
		queue<TreeNode<Type>*> queue;//�������У����ڲ�α���
		if (root == NULL) {
			return;
		}
		queue.push(root);
		TreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << temp->data << " ";
				if (temp->leftchild != NULL) {
					queue.push(temp->leftchild);
				}
				if (temp->rightchild != NULL) {
					queue.push(temp->rightchild);
				}
			}
			cout << endl;//����
		}
	}
public:
	BinaryTree() : root(NULL), m_size(0) {}
	BinaryTree(Type data) : root(NULL), m_size(0) {
		TreeNode<Type> *newNode = new TreeNode<Type>();
		newNode->data = data;
		this->root = newNode;
		this->m_size++;
	}
	~BinaryTree() { release(root); }
	void insertRoot(Type data) {
		TreeNode<Type> *newNode = new TreeNode<Type>();
		newNode->data = data;
		this->root = newNode;
		this->m_size++;
	}
	void insert(Type data, Type parent, int leftOrRight) { if (!insertNode(data, parent, leftOrRight, root))cout << "insert failed" << endl; }
	void preOrder() {
		preOrderTraverse(root);
		cout << endl;
	}
	void inOrder() {
		inOrderTraverse(root);
		cout << endl;
	}
	void postOrder() {
		postOrderTraverse(root);
		cout << endl;
	}
	void levelOrder() { levelOrderTraverse(root); }
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��24��
*����: ʵ�ֶ���������Ĳ��롢ɾ�������ҹ���
*/
#pragma region ����������������������������������
/*template <class Type>
struct TreeNode{
	Type data;
	TreeNode<Type> *leftchild, *rightchild;
};*/
template <class Type>
class BinarySearchTree {
private:
	TreeNode<Type> *root;
	int m_size;
	void release(TreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			release(treeNode->leftchild);
			release(treeNode->rightchild);
			delete treeNode;
		}
	}
	void insertNode(TreeNode<Type> * &parentNode,Type data) {
		if (NULL == parentNode) {
			parentNode = new TreeNode<Type>();
			parentNode->data = data;
			m_size++;
			return;
		}
		if (parentNode->data > data)
			insertNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			insertNode(parentNode->rightchild, data);
	}
	TreeNode<Type> *findNode(TreeNode<Type> * &parentNode, Type data) {
		if (NULL == parentNode) return NULL;
		if (parentNode->data == data) return parentNode;
		if (parentNode->data > data)
			findNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			findNode(parentNode->rightchild, data);
	}
	void removeNode(TreeNode<Type> * &parentNode, Type data) {
		if (NULL == parentNode) return;
		if (parentNode->data == data) {
			if (parentNode->leftchild == NULL&&parentNode->rightchild == NULL)
				delete parentNode;
			else if (parentNode->leftchild != NULL&&parentNode->rightchild == NULL)
				parentNode = parentNode->leftchild;
			else if (parentNode->leftchild == NULL&&parentNode->rightchild != NULL)
				parentNode = parentNode->rightchild;
			else if (parentNode->leftchild != NULL&&parentNode->rightchild != NULL)
				parentNode->data = removeMinNode(parentNode->rightchild)->data;
			return;
		}
		if (parentNode->data > data)
			removeNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			removeNode(parentNode->rightchild, data);
	}
	TreeNode<Type> *removeMinNode(TreeNode<Type> *&parentNode) {
		if (NULL == parentNode->leftchild) {
			TreeNode<Type> *treeNode = parentNode;
			parentNode = parentNode->rightchild;
			return treeNode;
		}
		removeMinNode(parentNode->leftchild);
	}
	void preOrderTraverse(TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			cout << treeNode->data << " ";
			preOrderTraverse(treeNode->leftchild);
			preOrderTraverse(treeNode->rightchild);
		}
	}
	void inOrderTraverse(TreeNode<Type> *treeNode){
		if (NULL == treeNode)return;
		else
		{
			inOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
			inOrderTraverse(treeNode->rightchild);
		}
	}
	void postOrderTraverse(TreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			postOrderTraverse(treeNode->rightchild);
			postOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
		}
	}
	/*��α������ǵݹ�*/
	void levelOrderTraverse(TreeNode<Type> *root) {
		queue<TreeNode<Type>*> queue;//�������У����ڲ�α���
		if (root == NULL) {
			return;
		}
		queue.push(root);
		TreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << temp->data << " ";
				if (temp->leftchild != NULL) {
					queue.push(temp->leftchild);
				}
				if (temp->rightchild != NULL) {
					queue.push(temp->rightchild);
				}
			}
			cout << endl;//����
		}
	}
public:
	BinarySearchTree() : root(NULL), m_size(0) {}
	~BinarySearchTree() { release(root); }
	void insert(Type data) { insertNode(root, data); }
	TreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	TreeNode<Type> *removeMin() { return removeMinNode(root); }
	void preOrder() {
		preOrderTraverse(root);
		cout << endl;
	}
	void inOrder() {
		inOrderTraverse(root);
		cout << endl;
	}
	void postOrder() {
		postOrderTraverse(root);
		cout << endl;
	}
	void levelOrder() { levelOrderTraverse(root); }
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��26��
*����: ʵ��ƽ��������Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region ƽ���������AVL��
template <class Type>
struct BalanceBinaryTreeNode {
	Type data;
	int level;
	BalanceBinaryTreeNode<Type> *leftchild, *rightchild;
};
template <class Type>
class BalanceBinaryTree {
private:
	BalanceBinaryTreeNode<Type> *root;
	int m_size;
	int m_level;
	void release(BalanceBinaryTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			release(treeNode->leftchild);
			release(treeNode->rightchild);
			delete treeNode;
		}
	}
	int height(BalanceBinaryTreeNode<Type> *node) {
		return (NULL == node) ? 0 : node->level;
	}
	/*���LL�ͣ�����*/
	void rightRotate(BalanceBinaryTreeNode<Type> *&node) {
		/*�����ӽڵ���Ϊ�¸��ڵ�result*/
		BalanceBinaryTreeNode<Type> *result = node->leftchild;

		/*�����ӽڵ���ҽڵ�ָ��ɸ��ڵ�node�������ɸ��ڵ�����ӽڵ�ָ�����ӽڵ���ҽڵ�*/
        #pragma region �Ƚ����ӽ���ݴ棬Ȼ���滻
		/*BalanceBinaryTreeNode<Type> *temp = result->rightchild;
		result->rightchild = node;
		node->leftchild = temp;*/
        #pragma endregion
        #pragma region ������滻����
		node->leftchild = result->rightchild;
		result->rightchild = node;
        #pragma endregion

		/*���¸߶�*/
		node->level = max(height(node->leftchild), height(node->rightchild)) + 1;
		result->level = max(height(result->leftchild), height(result->rightchild)) + 1;

		node=result;
	}
	/*���RR�ͣ�����*/
	void leftRotate(BalanceBinaryTreeNode<Type> *&node) {
		/*�����ӽڵ���Ϊ�¸��ڵ�result*/
		BalanceBinaryTreeNode<Type> *result = node->rightchild;

		/*�����ӽڵ���ҽڵ�ָ��ɸ��ڵ�node�������ɸ��ڵ�����ӽڵ�ָ�����ӽڵ���ҽڵ�*/
        #pragma region �Ƚ����ӽ���ݴ棬Ȼ���滻
		/*BalanceBinaryTreeNode<Type> *temp = result->leftchild;
		result->leftchild = node;
		node->rightchild = temp;*/
        #pragma endregion
        #pragma region ������滻����
		node->rightchild = result->leftchild;
		result->leftchild = node;
        #pragma endregion

		/*���¸߶�*/
		node->level = max(height(node->leftchild), height(node->rightchild)) + 1;
		result->level = max(height(result->leftchild), height(result->rightchild)) + 1;

		node = result;
	}
	void insertNode(BalanceBinaryTreeNode<Type> * &parentNode, Type data) {
		if (NULL == parentNode) {
			parentNode = new BalanceBinaryTreeNode<Type>();
			parentNode->data = data;
			parentNode->level = 1;
			m_size++;
			return;
		}
		else if (parentNode->data > data) {
			insertNode(parentNode->leftchild, data);
		}
		else if (parentNode->data < data) {
			insertNode(parentNode->rightchild, data);
		}

		parentNode->level = max(height(parentNode->leftchild), height(parentNode->rightchild)) + 1;

		int balenceFactor= (NULL == parentNode) ? 0 : height(parentNode->leftchild) - height(parentNode->rightchild);
		if (balenceFactor > 1 && parentNode->leftchild->data > data)rightRotate(parentNode);
		else if (balenceFactor > 1 && parentNode->leftchild->data < data) {/*���LR��ƽ�⣬��������������*/
			leftRotate(parentNode->leftchild);
			rightRotate(parentNode);
		}
		else if (balenceFactor < -1 && parentNode->rightchild->data < data)leftRotate(parentNode);
		else if (balenceFactor < -1 && parentNode->rightchild->data > data) {/*���RL��ƽ�⣬��������������*/
			rightRotate(parentNode->rightchild);
			leftRotate(parentNode);
		}
	}
	BalanceBinaryTreeNode<Type> *findNode(BalanceBinaryTreeNode<Type> * &parentNode, Type data) {
		if (NULL == parentNode) return NULL;
		if (parentNode->data == data) return parentNode;
		if (parentNode->data > data)
			findNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			findNode(parentNode->rightchild, data);
	}
	void removeNode(BalanceBinaryTreeNode<Type> * &parentNode, Type data) {
		if (NULL == parentNode) return;
		if (parentNode->data == data) {
			if (parentNode->leftchild == NULL&&parentNode->rightchild == NULL)
				delete parentNode;
			else if (parentNode->leftchild != NULL&&parentNode->rightchild == NULL)
				parentNode = parentNode->leftchild;
			else if (parentNode->leftchild == NULL&&parentNode->rightchild != NULL)
				parentNode = parentNode->rightchild;
			else if (parentNode->leftchild != NULL&&parentNode->rightchild != NULL)
				parentNode->data = removeMinNode(parentNode->rightchild)->data;
			return;
		}
		if (parentNode->data > data)
			removeNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			removeNode(parentNode->rightchild, data);
	}
	BalanceBinaryTreeNode<Type> *removeMinNode(BalanceBinaryTreeNode<Type> *&parentNode) {
		if (NULL == parentNode->leftchild) {
			BalanceBinaryTreeNode<Type> *treeNode = parentNode;
			parentNode = parentNode->rightchild;
			return treeNode;
		}
		removeMinNode(parentNode->leftchild);
	}
	void preOrderTraverse(BalanceBinaryTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			cout << treeNode->data << " ";
			preOrderTraverse(treeNode->leftchild);
			preOrderTraverse(treeNode->rightchild);
		}
	}
	void inOrderTraverse(BalanceBinaryTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			inOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
			inOrderTraverse(treeNode->rightchild);
		}
	}
	void postOrderTraverse(BalanceBinaryTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			postOrderTraverse(treeNode->rightchild);
			postOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
		}
	}
	/*��α������ǵݹ�*/
	void levelOrderTraverse(BalanceBinaryTreeNode<Type> *root) {
		queue<BalanceBinaryTreeNode<Type>*> queue;//�������У����ڲ�α���
		if (root == NULL) {
			return;
		}
		queue.push(root);
		BalanceBinaryTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << temp->data << " ";
				if (temp->leftchild != NULL) {
					queue.push(temp->leftchild);
				}
				if (temp->rightchild != NULL) {
					queue.push(temp->rightchild);
				}
			}
			cout << endl;//����
		}
	}
	/*��������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
	��Ϊ���Ľ��λ�����丸���λ����أ����Եݹ����ʱ��Ҫ���ݸ�����λ�á�*/
	void writeArray(BalanceBinaryTreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int level = row / 2 + 1;
		if (level == root->level)return;

		/*�ݹ������ӽ��*/
		//int gap = pow(2, root->level - level - 1) * 3;//3,6,12,...
		int gap = (2 << (root->level - level - 1));//2,4,8,...
		if (node->leftchild != NULL) {
			array[row + 1][col - gap / 2] = "/";
			writeArray(node->leftchild, array, row + 2, col - gap);
		}
		if (node->rightchild != NULL) {
			array[row + 1][col + gap / 2] = "\\";
			writeArray(node->rightchild, array, row + 2, col + gap);
		}
	}
public:
	BalanceBinaryTree() : root(NULL), m_size(0) {}
	~BalanceBinaryTree() { release(root); }
	void insert(Type data) { insertNode(root, data); }
	BalanceBinaryTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	BalanceBinaryTreeNode<Type> *removeMin() { return removeMinNode(root); }
	void preOrder() {
		preOrderTraverse(root);
		cout << endl;
	}
	void inOrder() {
		inOrderTraverse(root);
		cout << endl;
	}
	void postOrder() {
		postOrderTraverse(root);
		cout << endl;
	}
	void levelOrder() { levelOrderTraverse(root); }
	void printTree() {
		if (NULL == root)return;
		//int width = (pow(2, root->level - 1) - 1) * 6 + 1;//((2 << (m_height - 2)) - 1) * 6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
		int width = (pow(2, root->level - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1) * 4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
		//string array[2 * root->level - 1][width];
		string **array = new string*[2 * root->level - 1];
		for (int i = 0; i < 2 * root->level - 1; i++) {
			array[i] = new string[width];
			for (int j = 0; j < width; j++) {
				array[i][j] = " ";
			}
		}
		int a = 2 << (root->level - 2);
		//writeArray(root, array, 0, (pow(2, root->level - 1) - 1) * 3);//(pow(2, root->level - 1) - 1) * 3;
		writeArray(root, array, 0, (pow(2, root->level - 1) - 1) * 2);//(pow(2, root->level - 1) - 1) * 2;
		/*��ӡ����*/
		for (int i = 0; i < 2 * root->level - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//����
		}
	}
};
#pragma endregion

/**
*����: ϰ����
*�汾: version 1.0
*����: 2020��1��27��
*����: ʵ�ֺ�����Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region �����
enum {
	red = true,
	black = false,
};
template <class Type>
struct RedBlackTreeNode {
	Type data;
	bool color;//true��ʾ�죬false��ʾ��
	RedBlackTreeNode<Type> *leftchild, *rightchild, *parent;

	RedBlackTreeNode() :color(red), leftchild(NULL), rightchild(NULL), parent(NULL) {};
};
template <class Type>
class RedBlackTree {
private:
	RedBlackTreeNode<Type> *root;
	int m_size;
	int m_height;
	void release(RedBlackTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			release(treeNode->leftchild);
			release(treeNode->rightchild);
			delete treeNode;
		}
	}
	int height(RedBlackTreeNode<Type> *node) {
		return (NULL == node) ? 0 : max(height(node->leftchild), height(node->rightchild)) + 1;
	}
	bool isRed(RedBlackTreeNode<Type> *node) {
		return (NULL == node) ? false : node->color;
	}
	void flipColor(RedBlackTreeNode<Type> *&node) {
		node->color = red;
		node->leftchild->color = black;
		node->rightchild->color = black;
	}
	void rightRotate(RedBlackTreeNode<Type> *&node) {
		RedBlackTreeNode<Type> *treeNode = node;
		/*�����ӽڵ���Ϊ�¸��ڵ�result*/
		RedBlackTreeNode<Type> *result = node->leftchild;
		result->parent = node->parent;
		if (node == root)
			root = result;
		else {
			if (node == node->parent->leftchild)
				node->parent->leftchild = result;
			else node->parent->rightchild = result;
		}

		/*�����ӽڵ���ҽڵ�ָ��ɸ��ڵ�node�������ɸ��ڵ�����ӽڵ�ָ�����ӽڵ���ҽڵ�*/
		treeNode->leftchild = result->rightchild;
		if (NULL != result->rightchild)
			result->rightchild->parent = treeNode;
		result->rightchild = treeNode;
		treeNode->parent = result;

		/*��ɫ*/
		/*result->color = node->color;
		node->color = red;*/
		bool color = result->color;
		result->color = treeNode->color;
		treeNode->color = color;

		//node = result;//ָ��result
	}
	void leftRotate(RedBlackTreeNode<Type> *&node) {
		RedBlackTreeNode<Type> *treeNode = node;
		/*�����ӽڵ���Ϊ�¸��ڵ�result*/
		RedBlackTreeNode<Type> *result = node->rightchild;
		result->parent = node->parent;
		if (node == root)
			root = result;
		else {
			if (node == node->parent->leftchild)
				node->parent->leftchild = result;
			else node->parent->rightchild = result;
		}

		/*�����ӽڵ���ҽڵ�ָ��ɸ��ڵ�node�������ɸ��ڵ�����ӽڵ�ָ�����ӽڵ���ҽڵ�*/
		treeNode->rightchild = result->leftchild;
		if (NULL != result->leftchild)
			result->leftchild->parent = treeNode;
		result->leftchild = treeNode;
		treeNode->parent = result;

		/*��ɫ*/
		/*result->color = node->color;
		node->color = red;*/
		bool color = result->color;
		result->color = treeNode->color;
		treeNode->color = color;

		//node = result;//ָ��result
	}
	void insertNode(RedBlackTreeNode<Type> *&parentNode, Type data) {
		if (NULL == parentNode) {
			parentNode = new RedBlackTreeNode<Type>();
			parentNode->data = data;
			m_size++;
			return;
		}
		if (parentNode->data == data) {
			cout << "insert failed" << endl;
			return;
		}
		else if (parentNode->data > data) {
			insertNode(parentNode->leftchild, data);
			parentNode->leftchild->parent = parentNode;
		}
		else if (parentNode->data < data) {
			insertNode(parentNode->rightchild, data);
			parentNode->rightchild->parent = parentNode;
		}
		/*if (parentNode->data == data) {
			cout << "insert failed" << endl;
			return;
		}
		if (parentNode->data > data) {
			if (parentNode->leftchild == NULL) {
				RedBlackTreeNode<Type> *newNode = new RedBlackTreeNode<Type>();
				newNode->data = data;
				newNode->parent = parentNode;
				parentNode->leftchild = newNode;
				m_size++;
				return;
			}
			else
				insertNode(parentNode->leftchild, data);
		}
		else if (parentNode->data < data) {
			if (parentNode->rightchild == NULL) {
				RedBlackTreeNode<Type> *newNode = new RedBlackTreeNode<Type>();
				newNode->data = data;
				newNode->parent = parentNode;
				parentNode->rightchild = newNode;
				m_size++;
			}
			else
				insertNode(parentNode->rightchild, data);
		}*/

        #pragma region ��������
		/*
		1.������ӽ��Ϊ�ڣ����ӽ��Ϊ�죬������������2-3���ܱ�ɺ�������������
		2.������ӽ��Ϊ�죬�����ӽ������ӽ��ҲΪ�죬�������������������4��
		3.��������ӽ���Ϊ�죬����ɫ��ת*/
		/*if(!isRed(parentNode->leftchild) && isRed(parentNode->rightchild))leftRotate(parentNode);//������ӽ��Ϊ�ڣ����ӽ��Ϊ�죬������
		if (isRed(parentNode->leftchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//������ӽ��Ϊ�죬�����ӽ������ӽ��ҲΪ�죬������
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//��������ӽ���Ϊ�죬����ɫ��ת*/
        #pragma endregion
        #pragma region �Ľ������������ߣ�ϰ������
		/*
		1.��������ӽ���Ϊ�죬����ɫ��ת��
		2.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		3.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		4.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		5.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		��case2��case3Ϊһ����ϣ�case4��case5Ϊһ����ϣ��Ǿ���Գơ�
		ע�⣬�ж�case2��case3ʱ��Ӧ�ȶ�case3�����жϣ�Ȼ���ٶ�case2�����жϣ���Ϊ�������case3�������������ӽ���������任�����case2���������ʱ�Ϳ����ٶԸ�������������case4��case5Ҳ����ˡ�
		��case1����жϣ�����ɫ�����У���ֹ��ɫ���±�Ӧ��ת�Ĳ���ת������
		*/
		/*if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4*/
        #pragma endregion
        #pragma region ��׼������
		/*
		1.��������ӽ���Ϊ�죬�����ӽ����ӽ������ӽ����ӽ��Ϊ�죬����ɫ��ת�������������4��
		2.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		3.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		4.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		5.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		��case2��case3Ϊһ����ϣ�case4��case5Ϊһ����ϣ��Ǿ���Գơ�
		ע�⣬�ж�case2��case3ʱ��Ӧ�ȶ�case3�����жϣ�Ȼ���ٶ�case2�����жϣ���Ϊ�������case3�������������ӽ���������任�����case2���������ʱ�Ϳ����ٶԸ�������������case4��case5Ҳ����ˡ�
		case1���Ƚ����ж�����Ϊ�Ȼ�ɫ�󣬿��Լ�����ת��������
		*/
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild) && (isRed(parentNode->leftchild->leftchild) || isRed(parentNode->leftchild->rightchild) || isRed(parentNode->rightchild->leftchild) || isRed(parentNode->rightchild->rightchild)))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4
        #pragma endregion
	}
	void insertNode(RedBlackTreeNode<Type> *&parentNode, RedBlackTreeNode<Type> *newNode) {
		if (parentNode->data == newNode->data) {
			cout << "insert failed" << endl;
			return;
		}
		if (parentNode->data > newNode->data) {
			if (parentNode->leftchild == NULL) {
				newNode->parent = parentNode;
				parentNode->leftchild = newNode;
			}
			else
				insertNode(parentNode->leftchild, newNode);
		}
		else if (parentNode->data < newNode->data) {
			if (parentNode->rightchild == NULL) {
				newNode->parent = parentNode;
				parentNode->rightchild = newNode;
			}
			else
				insertNode(parentNode->rightchild, newNode);
		}

        #pragma region ��������
		/*
		1.������ӽ��Ϊ�ڣ����ӽ��Ϊ�죬������������2-3���ܱ�ɺ�������������
		2.������ӽ��Ϊ�죬�����ӽ������ӽ��ҲΪ�죬�������������������4��
		3.��������ӽ���Ϊ�죬����ɫ��ת*/
		/*if(!isRed(parentNode->leftchild) && isRed(parentNode->rightchild))leftRotate(parentNode);//������ӽ��Ϊ�ڣ����ӽ��Ϊ�죬������
		if (isRed(parentNode->leftchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//������ӽ��Ϊ�죬�����ӽ������ӽ��ҲΪ�죬������
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//��������ӽ���Ϊ�죬����ɫ��ת*/
        #pragma endregion
        #pragma region �Ľ������������ߣ�ϰ������
		/*
		1.��������ӽ���Ϊ�죬����ɫ��ת��
		2.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		3.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		4.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		5.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		��case2��case3Ϊһ����ϣ�case4��case5Ϊһ����ϣ��Ǿ���Գơ�
		ע�⣬�ж�case2��case3ʱ��Ӧ�ȶ�case3�����жϣ�Ȼ���ٶ�case2�����жϣ���Ϊ�������case3�������������ӽ���������任�����case2���������ʱ�Ϳ����ٶԸ�������������case4��case5Ҳ����ˡ�
		��case1����жϣ�����ɫ�����У���ֹ��ɫ���±�Ӧ��ת�Ĳ���ת������
		*/
		/*if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4*/
        #pragma endregion
        #pragma region ��׼������
		/*
		1.��������ӽ���Ϊ�죬�����ӽ����ӽ������ӽ����ӽ��Ϊ�죬����ɫ��ת�������������4��
		2.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		3.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		4.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬��������
		5.������ӽ��Ϊ�죬���ӽ��Ϊ�ڣ����²�����Ϊ���ӽ������ӽ�㣬�����ӽ��������
		��case2��case3Ϊһ����ϣ�case4��case5Ϊһ����ϣ��Ǿ���Գơ�
		ע�⣬�ж�case2��case3ʱ��Ӧ�ȶ�case3�����жϣ�Ȼ���ٶ�case2�����жϣ���Ϊ�������case3�������������ӽ���������任�����case2���������ʱ�Ϳ����ٶԸ�������������case4��case5Ҳ����ˡ�
		case1���Ƚ����ж�����Ϊ�Ȼ�ɫ�󣬿��Լ�����ת��������
		*/
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild) && (isRed(parentNode->leftchild->leftchild) || isRed(parentNode->leftchild->rightchild) || isRed(parentNode->rightchild->leftchild) || isRed(parentNode->rightchild->rightchild)))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4
        #pragma endregion
	}
	RedBlackTreeNode<Type> *findNode(RedBlackTreeNode<Type> *&parentNode, Type data) {
		if (NULL == parentNode) return NULL;
		if (parentNode->data == data) return parentNode;
		if (parentNode->data > data)
			findNode(parentNode->leftchild, data);
		else if (parentNode->data < data)
			findNode(parentNode->rightchild, data);
	}
	void removeNode(RedBlackTreeNode<Type> *&treeNode, Type data) {
		if (NULL == treeNode) return;
		if (treeNode->data == data) {
			if (treeNode->leftchild == NULL&&treeNode->rightchild == NULL) {
				adjustBeforeRemove(treeNode);
				if (NULL != treeNode->parent)
					if (treeNode == treeNode->parent->leftchild)
						treeNode->parent->leftchild = NULL;
					else treeNode->parent->rightchild = NULL;
			}
			else if (treeNode->leftchild != NULL && treeNode->rightchild == NULL) {
				treeNode->data = treeNode->leftchild->data;
				adjustBeforeRemove(treeNode->leftchild);
				treeNode->leftchild = NULL;
			}
			else if (treeNode->leftchild == NULL && treeNode->rightchild != NULL) {
				treeNode->data = treeNode->rightchild->data;
				adjustBeforeRemove(treeNode->rightchild);
				treeNode->rightchild = NULL;
			}
			else if (treeNode->leftchild != NULL && treeNode->rightchild != NULL) {
				//treeNode->data = removeMinNode(treeNode->rightchild)->data;
				treeNode->data = findMinNode(treeNode->rightchild)->data;
				removeMinNode(treeNode->rightchild);
			}
		}
		else if (treeNode->data > data)
			removeNode(treeNode->leftchild, data);
		else if (treeNode->data < data)
			removeNode(treeNode->rightchild, data);
	}
	RedBlackTreeNode<Type> *findMinNode(RedBlackTreeNode<Type> *&parentNode) {
		RedBlackTreeNode<Type> *treeNode = parentNode;
		while (NULL != treeNode->leftchild) {
			treeNode = treeNode->leftchild;
		}
		return treeNode;
	}
	RedBlackTreeNode<Type> *removeMinNode(RedBlackTreeNode<Type> *&parentNode) {
		if (NULL == parentNode->leftchild) {
			RedBlackTreeNode<Type> *treeNode = parentNode;
			if (NULL == parentNode->rightchild) {
				adjustBeforeRemove(parentNode);
				parentNode = NULL;
			}
			else {
				parentNode = parentNode->rightchild;
				parentNode->color = treeNode->color;
				parentNode->parent = treeNode->parent;
			}
			return treeNode;
		}
		removeMinNode(parentNode->leftchild);
	}
	void adjustBeforeRemove(RedBlackTreeNode<Type> *&deleteTreeNode) {
		RedBlackTreeNode<Type> *treeNode = deleteTreeNode;
		/*���Ҫɾ�����������ӽ��Ϊ�գ�����ɫΪ�ڣ���Ҫ���е���*/
		// �Ӵ�ɾ���Ϊ���������ӽ�㿼�ǣ�����5�������
		// case1:��ɾ���Ľ��Ϊ���㣬�ֵܽ��Ϊ�����ֵܽ������ֻ��һ����ɫ���ӽ�㣬�򽫸������ɫ�����ֵܽ�㣬Ȼ�󸸽����ֵܽ����ӽ���ڣ���󸸽���������������
		// case2:��ɾ���Ľ��Ϊ���㣬�ֵܽ��Ϊ�����ֵܽ������ֻ��һ����ɫ���ӽ�㣬���ֵܽ����ֵܽ����ӽ�����ɫ������Ȼ���ֵܽ����������ʱת��case1��ִ��case1�Ĳ��裬�������
		// case3:��ɾ���Ľ��Ϊ���㣬�ֵܽ��Ϊ�����ֵܽ����������ɫ�������ӽ�㣬��ִ��case1��ͬ�Ĳ��裬���������ɫ�����ֵܽ�㣬Ȼ�󸸽����ֵܽ������ӽ���ڣ���󸸽���������������
		// case4:��ɾ���Ľ��Ϊ���㣬�ֵܽ��Ϊ�����ֵܽ��û���ӽ�㣬���ֵܽ���죬�Ը����Ϊ������ϵݹ飬ֱ��������ɫ������������ݹ飬��������
		// case5:��ɾ���Ľ��Ϊ���㣬�ֵܽ��Ϊ�����ֵܽ����������ɫ�������ӽ�㣬���ֵܽ���ڣ��ֵܽ������ӽ���죬Ȼ�󸸽���������������
		// case1:��ɾ���Ľ��Ϊ�ҽ�㣬�ֵܽ��Ϊ�����ֵܽ������ֻ��һ����ɫ���ӽ�㣬�򽫸������ɫ�����ֵܽ�㣬Ȼ�󸸽����ֵܽ����ӽ���ڣ���󸸽���������������
		// case2:��ɾ���Ľ��Ϊ�ҽ�㣬�ֵܽ��Ϊ�����ֵܽ������ֻ��һ����ɫ���ӽ�㣬���ֵܽ����ֵܽ����ӽ�����ɫ������Ȼ���ֵܽ����������ʱת��case1��ִ��case1�Ĳ��裬�������
		// case3:��ɾ���Ľ��Ϊ�ҽ�㣬�ֵܽ��Ϊ�����ֵܽ����������ɫ�������ӽ�㣬��ִ��case1��ͬ�Ĳ��裬���������ɫ�����ֵܽ�㣬Ȼ�󸸽����ֵܽ������ӽ���ڣ���󸸽���������������
		// case4:��ɾ���Ľ��Ϊ�ҽ�㣬�ֵܽ��Ϊ�����ֵܽ��û���ӽ�㣬���ֵܽ���죬�Ը����Ϊ������ϵݹ飬ֱ��������ɫ������������ݹ飬��������
		// case5:��ɾ���Ľ��Ϊ�ҽ�㣬�ֵܽ��Ϊ�����ֵܽ����������ɫ�������ӽ�㣬���ֵܽ���ڣ��ֵܽ������ӽ���죬Ȼ�󸸽���������������
		while (treeNode != root&&treeNode->color == black) {
			if (treeNode == treeNode->parent->leftchild) {
				if (treeNode->parent->rightchild->color == black) {
					if (treeNode->parent->rightchild->leftchild == NULL && treeNode->parent->rightchild->rightchild != NULL) {
						/*treeNode->parent->rightchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->rightchild->rightchild->color = black;
						leftRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->rightchild->leftchild != NULL && treeNode->parent->rightchild->rightchild == NULL) {
						/*treeNode->parent->rightchild->color = Color->red;
						treeNode->parent->rightchild->leftchild->color = Color->black;*/
						rightRotate(treeNode->parent->rightchild);//ת��case1
						/*treeNode->parent->rightchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->rightchild->rightchild->color = black;
						leftRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->rightchild->leftchild != NULL && treeNode->parent->rightchild->rightchild != NULL) {
						/*treeNode->parent->rightchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->rightchild->rightchild->color = black;
						leftRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->rightchild->leftchild == NULL && treeNode->parent->rightchild->rightchild == NULL) {
						treeNode->parent->rightchild->color = red;
						treeNode = treeNode->parent;//���ϵݹ�
					}
				}
				else if (treeNode->parent->rightchild->color == red && treeNode->parent->rightchild->leftchild != NULL && treeNode->parent->rightchild->rightchild != NULL) {
					treeNode->parent->rightchild->color = black;
					treeNode->parent->rightchild->leftchild->color = red;
					leftRotate(treeNode->parent);
					break;
				}
			}
			else if (treeNode == treeNode->parent->rightchild) {
				if (treeNode->parent->leftchild->color == black) {
					if (treeNode->parent->leftchild->leftchild != NULL && treeNode->parent->leftchild->rightchild == NULL) {
						/*treeNode->parent->leftchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->leftchild->leftchild->color = black;
						rightRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->leftchild->leftchild == NULL && treeNode->parent->leftchild->rightchild != NULL) {
						/*treeNode->parent->leftchild->color = Color->red;
						treeNode->parent->leftchild->rightchild->color = Color->black;*/
						leftRotate(treeNode->parent->leftchild);
						/*treeNode->parent->leftchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->leftchild->leftchild->color = black;
						rightRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->leftchild->leftchild != NULL && treeNode->parent->leftchild->rightchild != NULL) {
						/*treeNode->parent->leftchild->color = treeNode->parent->color;
						treeNode->parent->color = Color->black;*/
						treeNode->parent->leftchild->leftchild->color = black;
						rightRotate(treeNode->parent);
						break;
					}
					else if (treeNode->parent->leftchild->leftchild == NULL && treeNode->parent->leftchild->rightchild == NULL) {
						treeNode->parent->leftchild->color = red;
						treeNode = treeNode->parent;//���ϵݹ�
					}
				}
				else if (treeNode->parent->leftchild->color == red && treeNode->parent->leftchild->leftchild != NULL && treeNode->parent->leftchild->rightchild != NULL) {
					treeNode->parent->leftchild->color = black;
					treeNode->parent->leftchild->rightchild->color = red;
					rightRotate(treeNode->parent);
					break;
				}
			}
		}
		if (NULL != treeNode)treeNode->color = black;
	}
	void preOrderTraverse(RedBlackTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			cout << treeNode->data << " ";
			preOrderTraverse(treeNode->leftchild);
			preOrderTraverse(treeNode->rightchild);
		}
	}
	void inOrderTraverse(RedBlackTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			inOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
			inOrderTraverse(treeNode->rightchild);
		}
	}
	void postOrderTraverse(RedBlackTreeNode<Type> *treeNode) {
		if (NULL == treeNode)return;
		else
		{
			postOrderTraverse(treeNode->rightchild);
			postOrderTraverse(treeNode->leftchild);
			cout << treeNode->data << " ";
		}
	}
	/*��α������ǵݹ�*/
	void levelOrderTraverse(RedBlackTreeNode<Type> *root) {
		queue<RedBlackTreeNode<Type>*> queue;//�������У����ڲ�α���
		if (root == NULL) {
			return;
		}
		queue.push(root);
		RedBlackTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << temp->data << " ";
				if (temp->leftchild != NULL) {
					queue.push(temp->leftchild);
				}
				if (temp->rightchild != NULL) {
					queue.push(temp->rightchild);
				}
			}
			cout << endl;//����
		}
	}
	/*��������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
	��Ϊ���Ľ��λ�����丸���λ����أ����Եݹ����ʱ��Ҫ���ݸ�����λ�á�*/
	void writeArray(RedBlackTreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		/*char* dataStr = new char[strlen(to_string(node->data).c_str())];
		strcpy(dataStr, to_string(node->data).c_str());
		if (node->color == red)array[row][col] = string_concat({ dataStr, "-r" });
		else array[row][col] = string_concat({ dataStr,"-b" });*/
		int level = row / 2 + 1;
		if (level == m_height)return;

		/*�ݹ������ӽ��*/
		//int gap = pow(2, m_height - level - 1) * 3;//3,6,12,...
		int gap = (2 << (m_height - level - 1));//2,4,8,...
		if (node->leftchild != NULL) {
			array[row + 1][col - gap / 2] = "/";
			writeArray(node->leftchild, array, row + 2, col - gap);
		}
		if (node->rightchild != NULL) {
			array[row + 1][col + gap / 2] = "\\";
			writeArray(node->rightchild, array, row + 2, col + gap);
		}
	}
public:
	RedBlackTree() : root(NULL), m_size(0), m_height(0) {}
	~RedBlackTree() { release(root); }
	void insert(Type data) {
		insertNode(root, data);
		/*RedBlackTreeNode<Type> *newNode = new RedBlackTreeNode<Type>();
		newNode->data = data;
		if (NULL == root) {
			root = newNode;
			root->color = black;
			return;
		}
		insertNode(root, newNode);*/
		/*if (NULL == root) {
			root = new RedBlackTreeNode<Type>();
			root->data = data;
			root->color = black;
			return;
		}
		insertNode(root, data);*/
		root->color = black;
	}
	RedBlackTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	RedBlackTreeNode<Type> *removeMin() { return removeMinNode(root); }
	void preOrder() {
		preOrderTraverse(root);
		cout << endl;
	}
	void inOrder() {
		inOrderTraverse(root);
		cout << endl;
	}
	void postOrder() {
		postOrderTraverse(root);
		cout << endl;
	}
	void levelOrder() { levelOrderTraverse(root); }
	void printTree(){
		if (NULL == root)return;
		m_height = height(root);//���߶�
		//int width = (pow(2, m_height - 1) - 1) * 6 + 1;//((2 << (m_height - 2)) - 1) * 6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
		int width = (pow(2, m_height - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1) * 4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
		//string array[2 * m_height - 1][width];
		string **array=new string*[2 * m_height - 1];
		for (int i = 0; i < 2 * m_height - 1; i++) {
			array[i] = new string[width];
			for (int j = 0; j < width; j++) {
				array[i][j] = " ";
			}
		}
		int a = 2 << (m_height - 2);
		//writeArray(root, array, 0, (pow(2, m_height - 1) - 1) * 3);//(pow(2, m_height - 1) - 1) * 3;
		writeArray(root, array, 0, (pow(2, m_height - 1) - 1) * 2);//(pow(2, m_height - 1) - 1) * 2;
		/*��ӡ����*/
		for (int i = 0; i < 2 * m_height - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//����
		}
	}
};
#pragma endregion

/**
 *����: ϰ����
 *�汾: version 1.0
 *����: 2020��4��7��
 *����: ʵ��B���Ĳ��롢ɾ�������Ҽ���ӡ����
 */
#pragma region ƽ������Ӣ����Balance Tree�����B��������һ�ֶ�·����������·���������·��������������2-3���ǽ���Ϊ3��B��
template <class Type>
struct BalanceTreeNode {
	int count;
	int level;//���߶ȣ�Ҷ�ӽ���levelΪ1
	Type *data;//�ؼ���
	BalanceTreeNode<Type> **child;
	BalanceTreeNode<Type> *parent;
	BalanceTreeNode() :parent(NULL), count(0){}
	BalanceTreeNode(int m) :parent(NULL), count(0){
		data = new Type[m];//m��ʾb���������ؼ������洢m-1�������峤��Ϊm�Ĺؼ������飬�����1���ռ���Ϊ���ڲ�����Ĺؼ�����ʱʹ��
		this->child = new BalanceTreeNode*[m+1];//�ӽ�����m�������峤��Ϊm+1���ӽ�����飬�����1���ռ���Ϊ���ڲ�������ӽ������ʱʹ��
	}
};
template <class Type>
class BalanceTree {
private:
	BalanceTreeNode<Type> *root;
	int m;
	int min;
	int m_size;
	void release(BalanceTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			if (treeNode->level != 1)
				for (int i = 0; i <= treeNode->count; i++)
					release(treeNode->child[i]);
			delete treeNode;
		}
	}
	int level(BalanceTreeNode<Type> *node) {
		return (NULL == node) ? 0 : node->level;
	}
	void insertNode(BalanceTreeNode<Type> *&treeNode, Type data) {
		if (treeNode->level == 1)
		{//�����ǰ�����Ҷ�ӽ�㣬���뵽��ǰ���
			int index;
			for (int i = treeNode->count - 1; i >= 0; i--) {
				if (treeNode->data[i] == data) {
					cout << "insert failed" << endl;
					return;
				}
				if (treeNode->data[i] > data) {
					treeNode->data[i + 1] = treeNode->data[i];
					index = i;
				}
				else {
					index = i + 1;
					break;
				}
			}
			treeNode->data[index] = data;
			treeNode->count++;
			this->m_size++;
		}
		else
		{//�����ǰ����Ҷ�ӽ�㣬���뵽��ǰ�����ӽ����
			int i;
			for (i = 0; i < treeNode->count; i++) {
				if (treeNode->data[i] == data) {
					cout << "insert failed" << endl;
					return;
				}
				if (treeNode->data[i] > data)
					break;
			}
			insertNode(treeNode->child[i], data);
		}

        #pragma region ���ѵ���
		if (treeNode->count == this->m)
		{
			BalanceTreeNode<Type> *brotherNode = new BalanceTreeNode<Type>(this->m);
			int index = 0, middle = this->m / 2;
			/*for (int i = middle + 1; i < treeNode->count; i++)
				brotherNode->data[index++] = treeNode->data[i];*/
			if (treeNode->level == 1) {
				for (int i = middle + 1; i < treeNode->count; i++)
					brotherNode->data[index++] = treeNode->data[i];
			}
			else
			{
				for (int i = middle + 1; i < treeNode->count; i++) 
				{
					brotherNode->data[index] = treeNode->data[i];
					brotherNode->child[index] = treeNode->child[i];
					treeNode->child[i]->parent = brotherNode;
					index++;
				}
				brotherNode->child[index] = treeNode->child[treeNode->count];
				treeNode->child[treeNode->count]->parent = brotherNode;
			}
			brotherNode->count = index;
			brotherNode->level = treeNode->level;
			treeNode->count = middle;

			if (root == treeNode) {
				BalanceTreeNode<Type> *parentNode = new BalanceTreeNode<Type>(this->m);
				parentNode->data[0] = treeNode->data[middle];
				parentNode->child[0] = treeNode;
				parentNode->child[1] = brotherNode;
				treeNode->parent = parentNode;
				brotherNode->parent = parentNode;
				parentNode->count++;
				parentNode->level = treeNode->level + 1;
				this->root = parentNode;
			}
			else
			{
				for (int i = treeNode->parent->count; i >= 0; i--) {
					if (treeNode->parent->child[i] != treeNode) {
						treeNode->parent->data[i] = treeNode->parent->data[i - 1];
						treeNode->parent->child[i + 1] = treeNode->parent->child[i];
						index = i;
					}
					else
					{
						index = i + 1;
						break;
					}
				}
				treeNode->parent->data[index-1] = treeNode->data[middle];
				treeNode->parent->child[index] = brotherNode;
				brotherNode->parent = treeNode->parent;
				treeNode->parent->count++;
			}
		}
        #pragma endregion
	}
	BalanceTreeNode<Type> *findNode(BalanceTreeNode<Type> *&treeNode, Type data) {
		int i;
		for (i = 0; i < treeNode->count; i++) {
			if (treeNode->data[i] == data) {
				return treeNode;
			}
			else if (treeNode->data[i] > data) {
				break;
			}
		}
		if (treeNode->level == 1)return NULL;
		else findNode(treeNode->child[i], data);
	}
	void removeNode(BalanceTreeNode<Type> *&treeNode, Type data) {
		if (treeNode->level == 1)
		{
			/*�����ǰ�����Ҷ�ӽ�㣬���ǵ�ǰ���ؼ������Ƿ��������min
			1.�����ǰ���ؼ�������������min����ֱ��ɾ��
			2.���򣬿����������ֵܽ��Ĺؼ������Ƿ��������min������������ֵܽ��Ĺؼ�������ȫΪ���ޣ�������йؼ������������޵��ֵܽ���һ��Ԫ�أ�����������ֵܽ��Ĺؼ������պö�Ϊ���ޣ���������һ���ֵܽ��ϲ��������ϵݹ�*/
			int i;
			for (i = 0; i < treeNode->count; i++) {
				if (treeNode->data[i] == data)
					break;
			}
			if (i == treeNode->count) cout << "remove failed" << endl;
			else
			{
				if (treeNode->count > min) {
					for (int j = i; j < treeNode->count; j++) {
						treeNode->data[j] = treeNode->data[j + 1];
					}
					treeNode->count--;
					this->m_size--;
					return;
				}
				else
				{
					int index;
					for (index = 0; index <= treeNode->parent->count; index++) {
						if (treeNode->parent->child[index] == treeNode)
							break;
					}
					if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
						for (int j = 0; j < i; j++)
							treeNode->data[j + 1] = treeNode->data[j];
						treeNode->data[0] = treeNode->parent->data[index - 1];
						treeNode->parent->data[index - 1] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
						treeNode->parent->child[index - 1]->count--;
						return;
					}
					if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
						for (int j = i; j < treeNode->count; j++)
							treeNode->data[j] = treeNode->data[j + 1];
						treeNode->data[treeNode->count - 1] = treeNode->parent->data[index];
						treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[0];
						for (int j = 0; j < treeNode->parent->child[index + 1]->count; j++)
							treeNode->parent->child[index + 1]->data[j] = treeNode->parent->child[index + 1]->data[j + 1];
						treeNode->parent->child[index + 1]->count--;
						return;
					}
					//��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
					for (int j = i; j < treeNode->count; j++)
						treeNode->data[j] = treeNode->data[j + 1];
					treeNode->count--;
					if (index < treeNode->parent->count)
						merge(treeNode, index, 1);
					else
						merge(treeNode, index, -1);
				}
			}
		}
		else
		{
			/*�����ǰ����Ҷ�ӽ�㣬��������ӽ�����ҵ����ֵ�����ӽ������Ҽ�ֵ�����ӽ��������ֵ����Ȼ�����µݹ�ɾ��*/
			int i;
			for (i = 0; i < treeNode->count; i++) {
				if (treeNode->data[i] == data) {
					//������ӽ��ļ�ֵ���������ޣ������ӽ������Ҽ�ֵ��Ϊ��̽�㣻�������ӽ��������ֵ��Ϊ��̽��
					if (treeNode->child[i]->count > min) {
						treeNode->data[i] = treeNode->child[i]->data[treeNode->child[i]->count - 1];
						removeNode(treeNode->child[i], treeNode->child[i]->data[treeNode->child[i]->count - 1]);
						return;
					}
					else {
						treeNode->data[i] = treeNode->child[i + 1]->data[0];
						removeNode(treeNode->child[i + 1], treeNode->child[i + 1]->data[0]);
						return;
					}
				}
				if (treeNode->data[i] > data)
					break;
			}
			removeNode(treeNode->child[i], data);
		}
	}
	/*�ϲ��ֵܽ�㣬����˵����
	����treeNode��ʾ��ǰҪ�ϲ��Ľ�㣬
	����index��ʾtreeNode�ڸ�����е�λ�ã�
	����leftOrRight��ʾ����һ��Ҫ�ϲ��Ľ����treeNode�����ֵܽ�㻹��treeNode�����ֵܽ�㣬leftOrRight=-1��ʾ���ֵܽ�㣬leftOrRight=1��ʾ���ֵܽ��*/
	void merge(BalanceTreeNode<Type> *&treeNode, int index, int leftOrRight) {
		if (treeNode->level == 1) {
			if (leftOrRight == -1) {
				for (int i = 0; i < treeNode->count; i++) {
					treeNode->parent->child[index + leftOrRight]->data[i + treeNode->parent->child[index + leftOrRight]->count + 1] = treeNode->data[i];
				}
				treeNode->parent->child[index + leftOrRight]->data[treeNode->parent->child[index + leftOrRight]->count] = treeNode->parent->data[index - 1];
				treeNode->parent->child[index + leftOrRight]->count = treeNode->count + treeNode->parent->child[index + leftOrRight]->count + 1;
				//release(treeNode);
				for (int i = index - 1; i < treeNode->parent->count - 1; i++) {
					treeNode->parent->data[i] = treeNode->parent->data[i + 1];
					treeNode->parent->child[i + 1] = treeNode->parent->child[i + 2];
				}
			}
			else
			{
				for (int i = 0; i < treeNode->parent->child[index + leftOrRight]->count; i++) {
					treeNode->data[i + treeNode->count + 1] = treeNode->parent->child[index + leftOrRight]->data[i];
				}
				treeNode->data[treeNode->count] = treeNode->parent->data[index];
				treeNode->count = treeNode->count + treeNode->parent->child[index + leftOrRight]->count + 1;
				//release(treeNode->parent->child[index + leftOrRight]);
				for (int i = index; i < treeNode->parent->count - 1; i++) {
					treeNode->parent->data[i] = treeNode->parent->data[i + 1];
					treeNode->parent->child[i + 1] = treeNode->parent->child[i + 2];
				}
			}
			treeNode->parent->count--;
		}
		else
		{
			if (leftOrRight == -1) {
				for (int i = 0; i < treeNode->count; i++) {
					treeNode->parent->child[index + leftOrRight]->data[i + treeNode->parent->child[index + leftOrRight]->count + 1] = treeNode->data[i];
					treeNode->parent->child[index + leftOrRight]->child[i + treeNode->parent->child[index + leftOrRight]->count + 1] = treeNode->child[i];
				}
				treeNode->parent->child[index + leftOrRight]->data[treeNode->parent->child[index + leftOrRight]->count] = treeNode->parent->data[index - 1];
				treeNode->parent->child[index + leftOrRight]->count = treeNode->count + treeNode->parent->child[index + leftOrRight]->count + 1;
				//release(treeNode);
				for (int i = index - 1; i < treeNode->parent->count - 1; i++) {
					treeNode->parent->data[i] = treeNode->parent->data[i + 1];
					treeNode->parent->child[i + 1] = treeNode->parent->child[i + 2];
				}
			}
			else
			{
				for (int i = 0; i < treeNode->parent->child[index + leftOrRight]->count; i++) {
					treeNode->data[i + treeNode->count + 1] = treeNode->parent->child[index + leftOrRight]->data[i];
					treeNode->child[i + treeNode->count + 1] = treeNode->parent->child[index + leftOrRight]->child[i];
				}
				treeNode->child[treeNode->count + treeNode->parent->child[index + leftOrRight]->count + 1] = treeNode->parent->child[index + leftOrRight]->child[treeNode->parent->child[index + leftOrRight]->count];
				treeNode->data[treeNode->count] = treeNode->parent->data[index];
				treeNode->count = treeNode->count + treeNode->parent->child[index + leftOrRight]->count + 1;
				//release(treeNode->parent->child[index + leftOrRight]);
				for (int i = index; i < treeNode->parent->count - 1; i++) {
					treeNode->parent->data[i] = treeNode->parent->data[i + 1];
					treeNode->parent->child[i + 1] = treeNode->parent->child[i + 2];
				}
			}
			treeNode->parent->count--;
		}
		

		/*���treeNode�ĸ����Ϊ������Һϲ��󸸽��ؼ���Ϊ0���򽫸����ָ��treeNode�����ĵ�һ���ӽ��*/
		if (root == treeNode->parent) {
			if (treeNode->parent->count == 0)
				root = treeNode->parent->child[0];
			return;
		}
		else {
			/*����ϲ��󸸽��ؼ�������������Ҫ�������ɾ������*/
			if (treeNode->parent->count >= min)
				return;

			/*����ϲ��󸸽��ؼ���������������Ҫ�������������ֵܽ��Ĺؼ�����
			1.����������ֵܽ��Ĺؼ�������ȫΪ���ޣ��������д������޵�һ���ֵܽ���һ���ؼ��֣�ͬʱ�ֵܽ��Ķ�Ӧ�ӽ��Ҳ�������
			2.����������ֵܽ��Ĺؼ������պö�Ϊ���ޣ������ϵݹ�ϲ�*/
			for (index = 0; index <= treeNode->parent->parent->count; index++) {
				if (treeNode->parent->parent->child[index] == treeNode->parent)
					break;
			}
			if (index > 0 && treeNode->parent->parent->child[index - 1]->count > min) {
				for (int i = 0; i < index; i++)
					treeNode->parent->data[i + 1] = treeNode->parent->data[i];
				treeNode->parent->data[0] = treeNode->parent->parent->data[index - 1];
				treeNode->parent->parent->data[index - 1] = treeNode->parent->parent->child[index - 1]->data[treeNode->parent->parent->child[index - 1]->count - 1];
				//�������ֵܽ��������ӽ��
				for (int i = treeNode->parent->count; i >= 0; i--)
					treeNode->parent->child[i + 1] = treeNode->parent->child[i];
				treeNode->parent->child[0] = treeNode->parent->parent->child[index - 1]->child[treeNode->parent->parent->child[index - 1]->count];
				treeNode->parent->count++;
				treeNode->parent->parent->child[index - 1]->count--;
				return;
			}
			if (index < treeNode->parent->parent->count && treeNode->parent->parent->child[index + 1]->count > min) {
				treeNode->parent->data[treeNode->parent->count] = treeNode->parent->parent->data[index];
				treeNode->parent->parent->data[index] = treeNode->parent->parent->child[index + 1]->data[0];
				for (int i = 0; i < treeNode->parent->parent->child[index + 1]->count; i++)
					treeNode->parent->parent->child[index + 1]->data[i] = treeNode->parent->parent->child[index + 1]->data[i + 1];
				//�������ֵܽ��������ӽ��
				treeNode->parent->count++;
				treeNode->parent->child[treeNode->parent->count] = treeNode->parent->parent->child[index + 1]->child[0];
				treeNode->parent->parent->child[index + 1]->count--;
				for (int i = 0; i <= treeNode->parent->parent->child[index + 1]->count; i++)
					treeNode->parent->parent->child[index + 1]->child[i] = treeNode->parent->parent->child[index + 1]->child[i + 1];
				return;
			}
			if (index < treeNode->parent->parent->count)
				merge(treeNode->parent, index, 1);
			else
				merge(treeNode->parent, index, -1);
		}
	}
	/*��α������ǵݹ�*/
	void levelOrderTraverse(BalanceTreeNode<Type> *root) {
		queue<BalanceTreeNode<Type>*> queue;//�������У����ڲ�α���
		if (root == NULL) {
			return;
		}
		queue.push(root);
		BalanceTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << "{";
				for (int j = 0; j < temp->count-1; j++) {
					cout << temp->data[j] << " ";
				}
				cout << temp->data[temp->count - 1] << "}";
				if (temp->level != 1) {
					for (int j = 0; j <= temp->count; j++) {
						queue.push(temp->child[j]);
					}
				}
			}
			cout << endl;//����
		}
	}
public:
	BalanceTree(int m) : root(NULL), m_size(0) {
		this->m = m;
		this->min = (this->m - 1) / 2;
	}
	~BalanceTree() { release(root); }
	void insert(Type data) {
		if (NULL == root) {
			root = new BalanceTreeNode<Type>(this->m);
			root->data[0] = data;
			root->count++;
			root->level = 1;
			m_size++;
			return;
		}
		insertNode(root, data);
	}
	BalanceTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	void levelOrder() { levelOrderTraverse(root); }
};
#pragma endregion