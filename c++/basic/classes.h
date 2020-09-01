#pragma once

#ifndef _CLASSES_H
#define _CLASSES_H

#pragma warning(disable:4996)

#include <iostream>
#include <string>
using namespace std;

#include "strings.h"
#pragma region 结构体
typedef struct Packet {
	uint8_t *buf;
	uint32_t size;
	uint32_t type;
};
#pragma endregion

#pragma region 构造与析构
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

#pragma region 继承
//基类
class Shape
{
public:
	double area;

	void print();
};

//继承类：public继承
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

//继承类：public继承
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

//继承类：private继承
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

#pragma region 多态（以及设计模式）
class People {
public:
	char* name;
	char* label = "";

	/*虚函数是指一个类中你希望子类重载的成员函数，当你用一个基类指针或引用指向一个继承类对象的时候，调用一个虚函数时, 实际调用的是继承类的版本
	* 虚函数后面写上=0，则成员函数为纯虚函数。等于0，防止因函数未写具体实现而导致编译报错“无法解析此函数”。
	*/
	//工厂模式：父类统一接口，子类多种实现
	virtual void setLabel()=0;

	//原型模式：复制
	virtual People* clone() = 0;

	//观察者模式：通知/监听
	virtual void notify(char* message) = 0;
	virtual void listen(char* message) = 0;

	char* getLabel() { return this->label; }
};

class Student:public People {
public:
	Student(char* name) { this->name = name; }

	void setLabel() { this->label = "student"; }

	People* clone() { 
		return new Student(*this); //调用拷贝构造函数，深度复制
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

/*装饰者模式*/
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

/*单例模式*/
//方式一：
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
//方式二（推荐）：
class Tom {
public:
	static Tom *instance() {
		/*static Tom *m_instance = new Tom;//new创建的对象存放在堆区，需手动释放，无法自动析构
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