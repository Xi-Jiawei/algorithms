#pragma once
// data_structures.h
//

#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

#include "strings.h"

/**
 *����: ջ
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
 *����: ˳��ѭ������
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
 *����: ��
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
			else { // �������ӽ��
				a[parentIndex] = a[minIndex];
				a[minIndex] = a[0];
			}
			parentIndex = minIndex;
		}
	}
	static void print(long *a, int size) {
		if (size == 1) {
			cout << a[1] << endl;
			return;
		}

		int l = log2(size) + 1, b = 3 * (1 << (l - 2));
		int p, q;
		for (int i = 1; i < b; i++)
			cout << " ";
		cout << a[1] << endl;
		for (int i = 1; i < l - 1; i++) {
			p = i ? 2 << (i - 1) : 1;
			q = 1 << i;
			b = 3 * (1 << (l - i - 2));
			for (int i = 1; i < b + 1; i++)
				cout << " ";
			for (int i = p; i < p + q; i++) {
				if (!(i % 2))
					cout << "/";
				else
					cout << "\\";
				for (int i = 1; i < b * 2 - 1; i++)
					cout << " ";
			}
			cout << endl;
			for (int i = 1; i < b; i++)
				cout << " ";
			for (int i = p; i < p + q; i++) {
				cout << a[i];
				for (int i = 1; i < b * 2 + 1; i++)
					cout << " ";
			}
			cout << endl;
		}
		q = 1 << (l - 1);
		b = 3;
		cout << " ";
		for (int i = q; i <= size; i++) {
			if (!(i % 2)) {
				cout << "/";
				for (int i = 1; i < b; i++)
					cout << " ";
			}
			else {
				cout << "\\";
				for (int i = 1; i < b + 2; i++)
					cout << " ";
			}
		}
		cout << endl;
		for (int i = q; i <= size; i++) {
			cout << a[i];
			for (int i = 1; i < b; i++)
				cout << " ";
		}
		cout << endl;
	}

	/*�ϸ�+�³�������ʱʹ�ã�*/
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
			else { // �������ӽ��
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
 *����: ���ȶ���
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
 *����: ������������
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
 *����: ˫����������
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
 *����: ��ͨ��������
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

	/*��ת*/
	void reverse();

	/*��ת*/
	static List reverse(List list) {
		Node *previous = NULL;
		Node *current = list.first;
		Node *next;
		while (current != NULL)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}

		List reverseList = List();
		reverseList.first = previous;
		reverseList.m_size = list.m_size;
		return reverseList;
	}

	/*����*/
	int size();
};
#pragma endregion

/**
 *����: ��ͨ˫������
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
 *����: ��ͨ������
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
	int height(TreeNode<Type> *node) {
		return (NULL == node) ? 0 : max(height(node->leftchild), height(node->rightchild)) + 1;
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
			postOrderTraverse(treeNode->leftchild);
			postOrderTraverse(treeNode->rightchild);
			cout << treeNode->data << " ";
		}
	}
	/*������ȱ����������ң�ʵ���Ͼ���������������ǵݹ�*/
	void dfsTraverse(TreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<TreeNode<Type>*> stack;
		stack.push(root);
		TreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << temp->data << " ";
			if (temp->rightchild != NULL) { // ��Ϊ�Ǵ����ұ����������Ƚ����ӽ����ջ�������ӽ����ջ����ջʱ�����ӽ���ȳ�ջ�����ӽ����ջ
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
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
	/*���ڲ�α����㷨����������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
	��Ϊ���Ľ��λ�����丸���λ����أ����Եݹ����ʱ��Ҫ���ݸ�����λ�á�*/
	void writeArray(TreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int m_height = height(root);
		int h = row / 2 + 1;
		if (h == m_height)return;

		/*�ݹ������ӽ��*/
		//int gap = pow(2, m_height - h - 1) * 3;//3,6,12,...
		int gap = (2 << (m_height - h - 1));//2,4,8,...
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
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
	void printTree() {
		if (NULL == root)return;
		int m_height = height(root);
		//int width = (pow(2, m_height - 1) - 1) * 6 + 1;//((2 << (m_height - 2)) - 1) * 6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
		int width = (pow(2, m_height - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1) * 4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
													   //string array[2 * m_height - 1][width];
		string **array = new string*[2 * m_height - 1];
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
 *����: ���������
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
	int height(TreeNode<Type> *node) {
		return (NULL == node) ? 0 : max(height(node->leftchild), height(node->rightchild)) + 1;
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
			postOrderTraverse(treeNode->leftchild);
			postOrderTraverse(treeNode->rightchild);
			cout << treeNode->data << " ";
		}
	}
	/*������ȱ����������ң�ʵ���Ͼ���������������ǵݹ�*/
	void dfsTraverse(TreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<TreeNode<Type>*> stack;
		stack.push(root);
		TreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << temp->data << " ";
			if (temp->rightchild != NULL) { // ��Ϊ�Ǵ����ұ����������Ƚ����ӽ����ջ�������ӽ����ջ����ջʱ�����ӽ���ȳ�ջ�����ӽ����ջ
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
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
	/*���ڲ�α����㷨����������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
	��Ϊ���Ľ��λ�����丸���λ����أ����Եݹ����ʱ��Ҫ���ݸ�����λ�á�*/
	void writeArray(TreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int m_height = height(root);
		int h = row / 2 + 1;
		if (h == m_height)return;

		/*�ݹ������ӽ��*/
		//int gap = pow(2, m_height - h - 1) * 3;//3,6,12,...
		int gap = (2 << (m_height - h - 1));//2,4,8,...
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
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
	void printTree() {
		if (NULL == root)return;
		int m_height = height(root);
		//int width = (pow(2, m_height - 1) - 1) * 6 + 1;//((2 << (m_height - 2)) - 1) * 6 + 1;//0+1,3*2+1,9*2+1,21*2+1,...,6*(pow(2,level-1)-1)+1
		int width = (pow(2, m_height - 1) - 1) * 4 + 1;//((2 << (m_height - 2)) - 1) * 4 + 1;//0+1,2*2+1,6*2+1,14*2+1,...,4*(pow(2,level-1)-1)+1
		//string array[2 * m_height - 1][width];
		string **array = new string*[2 * m_height - 1];
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
 *����: ƽ�������
 *����: ϰ����
 *�汾: version 1.0
 *����: 2020��1��26��
 *����: ʵ��ƽ��������Ĳ��롢ɾ�������Ҽ���ӡ����
 */
#pragma region ƽ���������AVL��
template <class Type>
struct BalanceBinaryTreeNode {
	Type data;
	int level; // ���߶ȣ�Ҷ�ӽ���levelΪ1��node->level=max(node->child->level)+1
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
			postOrderTraverse(treeNode->leftchild);
			postOrderTraverse(treeNode->rightchild);
			cout << treeNode->data << " ";
		}
	}
	/*������ȱ����������ң�ʵ���Ͼ���������������ǵݹ�*/
	void dfsTraverse(BalanceBinaryTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<BalanceBinaryTreeNode<Type>*> stack;
		stack.push(root);
		BalanceBinaryTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << temp->data << " ";
			if (temp->rightchild != NULL) { // ��Ϊ�Ǵ����ұ����������Ƚ����ӽ����ջ�������ӽ����ջ����ջʱ�����ӽ���ȳ�ջ�����ӽ����ջ
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
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
	/*���ڲ�α����㷨����������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
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
	void dfs() { dfsTraverse(root); }
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
 *����: �����
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
			postOrderTraverse(treeNode->leftchild);
			postOrderTraverse(treeNode->rightchild);
			cout << treeNode->data << " ";
		}
	}
	/*������ȱ����������ң�ʵ���Ͼ���������������ǵݹ�*/
	void dfsTraverse(RedBlackTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<RedBlackTreeNode<Type>*> stack;
		stack.push(root);
		RedBlackTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << temp->data << " ";
			if (temp->rightchild != NULL) { // ��Ϊ�Ǵ����ұ����������Ƚ����ӽ����ջ�������ӽ����ջ����ջʱ�����ӽ���ȳ�ջ�����ӽ����ջ
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
		}
	}
	/*��α�����������ȱ��������ǵݹ�*/
	void levelOrderTraverse(RedBlackTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<RedBlackTreeNode<Type>*> queue;//�������У����ڲ�α���
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
	/*���ڲ�α����㷨����������Ծ�����ʽд�룬����ӡ���󼴿�����ؽ���չʾ������
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
	void dfs() { dfsTraverse(root); }
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
 *����: B��
 *����: ϰ����
 *�汾: version 1.0
 *����: 2020��4��7��
 *����: ʵ��B���Ĳ��롢ɾ�������Ҽ���ӡ����
 */
#pragma region ƽ������Ӣ����Balance Tree�����B��������һ�ֶ�·����������·���������·��������������2-3���ǽ���Ϊ3��B��
template <class Type>
struct BalanceTreeNode {
	int count;
	int level; // ���߶ȣ�Ҷ�ӽ���levelΪ1��node->level=max(node->child->level)+1
	Type *data; // �ؼ���
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

			if (root == treeNode) { // �����ķ��ѣ����½��µĸ����
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
			else { // �Ǹ����ķ��ѣ���Ҫ����������data��child
				for (int i = treeNode->parent->count; i >= 0; i--) {
					if (treeNode->parent->child[i] != treeNode) { // ���ҵ�ǰ����ڸ������ӽ�㼯���е�λ��
						treeNode->parent->data[i] = treeNode->parent->data[i - 1];
						treeNode->parent->child[i + 1] = treeNode->parent->child[i];
						index = i;
					}
					else {
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
	/*ɾ����㣬�粻�������ٹؼ���Ҫ����ϲ��ֵܽ��*/
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
				for (int j = i; j < treeNode->count; j++)
					treeNode->data[j] = treeNode->data[j + 1];
				treeNode->count--;

				if (root == treeNode || treeNode->count >= min) {
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
					merge(treeNode, index);
				}
			}
		}
		else
		{
			int i;
			for (i = 0; i < treeNode->count; i++) {
				if (treeNode->data[i] == data) {
					// ������ӽ��ļ�ֵ���������ޣ������ӽ������Ҽ�ֵ��Ϊ��̽�㣻�������ӽ��������ֵ��Ϊ��̽��
					if (treeNode->child[i]->count > min) {
						treeNode->data[i] = treeNode->child[i]->data[treeNode->child[i]->count - 1];
						removeNode(treeNode->child[i], treeNode->child[i]->data[treeNode->child[i]->count - 1]);
					}
					else {
						treeNode->data[i] = treeNode->child[i + 1]->data[0];
						removeNode(treeNode->child[i + 1], treeNode->child[i + 1]->data[0]);
					}
					return;
				}
				else if (treeNode->data[i] > data)
					break;
			}
			removeNode(treeNode->child[i], data);
		}
	}
	/*�ϲ��ֵܽ�㣬����˵��������treeNode��ʾ��ǰҪ�ϲ��Ľ�㣬����index��ʾtreeNode�ڸ�����е�λ��*/
	void merge(BalanceTreeNode<Type> *treeNode, int index) {
		if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
			// Ǩ�Ƽ�ֵ
			for (int i = treeNode->count - 1; i >= 0; i--)
				treeNode->data[i + 1] = treeNode->data[i];
			treeNode->data[0] = treeNode->parent->data[index - 1];
			treeNode->parent->data[index - 1] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];

			// Ǩ���ӽ��
			for (int i = treeNode->count; i >= 0; i--)
				treeNode->child[i + 1] = treeNode->child[i];
			treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count];
			if (treeNode->level > 1)treeNode->child[0]->parent = treeNode;

			treeNode->parent->child[index - 1]->count--;
			treeNode->count++;
			return;
		}
		if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
			// Ǩ�Ƽ�ֵ
			treeNode->data[treeNode->count] = treeNode->parent->data[index];
			treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[0];
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
				treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];

			// Ǩ���ӽ��
			treeNode->child[treeNode->count + 1] = treeNode->parent->child[index + 1]->child[0];
			if (treeNode->level > 1)treeNode->child[treeNode->count + 1]->parent = treeNode;
			for (int i = 0; i <= treeNode->parent->child[index + 1]->count; i++)
				treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];

			treeNode->parent->child[index + 1]->count--;
			treeNode->count++;
			return;
		}

		// ��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
		if (index >0) { // ��ǰ��㼰������Ӧ��ֵ�������ֵܽ��
			treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count] = treeNode->parent->data[index - 1];
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent = treeNode->parent->child[index - 1]; // ����е����⣬��ΪtreeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent��treeNode��ͬһָ��������޸����ֵ��ͬʱ�ı�treeNode
			}
			treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + treeNode->count] = treeNode->child[treeNode->count];
			if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + treeNode->count]->parent = treeNode->parent->child[index - 1];
			treeNode->parent->child[index - 1]->count += 1 + treeNode->count;
			for (int i = index; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i - 1] = treeNode->parent->data[i];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1];
			}
			treeNode->parent->count--;
		}
		else if (index < treeNode->parent->count) { // ������Ӧ��ֵ�����ֵܽ�㲢�뵱ǰ���
			treeNode->data[treeNode->count] = treeNode->parent->data[index];
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
				treeNode->data[treeNode->count + 1 + i] = treeNode->parent->child[index + 1]->data[i];
				treeNode->child[treeNode->count + 1 + i] = treeNode->parent->child[index + 1]->child[i];
				if (treeNode->level > 1)treeNode->child[treeNode->count + 1 + i]->parent = treeNode;
			}
			treeNode->child[treeNode->count + 1 + treeNode->parent->child[index + 1]->count] = treeNode->parent->child[index + 1]->child[treeNode->parent->child[index + 1]->count];
			if (treeNode->level > 1)treeNode->child[treeNode->count + 1 + treeNode->parent->child[index + 1]->count]->parent = treeNode;
			treeNode->count += 1 + treeNode->parent->child[index + 1]->count;
			for (int i = index + 1; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i - 1] = treeNode->parent->data[i];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1];
			}
			treeNode->parent->count--;
		}

		//levelOrder();

		// ���treeNode�ĸ����Ϊ������Һϲ��󸸽��ؼ���Ϊ0���򽫸����ָ��treeNode�����ĵ�һ���ӽ��
		if (root == treeNode->parent) {
			if (treeNode->parent->count == 0)
				root = treeNode->parent->child[0];
			return;
		}
		if (treeNode->parent->count >= min)return;
		for (index = 0; index <= treeNode->parent->parent->count; index++) {
			if (treeNode->parent->parent->child[index] == treeNode->parent)
				break;
		}
		merge(treeNode->parent, index);
	}
	/*������ȱ������ǵݹ�*/
	void dfsTraverse(BalanceTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<BalanceTreeNode<Type>*> stack;
		stack.push(root);
		BalanceTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop(); 
			cout << "{";
			for (int j = 0; j < temp->count - 1; j++) {
				cout << temp->data[j] << " ";
			}
			cout << temp->data[temp->count - 1] << "}";
			if (temp->level != 1) {
				for (int i = temp->count; i >= 0; i--) {
					stack.push(temp->child[i]);
				}
			}
			cout << endl; // ����
		}
	}
	/*��α�����������ȱ��������ǵݹ�*/
	void levelOrderTraverse(BalanceTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalanceTreeNode<Type>*> queue;//�������У����ڲ�α���
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
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
};
#pragma endregion

/**
*����: �ֵ���/ǰ׺��
*����: ϰ����
*�汾: version 1.0
*����: 2020��8��26��
*����: ʵ��ƽ��������Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region �ֵ�����Trie��
/*�ֵ�����ͳ�Ƶ��ʸ���*/
struct TrieNode {
	int count; // ��ʾ�Ըý���ǰ׺���ɵĵ��ʵĸ��������Ϊcount=0����ʾ�������Ըý���ǰ׺���ɵĵ���
	int prefix; // ��ʾ�ý���ǰ׺����
	TrieNode *child[26]; // Ĭ��ΪӢ����ĸ���ֵ������ӽ�����26���������������ֵ������������ַ���ʾ��
	TrieNode *parent;
};
class Trie {
private:
	TrieNode *root;
	int m_size;
	void release(TrieNode *treeNode) {
		if (NULL != treeNode) {
			for (int i = 0; i < 26; i++)
				release(treeNode->child[i]);
			delete treeNode;
		}
	}
	void insertStr(TrieNode *&treeNode, char *str) {
		if (NULL == treeNode||*str == '\0')
			return;

		TrieNode *node = treeNode;
		while (*str!='\0') {
			if (NULL == node->child[*str - 'a']) {
				node->child[*str - 'a']= new TrieNode();
				node->child[*str - 'a']->prefix = 1;
				node->child[*str - 'a']->parent = node;
				node->child[*str - 'a']->prefix += node->prefix;
			}
			node = node->child[*str - 'a'];
			str++;
		}
		node->count++;
		this->m_size++;
	}
	void insertStr(TrieNode *&treeNode, string str) {
		if (NULL == treeNode || str == "")
			return;

		TrieNode *node = treeNode;
		int i = 0;
		while (str[i] != '\0') {
			if (NULL == node->child[str[i] - 'a']) {
				node->child[str[i] - 'a'] = new TrieNode();
				node->child[str[i] - 'a']->prefix = 1;
				node->child[str[i] - 'a']->parent = node;
				node->child[str[i] - 'a']->prefix += node->prefix;
			}
			node = node->child[str[i] - 'a'];
			i++;
		}
		node->count++;
		this->m_size++;
	}
	int findStr(TrieNode * &treeNode, char *str) {
		if (NULL == treeNode||*str == '\0') return 0;
		TrieNode *node = treeNode;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) return 0;
			node = node->child[*str - 'a'];
		}
		return node->count;
	}
	/*ɾ�����ʣ����ʸ������㡣����0��ʾ�����ڸõ��ʣ�ɾ�����󣻷���0��ʾɾ����ȷ��*/
	int removeStr(TrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return 0;
		TrieNode *node = treeNode;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) return 0;
			node = node->child[*str - 'a'];
		}
		if (!node->count)return 0;
		this->m_size -= node->count;
		node->count = 0;

		// ����ӽ��ȫΪ�գ����ͷŸý��
		int flag = 1;
		for (int i = 0; i < 26; i++)
			flag &= (NULL == node->child[i]);
		if (flag)release(node);

		return 1;
	}
	/*������ȱ���*/
	void dfsTraverse(TrieNode *treeNode, string str) {
		for (int i = 0; i < 26; i++) {
			if (NULL != treeNode->child[i]){
				str.push_back('a' + i);
				if (treeNode->child[i]->count)
					cout << str << ": " << treeNode->child[i]->count << endl;
				dfsTraverse(treeNode->child[i], str);
				str.pop_back();
			}
		}
	}
public:
	Trie() : m_size(0) { root = new TrieNode(); }
	~Trie() { release(root); }
	void insert(char *str) { insertStr(root, str); }
	void insert(string str) { insertStr(root, str); }
	int find(char *str) { return findStr(root, str); }
	void remove(char *str) { removeStr(root, str); }
	void dfs() { dfsTraverse(root, ""); }
};

/*ǰ׺����ͳ����ĳ���ַ���Ϊǰ׺�ĵ��ʸ���*/
struct PrefixTrieNode {
	int count; // ��ʾ�Ըý��ǰ׺Ϊǰ׺�ĵ��ʸ���
	int prefix; // ��ʾ�ý���ǰ׺����
	int isword; // ��ʾ�ý��ǰ׺�Ƿ��ǵ��ʣ�0��ʾ�ý��ǰ׺���ǵ��ʣ�1��ʾ�ý��ǰ׺�ǵ���
	PrefixTrieNode *child[26]; // Ĭ��ΪӢ����ĸ���ֵ������ӽ�����26���������������ֵ������������ַ���ʾ��
	PrefixTrieNode *parent;
};
class PrefixTrie {
private:
	PrefixTrieNode *root;
	int m_size;
	void release(PrefixTrieNode *treeNode) {
		if (NULL != treeNode) {
			for (int i = 0; i < 26; i++)
				release(treeNode->child[i]);
			delete treeNode;
		}
	}
	void insertPrefix(PrefixTrieNode *&treeNode, char *str) {
		if (NULL == treeNode || *str == '\0')
			return;

		PrefixTrieNode *node = treeNode;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) {
				node->child[*str - 'a'] = new PrefixTrieNode();
				node->child[*str - 'a']->prefix = 1;
				node->child[*str - 'a']->parent = node;
				node->child[*str - 'a']->prefix += node->prefix;
			}
			node = node->child[*str - 'a'];
			node->count++;
			str++;
		}
		node->isword = 1;

		this->m_size++;
	}
	void insertPrefix(PrefixTrieNode *&treeNode, string str) {
		if (NULL == treeNode || str == "")
			return;

		PrefixTrieNode *node = treeNode;
		int i = 0;
		while (str[i] != '\0') {
			if (NULL == node->child[str[i] - 'a']) {
				node->child[str[i] - 'a'] = new PrefixTrieNode();
				node->child[str[i] - 'a']->prefix = 1;
				node->child[str[i] - 'a']->parent = node;
				node->child[str[i] - 'a']->prefix += node->prefix;
			}
			node = node->child[str[i] - 'a'];
			node->count++;
			i++;
		}
		node->isword = 1;

		this->m_size++;
	}
	int findPrefix(PrefixTrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return 0;
		PrefixTrieNode *node = treeNode;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) return 0;
			node = node->child[*str - 'a'];
			str++;
		}
		return node->count;
	}
	/*�������ǰ׺��POJ 2001 Shortest Prefixes����ע���˷�����������ÿ���ַ���ֻ����һ�ε��������������ĳ���ַ������ֶ�ε����*/
	char *findDistinctPrefix(PrefixTrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return "";
		PrefixTrieNode *node = treeNode;
		char *result = new char[strlen(str)]{ 0 };
		result[strlen(str)] = 0;
		int i = 0;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) return "";
			node = node->child[*str - 'a'];
			result[i++] = *str;
			if (node->count == 1) break;
			str++;
		}
		return result;
	}
	string findDistinctPrefix(PrefixTrieNode * &treeNode, string str) {
		if (NULL == treeNode || str == "") return "";
		PrefixTrieNode *node = treeNode;
		string result;
		int i = 0;
		while (str[i] != '\0') {
			if (NULL == node->child[str[i] - 'a']) return "";
			node = node->child[str[i] - 'a'];
			result += str[i];
			if (node->count == 1) break;
			i++;
		}
		return result;
	}
	/*ɾ��ǰ׺���ͷŸ�ǰ׺��Ӧ��㡣����0��ʾ�����ڸ�ǰ׺��ɾ�����󣻷���0��ʾɾ����ȷ��*/
	int removePrefix(PrefixTrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return 0;
		PrefixTrieNode *node = treeNode;
		while (*str != '\0') {
			if (NULL == node->child[*str - 'a']) return 0;
			node->count--;
			node = node->child[*str - 'a'];
		}
		this->m_size -= node->count;
		release(node);
		return 1;
	}
	/*������ȱ���*/
	void dfsTraverse(PrefixTrieNode *treeNode, string str) {
		for (int i = 0; i < 26; i++) {
			if (NULL != treeNode->child[i]) {
				str.push_back('a' + i);
				if (treeNode->child[i]->isword)
					cout << str << ": " << treeNode->child[i]->count << endl;
				dfsTraverse(treeNode->child[i], str);
				str.pop_back();
			}
		}
	}
public:
	PrefixTrie() : m_size(0) { root = new PrefixTrieNode(); }
	~PrefixTrie() { release(root); }
	void insert(char *str) { insertPrefix(root, str); }
	void insert(string str) { insertPrefix(root, str); }
	int find(char *str) { return findPrefix(root, str); }
	/*�������ǰ׺��POJ 2001 Shortest Prefixes����ע���˷�����������ÿ���ַ���ֻ����һ�ε��������������ĳ���ַ������ֶ�ε����*/
	char *findDistinct(char *str) { return findDistinctPrefix(root, str); }
	string findDistinct(string str) { return findDistinctPrefix(root, str); }
	void remove(char *str) { removePrefix(root, str); }
	void dfs() { dfsTraverse(root, ""); }
};

/*����unordered_map��hashmap��ʵ�ֵ��ֵ�����ͳ�Ƶ��ʸ���*/
struct HashTrieNode {
	int count; // ��ʾ�Ըý���ǰ׺���ɵĵ��ʵĸ��������Ϊcount=0����ʾ�������Ըý���ǰ׺���ɵĵ���
	int prefix; // ��ʾ�ý���ǰ׺����
	unordered_map<char,HashTrieNode*> childmap; // Ĭ��ΪӢ����ĸ���ֵ������ӽ�����26���������������ֵ������������ַ���ʾ��
	HashTrieNode *parent;
};
class HashTrie {
private:
	HashTrieNode *root;
	long long m_size; // �ַ�����
	long long m_wordcount; // ������
	long long m_nodecount; // �����
	void release(HashTrieNode *treeNode) {
		unordered_map<char, HashTrieNode*>::iterator itr;
		for (itr = treeNode->childmap.begin(); itr != treeNode->childmap.end();itr++) {
			release(itr->second);
		}
		delete treeNode;
	}
	void insertStr(HashTrieNode *&treeNode, char *str) {
		if (NULL == treeNode || *str == '\0')
			return;

		HashTrieNode *node = treeNode, *temp;
		int nodecount = this->m_nodecount;
		while (*str != '\0') {
			unordered_map<char, HashTrieNode*>::iterator itr = node->childmap.find(*str);
			if (itr == node->childmap.end()) {
				temp = new HashTrieNode();
				temp->prefix = 1;
				temp->parent = node;
				temp->prefix += node->prefix;
				node->childmap.insert(make_pair(*str, temp));
				node = temp;
				this->m_nodecount++;
			}
			else
				node = itr->second;
			str++;
		}
		node->count++;
		this->m_size++;
		if (this->m_nodecount > nodecount)
			this->m_wordcount++;
	}
	int findStr(HashTrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return 0;
		HashTrieNode *node = treeNode;
		unordered_map<char, HashTrieNode*>::iterator itr;
		while (*str != '\0') {
			itr = node->childmap.find(*str);
			if (itr == node->childmap.end()) return 0;
			node = itr->second;
		}
		return node->count;
	}
	/*ɾ�����ʣ����ʸ������㡣����0��ʾ�����ڸõ��ʣ�ɾ�����󣻷���0��ʾɾ����ȷ��*/
	int removeStr(HashTrieNode * &treeNode, char *str) {
		if (NULL == treeNode || *str == '\0') return 0;
		HashTrieNode *node = treeNode;
		unordered_map<char, HashTrieNode*>::iterator itr;
		while (*str != '\0') {
			itr = node->childmap.find(*str);
			if (itr == node->childmap.end()) return 0;
			node = itr->second;
		}
		if (!node->count)return 0;
		this->m_size -= node->count;
		node->count = 0;

		// ����ӽ��ȫΪ�գ����ͷŸý��
		if (node->childmap.empty())release(node);

		return 1;
	}
	/*������ȱ���*/
	void dfsTraverse(HashTrieNode *treeNode, string str) {
		unordered_map<char, HashTrieNode*>::iterator itr;
		for (itr = treeNode->childmap.begin(); itr != treeNode->childmap.end(); itr++) {
			str.push_back(itr->first);
			if (itr->second->count)
				cout << str << ": " << itr->second->count << endl;
			dfsTraverse(itr->second, str);
			str.pop_back();
		}
	}
	/*������ȱ�����д���ļ�*/
	void dfsTraverse(HashTrieNode *treeNode, string str, FILE *fwriter) {
		unordered_map<char, HashTrieNode*>::iterator itr;
		string temp;
		char *numchar = new char[20];
		for (itr = treeNode->childmap.begin(); itr != treeNode->childmap.end(); itr++) {
			str.push_back(itr->first);
			if (itr->second->count) {
				//cout << str << ": " << itr->second->count << endl;
				temp = str;
				sprintf(numchar, "%d", itr->second->count);
				temp += ": ";
				temp += numchar;
				temp += "\n";
				fwrite(temp.c_str(), 1, temp.length(), fwriter);
			}
			dfsTraverse(itr->second, str, fwriter);
			str.pop_back();
		}
	}
public:
	HashTrie() : m_size(0) { root = new HashTrieNode(); this->m_nodecount = 1; }
	~HashTrie() { release(root); }
	void insert(char *str) { insertStr(root, str); }
	int find(char *str) { return findStr(root, str); }
	void remove(char *str) { removeStr(root, str); }
	void dfs() { dfsTraverse(root, ""); }
	void dfs(FILE *fwriter) { dfsTraverse(root, "", fwriter); }
	long long size() { return this->m_size; }
	long long wordcount() { return this->m_wordcount; }
	long long nodecount() { return this->m_nodecount; }
};
#pragma endregion

/**
*����: B+��/B*��
*����: ϰ����
*�汾: version 1.0
*����: 2020��8��29��
*����: ʵ��B+������׼�汾����B+�������ڰ汾����B*���Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region B+������B���ĸİ棬Ҷ�ӽ������ָ���ֵܽ���ָ�룬�������ݶ��洢��Ҷ�ӽ���ϣ�֦���ֻ�洢�������ݣ����ڲ��ҵĹؼ��֣�

/**
*����: B+������׼�汾��
*����: ϰ����
*�汾: version 1.0
*����: 2020��8��29��
*����: �ο������ı�׼�汾��m��B+���ؼ������洢m-1�������ٴ洢(m+1)/2-1�����ӽ�������m��������m/2����
	   ʵ��B+���Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region B+������׼�汾��
template <class Type>
struct BPlusTreeNode {
	int count; // �ؼ��ָ���
	int level; // ���߶ȣ�Ҷ�ӽ���levelΪ1��node->level=max(node->child->level)+1
	Type *data; // �ؼ���
	BPlusTreeNode<Type> **child;
	BPlusTreeNode<Type> *parent;
	BPlusTreeNode<Type> *brother;
	BPlusTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BPlusTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m];//m��ʾb+���������ؼ������洢m-1�������峤��Ϊm�Ĺؼ������飬�����1���ռ���Ϊ���ڲ�����Ĺؼ�����ʱʹ��
		this->child = new BPlusTreeNode*[m + 1];//�ӽ�����m�������峤��Ϊm+1���ӽ�����飬�����1���ռ���Ϊ���ڲ�������ӽ������ʱʹ��
	}
};
template <class Type>
class BPlusTree {
private:
	BPlusTreeNode<Type> *root;
	BPlusTreeNode<Type> *data; // ָ���һ��Ҷ�ӽ��
	int m;
	int min;
	int m_size;
	void release(BPlusTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			if (treeNode->level != 1)
				for (int i = 0; i <= treeNode->count; i++)
					release(treeNode->child[i]);
			delete treeNode;
		}
	}
	int level(BPlusTreeNode<Type> *node) {
		return (NULL == node) ? 0 : node->level;
	}
	void insertNode(BPlusTreeNode<Type> *&treeNode, Type data) {
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
			BPlusTreeNode<Type> *brotherNode = new BPlusTreeNode<Type>(this->m - 1), *temp;
			int index = 0, middle = this->m / 2 - 1;
			if (treeNode->level == 1) {
				for (int i = middle + 1; i < treeNode->count; i++)
					brotherNode->data[index++] = treeNode->data[i];

				// Ҷ�ӽ������һ��ָ���ֵܽ���ָ��
				temp = treeNode->brother;
				treeNode->brother = brotherNode;
				brotherNode->brother = temp;
			}
			else
			{
				for (int i = middle + 2; i < treeNode->count; i++)
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
			treeNode->count = middle + 1;

			if (root == treeNode) {
				BPlusTreeNode<Type> *parentNode = new BPlusTreeNode<Type>(this->m - 1);
				parentNode->data[0] = treeNode->data[middle + 1];
				parentNode->child[0] = treeNode;
				parentNode->child[1] = brotherNode;
				treeNode->parent = parentNode;
				brotherNode->parent = parentNode;
				parentNode->count = 1;
				parentNode->level = treeNode->level + 1;
				this->root = parentNode;
			}
			else {
				for (index = treeNode->parent->count; index >= 0; index--) {
					if (treeNode->parent->child[index] != treeNode) { // ���ҵ�ǰ����ڸ������ӽ�㼯���е�λ��
						treeNode->parent->data[index] = treeNode->parent->data[index - 1];
						treeNode->parent->child[index + 1] = treeNode->parent->child[index];
					}
					else
						break;
				}
				treeNode->parent->data[index] = treeNode->data[middle + 1];
				treeNode->parent->child[index + 1] = brotherNode;
				brotherNode->parent = treeNode->parent;
				treeNode->parent->count++;
			}
		}
        #pragma endregion
	}
	BPlusTreeNode<Type> *findNode(BPlusTreeNode<Type> *&treeNode, Type data) {
		int i;
		if (treeNode->level == 1) {
			for (i = treeNode->count - 1; i >= 0; i--)
				if (treeNode->data[i] == data)
					return treeNode;
			cout << "not found" << endl;
			return NULL;
		}
		else {
			for (i = 0; i < treeNode->count; i++)
				if (treeNode->data[i] > data)
					return findNode(treeNode->child[i], data);
			return findNode(treeNode->child[treeNode->count], data);
		}
	}
	/*ɾ����㣬�粻�������ٹؼ���Ҫ����ϲ��ֵܽ�㡣ע��֦����п��ܰ�����ɾ��Ԫ�صļ�ֵ������level��¼������Ԫ�ؼ�ֵ�ĸ�����level�����level>1��ʾ����������ɾ��Ԫ�صļ�ֵ����Ҫ���¸ø�����ֵ�����level=1��ʾ����㲻������ɾ��Ԫ�صļ�ֵ*/
	void removeNode(BPlusTreeNode<Type> *&treeNode, Type data, int level) {
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
				for (int j = i; j < treeNode->count; j++)
					treeNode->data[j] = treeNode->data[j + 1];
				treeNode->count--;

				// �����ɾԪ���ǵ�1���ҵ�ǰ��㽫��ɾԪ��ɾ����ʣ��Ԫ�ظ��������㣬���¸������ֵ�����򲻸��¸������ֵ
				if (!i && treeNode->count) {
					int l = level;
					BPlusTreeNode<Type> *node = treeNode;
					while (l-- > 2)
						node = node->parent;
					int index;
					for (index = 0; index <= node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
					if (index > 0)
						node->parent->data[index - 1] = treeNode->data[0];
				}
				if (root == treeNode || treeNode->count >= min) {
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
					merge(treeNode, index, level);
				}
			}
		}
		else
		{
			int i;
			for (i = 0; i < treeNode->count; i++) {
				if (treeNode->data[i] == data)level = treeNode->level;
				if (treeNode->data[i] > data)
					break;
			}
			removeNode(treeNode->child[i], data, level);
		}
	}
	/*�ϲ��ֵܽ�㣬����˵��������treeNode��ʾ��ǰҪ�ϲ��Ľ�㣬����index��ʾtreeNode�ڸ�����е�λ�ã�����level��removeNode�������룬level��¼������ɾ��Ԫ�ؼ�ֵ�ĸ�����level*/
	void merge(BPlusTreeNode<Type> *treeNode, int index, int level){
		if (treeNode->level == 1) {
			if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
				for (int i = treeNode->count - 1; i >= 0; i--)
					treeNode->data[i + 1] = treeNode->data[i];
				treeNode->parent->data[index - 1] = treeNode->data[0] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
				treeNode->parent->child[index - 1]->count--;
				treeNode->count++;

				// ���¸������ֵ
				BPlusTreeNode<Type> *node = treeNode;
				while (level-- > 2)
					node = node->parent;
				int index;
				for (index = 0; index <= node->parent->count; index++) {
					if (node->parent->child[index] == node)
						break;
				}
				if (index > 0)
					node->parent->data[index - 1] = treeNode->data[0];

				return;
			}
			if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
				int count = treeNode->count;
				treeNode->data[treeNode->count] = treeNode->parent->child[index + 1]->data[0];
				treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[1];
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
					treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];
				treeNode->parent->child[index + 1]->count--;
				treeNode->count++;

				// ���¸������ֵ
				if (!count && level > 1) {
					BPlusTreeNode<Type> *node = treeNode;
					while (level-- > 2)
						node = node->parent;
					for (index = 0; index <= node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
					if (index > 0)
						node->parent->data[index - 1] = treeNode->data[0];
				}

				return;
			}

			// ��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
			if (index > 0) { // ��ǰ��㲢�뵽���ֵܽ��
				for (int i = 0; i < treeNode->count; i++)
					treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->count += treeNode->count;
				for (int i = index; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;

				// ע����������ø��¸������ֵ����Ϊ3�㼰3�����ϵĸ�����ֵ���������ӽ�����ֵ������������ý�㲢�뵽�����ֵܽ�㣬˵���ý�㲻�������ӽ��

				// ����ָ���ֵܽ���ָ��
				treeNode->parent->child[index - 1]->brother = treeNode->brother;
			}
			else if (index < treeNode->parent->count){ // ���ֵܽ�㲢�뵽��ǰ���
				int count = treeNode->count;
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
					treeNode->data[treeNode->count + i] = treeNode->parent->child[index + 1]->data[i];
				treeNode->count += treeNode->parent->child[index + 1]->count;
				for (int i = index + 1; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;

				// ���¸������ֵ
				if (!count && level > 1) {
					BPlusTreeNode<Type> *node = treeNode;
					while (level-- > 2)
						node = node->parent;
					for (index = 0; index <= node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
					if (index > 0)
						node->parent->data[index - 1] = treeNode->data[0];
				}

				// ����ָ���ֵܽ���ָ��
				treeNode->brother = treeNode->brother->brother;
			}
		}
		else
		{
			if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
				// Ǩ�Ƽ�ֵ
				for (int i = treeNode->count - 1; i >= 0; i--)
					treeNode->data[i + 1] = treeNode->data[i];
				treeNode->data[0] = treeNode->parent->data[index - 1];
				treeNode->parent->data[index - 1] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
				
				// Ǩ���ӽ��
				for (int i = treeNode->count; i >= 0; i--)
					treeNode->child[i + 1] = treeNode->child[i];
				treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count];
				treeNode->child[0]->parent = treeNode;

				treeNode->parent->child[index - 1]->count--;
				treeNode->count++;
				return;
			}
			if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
				// Ǩ�Ƽ�ֵ
				treeNode->data[treeNode->count] = treeNode->parent->data[index];
				treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[0];
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
					treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];

				// Ǩ���ӽ��
				treeNode->child[treeNode->count + 1] = treeNode->parent->child[index + 1]->child[0];
				treeNode->child[treeNode->count + 1]->parent = treeNode;
				for (int i = 0; i <= treeNode->parent->child[index + 1]->count; i++)
					treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];

				treeNode->parent->child[index + 1]->count--;
				treeNode->count++;
				return;
			}

			// ��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
			if (index >0) { // ��ǰ��㼰������Ӧ��ֵ�������ֵܽ��
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count] = treeNode->parent->data[index - 1];
				for (int i = 0; i < treeNode->count; i++) {
					treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->data[i];
					treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->child[i];
					treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent = treeNode->parent->child[index - 1]; // ����е����⣬��ΪtreeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent��treeNode��ͬһָ��������޸����ֵ��ͬʱ�ı�treeNode
				}
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + treeNode->count] = treeNode->child[treeNode->count];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + treeNode->count]->parent = treeNode->parent->child[index - 1];
				treeNode->parent->child[index - 1]->count += 1 + treeNode->count;
				for (int i = index; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;
			} 
			else if (index < treeNode->parent->count) { // ������Ӧ��ֵ�����ֵܽ�㲢�뵱ǰ���
				treeNode->data[treeNode->count] = treeNode->parent->data[index];
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
					treeNode->data[treeNode->count + 1 + i] = treeNode->parent->child[index + 1]->data[i];
					treeNode->child[treeNode->count + 1 + i] = treeNode->parent->child[index + 1]->child[i];
					treeNode->child[treeNode->count + 1 + i]->parent = treeNode;
				}
				treeNode->child[treeNode->count + 1 + treeNode->parent->child[index + 1]->count] = treeNode->parent->child[index + 1]->child[treeNode->parent->child[index + 1]->count];
				treeNode->child[treeNode->count + 1 + treeNode->parent->child[index + 1]->count]->parent = treeNode;
				treeNode->count += 1 + treeNode->parent->child[index + 1]->count;
				for (int i = index + 1; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;
			}
		}
		
		levelOrder();

		// ���treeNode�ĸ����Ϊ������Һϲ��󸸽��ؼ���Ϊ0���򽫸����ָ��treeNode�����ĵ�һ���ӽ��
		if (root == treeNode->parent) {
			if (treeNode->parent->count == 0)
				root = treeNode->parent->child[0];
			return;
		}
		if (treeNode->parent->count >= min)return;
		for (index = 0; index <= treeNode->parent->parent->count; index++) {
			if (treeNode->parent->parent->child[index] == treeNode->parent)
				break;
		}
		merge(treeNode->parent, index, level);
	}
	/*������ȱ������ǵݹ�*/
	void dfsTraverse(BPlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<BPlusTreeNode<Type>*> stack;
		stack.push(root);
		BPlusTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << "{";
			for (int j = 0; j < temp->count - 1; j++) {
				cout << temp->data[j] << " ";
			}
			cout << temp->data[temp->count - 1] << "}";
			if (temp->level != 1) {
				for (int i = temp->count; i >= 0; i--) {
					stack.push(temp->child[i]);
				}
			}
			cout << endl; // ����
		}
	}
	/*��α�����������ȱ��������ǵݹ�*/
	void levelOrderTraverse(BPlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BPlusTreeNode<Type>*> queue;//�������У����ڲ�α���
		queue.push(root);
		BPlusTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << "{";
				for (int j = 0; j < temp->count - 1; j++) {
					cout << temp->data[j] << " ";
				}
				cout << temp->data[temp->count - 1] << "}";
				if (temp->level != 1) {
					for (int j = 0; j <= temp->count; j++) {
						queue.push(temp->child[j]);
					}
				}
			}
			cout << endl; // ����
		}
	}
public:
	BPlusTree(int m) : root(NULL), m_size(0) {
		this->m = m;
		this->min = (this->m - 1) / 2;
	}
	~BPlusTree() { release(root); }
	void insert(Type data) {
		if (NULL == root) {
			this->root = new BPlusTreeNode<Type>(this->m - 1);
			this->root->data[0] = data;
			this->root->count++;
			this->root->level = 1;
			this->m_size++;
			this->data = this->root; // ���ݱ��㷨��Ƶ�ԭ��ֻ���ڸ�����һ������ʱ������ָ��this->dataָ���һ�����ɵ�root
			return;
		}
		insertNode(root, data);
	}
	BPlusTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data, 1); }
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
	void printData() {
		BPlusTreeNode<Type> *node = this->data;
		while (NULL != node) {
			cout << "{";
			for (int j = 0; j < node->count - 1; j++)
				cout << node->data[j] << " ";
			cout << node->data[node->count - 1] << "}";
			node = node->brother;
			if (NULL != node)
				cout << "->";
		}
		cout << endl; // ����
	}
};
#pragma endregion

/**
*����: B+�������ڰ汾��
*����: ϰ����
*�汾: version 2.0
*����: 2020��8��29��
*����: �ο����ڰ汾����ͬ�ڱ�׼�汾��m��B+���ؼ������洢m�������ٴ洢(m+1)/2�����ӽ�������m��������m/2����
*/
#pragma region B+�������ڰ汾��
template <class Type>
struct BalancePlusTreeNode {
	int count;
	int level; // ���߶ȣ�Ҷ�ӽ���levelΪ1��node->level=max(node->child->level)+1
	Type *data; // �ؼ���
	BalancePlusTreeNode<Type> **child;
	BalancePlusTreeNode<Type> *parent;
	BalancePlusTreeNode<Type> *brother;
	BalancePlusTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BalancePlusTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m + 1];//m��ʾb+���������ؼ������洢m�������峤��Ϊm+1�Ĺؼ������飬�����1���ռ���Ϊ���ڲ�����Ĺؼ�����ʱʹ��
		this->child = new BalancePlusTreeNode*[m + 1];//�ӽ�����m�������峤��Ϊm+1���ӽ�����飬�����1���ռ���Ϊ���ڲ�������ӽ������ʱʹ��
	}
};
template <class Type>
class BalancePlusTree {
private:
	BalancePlusTreeNode<Type> *root;
	BalancePlusTreeNode<Type> *data;
	int m;
	int min;
	int m_size;
	void release(BalancePlusTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			if (treeNode->level != 1)
				for (int i = 0; i < treeNode->count; i++)
					release(treeNode->child[i]);
			delete treeNode;
		}
	}
	int level(BalancePlusTreeNode<Type> *node) {
		return (NULL == node) ? 0 : node->level;
	}
	void insertNode(BalancePlusTreeNode<Type> *&treeNode, Type data) {
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
			for (i = 1; i < treeNode->count; i++) {
				if (treeNode->data[i] == data) {
					cout << "insert failed" << endl;
					return;
				}
				if (treeNode->data[i] > data)
					break;
			}
			insertNode(treeNode->child[i - 1], data);

			// ���¸������ֵ
			if (treeNode->data[0] > data)
				treeNode->data[0] = data;
		}

        #pragma region ���ѵ���
		if (treeNode->count > this->m)
		{
			BalancePlusTreeNode<Type> *brotherNode = new BalancePlusTreeNode<Type>(this->m), *temp;
			int index = 0, middle = this->m / 2;
			if (treeNode->level == 1) {
				for (int i = middle + 1; i < treeNode->count; i++)
					brotherNode->data[index++] = treeNode->data[i];

				// Ҷ�ӽ������һ��ָ���ֵܽ���ָ��
				temp = treeNode->brother;
				treeNode->brother = brotherNode;
				brotherNode->brother = temp;
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
			}
			brotherNode->count = index;
			brotherNode->level = treeNode->level;
			treeNode->count = middle + 1;

			if (root == treeNode) {
				BalancePlusTreeNode<Type> *parentNode = new BalancePlusTreeNode<Type>(this->m);
				parentNode->data[0] = treeNode->data[0];
				parentNode->data[1] = brotherNode->data[0];
				parentNode->child[0] = treeNode;
				parentNode->child[1] = brotherNode;
				treeNode->parent = parentNode;
				brotherNode->parent = parentNode;
				parentNode->count = 2;
				parentNode->level = treeNode->level + 1;
				this->root = parentNode;
			}
			else {
				for (int i = treeNode->parent->count - 1; i >= 0; i--) {
					if (treeNode->parent->child[i] != treeNode) { // ���ҵ�ǰ����ڸ������ӽ�㼯���е�λ��
						treeNode->parent->data[i + 1] = treeNode->parent->data[i];
						treeNode->parent->child[i + 1] = treeNode->parent->child[i];
						index = i - 1;
					}
					else
					{
						index = i;
						break;
					}
				}
				treeNode->parent->data[index + 1] = brotherNode->data[0];
				treeNode->parent->child[index + 1] = brotherNode;
				brotherNode->parent = treeNode->parent;
				treeNode->parent->count++;
			}
		}
        #pragma endregion
	}
	BalancePlusTreeNode<Type> *findNode(BalancePlusTreeNode<Type> *&treeNode, Type data) {
		int i;
		if (treeNode->level == 1) {
			for (i = treeNode->count - 1; i >= 0; i--)
				if (treeNode->data[i] == data)
					return treeNode;
			cout << "not found" << endl;
			return NULL;
		}
		else {
			if (treeNode->data[0] > data) {
				cout << "not found" << endl;
				return NULL;
			}
			for (i = 1; i < treeNode->count; i++)
				if (treeNode->data[i] > data)
					break;
			return findNode(treeNode->child[i - 1], data);
		}
	}
	/*ɾ����㣬�粻�������ٹؼ���Ҫ����ϲ��ֵܽ��*/
	void removeNode(BalancePlusTreeNode<Type> *&treeNode, Type data) {
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
				for (int j = i; j < treeNode->count; j++)
					treeNode->data[j] = treeNode->data[j + 1];
				treeNode->count--;

				// ���¸������ֵ
				if (treeNode->count > 0) {
					BalancePlusTreeNode<Type> *node = treeNode;
					while (!i && root != node) {
						for (i = 0; i < node->parent->count; i++) {
							if (node->parent->child[i] == node)
								break;
						}
						node->parent->data[i] = treeNode->data[0];
						node = node->parent;
					}
				}

				if (root == treeNode || treeNode->count >= min) {
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
					merge(treeNode, index);
				}
			}
		}
		else
		{
			int i;
			for (i = 1; i < treeNode->count; i++) {
				if (treeNode->data[i] > data)
					break;
			}
			removeNode(treeNode->child[i - 1], data);
		}
	}
	/*�ϲ��ֵܽ�㣬����˵��������treeNode��ʾ��ǰҪ�ϲ��Ľ�㣬����index��ʾtreeNode�ڸ�����е�λ��*/
	void merge(BalancePlusTreeNode<Type> *treeNode, int index) {
		if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
			for (int i = treeNode->count - 1; i >= 0; i--) {
				treeNode->data[i + 1] = treeNode->data[i];
				treeNode->child[i + 1] = treeNode->child[i];
			}
			treeNode->parent->data[index] = treeNode->data[0] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
			treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count - 1];
			if (treeNode->level > 1)
				treeNode->child[0]->parent = treeNode;
			treeNode->parent->child[index - 1]->count--;
			treeNode->count++;
			return;
		}
		if (index < treeNode->parent->count - 1 && treeNode->parent->child[index + 1]->count > min) {
			treeNode->data[treeNode->count] = treeNode->parent->child[index + 1]->data[0];
			treeNode->child[treeNode->count] = treeNode->parent->child[index + 1]->child[0];
			if (treeNode->level > 1)treeNode->child[treeNode->count]->parent = treeNode;
			treeNode->parent->data[index + 1] = treeNode->parent->child[index + 1]->data[1];
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
				treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];
				treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];
			}
			treeNode->parent->child[index + 1]->count--;
			treeNode->count++;

			// �����ǰ�����Ԫ��֮ǰΪ�գ�����¸������ֵ
			if (!(treeNode->count - 1)) {
				BalancePlusTreeNode<Type> *node = treeNode;
				while (!index && root != node) {
					node->parent->data[index] = treeNode->data[0];
					node = node->parent;
					for (index = 0; index < node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
				}
				node->parent->data[index] = treeNode->data[0];
			}

			return;
		}

		// ��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
		if (index > 0) { // ��ǰ��㲢�뵽���ֵܽ��
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i]->parent = treeNode->parent->child[index - 1];
			}
			treeNode->parent->child[index - 1]->count += treeNode->count;
			for (int i = index; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i + 1];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1]; // �������treeNode�����ò������������е����⡣ԭ�������treeNode�����ò�������treeNode->parent->child[index]��ͬһָ�룬�޸�treeNode->parent->child[index]��ͬʱ�޸�treeNode������취�ǽ�����treeNode�ĳ���ʽ����
			}
			treeNode->parent->count--;

			// ����ָ���ֵܽ���ָ��
			if (treeNode->level == 1)treeNode->parent->child[index - 1]->brother = treeNode->brother;
		}
		else if (index < treeNode->parent->count - 1) { // ���ֵܽ�㲢�뵽��ǰ���
			int count=treeNode->count;
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
				treeNode->data[treeNode->count + i] = treeNode->parent->child[index + 1]->data[i];
				treeNode->child[treeNode->count + i] = treeNode->parent->child[index + 1]->child[i];
				if (treeNode->level > 1)treeNode->child[treeNode->count + i]->parent = treeNode;
			}
			treeNode->count += treeNode->parent->child[index + 1]->count;
			for (int i = index + 1; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1];
			}
			treeNode->parent->count--;

			// �����ǰ���ϲ�֮ǰΪ�գ�����¸������ֵ
			if (!count) {
				treeNode->parent->data[index] = treeNode->data[0];
				BalancePlusTreeNode<Type> *node = treeNode->parent;
				while (root != node) {
					for (index = 0; index < node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
					if (index > 0)break;
					node->parent->data[index] = treeNode->data[0];
					node = node->parent;
				}
			}

			// ����ָ���ֵܽ���ָ��
			if (treeNode->level == 1)treeNode->brother = treeNode->brother->brother;
		}

		// ���treeNode�ĸ����Ϊ������Һϲ��󸸽��ؼ���Ϊ0���򽫸����ָ��treeNode�����ĵ�һ���ӽ��
		if (root == treeNode->parent) {
			if (treeNode->parent->count == 1)
				root = treeNode->parent->child[0];
			return;
		}
		if (treeNode->parent->count >= min)return;
		for (index = 0; index <= treeNode->parent->parent->count; index++) {
			if (treeNode->parent->parent->child[index] == treeNode->parent)
				break;
		}
		merge(treeNode->parent, index);
	}
	/*������ȱ������ǵݹ�*/
	void dfsTraverse(BalancePlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<BalancePlusTreeNode<Type>*> stack;
		stack.push(root);
		BalancePlusTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << "{";
			for (int j = 0; j < temp->count - 1; j++) {
				cout << temp->data[j] << " ";
			}
			cout << temp->data[temp->count - 1] << "}";
			if (temp->level != 1) {
				for (int i = temp->count - 1; i >= 0; i--) {
					stack.push(temp->child[i]);
				}
			}
			cout << endl; // ����
		}
	}
	/*��α�����������ȱ��������ǵݹ�*/
	void levelOrderTraverse(BalancePlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalancePlusTreeNode<Type>*> queue;//�������У����ڲ�α���
		queue.push(root);
		BalancePlusTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << "{";
				for (int j = 0; j < temp->count - 1; j++) {
					cout << temp->data[j] << " ";
				}
				cout << temp->data[temp->count - 1] << "}";
				if (temp->level != 1) {
					for (int j = 0; j < temp->count; j++) {
						queue.push(temp->child[j]);
					}
				}
			}
			cout << endl; // ����
		}
	}
public:
	BalancePlusTree(int m) : root(NULL), m_size(0) {
		this->m = m;
		this->min = (this->m + 1) / 2;
	}
	~BalancePlusTree() { release(root); }
	void insert(Type data) {
		if (NULL == root) {
			this->root = new BalancePlusTreeNode<Type>(this->m);
			this->root->data[0] = data;
			this->root->count++;
			this->root->level = 1;
			this->m_size++;
			this->data = this->root; // ���ݱ��㷨��Ƶ�ԭ��ֻ���ڸ�����һ������ʱ������ָ��ָthis->data���һ�����ɵ�root
			return;
		}
		insertNode(root, data);
	}
	BalancePlusTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
	void printData() {
		BalancePlusTreeNode<Type> *node = this->data;
		while (NULL != node) {
			cout << "{";
			for (int j = 0; j < node->count - 1; j++)
				cout << node->data[j] << " ";
			cout << node->data[node->count - 1] << "}";
			node = node->brother;
			if (NULL != node)
				cout << "->";
		}
		cout << endl; // ����
	}
};
#pragma endregion

/**
*����: B*��
*����: ϰ����
*�汾: version 1.0
*����: 2020��8��29��
*����: B*����B+���ĸİ棬��Ҷ�ӽ����ָ���ֵܽ���ָ�룬֦���Ҳ����ָ���ֵܽ���ָ�룬ͬʱ����B+��һ�������ݶ��洢��Ҷ�ӽ���ϣ�֦���ֻ�洢�������ݣ����ڲ��ҵĹؼ��֣�
	   ʵ��B*���Ĳ��롢ɾ�������Ҽ���ӡ����
*/
#pragma region B*��
template <class Type>
struct BalancePlusProTreeNode {
	int count;
	int level; // ���߶ȣ�Ҷ�ӽ���levelΪ1��node->level=max(node->child->level)+1
	Type *data; // �ؼ���
	BalancePlusProTreeNode<Type> **child;
	BalancePlusProTreeNode<Type> *parent;
	BalancePlusProTreeNode<Type> *brother;
	BalancePlusProTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BalancePlusProTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m + 1];//m��ʾb+���������ؼ������洢m�������峤��Ϊm+1�Ĺؼ������飬�����1���ռ���Ϊ���ڲ�����Ĺؼ�����ʱʹ��
		this->child = new BalancePlusProTreeNode*[m + 1];//�ӽ�����m�������峤��Ϊm+1���ӽ�����飬�����1���ռ���Ϊ���ڲ�������ӽ������ʱʹ��
	}
};
template <class Type>
class BalancePlusProTree {
private:
	BalancePlusProTreeNode<Type> *root;
	BalancePlusProTreeNode<Type> *data;
	int m;
	int min;
	int m_size;
	void release(BalancePlusProTreeNode<Type> *treeNode) {
		if (NULL != treeNode) {
			if (treeNode->level != 1)
				for (int i = 0; i < treeNode->count; i++)
					release(treeNode->child[i]);
			delete treeNode;
		}
	}
	int level(BalancePlusProTreeNode<Type> *node) {
		return (NULL == node) ? 0 : node->level;
	}
	void insertNode(BalancePlusProTreeNode<Type> *&treeNode, Type data) {
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
			for (i = 1; i < treeNode->count; i++) {
				if (treeNode->data[i] == data) {
					cout << "insert failed" << endl;
					return;
				}
				if (treeNode->data[i] > data)
					break;
			}
			insertNode(treeNode->child[i - 1], data);

			// ���¸������ֵ
			if (treeNode->data[0] > data)
				treeNode->data[0] = data;
		}

        #pragma region ���ѵ���
		if (treeNode->count > this->m)
		{
			BalancePlusProTreeNode<Type> *brotherNode = new BalancePlusProTreeNode<Type>(this->m), *temp;
			int index = 0, middle = this->m / 2;
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
			}
			brotherNode->count = index;
			brotherNode->level = treeNode->level;
			treeNode->count = middle + 1;
			// Ҷ�ӽ������һ��ָ���ֵܽ���ָ��
			temp = treeNode->brother;
			treeNode->brother = brotherNode;
			brotherNode->brother = temp;

			if (root == treeNode) {
				BalancePlusProTreeNode<Type> *parentNode = new BalancePlusProTreeNode<Type>(this->m);
				parentNode->data[0] = treeNode->data[0];
				parentNode->data[1] = brotherNode->data[0];
				parentNode->child[0] = treeNode;
				parentNode->child[1] = brotherNode;
				treeNode->parent = parentNode;
				brotherNode->parent = parentNode;
				parentNode->count = 2;
				parentNode->level = treeNode->level + 1;
				this->root = parentNode;
			}
			else {
				for (int i = treeNode->parent->count - 1; i >= 0; i--) {
					if (treeNode->parent->child[i] != treeNode) { // ���ҵ�ǰ����ڸ������ӽ�㼯���е�λ��
						treeNode->parent->data[i + 1] = treeNode->parent->data[i];
						treeNode->parent->child[i + 1] = treeNode->parent->child[i];
						index = i - 1;
					}
					else
					{
						index = i;
						break;
					}
				}
				treeNode->parent->data[index + 1] = brotherNode->data[0];
				treeNode->parent->child[index + 1] = brotherNode;
				brotherNode->parent = treeNode->parent;
				treeNode->parent->count++;
			}
		}
        #pragma endregion
	}
	BalancePlusProTreeNode<Type> *findNode(BalancePlusProTreeNode<Type> *&treeNode, Type data) {
		int i;
		if (treeNode->level == 1) {
			for (i = treeNode->count - 1; i >= 0; i--)
				if (treeNode->data[i] == data)
					return treeNode;
			cout << "not found" << endl;
			return NULL;
		}
		else {
			if (treeNode->data[0] > data) {
				cout << "not found" << endl;
				return NULL;
			}
			for (i = 1; i < treeNode->count; i++)
				if (treeNode->data[i] > data)
					break;
			return findNode(treeNode->child[i - 1], data);
		}
	}
	/*ɾ����㣬�粻�������ٹؼ���Ҫ����ϲ��ֵܽ��*/
	void removeNode(BalancePlusProTreeNode<Type> *&treeNode, Type data) {
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
				for (int j = i; j < treeNode->count; j++)
					treeNode->data[j] = treeNode->data[j + 1];
				treeNode->count--;

				// ���¸������ֵ
				if (treeNode->count > 0) {
					BalancePlusProTreeNode<Type> *node = treeNode;
					while (!i && root != node) {
						for (i = 0; i < node->parent->count; i++) {
							if (node->parent->child[i] == node)
								break;
						}
						node->parent->data[i] = treeNode->data[0];
						node = node->parent;
					}
				}

				if (root == treeNode || treeNode->count >= min) {
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
					merge(treeNode, index);
				}
			}
		}
		else
		{
			int i;
			for (i = 1; i < treeNode->count; i++) {
				if (treeNode->data[i] > data)
					break;
			}
			removeNode(treeNode->child[i - 1], data);
		}
	}
	/*�ϲ��ֵܽ�㣬����˵��������treeNode��ʾ��ǰҪ�ϲ��Ľ�㣬����index��ʾtreeNode�ڸ�����е�λ��*/
	void merge(BalancePlusProTreeNode<Type> *treeNode, int index) {
		if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
			for (int i = treeNode->count - 1; i >= 0; i--) {
				treeNode->data[i + 1] = treeNode->data[i];
				treeNode->child[i + 1] = treeNode->child[i];
			}
			treeNode->parent->data[index] = treeNode->data[0] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
			treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count - 1];
			if (treeNode->level > 1)
				treeNode->child[0]->parent = treeNode;
			treeNode->parent->child[index - 1]->count--;
			treeNode->count++;
			return;
		}
		if (index < treeNode->parent->count - 1 && treeNode->parent->child[index + 1]->count > min) {
			treeNode->data[treeNode->count] = treeNode->parent->child[index + 1]->data[0];
			treeNode->child[treeNode->count] = treeNode->parent->child[index + 1]->child[0];
			if (treeNode->level > 1)treeNode->child[treeNode->count]->parent = treeNode;
			treeNode->parent->data[index + 1] = treeNode->parent->child[index + 1]->data[1];
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
				treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];
				treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];
			}
			treeNode->parent->child[index + 1]->count--;
			treeNode->count++;

			// �����ǰ�����Ԫ��֮ǰΪ�գ�����¸������ֵ
			if (!(treeNode->count - 1)) {
				BalancePlusProTreeNode<Type> *node = treeNode;
				while (!index && root != node) {
					node->parent->data[index] = treeNode->data[0];
					node = node->parent;
					for (index = 0; index < node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
				}
				node->parent->data[index] = treeNode->data[0];
			}

			return;
		}

		// ��������ֵܽ��ؼ������պö�Ϊ���ޣ���ֵ�ӵ�ǰ�����ɾ�������ѡ��һ���ֵܽ��ϲ�
		if (index > 0) { // ��ǰ��㲢�뵽���ֵܽ��
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i]->parent = treeNode->parent->child[index - 1];
			}
			treeNode->parent->child[index - 1]->count += treeNode->count;
			for (int i = index; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i + 1];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1]; // �������treeNode�����ò������������е����⡣ԭ�������treeNode�����ò�������treeNode->parent->child[index]��ͬһָ�룬�޸�treeNode->parent->child[index]��ͬʱ�޸�treeNode������취�ǽ�����treeNode�ĳ���ʽ����
			}
			treeNode->parent->count--;

			// ����ָ���ֵܽ���ָ��
			treeNode->parent->child[index - 1]->brother = treeNode->brother;
		}
		else if (index < treeNode->parent->count - 1) { // ���ֵܽ�㲢�뵽��ǰ���
			int count = treeNode->count;
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++) {
				treeNode->data[treeNode->count + i] = treeNode->parent->child[index + 1]->data[i];
				treeNode->child[treeNode->count + i] = treeNode->parent->child[index + 1]->child[i];
				if (treeNode->level > 1)treeNode->child[treeNode->count + i]->parent = treeNode;
			}
			treeNode->count += treeNode->parent->child[index + 1]->count;
			for (int i = index + 1; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1];
			}
			treeNode->parent->count--;

			// �����ǰ���ϲ�֮ǰΪ�գ�����¸������ֵ
			if (!count) {
				treeNode->parent->data[index] = treeNode->data[0];
				BalancePlusProTreeNode<Type> *node = treeNode->parent;
				while (root != node) {
					for (index = 0; index < node->parent->count; index++) {
						if (node->parent->child[index] == node)
							break;
					}
					if (index > 0)break;
					node->parent->data[index] = treeNode->data[0];
					node = node->parent;
				}
			}

			// ����ָ���ֵܽ���ָ��
			treeNode->brother = treeNode->brother->brother;
		}

		// ���treeNode�ĸ����Ϊ������Һϲ��󸸽��ؼ���Ϊ0���򽫸����ָ��treeNode�����ĵ�һ���ӽ��
		if (root == treeNode->parent) {
			if (treeNode->parent->count == 1)
				root = treeNode->parent->child[0];
			return;
		}
		if (treeNode->parent->count >= min)return;
		for (index = 0; index <= treeNode->parent->parent->count; index++) {
			if (treeNode->parent->parent->child[index] == treeNode->parent)
				break;
		}
		merge(treeNode->parent, index);
	}
	/*������ȱ������ǵݹ�*/
	void dfsTraverse(BalancePlusProTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		stack<BalancePlusProTreeNode<Type>*> stack;
		stack.push(root);
		BalancePlusProTreeNode<Type> *temp;
		string str;
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			cout << "{";
			for (int j = 0; j < temp->count - 1; j++) {
				cout << temp->data[j] << " ";
			}
			cout << temp->data[temp->count - 1] << "}";
			if (temp->level != 1) {
				for (int i = temp->count - 1; i >= 0; i--) {
					stack.push(temp->child[i]);
				}
			}
			cout << endl; // ����
		}
	}
	/*��α�����������ȱ��������ǵݹ�*/
	void levelOrderTraverse(BalancePlusProTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalancePlusProTreeNode<Type>*> queue;//�������У����ڲ�α���
		queue.push(root);
		BalancePlusProTreeNode<Type> *temp = NULL;
		while (!queue.empty()) {
			int size = queue.size();
			for (int i = 0; i < size; ++i) {
				temp = queue.front();
				queue.pop();
				cout << "{";
				for (int j = 0; j < temp->count - 1; j++) {
					cout << temp->data[j] << " ";
				}
				cout << temp->data[temp->count - 1] << "}";
				if (temp->level != 1) {
					for (int j = 0; j < temp->count; j++) {
						queue.push(temp->child[j]);
					}
				}
			}
			cout << endl;//����
		}
	}
public:
	BalancePlusProTree(int m) : root(NULL), m_size(0) {
		this->m = m;
		this->min = (this->m + 1) / 2;
	}
	~BalancePlusProTree() { release(root); }
	void insert(Type data) {
		if (NULL == root) {
			this->root = new BalancePlusProTreeNode<Type>(this->m);
			this->root->data[0] = data;
			this->root->count++;
			this->root->level = 1;
			this->m_size++;
			this->data = this->root; // ���ݱ��㷨��Ƶ�ԭ��ֻ���ڸ�����һ������ʱ������ָ��ָthis->data���һ�����ɵ�root
			return;
		}
		insertNode(root, data);
	}
	BalancePlusProTreeNode<Type> *find(Type data) { return findNode(root, data); }
	void remove(Type data) { removeNode(root, data); }
	void dfs() { dfsTraverse(root); }
	void levelOrder() { levelOrderTraverse(root); }
	void printData() {
		BalancePlusProTreeNode<Type> *node = this->data;
		while (NULL != node) {
			cout << "{";
			for (int j = 0; j < node->count - 1; j++)
				cout << node->data[j] << " ";
			cout << node->data[node->count - 1] << "}";
			node = node->brother;
			if (NULL != node)
				cout << "->";
		}
	}
};
#pragma endregion

#pragma endregion
