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
 *名称: 栈
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月20日
 *描述: 实现栈的添加、删除功能
 */
#pragma region 栈（先进后出）
class Stack {
private:
	int *a;//数组
	int maxSize;//栈容量
	int top;//顶栈索引，表示栈实际存储的数量。-1表示没有存入数据，为空栈

public:
	Stack(int maxSize) {
		this->maxSize = maxSize;
		this->a = new int[this->maxSize];
		this->top = -1;//-1表示空栈
	}

	/*入栈*/
	void push(int value) {
		if (this->top == this->maxSize - 1) {
			cout << "stack is full!" << endl;
			return;
		}
		a[++top] = value;
	}

	/*返回顶栈，并移除之*/
	int pop() {
		if (this->top == -1) {
			cout << "stack is empty!" << endl;
			return 0;
		}
		return a[top--];
	}

	/*返回顶栈，但不移除*/
	int peek() {
		if (this->top == -1) {
			cout << "stack is empty!" << endl;
			return 0;
		}
		return a[top];
	}

	/*返回实际存储数量*/
	int size() {
		return this->top + 1;
	}
};
#pragma endregion

/**
 *名称: 顺序循环队列
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月20日
 *描述: 实现顺序循环队列的添加、删除功能
 */
#pragma region 队列（先进先出）
/*顺序循环队列
  说明：以顺序结构存储的队列称为顺序队列，因为一般的顺序队列的队满条件是this->end=this->maxSize，会出现假上溢现象
        为克服假上溢问题，在顺序队列的基础上设计出顺序循环队列（简称为循环队列），即一个首尾相接的环。
        实际中一般使用顺序循环队列
        循环队列队满时元素个数为maxSize-1*/
class RoundQueue {
private:
	long *a;//数组
	int maxSize;//队列容量
	int m_size; //实际存储数量
	int start;//起始索引
	int end;//结束索引

public:
	RoundQueue(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize];
		this->start = 0;
		this->end = 0;//this->start=this->end表示队列为空,this->start=(this->end+1)%this->maxSize表示队列满
		this->m_size = 0;
	}

	/*加入队列*/
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

	/*返回队列头，并移除之*/
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

	/*返回队列头，但不移除*/
	long peek() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[start];
	}

	/*返回实际存储数量*/
	int size() {
		return this->m_size;
	}
};
#pragma endregion

/**
 *名称: 堆
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月21日
 *描述: 实现最大堆、最小堆的添加数据及删除堆顶功能
 */
#pragma region 堆
/*堆的逻辑结构为完全二叉树，存储结构可以是数组：
在完全二叉树中，若当前节点的下标为 i， 则其父节点的下标为 i / 2，其左子节点的下标为 i * 2，其右子节点的下标为i * 2 + 1；*/
class MaxHeap
{
private:
	long *a;//数组
	int maxSize;//队列容量
	int m_size; //实际存储数量
public:
	MaxHeap(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize+1];//元素索引从1开始，a[0]不存元素
		this->m_size = 0;
	}

	void push(int value) {
		this->a[++m_size] = value;
		//adjust();//上浮+下沉
		shift_up();//上浮
	}

	long pop() {
		int top = this->a[1];
		this->a[1] = this->a[this->m_size--];
		shift_down();//下沉
		return top;
	}

	long peek() { return this->a[1]; }

	static void insert(long *a, long value, int &size) {
		a[++size] = value;
	}
	static void adjust(long *a, int size) {
		//上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
		//下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
		for (int i = size / 2; i > 0; i--)
		{
			a[0] = a[i];//暂存父结点
			int childIndex = i * 2;
			while (childIndex <= size)
			{
				if (childIndex < size && a[childIndex] < a[childIndex + 1])
					childIndex++;
				if (a[childIndex] < a[0])break;
				else
				{
					a[childIndex / 2] = a[childIndex];//上浮调整
					childIndex *= 2;//下沉调整
				}
			}
			a[childIndex / 2] = a[0];
		}
	}
	static void shift_up(long *a, int size) {
		int childIndex = size;
		while (childIndex > 1)
		{
			a[0] = a[childIndex / 2];//暂存父结点
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
			a[0] = a[parentIndex];//暂存父结点
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

	/*上浮+下沉*/
	void adjust(){
		//上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
		//下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
		for (int i = this->m_size / 2; i > 0; i--)
		{
			this->a[0] = this->a[i];//暂存父结点
			int childIndex = i * 2;
			while (childIndex <= this->m_size)
			{
				if (childIndex < this->m_size && this->a[childIndex] < this->a[childIndex + 1])
					childIndex++;
				if (this->a[childIndex] < this->a[0])break;
				else
				{
					this->a[childIndex / 2] = this->a[childIndex];//上浮调整
					childIndex *= 2;//下沉调整
				}
			}
			this->a[childIndex / 2] = this->a[0];
		}
	}

	/*上浮*/
	void shift_up() {
		int childIndex = this->m_size;
		while (childIndex > 1)
		{
			this->a[0] = this->a[childIndex / 2];//暂存父结点
			if (this->a[childIndex] < this->a[0])
				break;
			else {
				this->a[childIndex / 2] = this->a[childIndex];
				this->a[childIndex] = this->a[0];
				childIndex /= 2;
			}
		}
	}

	/*下沉*/
	void shift_down() {
		int parentIndex = 1, maxIndex;
		while (parentIndex <= this->m_size / 2)
		{
			this->a[0] = this->a[parentIndex];//暂存父结点
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
	long *a;//数组
	int maxSize;//队列容量
	int m_size; //实际存储数量
public:
	MinHeap(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize + 1];//元素索引从1开始，a[0]不存元素
		this->m_size = 0;
	}

	void push(int value) {
		this->a[++m_size] = value;
		//adjust();//上浮+下沉
		shift_up();//上浮
	}

	long pop() {
		int top = this->a[1];
		this->a[1] = this->a[this->m_size--];
		shift_down();//下沉
		return top;
	}

	long peek() { return this->a[1]; }

	static void insert(long *a, long value, int &size) {
		a[++size] = value;
	}
	static void adjust(long *a, int size) {
		//上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
		//下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
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
					a[childIndex / 2] = a[childIndex];//上浮调整
					childIndex *= 2;//下沉调整
				}
			}
			a[childIndex / 2] = a[0];
		}
	}
	static void shift_up(long *a, int size) {
		int childIndex = size;
		while (childIndex > 1)
		{
			a[0] = a[childIndex / 2];//暂存父结点
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
			a[0] = a[parentIndex];//暂存父结点
			if (parentIndex * 2 < size&&a[parentIndex * 2] > a[parentIndex * 2 + 1])
				minIndex = parentIndex * 2 + 1;
			else minIndex = parentIndex * 2;
			if (a[minIndex] > a[0])break;
			else { // 交换父子结点
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

	/*上浮+下沉（插入时使用）*/
	void adjust() {
		//上浮：从m_size / 2结点开始，先比较左右子结点，将其中较大的数与父结点置换，依次比较，直至根结点；
		//下沉：当左右子结点中有比父结点大的数，那么子结点的子结点可能也会有大于父结点的数，所以再将子结点的子结点与父结点比较
		for (int i = this->m_size / 2; i > 0; i--)
		{
			this->a[0] = this->a[i];//暂存父结点
			int childIndex = i * 2;
			while (childIndex <= this->m_size)
			{
				if (childIndex < this->m_size && this->a[childIndex] > this->a[childIndex + 1])
					childIndex++;
				if (this->a[childIndex] > this->a[0])break;
				else
				{
					this->a[childIndex / 2] = this->a[childIndex];//上浮调整
					childIndex *= 2;//下沉调整
				}
			}
			this->a[childIndex / 2] = this->a[0];
		}
	}

	/*上浮*/
	void shift_up() {
		int childIndex = this->m_size;
		while (childIndex > 1)
		{
			this->a[0] = this->a[childIndex / 2];//暂存父结点
			if (this->a[childIndex] > this->a[0])
				break;
			else {
				this->a[childIndex / 2] = this->a[childIndex];
				this->a[childIndex] = this->a[0];
				childIndex /= 2;
			}
		}
	}

	/*下沉*/
	void shift_down() {
		int parentIndex = 1, minIndex;
		while (parentIndex <= this->m_size / 2)
		{
			this->a[0] = this->a[parentIndex];//暂存父结点
			if (parentIndex * 2 < this->m_size&&this->a[parentIndex * 2] > this->a[parentIndex * 2 + 1])
				minIndex = parentIndex * 2 + 1;
			else minIndex = parentIndex * 2;
			if (this->a[minIndex] > this->a[0])break;
			else { // 交换父子结点
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
 *名称: 优先队列
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现优先队列的添加数据及删除优先值功能
 */
#pragma region 优先队列
/*又称优先级队列，是一种有序队列，按大小排好序的队列，可用数组或堆来实现。
因为上面已经写了堆的实现，下面展示的是用数组实现最大优先队列。
如果用数组实现，按大小顺序依次存储，a[0]是优先级最低的，a[size-1]是优先级最高的*/
class MaxPriorityQueue {
private:
	long *a;//数组
	int maxSize;//队列容量
	int m_size; //实际存储数量

public:
	MaxPriorityQueue(int maxSize) {
		this->maxSize = maxSize;
		this->a = new long[this->maxSize];
		this->m_size = 0;
	}

	/*加入队列*/
	void push(long value) {
		if (this->m_size == this->maxSize) {
			cout << "queue is full!" << endl;
			return;
		}
		if (this->m_size == 0) {
			this->a[this->m_size++] = value; 
			return;
		}
		//从优先级别高的数开始比较，如果被比较数大于插入数，则被比较数往后移一位。也就是说，让最大数保持在最末位置，插入数后不打乱原来顺序
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

	/*返回队列头，并移除之*/
	long pop() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[--m_size];
	}

	/*返回队列头，但不移除*/
	long peek() {
		if (this->m_size == 0) {
			cout << "queue is empty!" << endl;
			return 0;
		}
		return a[m_size - 1];
	}

	/*返回实际存储数量*/
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
 *名称: 单向有序链表
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现单向有序链表的插入、删除及查找功能
 */
#pragma region 链表（单向有序链表）
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
	Node *first=NULL;//起始节点
	int m_size=0;//节点数量

public:
	/*插入*/
	void insert(int value);

	/*移除*/
	void remove(int value);

	/*查找*/
	Node* find(int value);

	/*数量*/
	int size();
};
#pragma endregion

/**
 *名称: 双向有序链表
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月22日
 *描述: 实现双向有序链表的插入、删除及查找功能
 */
#pragma region 链表（双向有序链表）
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
	DoublyNode *first = NULL;//起始节点
	DoublyNode *last = NULL;//终止节点
	int m_size = 0;//节点数量

public:
	/*插入*/
	void insert(int value);

	/*移除*/
	void remove(int value);

	/*查找*/
	DoublyNode* find(int value);

	/*数量*/
	int size();
};
#pragma endregion

/**
 *名称: 普通单向链表
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月23日
 *描述: 实现普通单向链表的添加、删除及查找功能
 */
#pragma region 链表（普通单向链表）
class List {
private:
	Node *first = NULL;//起始节点
	int m_size = 0;//节点数量

public:
	/*插入起始节点*/
	void insertFirst(int value);

	/*删除起始节点*/
	Node* removeFirst();

	/*插入*/
	void insert(int value);

	/*移除*/
	void remove(int value);

	/*查找*/
	Node* find(int value);

	/*反转*/
	void reverse();

	/*反转*/
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

	/*数量*/
	int size();
};
#pragma endregion

/**
 *名称: 普通双向链表
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月23日
 *描述: 实现普通双向链表的添加、删除及查找功能
 */
#pragma region 链表（普通双向链表）
class DoublyList {
private:
	DoublyNode *first = NULL;//起始节点
	DoublyNode *last = NULL;//终止节点
	int m_size = 0;//节点数量

public:
	/*插入起始节点*/
	void insertFirst(int value);

	/*删除起始节点*/
	DoublyNode* removeFirst();

	/*插入终止节点*/
	void insertLast(int value);

	/*删除终止节点*/
	DoublyNode* removeLast();

	/*插入*/
	void insert(int value);

	/*移除*/
	void remove(int value);

	/*查找*/
	DoublyNode* find(int value);

	/*数量*/
	int size();
};
#pragma endregion

/**
 *名称: 普通二叉树
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月24日
 *描述: 实现一棵普通二叉树的构建及遍历
 */
#pragma region 普通二叉树
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
	/*深度优先遍历（从左到右，实际上就是先序遍历），非递归*/
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
			if (temp->rightchild != NULL) { // 因为是从左到右遍历，所以先将右子结点入栈，后将左子结点入栈，出栈时则左子结点先出栈，右子结点后出栈
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
		}
	}
	/*层次遍历，非递归*/
	void levelOrderTraverse(TreeNode<Type> *root) {
		queue<TreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
		}
	}
	/*基于层次遍历算法。将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
	因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
	void writeArray(TreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int m_height = height(root);
		int h = row / 2 + 1;
		if (h == m_height)return;

		/*递归左右子结点*/
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
																   /*打印矩阵*/
		for (int i = 0; i < 2 * m_height - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//换行
		}
	}
};
#pragma endregion

/**
 *名称: 二叉查找树
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月24日
 *描述: 实现二叉查找树的插入、删除及查找功能
 */
#pragma region 二叉查找树（二叉搜索树或二叉排序树）
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
	/*深度优先遍历（从左到右，实际上就是先序遍历），非递归*/
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
			if (temp->rightchild != NULL) { // 因为是从左到右遍历，所以先将右子结点入栈，后将左子结点入栈，出栈时则左子结点先出栈，右子结点后出栈
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
		}
	}
	/*层次遍历，非递归*/
	void levelOrderTraverse(TreeNode<Type> *root) {
		queue<TreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
		}
	}
	/*基于层次遍历算法。将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
	因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
	void writeArray(TreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int m_height = height(root);
		int h = row / 2 + 1;
		if (h == m_height)return;

		/*递归左右子结点*/
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
		/*打印矩阵*/
		for (int i = 0; i < 2 * m_height - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//换行
		}
	}
};
#pragma endregion

/**
 *名称: 平衡二叉树
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月26日
 *描述: 实现平衡二叉树的插入、删除、查找及打印功能
 */
#pragma region 平衡二叉树（AVL）
template <class Type>
struct BalanceBinaryTreeNode {
	Type data;
	int level; // 结点高度，叶子结点的level为1。node->level=max(node->child->level)+1
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
	/*针对LL型，右旋*/
	void rightRotate(BalanceBinaryTreeNode<Type> *&node) {
		/*将左子节点设为新父节点result*/
		BalanceBinaryTreeNode<Type> *result = node->leftchild;

		/*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        #pragma region 先将右子结点暂存，然后替换
		/*BalanceBinaryTreeNode<Type> *temp = result->rightchild;
		result->rightchild = node;
		node->leftchild = temp;*/
        #pragma endregion
        #pragma region 更简便替换方法
		node->leftchild = result->rightchild;
		result->rightchild = node;
        #pragma endregion

		/*更新高度*/
		node->level = max(height(node->leftchild), height(node->rightchild)) + 1;
		result->level = max(height(result->leftchild), height(result->rightchild)) + 1;

		node=result;
	}
	/*针对RR型，左旋*/
	void leftRotate(BalanceBinaryTreeNode<Type> *&node) {
		/*将右子节点设为新父节点result*/
		BalanceBinaryTreeNode<Type> *result = node->rightchild;

		/*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
        #pragma region 先将左子结点暂存，然后替换
		/*BalanceBinaryTreeNode<Type> *temp = result->leftchild;
		result->leftchild = node;
		node->rightchild = temp;*/
        #pragma endregion
        #pragma region 更简便替换方法
		node->rightchild = result->leftchild;
		result->leftchild = node;
        #pragma endregion

		/*更新高度*/
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
		else if (balenceFactor > 1 && parentNode->leftchild->data < data) {/*针对LR型平衡，先左旋，后右旋*/
			leftRotate(parentNode->leftchild);
			rightRotate(parentNode);
		}
		else if (balenceFactor < -1 && parentNode->rightchild->data < data)leftRotate(parentNode);
		else if (balenceFactor < -1 && parentNode->rightchild->data > data) {/*针对RL型平衡，先右旋，后左旋*/
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
	/*深度优先遍历（从左到右，实际上就是先序遍历），非递归*/
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
			if (temp->rightchild != NULL) { // 因为是从左到右遍历，所以先将右子结点入栈，后将左子结点入栈，出栈时则左子结点先出栈，右子结点后出栈
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
		}
	}
	/*层次遍历，非递归*/
	void levelOrderTraverse(BalanceBinaryTreeNode<Type> *root) {
		queue<BalanceBinaryTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
		}
	}
	/*基于层次遍历算法。将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
	因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
	void writeArray(BalanceBinaryTreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		int level = row / 2 + 1;
		if (level == root->level)return;

		/*递归左右子结点*/
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
		/*打印矩阵*/
		for (int i = 0; i < 2 * root->level - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//换行
		}
	}
};
#pragma endregion

/**
 *名称: 红黑树
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年1月27日
 *描述: 实现红黑树的插入、删除、查找及打印功能
 */
#pragma region 红黑树
enum {
	red = true,
	black = false,
};
template <class Type>
struct RedBlackTreeNode {
	Type data;
	bool color;//true表示红，false表示黑
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
		/*将左子节点设为新父节点result*/
		RedBlackTreeNode<Type> *result = node->leftchild;
		result->parent = node->parent;
		if (node == root)
			root = result;
		else {
			if (node == node->parent->leftchild)
				node->parent->leftchild = result;
			else node->parent->rightchild = result;
		}

		/*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
		treeNode->leftchild = result->rightchild;
		if (NULL != result->rightchild)
			result->rightchild->parent = treeNode;
		result->rightchild = treeNode;
		treeNode->parent = result;

		/*换色*/
		/*result->color = node->color;
		node->color = red;*/
		bool color = result->color;
		result->color = treeNode->color;
		treeNode->color = color;

		//node = result;//指向result
	}
	void leftRotate(RedBlackTreeNode<Type> *&node) {
		RedBlackTreeNode<Type> *treeNode = node;
		/*将右子节点设为新父节点result*/
		RedBlackTreeNode<Type> *result = node->rightchild;
		result->parent = node->parent;
		if (node == root)
			root = result;
		else {
			if (node == node->parent->leftchild)
				node->parent->leftchild = result;
			else node->parent->rightchild = result;
		}

		/*将左子节点的右节点指向旧父节点node，并将旧父节点的左子节点指向左子节点的右节点*/
		treeNode->rightchild = result->leftchild;
		if (NULL != result->leftchild)
			result->leftchild->parent = treeNode;
		result->leftchild = treeNode;
		treeNode->parent = result;

		/*换色*/
		/*result->color = node->color;
		node->color = red;*/
		bool color = result->color;
		result->color = treeNode->color;
		treeNode->color = color;

		//node = result;//指向result
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

        #pragma region 左倾红黑树
		/*
		1.如果左子结点为黑，右子结点为红，则左旋；（由2-3树衍变成红黑树的左倾规则）
		2.如果左子结点为红，且左子结点的左子结点也为红，则右旋；（红黑树性质4）
		3.如果左右子结点均为红，则颜色反转*/
		/*if(!isRed(parentNode->leftchild) && isRed(parentNode->rightchild))leftRotate(parentNode);//如果左子结点为黑，右子结点为红，则左旋
		if (isRed(parentNode->leftchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//如果左子结点为红，且左子结点的左子结点也为红，则右旋
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//如果左右子结点均为红，则颜色反转*/
        #pragma endregion
        #pragma region 改进版红黑树（作者：习佳威）
		/*
		1.如果左右子结点均为红，则颜色反转；
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		“case1最后判断，即换色最后进行，防止换色后导致本应旋转的不旋转”？）
		*/
		/*if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4*/
        #pragma endregion
        #pragma region 标准版红黑树
		/*
		1.如果左右子结点均为红，且左子结点的子结点或右子结点的子结点为红，则颜色反转；（红黑树性质4）
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		case1最先进行判断是因为先换色后，可以减少旋转次数。）
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

        #pragma region 左倾红黑树
		/*
		1.如果左子结点为黑，右子结点为红，则左旋；（由2-3树衍变成红黑树的左倾规则）
		2.如果左子结点为红，且左子结点的左子结点也为红，则右旋；（红黑树性质4）
		3.如果左右子结点均为红，则颜色反转*/
		/*if(!isRed(parentNode->leftchild) && isRed(parentNode->rightchild))leftRotate(parentNode);//如果左子结点为黑，右子结点为红，则左旋
		if (isRed(parentNode->leftchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//如果左子结点为红，且左子结点的左子结点也为红，则右旋
		if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//如果左右子结点均为红，则颜色反转*/
        #pragma endregion
        #pragma region 改进版红黑树（作者：习佳威）
		/*
		1.如果左右子结点均为红，则颜色反转；
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		“case1最后判断，即换色最后进行，防止换色后导致本应旋转的不旋转”？）
		*/
		/*if (isRed(parentNode->leftchild) && isRed(parentNode->rightchild))flipColor(parentNode);//case1
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->rightchild))leftRotate(parentNode->leftchild);//case3
		if (isRed(parentNode->leftchild) && !isRed(parentNode->rightchild) && isRed(parentNode->leftchild->leftchild))rightRotate(parentNode);//case2
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->leftchild))rightRotate(parentNode->rightchild);//case5
		if (isRed(parentNode->rightchild) && !isRed(parentNode->leftchild) && isRed(parentNode->rightchild->rightchild))leftRotate(parentNode);//case4*/
        #pragma endregion
        #pragma region 标准版红黑树
		/*
		1.如果左右子结点均为红，且左子结点的子结点或右子结点的子结点为红，则颜色反转；（红黑树性质4）
		2.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的左子结点，则右旋；
		3.如果左子结点为红，右子结点为黑，且新插入结点为左子结点的右子结点，则左子结点左旋；
		4.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的右子结点，则左旋；
		5.如果右子结点为红，左子结点为黑，且新插入结点为右子结点的左子结点，则右子结点右旋；
		（case2、case3为一个组合，case4、case5为一个组合，是镜像对称。
		注意，判断case2、case3时，应先对case3进行判断，然后再对case2进行判断，因为如果满足case3条件，则会对左子结点左旋，变换后会变成case2的情况，这时就可以再对父结点进行右旋。case4、case5也是如此。
		case1最先进行判断是因为先换色后，可以减少旋转次数。）
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
		/*如果要删除结点的左右子结点为空，且颜色为黑，则要进行调整*/
		// 从待删结点为结点的左右子结点考虑，各分5种情况：
		// case1:待删除的结点为左结点，兄弟结点为黑且兄弟结点有且只有一个红色右子结点，则将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的子结点变黑，最后父结点左旋，调整完毕
		// case2:待删除的结点为左结点，兄弟结点为黑且兄弟结点有且只有一个红色左子结点，则将兄弟结点和兄弟结点的子结点的颜色互换，然后兄弟结点右旋，此时转成case1，执行case1的步骤，调整完毕
		// case3:待删除的结点为左结点，兄弟结点为黑且兄弟结点有两个红色的左右子结点，则执行case1相同的步骤，将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的右子结点变黑，最后父结点左旋，调整完毕
		// case4:待删除的结点为左结点，兄弟结点为黑且兄弟结点没有子结点，则将兄弟结点变红，以父结点为起点向上递归，直到遇到红色结点或根结点结束递归，并将其变黑
		// case5:待删除的结点为左结点，兄弟结点为红且兄弟结点有两个黑色的左右子结点，则将兄弟结点变黑，兄弟结点的左子结点变红，然后父结点左旋，调整完毕
		// case1:待删除的结点为右结点，兄弟结点为黑且兄弟结点有且只有一个红色左子结点，则将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的子结点变黑，最后父结点右旋，调整完毕
		// case2:待删除的结点为右结点，兄弟结点为黑且兄弟结点有且只有一个红色右子结点，则将兄弟结点和兄弟结点的子结点的颜色互换，然后兄弟结点左旋，此时转成case1，执行case1的步骤，调整完毕
		// case3:待删除的结点为右结点，兄弟结点为黑且兄弟结点有两个红色的左右子结点，则执行case1相同的步骤，将父结点颜色赋予兄弟结点，然后父结点和兄弟结点的左子结点变黑，最后父结点右旋，调整完毕
		// case4:待删除的结点为右结点，兄弟结点为黑且兄弟结点没有子结点，则将兄弟结点变红，以父结点为起点向上递归，直到遇到红色结点或根结点结束递归，并将其变黑
		// case5:待删除的结点为右结点，兄弟结点为红且兄弟结点有两个黑色的左右子结点，则将兄弟结点变黑，兄弟结点的右子结点变红，然后父结点右旋，调整完毕
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
						rightRotate(treeNode->parent->rightchild);//转成case1
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
						treeNode = treeNode->parent;//向上递归
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
						treeNode = treeNode->parent;//向上递归
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
	/*深度优先遍历（从左到右，实际上就是先序遍历），非递归*/
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
			if (temp->rightchild != NULL) { // 因为是从左到右遍历，所以先将右子结点入栈，后将左子结点入栈，出栈时则左子结点先出栈，右子结点后出栈
				stack.push(temp->rightchild);
			}
			if (temp->leftchild != NULL) {
				stack.push(temp->leftchild);
			}
		}
	}
	/*层次遍历（广度优先遍历），非递归*/
	void levelOrderTraverse(RedBlackTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<RedBlackTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
		}
	}
	/*基于层次遍历算法。将树结点以矩阵形式写入，最后打印矩阵即可形象地将树展示出来。
	因为树的结点位置与其父结点位置相关，所以递归参数时需要传递父结点的位置。*/
	void writeArray(RedBlackTreeNode<Type> *node, string** &array, int row, int col) {
		if (NULL == root)return;
		array[row][col] = to_string(node->data);
		/*char* dataStr = new char[strlen(to_string(node->data).c_str())];
		strcpy(dataStr, to_string(node->data).c_str());
		if (node->color == red)array[row][col] = string_concat({ dataStr, "-r" });
		else array[row][col] = string_concat({ dataStr,"-b" });*/
		int level = row / 2 + 1;
		if (level == m_height)return;

		/*递归左右子结点*/
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
		m_height = height(root);//树高度
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
		/*打印矩阵*/
		for (int i = 0; i < 2 * m_height - 1; i++) {
			for (int j = 0; j < width; j++) {
				cout << array[i][j];
			}
			cout << endl;//换行
		}
	}
};
#pragma endregion

/**
 *名称: B树
 *作者: 习佳威
 *版本: version 1.0
 *日期: 2020年4月7日
 *描述: 实现B树的插入、删除、查找及打印功能
 */
#pragma region 平衡树（英文名Balance Tree，简称B树），是一种多路查找树（多路搜索树或多路排序树），其中2-3树是阶数为3的B树
template <class Type>
struct BalanceTreeNode {
	int count;
	int level; // 结点高度，叶子结点的level为1。node->level=max(node->child->level)+1
	Type *data; // 关键字
	BalanceTreeNode<Type> **child;
	BalanceTreeNode<Type> *parent;
	BalanceTreeNode() :parent(NULL), count(0){}
	BalanceTreeNode(int m) :parent(NULL), count(0){
		data = new Type[m];//m表示b树阶数，关键字最多存储m-1个。定义长度为m的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
		this->child = new BalanceTreeNode*[m+1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
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
		{//如果当前结点是叶子结点，插入到当前结点
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
		{//如果当前结点非叶子结点，插入到当前结点的子结点中
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

        #pragma region 分裂调整
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

			if (root == treeNode) { // 根结点的分裂，需新建新的根结点
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
			else { // 非根结点的分裂，需要调整父结点的data和child
				for (int i = treeNode->parent->count; i >= 0; i--) {
					if (treeNode->parent->child[i] != treeNode) { // 查找当前结点在父结点的子结点集合中的位置
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
	/*删除结点，如不满足最少关键字要求，则合并兄弟结点*/
	void removeNode(BalanceTreeNode<Type> *&treeNode, Type data) {
		if (treeNode->level == 1)
		{
			/*如果当前结点是叶子结点，考虑当前结点关键字数是否大于下限min
			1.如果当前结点关键字数大于下限min，则直接删除
			2.否则，考虑其左右兄弟结点的关键字数是否大于下限min。如果其左右兄弟结点的关键字数不全为下限，则从其中关键字数大于下限的兄弟结点借一个元素；如果其左右兄弟结点的关键字数刚好都为下限，则与其中一个兄弟结点合并，并向上递归*/
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
					// 如果左子结点的键值数大于下限，则将左子结点的最右键值作为后继结点；否则将右子结点的最左键值作为后继结点
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
	/*合并兄弟结点，参数说明：参数treeNode表示当前要合并的结点，参数index表示treeNode在父结点中的位置*/
	void merge(BalanceTreeNode<Type> *treeNode, int index) {
		if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
			// 迁移键值
			for (int i = treeNode->count - 1; i >= 0; i--)
				treeNode->data[i + 1] = treeNode->data[i];
			treeNode->data[0] = treeNode->parent->data[index - 1];
			treeNode->parent->data[index - 1] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];

			// 迁移子结点
			for (int i = treeNode->count; i >= 0; i--)
				treeNode->child[i + 1] = treeNode->child[i];
			treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count];
			if (treeNode->level > 1)treeNode->child[0]->parent = treeNode;

			treeNode->parent->child[index - 1]->count--;
			treeNode->count++;
			return;
		}
		if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
			// 迁移键值
			treeNode->data[treeNode->count] = treeNode->parent->data[index];
			treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[0];
			for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
				treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];

			// 迁移子结点
			treeNode->child[treeNode->count + 1] = treeNode->parent->child[index + 1]->child[0];
			if (treeNode->level > 1)treeNode->child[treeNode->count + 1]->parent = treeNode;
			for (int i = 0; i <= treeNode->parent->child[index + 1]->count; i++)
				treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];

			treeNode->parent->child[index + 1]->count--;
			treeNode->count++;
			return;
		}

		// 如果左右兄弟结点关键字数刚好都为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
		if (index >0) { // 当前结点及父结点对应键值并入左兄弟结点
			treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count] = treeNode->parent->data[index - 1];
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent = treeNode->parent->child[index - 1]; // 这句有点问题，因为treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent和treeNode是同一指针变量，修改这个值会同时改变treeNode
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
		else if (index < treeNode->parent->count) { // 父结点对应键值及右兄弟结点并入当前结点
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

		// 如果treeNode的父结点为根结点且合并后父结点关键字为0，则将根结点指向treeNode父结点的第一个子结点
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
	/*深度优先遍历，非递归*/
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
			cout << endl; // 换行
		}
	}
	/*层次遍历（广度优先遍历），非递归*/
	void levelOrderTraverse(BalanceTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalanceTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
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
*名称: 字典树/前缀树
*作者: 习佳威
*版本: version 1.0
*日期: 2020年8月26日
*描述: 实现平衡二叉树的插入、删除、查找及打印功能
*/
#pragma region 字典树（Trie）
/*字典树，统计单词个数*/
struct TrieNode {
	int count; // 表示以该结点的前缀构成的单词的个数，如果为count=0，表示不存在以该结点的前缀构成的单词
	int prefix; // 表示该结点的前缀长度
	TrieNode *child[26]; // 默认为英文字母型字典树，子结点最多26个（还有数字型字典树，数字以字符表示）
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
	/*删除单词，单词个数置零。返回0表示不存在该单词，删除错误；返回0表示删除正确。*/
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

		// 如果子结点全为空，则释放该结点
		int flag = 1;
		for (int i = 0; i < 26; i++)
			flag &= (NULL == node->child[i]);
		if (flag)release(node);

		return 1;
	}
	/*深度优先遍历*/
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

/*前缀树，统计以某个字符串为前缀的单词个数*/
struct PrefixTrieNode {
	int count; // 表示以该结点前缀为前缀的单词个数
	int prefix; // 表示该结点的前缀长度
	int isword; // 表示该结点前缀是否是单词，0表示该结点前缀不是单词，1表示该结点前缀是单词
	PrefixTrieNode *child[26]; // 默认为英文字母型字典树，子结点最多26个（还有数字型字典树，数字以字符表示）
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
	/*查找最短前缀（POJ 2001 Shortest Prefixes）。注：此方法仅适用于每个字符串只出现一次的情况，不适用于某个字符串出现多次的情况*/
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
	/*删除前缀，释放该前缀对应结点。返回0表示不存在该前缀，删除错误；返回0表示删除正确。*/
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
	/*深度优先遍历*/
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
	/*查找最短前缀（POJ 2001 Shortest Prefixes）。注：此方法仅适用于每个字符串只出现一次的情况，不适用于某个字符串出现多次的情况*/
	char *findDistinct(char *str) { return findDistinctPrefix(root, str); }
	string findDistinct(string str) { return findDistinctPrefix(root, str); }
	void remove(char *str) { removePrefix(root, str); }
	void dfs() { dfsTraverse(root, ""); }
};

/*基于unordered_map（hashmap）实现的字典树，统计单词个数*/
struct HashTrieNode {
	int count; // 表示以该结点的前缀构成的单词的个数，如果为count=0，表示不存在以该结点的前缀构成的单词
	int prefix; // 表示该结点的前缀长度
	unordered_map<char,HashTrieNode*> childmap; // 默认为英文字母型字典树，子结点最多26个（还有数字型字典树，数字以字符表示）
	HashTrieNode *parent;
};
class HashTrie {
private:
	HashTrieNode *root;
	long long m_size; // 字符串数
	long long m_wordcount; // 单词数
	long long m_nodecount; // 结点数
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
	/*删除单词，单词个数置零。返回0表示不存在该单词，删除错误；返回0表示删除正确。*/
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

		// 如果子结点全为空，则释放该结点
		if (node->childmap.empty())release(node);

		return 1;
	}
	/*深度优先遍历*/
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
	/*深度优先遍历，写入文件*/
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
*名称: B+树/B*树
*作者: 习佳威
*版本: version 1.0
*日期: 2020年8月29日
*描述: 实现B+树（标准版本）、B+树（国内版本）、B*树的插入、删除、查找及打印功能
*/
#pragma region B+树，是B树的改版，叶子结点新增指向兄弟结点的指针，而且数据都存储在叶子结点上，枝结点只存储卫星数据（用于查找的关键字）

/**
*名称: B+树（标准版本）
*作者: 习佳威
*版本: version 1.0
*日期: 2020年8月29日
*描述: 参考外网的标准版本，m阶B+树关键字最多存储m-1个，最少存储(m+1)/2-1个，子结点数最多m个，最少m/2个。
	   实现B+树的插入、删除、查找及打印功能
*/
#pragma region B+树（标准版本）
template <class Type>
struct BPlusTreeNode {
	int count; // 关键字个数
	int level; // 结点高度，叶子结点的level为1。node->level=max(node->child->level)+1
	Type *data; // 关键字
	BPlusTreeNode<Type> **child;
	BPlusTreeNode<Type> *parent;
	BPlusTreeNode<Type> *brother;
	BPlusTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BPlusTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m];//m表示b+树阶数，关键字最多存储m-1个。定义长度为m的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
		this->child = new BPlusTreeNode*[m + 1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
	}
};
template <class Type>
class BPlusTree {
private:
	BPlusTreeNode<Type> *root;
	BPlusTreeNode<Type> *data; // 指向第一个叶子结点
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
		{//如果当前结点是叶子结点，插入到当前结点
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
		{//如果当前结点非叶子结点，插入到当前结点的子结点中
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

        #pragma region 分裂调整
		if (treeNode->count == this->m)
		{
			BPlusTreeNode<Type> *brotherNode = new BPlusTreeNode<Type>(this->m - 1), *temp;
			int index = 0, middle = this->m / 2 - 1;
			if (treeNode->level == 1) {
				for (int i = middle + 1; i < treeNode->count; i++)
					brotherNode->data[index++] = treeNode->data[i];

				// 叶子结点新增一个指向兄弟结点的指针
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
					if (treeNode->parent->child[index] != treeNode) { // 查找当前结点在父结点的子结点集合中的位置
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
	/*删除结点，如不满足最少关键字要求，则合并兄弟结点。注：枝结点中可能包含被删除元素的键值，参数level记录包含该元素键值的父结点的level，如果level>1表示父结点包含被删除元素的键值，需要更新该父结点键值；如果level=1表示父结点不包含被删除元素的键值*/
	void removeNode(BPlusTreeNode<Type> *&treeNode, Type data, int level) {
		if (treeNode->level == 1)
		{
			/*如果当前结点是叶子结点，考虑当前结点关键字数是否大于下限min
			1.如果当前结点关键字数大于下限min，则直接删除
			2.否则，考虑其左右兄弟结点的关键字数是否大于下限min。如果其左右兄弟结点的关键字数不全为下限，则从其中关键字数大于下限的兄弟结点借一个元素；如果其左右兄弟结点的关键字数刚好都为下限，则与其中一个兄弟结点合并，并向上递归*/
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

				// 如果被删元素是第1个且当前结点将被删元素删除后剩余元素个数大于零，更新父结点最值；否则不更新父结点最值
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
	/*合并兄弟结点，参数说明：参数treeNode表示当前要合并的结点，参数index表示treeNode在父结点中的位置，参数level由removeNode方法传入，level记录包含被删除元素键值的父结点的level*/
	void merge(BPlusTreeNode<Type> *treeNode, int index, int level){
		if (treeNode->level == 1) {
			if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
				for (int i = treeNode->count - 1; i >= 0; i--)
					treeNode->data[i + 1] = treeNode->data[i];
				treeNode->parent->data[index - 1] = treeNode->data[0] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
				treeNode->parent->child[index - 1]->count--;
				treeNode->count++;

				// 更新父结点最值
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

				// 更新父结点最值
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

			// 如果左右兄弟结点关键字数刚好都为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
			if (index > 0) { // 当前结点并入到左兄弟结点
				for (int i = 0; i < treeNode->count; i++)
					treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->count += treeNode->count;
				for (int i = index; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;

				// 注：此情况不用更新父结点最值。因为3层及3层以上的父结点键值都是最左子结点的最值，而这种情况该结点并入到其左兄弟结点，说明该结点不是最左子结点

				// 更新指向兄弟结点的指针
				treeNode->parent->child[index - 1]->brother = treeNode->brother;
			}
			else if (index < treeNode->parent->count){ // 右兄弟结点并入到当前结点
				int count = treeNode->count;
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
					treeNode->data[treeNode->count + i] = treeNode->parent->child[index + 1]->data[i];
				treeNode->count += treeNode->parent->child[index + 1]->count;
				for (int i = index + 1; i < treeNode->parent->count; i++) {
					treeNode->parent->data[i - 1] = treeNode->parent->data[i];
					treeNode->parent->child[i] = treeNode->parent->child[i + 1];
				}
				treeNode->parent->count--;

				// 更新父结点最值
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

				// 更新指向兄弟结点的指针
				treeNode->brother = treeNode->brother->brother;
			}
		}
		else
		{
			if (index > 0 && treeNode->parent->child[index - 1]->count > min) {
				// 迁移键值
				for (int i = treeNode->count - 1; i >= 0; i--)
					treeNode->data[i + 1] = treeNode->data[i];
				treeNode->data[0] = treeNode->parent->data[index - 1];
				treeNode->parent->data[index - 1] = treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count - 1];
				
				// 迁移子结点
				for (int i = treeNode->count; i >= 0; i--)
					treeNode->child[i + 1] = treeNode->child[i];
				treeNode->child[0] = treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count];
				treeNode->child[0]->parent = treeNode;

				treeNode->parent->child[index - 1]->count--;
				treeNode->count++;
				return;
			}
			if (index < treeNode->parent->count && treeNode->parent->child[index + 1]->count > min) {
				// 迁移键值
				treeNode->data[treeNode->count] = treeNode->parent->data[index];
				treeNode->parent->data[index] = treeNode->parent->child[index + 1]->data[0];
				for (int i = 0; i < treeNode->parent->child[index + 1]->count; i++)
					treeNode->parent->child[index + 1]->data[i] = treeNode->parent->child[index + 1]->data[i + 1];

				// 迁移子结点
				treeNode->child[treeNode->count + 1] = treeNode->parent->child[index + 1]->child[0];
				treeNode->child[treeNode->count + 1]->parent = treeNode;
				for (int i = 0; i <= treeNode->parent->child[index + 1]->count; i++)
					treeNode->parent->child[index + 1]->child[i] = treeNode->parent->child[index + 1]->child[i + 1];

				treeNode->parent->child[index + 1]->count--;
				treeNode->count++;
				return;
			}

			// 如果左右兄弟结点关键字数刚好都为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
			if (index >0) { // 当前结点及父结点对应键值并入左兄弟结点
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count] = treeNode->parent->data[index - 1];
				for (int i = 0; i < treeNode->count; i++) {
					treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->data[i];
					treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i] = treeNode->child[i];
					treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent = treeNode->parent->child[index - 1]; // 这句有点问题，因为treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + 1 + i]->parent和treeNode是同一指针变量，修改这个值会同时改变treeNode
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
			else if (index < treeNode->parent->count) { // 父结点对应键值及右兄弟结点并入当前结点
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

		// 如果treeNode的父结点为根结点且合并后父结点关键字为0，则将根结点指向treeNode父结点的第一个子结点
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
	/*深度优先遍历，非递归*/
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
			cout << endl; // 换行
		}
	}
	/*层次遍历（广度优先遍历），非递归*/
	void levelOrderTraverse(BPlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BPlusTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl; // 换行
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
			this->data = this->root; // 根据本算法设计的原理，只需在根结点第一次生成时将数据指针this->data指向第一次生成的root
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
		cout << endl; // 换行
	}
};
#pragma endregion

/**
*名称: B+树（国内版本）
*作者: 习佳威
*版本: version 2.0
*日期: 2020年8月29日
*描述: 参考国内版本，不同于标准版本，m阶B+树关键字最多存储m个，最少存储(m+1)/2个，子结点数最多m个，最少m/2个。
*/
#pragma region B+树（国内版本）
template <class Type>
struct BalancePlusTreeNode {
	int count;
	int level; // 结点高度，叶子结点的level为1。node->level=max(node->child->level)+1
	Type *data; // 关键字
	BalancePlusTreeNode<Type> **child;
	BalancePlusTreeNode<Type> *parent;
	BalancePlusTreeNode<Type> *brother;
	BalancePlusTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BalancePlusTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m + 1];//m表示b+树阶数，关键字最多存储m个。定义长度为m+1的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
		this->child = new BalancePlusTreeNode*[m + 1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
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
		{//如果当前结点是叶子结点，插入到当前结点
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
		{//如果当前结点非叶子结点，插入到当前结点的子结点中
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

			// 更新父结点最值
			if (treeNode->data[0] > data)
				treeNode->data[0] = data;
		}

        #pragma region 分裂调整
		if (treeNode->count > this->m)
		{
			BalancePlusTreeNode<Type> *brotherNode = new BalancePlusTreeNode<Type>(this->m), *temp;
			int index = 0, middle = this->m / 2;
			if (treeNode->level == 1) {
				for (int i = middle + 1; i < treeNode->count; i++)
					brotherNode->data[index++] = treeNode->data[i];

				// 叶子结点新增一个指向兄弟结点的指针
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
					if (treeNode->parent->child[i] != treeNode) { // 查找当前结点在父结点的子结点集合中的位置
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
	/*删除结点，如不满足最少关键字要求，则合并兄弟结点*/
	void removeNode(BalancePlusTreeNode<Type> *&treeNode, Type data) {
		if (treeNode->level == 1)
		{
			/*如果当前结点是叶子结点，考虑当前结点关键字数是否大于下限min
			1.如果当前结点关键字数大于下限min，则直接删除
			2.否则，考虑其左右兄弟结点的关键字数是否大于下限min。如果其左右兄弟结点的关键字数不全为下限，则从其中关键字数大于下限的兄弟结点借一个元素；如果其左右兄弟结点的关键字数刚好都为下限，则与其中一个兄弟结点合并，并向上递归*/
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

				// 更新父结点最值
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
	/*合并兄弟结点，参数说明：参数treeNode表示当前要合并的结点，参数index表示treeNode在父结点中的位置*/
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

			// 如果当前结点借调元素之前为空，则更新父结点最值
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

		// 如果左右兄弟结点关键字数刚好都为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
		if (index > 0) { // 当前结点并入到左兄弟结点
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i]->parent = treeNode->parent->child[index - 1];
			}
			treeNode->parent->child[index - 1]->count += treeNode->count;
			for (int i = index; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i + 1];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1]; // 如果参数treeNode是引用参数，这句可能有点问题。原因是如果treeNode是引用参数，和treeNode->parent->child[index]是同一指针，修改treeNode->parent->child[index]会同时修改treeNode。解决办法是将参数treeNode改成形式参数
			}
			treeNode->parent->count--;

			// 更新指向兄弟结点的指针
			if (treeNode->level == 1)treeNode->parent->child[index - 1]->brother = treeNode->brother;
		}
		else if (index < treeNode->parent->count - 1) { // 右兄弟结点并入到当前结点
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

			// 如果当前结点合并之前为空，则更新父结点最值
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

			// 更新指向兄弟结点的指针
			if (treeNode->level == 1)treeNode->brother = treeNode->brother->brother;
		}

		// 如果treeNode的父结点为根结点且合并后父结点关键字为0，则将根结点指向treeNode父结点的第一个子结点
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
	/*深度优先遍历，非递归*/
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
			cout << endl; // 换行
		}
	}
	/*层次遍历（广度优先遍历），非递归*/
	void levelOrderTraverse(BalancePlusTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalancePlusTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl; // 换行
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
			this->data = this->root; // 根据本算法设计的原理，只需在根结点第一次生成时将数据指针指this->data向第一次生成的root
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
		cout << endl; // 换行
	}
};
#pragma endregion

/**
*名称: B*树
*作者: 习佳威
*版本: version 1.0
*日期: 2020年8月29日
*描述: B*树是B+树的改版，除叶子结点有指向兄弟结点的指针，枝结点也新增指向兄弟结点的指针，同时，和B+树一样，数据都存储在叶子结点上，枝结点只存储卫星数据（用于查找的关键字）
	   实现B*树的插入、删除、查找及打印功能
*/
#pragma region B*树
template <class Type>
struct BalancePlusProTreeNode {
	int count;
	int level; // 结点高度，叶子结点的level为1。node->level=max(node->child->level)+1
	Type *data; // 关键字
	BalancePlusProTreeNode<Type> **child;
	BalancePlusProTreeNode<Type> *parent;
	BalancePlusProTreeNode<Type> *brother;
	BalancePlusProTreeNode() :parent(NULL), brother(NULL), count(0) {}
	BalancePlusProTreeNode(int m) :parent(NULL), brother(NULL), count(0) {
		data = new Type[m + 1];//m表示b+树阶数，关键字最多存储m个。定义长度为m+1的关键字数组，多出的1个空间是为了在插入结点的关键字满时使用
		this->child = new BalancePlusProTreeNode*[m + 1];//子结点最多m个。定义长度为m+1的子结点数组，多出的1个空间是为了在插入结点的子结点数满时使用
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
		{//如果当前结点是叶子结点，插入到当前结点
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
		{//如果当前结点非叶子结点，插入到当前结点的子结点中
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

			// 更新父结点最值
			if (treeNode->data[0] > data)
				treeNode->data[0] = data;
		}

        #pragma region 分裂调整
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
			// 叶子结点新增一个指向兄弟结点的指针
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
					if (treeNode->parent->child[i] != treeNode) { // 查找当前结点在父结点的子结点集合中的位置
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
	/*删除结点，如不满足最少关键字要求，则合并兄弟结点*/
	void removeNode(BalancePlusProTreeNode<Type> *&treeNode, Type data) {
		if (treeNode->level == 1)
		{
			/*如果当前结点是叶子结点，考虑当前结点关键字数是否大于下限min
			1.如果当前结点关键字数大于下限min，则直接删除
			2.否则，考虑其左右兄弟结点的关键字数是否大于下限min。如果其左右兄弟结点的关键字数不全为下限，则从其中关键字数大于下限的兄弟结点借一个元素；如果其左右兄弟结点的关键字数刚好都为下限，则与其中一个兄弟结点合并，并向上递归*/
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

				// 更新父结点最值
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
	/*合并兄弟结点，参数说明：参数treeNode表示当前要合并的结点，参数index表示treeNode在父结点中的位置*/
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

			// 如果当前结点借调元素之前为空，则更新父结点最值
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

		// 如果左右兄弟结点关键字数刚好都为下限，则将值从当前结点中删除并随机选择一个兄弟结点合并
		if (index > 0) { // 当前结点并入到左兄弟结点
			for (int i = 0; i < treeNode->count; i++) {
				treeNode->parent->child[index - 1]->data[treeNode->parent->child[index - 1]->count + i] = treeNode->data[i];
				treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i] = treeNode->child[i];
				if (treeNode->level > 1)treeNode->parent->child[index - 1]->child[treeNode->parent->child[index - 1]->count + i]->parent = treeNode->parent->child[index - 1];
			}
			treeNode->parent->child[index - 1]->count += treeNode->count;
			for (int i = index; i < treeNode->parent->count; i++) {
				treeNode->parent->data[i] = treeNode->parent->data[i + 1];
				treeNode->parent->child[i] = treeNode->parent->child[i + 1]; // 如果参数treeNode是引用参数，这句可能有点问题。原因是如果treeNode是引用参数，和treeNode->parent->child[index]是同一指针，修改treeNode->parent->child[index]会同时修改treeNode。解决办法是将参数treeNode改成形式参数
			}
			treeNode->parent->count--;

			// 更新指向兄弟结点的指针
			treeNode->parent->child[index - 1]->brother = treeNode->brother;
		}
		else if (index < treeNode->parent->count - 1) { // 右兄弟结点并入到当前结点
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

			// 如果当前结点合并之前为空，则更新父结点最值
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

			// 更新指向兄弟结点的指针
			treeNode->brother = treeNode->brother->brother;
		}

		// 如果treeNode的父结点为根结点且合并后父结点关键字为0，则将根结点指向treeNode父结点的第一个子结点
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
	/*深度优先遍历，非递归*/
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
			cout << endl; // 换行
		}
	}
	/*层次遍历（广度优先遍历），非递归*/
	void levelOrderTraverse(BalancePlusProTreeNode<Type> *root) {
		if (root == NULL) {
			return;
		}
		queue<BalancePlusProTreeNode<Type>*> queue;//辅助队列，用于层次遍历
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
			cout << endl;//换行
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
			this->data = this->root; // 根据本算法设计的原理，只需在根结点第一次生成时将数据指针指this->data向第一次生成的root
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
