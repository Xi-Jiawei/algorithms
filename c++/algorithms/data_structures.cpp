#include "data_structures.h"

#pragma region ����������������
void SortedList::insert(int value) {
	Node *newNode = new Node(value);
	Node *previous = NULL;
	Node *current = this->first;
	if (this->m_size == 0)this->first = newNode;
	else
	{
		/*��ͷ��ʼ�Ƚϣ�ǰ��ֵ����С������ֵ�����*/
		while (current->data < value)
		{
			previous = current;
			//���������ĩ�˱��Ƚ�ֵ���Ȳ���ֵС���������ĩ��
			if (current->next == NULL) {
				current->next = newNode;
				break;
			}
			current = current->next;
		}
		//���������ʼ�ڵ�ֵ�ͱȲ���ֵ����������׶�
		if (previous == NULL) {
			/*previous = this->first;
			this->first = *newLink;
			this->first.next = &previous;*/
			newNode->next = this->first;
			this->first = newNode;
		}
		//����������м䣬ǰ���nextָ��newLink��newLink��nextָ�����
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
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		previous = current;
		current = current->next;
	}
	/*ɾ��*/
	if (current == this->first)first = first->next;//�����ʼ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ����ʼ�ڵ㣨û��ָ����ʼ�ڵ��ָ�룩
	else previous->next = current->next;//����Ŀ��ֵ���м䣬ǰ���next������ǰ�ֱ��ָ��ǰ���nextָ��Ľڵ�
	this->m_size--;
}

Node* SortedList::find(int value) {
	Node *current = this->first;
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//��ʾû�е���Ŀ��ֵ�Ľڵ�
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
	Node *current = &this->first;//����
	if (this->m_size == 0)this->first = *newLink;
	else
	{
		//��ͷ��ʼ�Ƚϣ�ǰ��ֵ����С������ֵ�����
		while (current->data < value)
		{
			previous = current;//����
			//���������ĩ�˱��Ƚ�ֵ���Ȳ���ֵС���������ĩ��
			if (current->next == NULL) {
				current->next = newLink;
				break;
			}
			current = current->next;
		}
		//���������ʼ�ڵ�ֵ�ͱȲ���ֵ����������׶�
		if (previous == NULL) {
			//previous = this->first;
			//this->first = *newLink;
			//this->first.next = &previous;
			newLink->next = &this->first;
			this->first = *newLink;
		}
		//����������м䣬ǰ���nextָ��newLink��newLink��nextָ�����
		else if (current != &this->first)
		{
			previous->next = newLink;
			newLink->next = current;
		}
	}
	this->m_size++;
}*/
#pragma endregion

#pragma region ����˫����������
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
		/*��ͷ��ʼ�Ƚϣ�ǰ��ֵ����С������ֵ�����*/
		while (current->data < value)
		{
			previous = current;
			//���������ĩ�˱��Ƚ�ֵ���Ȳ���ֵС���������ĩ��
			if (current->next == NULL) {
				current->next = newNode;
				newNode->previous = current;
				this->last = newNode;
				break;
			}
			current = current->next;
		}
		//���������ʼ�ڵ�ֵ�ͱȲ���ֵ����������׶�
		if (previous == NULL) {
			this->first->previous = newNode;
			newNode->next = this->first;
			this->first = newNode;
		}
		//����������м䣬ǰ���nextָ��newLink��newLink��nextָ�����
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
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		previous = current;
		current = current->next;
	}
	/*ɾ��*/
	if (current == this->first) {//�����ʼ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ����ʼ�ڵ�
		this->first->next->previous = NULL;
		this->first = this->first->next;
	}
	else if (current == this->last) {//���ĩβ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ��ĩβ�ڵ�
		this->last->previous->next = NULL;
		this->last = this->last->previous; 
	}
	else {//����Ŀ��ֵ���м䣬ǰ���next������ǰ�ֱ��ָ��ǰ���nextָ��Ľڵ�
		previous->next = current->next;
		current->next->previous = previous;
	}
	this->m_size--;
}

DoublyNode* DoublySortedList::find(int value) {
	DoublyNode *current = this->first;
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		current = current->next;
	}
	return current;
}

int DoublySortedList::size() {
	return this->m_size;
}
#pragma endregion

#pragma region ������ͨ��������
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
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		previous = current;
		current = current->next;
	}
	/*ɾ��*/
	if (current == this->first)first = first->next;//�����ʼ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ����ʼ�ڵ㣨û��ָ����ʼ�ڵ��ָ�룩
	else previous->next = current->next;//����Ŀ��ֵ���м䣬ǰ���next������ǰ�ֱ��ָ��ǰ���nextָ��Ľڵ�
	this->m_size--;
}

Node* List::find(int value) {
	Node *current = this->first;
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		current = current->next;
	}
	return current;
}

int List::size() {
	return this->m_size;
}
#pragma endregion

#pragma region ������ͨ˫������
void DoublyList::insertFirst(int value) {
	DoublyNode *newNode = new DoublyNode(value);
	if (this->m_size == 0) {
		this->first = newNode;
		this->last = newNode;
		this->m_size++;
		return;
	}
	/*�ؽ�ԭ��ʼ�ڵ������*/
	this->first->previous = newNode;
	/*��ʼ�ڵ�ָ���½ڵ�*/
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
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		previous = current;
		current = current->next;
	}
	/*ɾ��*/
	if (current == this->first) {//�����ʼ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ����ʼ�ڵ�
		this->first->next->previous = NULL;
		this->first = this->first->next;
	}
	else if (current == this->last) {//���ĩβ�ڵ�ֵ�͵���Ŀ��ֵ����ɾ��ĩβ�ڵ�
		this->last->previous->next = NULL;
		this->last = this->last->previous;
	}
	else {//����Ŀ��ֵ���м䣬ǰ���next������ǰ�ֱ��ָ��ǰ���nextָ��Ľڵ�
		previous->next = current->next;
		current->next->previous = previous;
	}
	this->m_size--;
}

DoublyNode* DoublyList::find(int value) {
	DoublyNode *current = this->first;
	/*��ͷ��ʼ�Ƚϣ����������Ŀ��ֵ��һֱ������ȥ*/
	while (current->data != value)
	{
		if (current->next == NULL)return NULL;//��ʾû�е���Ŀ��ֵ�Ľڵ�
		current = current->next;
	}
	return current;
}

int DoublyList::size() {
	return this->m_size;
}
#pragma endregion