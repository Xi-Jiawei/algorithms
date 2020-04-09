// CDiplusConsoleApplicationDemo.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include "classes.h"
#include "strings.h"

#pragma region static���ֲ���̬������ģ�黯
int static_test() {
	static int a = 0;
	a++;
	return a;
}
#pragma endregion

#pragma region ���ã���Ϊ������Ч����ָͬ��
void reference_test(int &a,int &b) {
	int temp=a;
	a = b;
	b = temp;
}
#pragma endregion

#pragma region �ؼ���inline�������������������ж�
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
	return flag ? "����" : "����";
}
#pragma endregion

int main()
{
    #pragma region ����������
	/*//X *x = new X(12,14);//new�����Ķ������ڶ��������ֶ��ͷţ��޷��Զ�����
	//delete x;//c++��ʹ��delete object�ͷŶ���c�п�ʹ��free(object)
	X x=X(12,14);
	X x1 = X(x);//�������캯����ϵͳ�Դ���Ҳ���Զ���
	X x2 = x;//ʵ����Ҳ�ǵ����˿������캯��
	X xs[3];
	xs[0] = x;
	xs[1] = x1;
	xs[2] = x2;

	//Y *y = new Y();//new�����Ķ������ڶ��������ֶ��ͷţ��޷��Զ�����
	//delete y;//c++��ʹ��delete object�ͷŶ���c�п�ʹ��free(object)
	Y y;
	y.x = xs;
	*y.p = 2;
	cout << y.x[2].key << " " << y.x[2].value << endl;
	cout << y.value << endl;*/
    #pragma endregion

    #pragma region �̳�
	/*Circle *circle = new Circle(2.0);
	circle->calcArea();
	circle->print();
	Rectangle *rectangle= new Rectangle(3.0,4.0);
	rectangle->calcArea();
	rectangle->print();
	Triangle *triangle = new Triangle(3.0, 4.0, 5.0);
	triangle->calcArea();
	//triangle->area;˽�з�ʽ�̳У��̳����г�Ա������˽�У����Ա���area���ɷ���
	//triangle->print();*/
    #pragma endregion

    #pragma region ��̬
	/*c++�ж�̬���麯��ʵ�֣����۸����е��麯���������麯��ʵ���Ƿ�һ�������������ô˺���ֻ����������麯���������Ը����麯��
	*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;
	people = new Teacher("Einstein");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/
    #pragma endregion

    #pragma region ���ģʽ
	/*����ģʽ*/
	/*Tom *tom = Tom::instance();
	Tom *tom1 = Tom::instance();//���Կ�������Ȼ��λ�ȡʵ�����󣬵�ֻ����/������һ��*/
	/*Tom *tom;
	Tom *tom1 = tom->instance();//��̬��Ա��ֱ�����������������::��ͨ���������ʣ�Ҳ������������
	Tom *tom2 = tom->instance();*/

	/*����ģʽ*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;
	people = new Teacher("Einstein");
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/

	/*ԭ��ģʽ*/
	/*People *people;
	people = new Student("Bob");
	people->setLabel();
	People *people2 = people->clone();//����people
	people2->name = "Tom";
	People *people3 = new Student("Nancy");
	cout << people->name << " " << people->getLabel() << endl;
	cout << people2->name << " " << people2->getLabel() << endl;
	cout << people3->name << " " << people3->getLabel() << endl;*/

	/*װ����ģʽ*/
	/*People *people = new Student("Bob");
	people->setLabel();
	//����UnderGraduate�࣬����װ��Student����
	people = new UnderGraduate(people);
	people->setLabel();
	cout << people->name << " " << people->getLabel() << endl;*/

	/*�۲���ģʽ*/
	/*Student *student1 = new Student("Bob");
	Student *student2 = new Student("Jerry");
	Teacher *teacher = new Teacher("Einstein");
	teacher->registerListenner(student1);
	teacher->registerListenner(student2);
	teacher->notify("hand in your homework tomorrow, pelease!");*/
    #pragma endregion

    #pragma region �ַ���ƴ��
	/*char str[10] = "hello";
	strcat(str, " world");*/
	/*char *str = "hello";
	str = string_concat(2, str, " world");
	str = string_concat({ str, " world" });
	str = string_format("i am %d years old", 26);*/
    #pragma endregion

    #pragma region ����
	/*const char *str = "utf8";
	str = "ansi";
	cout << str << endl;

	//��char*�⣬const���εı�������ֻ������������ֱ���޸ġ�
	//��Ȼֱ���޸ĳ�����õ�һ��������󣬵���ʹ�ü��ָ���޸��ڴ棬ֻҪ�����﷨�򲻻�õ��κδ���;���
	const int a = 17;
	//a = 23;//�������ʽ�����ǿ��޸ĵ���ֵ��
	int *p = (int*)&a;//ָ���ǿ��ת������const int*Ϊint*
	*p = 23;
	cout << a << endl;*/
    #pragma endregion

    #pragma region ��̬�ֲ�����
	/*һ�������new�����Ķ�̬���ݷ��ڶ�����
	�����ڲ����Զ���������ջ�����Զ�����һ������ź������˳����ͷſռ䣻
	��̬����(��ʹ�Ǻ����ڲ��ľ�̬�ֲ�����)�������ȫ����������������ǲ��������ź������˳����ͷſռ�*/
	/*�����ں����ڲ��ľ�̬������Ϊ��̬�ֲ���������̬�ֲ�����������ֻ�ڴ˺�����
	*/
	/*cout << static_test() << endl;
	cout << static_test() << endl;*/
    #pragma endregion

    #pragma region ָ��
	/*char *str = "hello world";
	char *ptr = str + 6;
	cout << ptr << endl;
	int a[] = {3,2,5,13,7,9,17,12};
	int *p = a, *p0 = &a[0], *p3 = &a[3];
	cout << (p0 - p) << endl;
	cout << (p3 - p0) << endl;
	int size = end(a) - begin(a);//�����鳤��*/
    #pragma endregion

    #pragma region ����
	/*char *str = "hello world";
	char *&ptr = str;*/
	/*int a = 3, b = 4;
	reference_test(a, b);//������Ϊ�����޸���ֵʱ���൱�����õı�����ֵҲ�����޸ģ�����ʹ�����û�ָ��ɷ��ض��ֵ����Ч�������ֻ����һ��ֵ������*/
    #pragma endregion

    #pragma region char*
	/*char *str = "hello world";//ָ�����str�洢��ջ�������Ǳ��������ַ���"hello world"�洢�ڳ�����
	char *str1= "hello world";//���Է���str��str1ָ��ĵ�ַ��ͬ�����֤���ַ���"hello world"��������ʹ洢�ڳ�����
	cout << (str == str1) << endl;

	cout << str << endl;
	cout << *str << endl;//ָ��ָ��ĵ�ַ��ŵ����ַ������׸��ַ�
	cout << strlen(str) << endl;
	cout << sizeof(*str) << endl;//sizeof(*str)==sizeof(char)
	cout << sizeof(str) << endl;//ָ�������С���ݱ�����������64λ��������ָ�������С��64λ����8�ֽڣ���32λָ�������С��32λ����4�ֽڣ�

	//char *dst = "hi";//������Ϊstrcpy��strcat�Ⱥ������������Ϊ��ʱָ��ָ����������java�г�Ϊ�ַ��������أ�������������д�������������д���쳣����
	//char dst[4];
	//char *dst=new char[20];
	char *dst = (char*)malloc(sizeof(char) * 20);
	strcpy(dst, "hello");
	strcat(dst, " world");*/

	/*int��string��ת*/
	/*char* num_str = "1214";
	int n;
	//stringתint
	sscanf(num_str, "%d", &n);
	//intתstring
	n = 3276;
	char *str = new char[20];
	sprintf(str, "%d", n);*/

    /*�ַ���ƴ��*/
    string str, str1 = "hello ", str2 = "world";
	str = str1 + str2;
	cout << str << endl;
    #pragma endregion

    #pragma region �ؼ���inline������������
	//c�����У����һЩ�򵥺�����Ƶ�����ã����ϵ��к�����ջ��������ջ�������ջ�ռ��ջ�ڴ�Ĵ������ģ���Ҳ�ǵݹ��㷨Ч�ʵ͵�ԭ��
	//Ϊ�˽��������⣬�ر��������inline���η�����ʾΪ��������
	//ʹ��inline���δ����ĺô����Ǳ��濴����������ʵ���ڲ��Ĺ���������ÿ��forѭ�����ڲ��κε���inline_test(i)�ĵط�����������Ӧ�Ĵ���顣
	//�����ͱ�����Ƶ�����ú�����ջ�ڴ��ظ����������������ġ�
	/*for (int i = 2; i < 100; i++)
		cout << i << ": " << inline_test(i) << endl;*/
    #pragma endregion

    #pragma region ��ֵ����˳��
	/*if (NULL)
		cout << "mark" << endl;
	if (0)
		cout << "mark" << endl;
	int a;
	int b= (a = 2);//���������н����󣬷��ص���a��ֵ���ֵ
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
	int size = sizeof(arrB) / sizeof(arrB[0]);//�����鳤��*/
    #pragma endregion

    #pragma region ����ת�ַ�����int��Χ��
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