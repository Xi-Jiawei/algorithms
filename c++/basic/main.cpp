// CDiplusConsoleApplicationDemo.cpp: 定义控制台应用程序的入口点。
//

#include "classes.h"
#include "strings.h"

#pragma region static：局部静态变量，模块化
int static_test() {
	static int a = 0;
	a++;
	return a;
}
#pragma endregion

#pragma region 引用：作为参数，效果如同指针
void reference_test(int &a,int &b) {
	int temp=a;
	a = b;
	b = temp;
}
#pragma endregion

#pragma region 关键字inline（内联函数）：质数判断
inline char* inline_test(int n)
{
	int i = sqrt(n),flag=0;
	while (i >= 2)
	{
		if (n%i == 0) {
			flag = 1;
			break;
		}
		else
		{
			i--;
		}
	}
	return flag ? "合数" : "质数";
}
#pragma endregion

int main()
{
    #pragma region 构造与析构
	/*//X *x = new X(12,14);//new创建的对象存放在堆区，需手动释放，无法自动析构
	//delete x;//c++中使用delete object释放对象，c中可使用free(object)
	X x=X(12,14);
	X x1 = X(x);//拷贝构造函数，系统自带，也可自定义
	X x2 = x;//实际上也是调用了拷贝构造函数
	X xs[3];
	xs[0] = x;
	xs[1] = x1;
	xs[2] = x2;

	//Y *y = new Y();//new创建的对象存放在堆区，需手动释放，无法自动析构
	//delete y;//c++中使用delete object释放对象，c中可使用free(object)
	Y y;
	y.x = xs;
	*y.p = 2;
	cout << y.x[2].key << " " << y.x[2].value << endl;
	cout << y.value << endl;*/
    #pragma endregion

    #pragma region 继承
	/*Circle *circle = new Circle(2.0);
	circle->calcArea();
	circle->print();
	Rectangle *rectangle= new Rectangle(3.0,4.0);
	rectangle->calcArea();
	rectangle->print();
	Triangle *triangle = new Triangle(3.0, 4.0, 5.0);
	triangle->calcArea();
	//triangle->area;私有方式继承，继承类中成员都会变成私有，所以变量area不可访问
	//triangle->print();*/
    #pragma endregion

    #pragma region 多态
	/*c++中多态以虚函数实现，无论父类中的虚函数与子类虚函数实现是否一样，子类对象调用此函数只会调用子类虚函数，而忽略父类虚函数
	*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;
	people = new Teacher("Einstein");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/
    #pragma endregion

    #pragma region 设计模式
	/*单例模式*/
	/*Tom *tom = Tom::instance();
	Tom *tom1 = Tom::instance();//可以看出，虽然多次获取实例对象，但只构造/析构了一次*/
	/*Tom *tom;
	Tom *tom1 = tom->instance();//静态成员可直接用作用域运算符“::”通过类名访问，也可用类对象访问
	Tom *tom2 = tom->instance();*/

	/*工厂模式*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;
	people = new Teacher("Einstein");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/

	/*原型模式*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	People *people2 = people->clone();//复制people
	people2->name = "Tom";
	People *people3 = new Student("Nancy");
	cout << people->name << " " << people->getLabel() << endl;
	cout << people2->name << " " << people2->getLabel() << endl;
	cout << people3->name << " " << people3->getLabel() << endl;*/

	/*装饰者模式*/
	/*People *people = new Student("Bob");
	people->setLabel();
	//定义UnderGraduate类，用于装饰Student对象
	people = new UnderGraduate(people);
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/

	/*观察者模式*/
	/*Student *student1 = new Student("Bob");
	Student *student2 = new Student("Jerry");
	Teacher *teacher = new Teacher("Einstein");
	teacher->registerListenner(student1);
	teacher->registerListenner(student2);
	teacher->notify("hand in your homework tomorrow, pelease!");*/
    #pragma endregion

    #pragma region 字符串拼接
	/*char str[10] = "hello";
	strcat(str, " world");*/
	/*char *str = "hello";
	str = string_concat(2, str, " world");
	str = string_concat({ str, " world" });
	str = string_format("i am %d years old", 26);*/
    #pragma endregion

    #pragma region 常量
	/*const char *str = "utf8";
	str = "ansi";
	cout << str << endl;

	//除char*外，const修饰的变量都是只读变量，不可直接修改。
	//虽然直接修改常量会得到一个编译错误，但是使用间接指针修改内存，只要符合语法则不会得到任何错误和警告
	const int a = 17;
	//a = 23;//报错“表达式必须是可修改的左值”
	int *p = (int*)&a;//指针可强制转换类型const int*为int*
	*p = 23;
	cout << a << endl;*/
    #pragma endregion

    #pragma region 静态局部变量
	/*一般程序由new产生的动态数据放在堆区；
	函数内部的自动变量放在栈区，自动变量一般会随着函数的退出而释放空间；
	静态数据(即使是函数内部的静态局部变量)都存放在全局数据区，因此它们并不会随着函数的退出而释放空间*/
	/*定义在函数内部的静态变量称为静态局部变量，静态局部变量作用域只在此函数内
	*/
	/*cout << static_test() << endl;
	cout << static_test() << endl;*/
    #pragma endregion

    #pragma region 指针
	/*char *str = "hello world";
	char *ptr = str + 6;
	cout << ptr << endl;
	int a[] = {3,2,5,13,7,9,17,12};
	int *p = a, *p0 = &a[0], *p3 = &a[3];
	cout << (p0 - p) << endl;
	cout << (p3 - p0) << endl;
	int size = end(a) - begin(a);//求数组长度*/
    #pragma endregion

    #pragma region 引用
	/*char *str = "hello world";
	char *&ptr = str;*/
	/*int a = 3, b = 4;
	reference_test(a, b);//引用作为参数修改其值时，相当于引用的变量的值也作了修改，所以使用引用或指针可返回多个值，有效解决函数只返回一个值的问题*/
    #pragma endregion

    #pragma region char*
	/*char *str = "hello world";//指针变量str存储在栈区，但是被创建的字符串"hello world"存储在常量区
	char *str1= "hello world";//调试发现str和str1指向的地址相同，这就证明字符串"hello world"被创建后就存储在常量区
	cout << (str == str1) << endl;

	cout << str << endl;
	cout << *str << endl;//指针指向的地址存放的是字符串的首个字符
	cout << strlen(str) << endl;
	cout << sizeof(*str) << endl;//sizeof(*str)==sizeof(char)
	cout << sizeof(str) << endl;//指针变量大小根据编译器而定，64位编译器上指针变量大小是64位（即8字节），32位指针变量大小是32位（即4字节）

	//char *dst = "hi";//不能作为strcpy、strcat等函数的输出。因为此时指针指向常量区（在java中称为字符串常量池），向常量区进行写入操作会引发“写入异常错误”
	//char dst[4];
	//char *dst=new char[20];
	char *dst = (char*)malloc(sizeof(char) * 20);
	strcpy(dst, "hello");
	strcat(dst, " world");*/

	/*int、string互转*/
	/*char* num_str = "1214";
	int n;
	//string转int
	sscanf(num_str, "%d", &n);
	//int转string
	n = 3276;
	char *str = new char[20];
	sprintf(str, "%d", n);*/

    /*字符串拼接*/
    string str, str1 = "hello ", str2 = "world";
	str = str1 + str2;
	cout << str << endl;
    #pragma endregion

    #pragma region 关键字inline（内联函数）
	//c语言中，如果一些简单函数被频繁调用，不断地有函数入栈，即函数栈，会造成栈空间或栈内存的大量消耗（这也是递归算法效率低的原因）
	//为了解决这个问题，特别的引入了inline修饰符，表示为内联函数
	//使用inline修饰带来的好处我们表面看不出来，其实在内部的工作就是在每个for循环的内部任何调用inline_test(i)的地方都换成了相应的代码块。
	//这样就避免了频繁调用函数对栈内存重复开辟所带来的消耗。
	/*for (int i = 2; i < 100; i++)
		cout << i << ": " << inline_test(i) << endl;*/
    #pragma endregion

    #pragma region 赋值运算顺序
	/*if (NULL)
		cout << "mark" << endl;
	if (0)
		cout << "mark" << endl;
	int a;
	int b= (a = 2);//括号内运行结束后，返回的是a赋值后的值
	if (a = 2)
		cout << "mark" << endl;*/
    #pragma endregion

    #pragma region cin
	/*int n;
	vector<int> a;
	cin >> n;
	a.push_back(n);
	while (cin.get() != '\n') {
		cin >> n;
		a.push_back(n);
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;*/
    #pragma endregion

    #pragma region sizeof
	/*int* arrA = new int[3];
	cout << sizeof(arrA) << endl;//8
	cout << sizeof(arrA[0]) << endl;//4
	int arrB[] = { 1,2,3 };
	cout << sizeof(arrB) << endl;//12
	cout << sizeof(arrB[0]) << endl;//4
	int size = sizeof(arrB) / sizeof(arrB[0]);//求数组长度*/
    #pragma endregion

    #pragma region 整型转字符串（int范围）
    int n, temp, d, i = 0, size = 1;
	cin >> n;
	/*temp = n;
	while (temp /= 10)size++;
	string n_str=string(size,0);
	do {
		d = pow(10, (size - i - 1));
		n_str[i++] = n / d + '0';
	} while (n %= d);
	n_str[i] = 0;*/
	char *n_str = new char[20];
	sprintf(n_str, "%d", n);
	size = strlen(n_str);
    #pragma endregion

    return 0;
}