#include "data_structures.h"

#pragma region 链表（单向有序链表）
void SortedList::insert(int value) {
	Node *newNode = new Node(value);
	Node *previous = NULL;
	Node *current = this->first;
	if (this->m_size == 0)this->first = newNode;
	else
	{
		/*从头开始比较，前项值比其小，后项值比其大*/
		while (current->data < value)
		{
			previous = current;
			//如果到链表末端被比较值还比插入值小，则将其插入末端
			if (current->next == NULL) {
				current->next = newNode;
				break;
			}
			current = current->next;
		}
		//如果链表起始节点值就比插入值大，则将其插入首端
		if (previous == NULL) {
			/*previous = this->first;
			this->first = *newLink;
			this->first.next = &previous;*/
			newNode->next = this->first;
			this->first = newNode;
		}
		//否则将其插入中间，前项的next指向newLink，newLink的next指向后项
		else if(current!=this->first && current->data > value)
		{
			previous->next = newNode;
			newNode->next = current;
		}
	}
	this->m_size++;
}

void SortedList::remove(int value) {
	Node *previous = this->first;
	Node *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//表示没有等于目标值的节点
		previous = current;
		current = current->next;
	}
	/*删除*/
	if (current == this->first)first = first->next;//如果起始节点值就等于目标值，则删除起始节点（没有指向起始节点的指针）
	else previous->next = current->next;//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
	this->m_size--;
}

Node* SortedList::find(int value) {
	Node *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//表示没有等于目标值的节点
		current = current->next;
	}
	return current;
}

int SortedList::size() {
	return this->m_size;
}

/*
void SortedList::insert(int value) {
	Node *newLink = new Node(value);
	Node *previous = NULL;
	Node *current = &this->first;//引用
	if (this->m_size == 0)this->first = *newLink;
	else
	{
		//从头开始比较，前项值比其小，后项值比其大
		while (current->data < value)
		{
			previous = current;//拷贝
			//如果到链表末端被比较值还比插入值小，则将其插入末端
			if (current->next == NULL) {
				current->next = newLink;
				break;
			}
			current = current->next;
		}
		//如果链表起始节点值就比插入值大，则将其插入首端
		if (previous == NULL) {
			//previous = this->first;
			//this->first = *newLink;
			//this->first.next = &previous;
			newLink->next = &this->first;
			this->first = *newLink;
		}
		//否则将其插入中间，前项的next指向newLink，newLink的next指向后项
		else if (current != &this->first)
		{
			previous->next = newLink;
			newLink->next = current;
		}
	}
	this->m_size++;
}*/
#pragma endregion

#pragma region 链表（双向有序链表）
void DoublySortedList::insert(int value){
	DoublyNode *newNode = new DoublyNode(value);
	DoublyNode *previous = NULL;
	DoublyNode *current = this->first;
	if (this->m_size == 0) { 
		this->first = newNode; 
		this->last = newNode;
	}
	else
	{
		/*从头开始比较，前项值比其小，后项值比其大*/
		while (current->data < value)
		{
			previous = current;
			//如果到链表末端被比较值还比插入值小，则将其插入末端
			if (current->next == NULL) {
				current->next = newNode;
				newNode->previous = current;
				this->last = newNode;
				break;
			}
			current = current->next;
		}
		//如果链表起始节点值就比插入值大，则将其插入首端
		if (previous == NULL) {
			this->first->previous = newNode;
			newNode->next = this->first;
			this->first = newNode;
		}
		//否则将其插入中间，前项的next指向newLink，newLink的next指向后项
		else if (current != this->first && current->data > value)
		{
			previous->next = newNode;
			newNode->previous = previous;
			newNode->next = current;
			current->previous = newNode;
		}
	}
	this->m_size++;
}

void DoublySortedList::remove(int value) {
	DoublyNode *previous = this->first;
	DoublyNode *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//表示没有等于目标值的节点
		previous = current;
		current = current->next;
	}
	/*删除*/
	if (current == this->first) {//如果起始节点值就等于目标值，则删除起始节点
		this->first->next->previous = NULL;
		this->first = this->first->next;
	}
	else if (current == this->last) {//如果末尾节点值就等于目标值，则删除末尾节点
		this->last->previous->next = NULL;
		this->last = this->last->previous; 
	}
	else {//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
		previous->next = current->next;
		current->next->previous = previous;
	}
	this->m_size--;
}

DoublyNode* DoublySortedList::find(int value) {
	DoublyNode *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//表示没有等于目标值的节点
		current = current->next;
	}
	return current;
}

int DoublySortedList::size() {
	return this->m_size;
}
#pragma endregion

#pragma region 链表（普通单向链表）
void List::insertFirst(int value) {
	Node *newNode = new Node(value);
	this->first->next = this->first;//*this->first.next = this->first;
	this->first = newNode;
	this->m_size++;
}

Node* List::removeFirst() {
	Node *t = this->first;
	this->first = this->first->next;
	this->m_size--;
	return t;
}

void List::insert(int value) {
	Node *newNode = new Node(value);
	Node *previous = NULL;
	Node *current = this->first;
	if (this->m_size == 0)this->first = newNode;
	else
	{
		while (current->next != NULL)current = current->next;
		current->next = newNode;
	}
	this->m_size++;
}

void List::remove(int value) {
	Node *previous = this->first;
	Node *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//表示没有等于目标值的节点
		previous = current;
		current = current->next;
	}
	/*删除*/
	if (current == this->first)first = first->next;//如果起始节点值就等于目标值，则删除起始节点（没有指向起始节点的指针）
	else previous->next = current->next;//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
	this->m_size--;
}

Node* List::find(int value) {
	Node *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//表示没有等于目标值的节点
		current = current->next;
	}
	return current;
}

int List::size() {
	return this->m_size;
}
#pragma endregion

#pragma region 链表（普通双向链表）
void DoublyList::insertFirst(int value) {
	DoublyNode *newNode = new DoublyNode(value);
	if (this->m_size == 0) {
		this->first = newNode;
		this->last = newNode;
		this->m_size++;
		return;
	}
	/*重建原起始节点的连接*/
	this->first->previous = newNode;
	/*起始节点指向新节点*/
	newNode->next = this->first;
	this->first = newNode;
	this->m_size++;
}

DoublyNode* DoublyList::removeFirst() {
	DoublyNode* t = this->first;
	this->first = this->first->next;
	this->first->previous = NULL;
	this->m_size--;
	return t;
}

void DoublyList::insertLast(int value) {
	DoublyNode *newNode = new DoublyNode(value);
	this->last->next = newNode;
	newNode->previous = this->last;
	this->last = newNode;
	this->m_size++;
}

DoublyNode* DoublyList::removeLast() {
	DoublyNode* t = this->last;
	this->last = this->last->previous;
	this->last->next = NULL;
	this->m_size--;
	return t;
}

void DoublyList::insert(int value) {
	DoublyNode *newNode = new DoublyNode(value);
	DoublyNode *previous = NULL;
	DoublyNode *current = this->first;
	if (this->m_size == 0) {
		this->first = newNode;
		this->last = newNode;
	}
	else
	{
		while (current->next != NULL)current = current->next;

		current->next = newNode;
		newNode->previous = current;
		this->last = newNode;
	}
	this->m_size++;
}

void DoublyList::remove(int value) {
	DoublyNode *previous = this->first;
	DoublyNode *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//表示没有等于目标值的节点
		previous = current;
		current = current->next;
	}
	/*删除*/
	if (current == this->first) {//如果起始节点值就等于目标值，则删除起始节点
		this->first->next->previous = NULL;
		this->first = this->first->next;
	}
	else if (current == this->last) {//如果末尾节点值就等于目标值，则删除末尾节点
		this->last->previous->next = NULL;
		this->last = this->last->previous;
	}
	else {//否则目标值在中间，前项的next跳过当前项，直接指向当前项的next指向的节点
		previous->next = current->next;
		current->next->previous = previous;
	}
	this->m_size--;
}

DoublyNode* DoublyList::find(int value) {
	DoublyNode *current = this->first;
	/*从头开始比较，如果不等于目标值，一直链接下去*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//表示没有等于目标值的节点
		current = current->next;
	}
	return current;
}

int DoublyList::size() {
	return this->m_size;
}
#pragma endregion