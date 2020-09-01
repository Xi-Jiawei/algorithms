#pragma once

#ifndef _CLASSES_H
#define _CLASSES_H

#pragma warning(disable:4996)

#include <iostream>
#include <string>
using namespace std;

#include "strings.h"
#pragma region �ṹ��
typedef struct Packet {
	uint8_t *buf;
	uint32_t size;
	uint32_t type;
};
#pragma endregion

#pragma region ����������
class X
{
public:
	int key;
	int value;

	X() { cout << "constructor x" << endl; }
	X(int key, int value) {
		this->key = key;
		this->value = value;
		cout << "constructor x" << endl;
	}
	~X() { cout << "destructor x" << endl; }
};
class Y
{
public:
	//X x[3];
	X *x;

	int value;
	int *p=&value;

	Y() { cout << "constructor y" << endl; }
	~Y() { cout << "destructor y" << endl; }
};
#pragma endregion

#pragma region �̳�
//����
class Shape
{
public:
	double area;

	void print();
};

//�̳��ࣺpublic�̳�
class Circle :public Shape
{
public:
	Circle(double radius) { this->radius = radius; }

	void calcArea(){
		this->area = 3.14*radius*radius;
	}

private:
	double radius;
};

//�̳��ࣺpublic�̳�
class Rectangle :public Shape
{
public:
	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
	}

	void calcArea(){
		this->area = width*height;
	}

private:
	double width;
	double height;
};

//�̳��ࣺprivate�̳�
class Triangle :Shape
{
public:
	Triangle(double a, double b, double c) { this->a = a; this->b = b; this->c = c; }

	void calcArea(){
		double p = (a + b + c) / 2;
		this->area = sqrt(p*(p - a)*(p - b)*(p - c));
	}

private:
	double a;
	double b;
	double c;
};
#pragma endregion

#pragma region ��̬���Լ����ģʽ��
class People {
public:
	char* name;
	char* label = "";

	/*�麯����ָһ��������ϣ���������صĳ�Ա������������һ������ָ�������ָ��һ���̳�������ʱ�򣬵���һ���麯��ʱ, ʵ�ʵ��õ��Ǽ̳���İ汾
	* �麯������д��=0�����Ա����Ϊ���麯��������0����ֹ����δд����ʵ�ֶ����±��뱨���޷������˺�������
	*/
	//����ģʽ������ͳһ�ӿڣ��������ʵ��
	virtual void setLabel()=0;

	//ԭ��ģʽ������
	virtual People* clone() = 0;

	//�۲���ģʽ��֪ͨ/����
	virtual void notify(char* message) = 0;
	virtual void listen(char* message) = 0;

	char* getLabel() { return this->label; }
};

class Student:public People {
public:
	Student(char* name) { this->name = name; }

	void setLabel() { this->label = "student"; }

	People* clone() { 
		return new Student(*this); //���ÿ������캯������ȸ���
	}

	void registerListenner(People *listener) { listeners.push_back(listener); }
	void unregisterListenner(People *listener) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++) {
			if (*itr == listener)
				listeners.erase(itr);
			if (itr == listeners.end()) break;
		}
	}
	void notify(char* message) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++)
			(*itr)->listen(message);
	};
	void listen(char* message) { cout << this->name << ", " << message << endl; }

private:
	vector<People*> listeners;
};

class Teacher :public People {
public:
	Teacher(char* name) { this->name = name; }

	void setLabel() {
		this->label = "teacher";
	}

	People* clone() { return new Teacher(*this); }

	void registerListenner(People *listener) { listeners.push_back(listener); }
	void unregisterListenner(People *listener) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++) {
			if (*itr == listener)
				listeners.erase(itr);
			if (itr == listeners.end()) break;
		}
	}
	void notify(char* message) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++)
			(*itr)->listen(message);
	};
	void listen(char* message) { cout << this->name << ", " << message << endl; }

private:
	vector<People*> listeners;
};

/*װ����ģʽ*/
class UnderGraduate :public People {
public:
	UnderGraduate(People* people) {
		this->name = people->name;
		this->label = people->label;
	}

	void setLabel() {
		this->label = string_concat({ this->label, ", undergraduate" });
	}

	People* clone() { return new UnderGraduate(*this); }

	void registerListenner(People *listener) { listeners.push_back(listener); }
	void unregisterListenner(People *listener) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++) {
			if (*itr == listener)
				listeners.erase(itr);
			if (itr == listeners.end()) break;
		}
	}
	void notify(char* message) {
		vector<People*>::iterator itr;
		for (itr = listeners.begin(); itr != listeners.end(); itr++)
			(*itr)->listen(message);
	};
	void listen(char* message) { cout << this->name << ", " << message << endl; }

private:
	vector<People*> listeners;
};

/*����ģʽ*/
//��ʽһ��
/*class Tom {
public:
	static Tom *instance() {
		if (m_instance == NULL) m_instance = new Tom();
		return m_instance;
	}

private:
	char* label;
	static Tom *m_instance;

	Tom() { cout << "constructor" << endl; }
	~Tom() { cout << "destructor" << endl; }
};*/
//��ʽ�����Ƽ�����
class Tom {
public:
	static Tom *instance() {
		/*static Tom *m_instance = new Tom;//new�����Ķ������ڶ��������ֶ��ͷţ��޷��Զ�����
		return m_instance;*/

		static Tom m_instance;
		return &m_instance;
	}

private:
	char* label;

	Tom() { cout << "constructor tom" << endl; }
	~Tom() { cout << "destructor tom" << endl; }
};

#pragma endregion

#endif