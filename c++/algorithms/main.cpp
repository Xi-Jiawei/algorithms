// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)

#include <iostream>

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <windows.h>
#include <psapi.h>

#include "sort.h"
#include "algorithms.h"
#include "data_structures.h"

void stl_test();
void stack_test();
void queue_test();
void heap_test();
void node_test();
void list_test();
void tree_test();

using namespace std;

int main()
{
	//std::cout << "Hello World!\n";

	//stl_test();
	//stack_test();
	//queue_test();
	//heap_test();
	//node_test();
	//list_test();
	tree_test();

	#pragma region 归并排序
	/*int data[] = { 13,3,34,23,23,19,22,18,2,9,13,19,6 };
	const int length = sizeof(data)/sizeof(int);
	int result[length];
	cout << "Before sorted:" << endl;
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;
	cout << "After sorted:" << endl;
	merge_sort(data, 0, length - 1, result);
	for (int i = 0; i < length; ++i)
		cout << result[i] << "  ";
	cout << endl;*/

	/*cout << "请输入一组整数:" << endl;
	int length = 0, temp[300];
	while (cin >> temp[length++])
		if (cin.get() == '\n')
			break;
	int *data = new int[length];
	for (int i = 0; i < length; i++) data[i] = temp[i];
	int *result = new int[length];

	cout << "After sorted:" << endl;
	merge_sort(data, 0, length - 1, result);
	for (int i = 0; i < length; ++i)
		cout << result[i] << "  ";
	cout << endl;*/
	#pragma endregion

	#pragma region 快速排序
	/*cout << "请输入一组整数:" << endl;
	int length = 0, temp[300];
	while (cin >> temp[length++])
		if (cin.get() == '\n')
			break;
	int *data = new int[length];
	for (int i = 0; i < length; i++) data[i] = temp[i];*/
	/*int length = 9;
	int *data = new int[length] {3, 1, 2, 5, 13, 7, 9, 17, 12};*/
	/*int length = 9;
	int *data = new int[length] {1, 5, 2, 3, 6, 8, 8, 7, 4};

	printf("before sort: ");
	for (int k = 0; k < length; k++)
		printf("%d, ", data[k]);
	printf("\n");

	quick_sort(data, 0, length - 1);
	cout << "after sort: ";
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;*/
	#pragma endregion

    #pragma region 二分查找
	/*//int n = 5, v = 4, a[5]{ 1, 2, 4, 4, 5 }, idx;
	//int n = 5, v = 3, a[5]{ 1, 2, 4, 4, 5 }, idx;
	//int n = 6, v = 4, a[6]{ 1, 4, 4, 5, 5, 6 }, idx;
	//int n = 6, v = 3, a[6]{ 1, 4, 4, 5, 5, 6 }, idx;
	//int n = 6, v = 5, a[6]{ 1, 4, 4, 5, 5, 6 }, idx;
	//int n = 10, v = 7, a[10]{ 1,2,3,4,5,6,7,7,7,7 }, idx;
	//int n = 10, v = 2, a[10]{ 1,1,2,3,7,7,7,9,9,10 }, idx;
	//int n = 10, v = 5, a[10]{ 1,1,2,3,7,7,7,9,9,10 }, idx;
	//int n = 10, v = 7, a[10]{ 1,1,2,3,7,7,7,9,9,10 }, idx;
	//int n = 10, v = 7, a[10]{ 1,1,2,3,7,7,7,7,9,10 }, idx;
	//int n = 10, v = 7, a[10]{ 1,1,2,3,7,7,7,7,7,10 }, idx;
	int n = 11, v = 7, a[11]{ 1,1,2,3,7,7,7,7,7,9,10 }, idx;
	//int n = 11, v = 7, a[11]{ 1,1,2,3,7,7,7,7,7,7,10 }, idx;
	//idx = binary_search(v, a, n);
	idx = binary_search2(v, a, n);
	//idx = binary_search3(v, a, n);
	idx = lower_bound(v, a, n);
	idx = upper_bound(v, a, n);*/
    #pragma endregion

    #pragma region 最长不重复子串长度（未完成）
	/*int result=length_of_longest_substring("adasdfasdf");
	cout << result << endl;*/
    #pragma endregion
	
    #pragma region 模式匹配
	//pattern_matching();
    #pragma endregion

    #pragma region 删除字符串中的"ab"字符
	//delete_string();
    #pragma endregion

    #pragma region 大数的加法和乘法（a, b可能超integer和long的取值范围）
	//bignumber();
    #pragma endregion

    #pragma region top k problem
	//search_top_k();
    #pragma endregion

    #pragma region 递归数组
	//fibonacci_seq();
    #pragma endregion

    #pragma region 质因数分解
	//prime_factorization();
    #pragma endregion

    #pragma region 最大公约数
	//greatest_common_factor();
    #pragma endregion

    #pragma region 最小公倍数
	//lowest_common_multiple();
    #pragma endregion

    #pragma region 字符统计
	//char_count();
    #pragma endregion

    #pragma region 阶乘求和
	//factorial_sum();
    #pragma endregion

    #pragma region 整数位数统计
	//digit_count();
    #pragma endregion

    #pragma region 回文数
	//palindrome_number();
    #pragma endregion

    #pragma region 腾讯笔试

    #pragma region 自实现strcpy
	/*char* str=new char[10];
	strcpy(str, NULL);
	cout << "strSrc == NULL: " << str << endl;
	strcpy(NULL, "hello");
	cout << "strDest == NULL: " << str << endl;
	strcpy(NULL, NULL);
	cout << "strDest == NULL && strSrc == NULL: " << str << endl;

	int n;
	string strSrc;
	char* strDest;
	cout << "输入测试次数: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "输入strSrc: ";
		cin >> strSrc;
		strDest = new char[strSrc.length()];
		strcpy(strDest, strSrc.c_str());
		cout << strDest << endl;
	}*/
    #pragma endregion

    #pragma region 查找点e附近距离最近的k个点
	/*vector<Coord> vec, vec_k;
	Coord cs[5], e;
	for (int i = 0; i < 10; i++) {
		cs[i].x = rand() % 100;
		cs[i].y = rand() % 100;
		vec.push_back(cs[i]);
	}
	e.x = 12; e.y = 14;
	vec_k = GetNearestCoord(vec, e, 3);
	for (int i = 0; i < vec_k.size(); i++)
		cout << vec_k[i].x << " " << vec_k[i].y << endl;*/

	/*int n, m, x, y, k;
	cout << "输入测试次数: ";
	cin >> n;
	vector<Coord> vec, vec_k;
	Coord cs[5], e;
	for (int j = 0; j < n; j++) {
		cout << "输入坐标点数组大小: ";
		cin >> m;
		cout << "输入坐标点数组: " << endl;
		for (int i = 0; i < m; i++) {
			cin >> x;
			cin >> y;
			cs[i].x = x;
			cs[i].y = y;
			vec.push_back(cs[i]);
		}
		cout << "输入目标点坐标: ";
		cin >> x;
		cin >> y;
		e.x = x; e.y = y;
		cout << "输入点数k: ";
		cin >> k;
		vec_k = GetNearestCoord(vec, e, 3);
		for (int i = 0; i < vec_k.size(); i++)
			cout << vec_k[i].x << " " << vec_k[i].y << endl;
	}*/
    #pragma endregion

    #pragma region 查找单链表倒数第k个结点
	/*ListNode list=ListNode(); list.m_nkey = 6;
	ListNode node1 = ListNode(), node2 = ListNode(), node3 = ListNode(), node4 = ListNode(), node5 = ListNode();
	node1.m_nkey = 7; node2.m_nkey = 5; node3.m_nkey = 2; node4.m_nkey = 3; node5.m_nkey = 9;
	list.m_pNext = &node1; node1.m_pNext = &node2; node2.m_pNext = &node3; node3.m_pNext = &node4; node4.m_pNext = &node5;
	ListNode *node;
	node = GetLastNodes(&list, 3);
	cout << node->m_nkey << endl;
	node = GetLastNodes(&list, 6);
	cout << node->m_nkey << endl;
	node = GetLastNodes(&list, 7);*/

	/*int n, k, value;
	cout << "输入测试次数: ";
	cin >> n;
	ListNode *list= new ListNode(), *current, *temp, *node;
	for (int j = 0; j < n; j++) {
		cout << "输入链表节点: ";
		current = list;
		cin >> value;
		current->m_nkey = value;
		while (cin.get() != '\n') {
			cin >> value;
			temp = new ListNode();
			temp->m_nkey = value;
			current->m_pNext = temp;
			current = current->m_pNext;
		}
		cout << "输入k: ";
		cin >> k;
		node = GetLastNodes(list, k);
		cout << node->m_nkey << endl;
	}*/
    #pragma endregion

    #pragma region 找出所有重复数大于阈值的数
	/*int arrAsize = 20, cnt = 3;
	int* arrA=new int[arrAsize];
	for (int i = 0; i < arrAsize; i++) {
		arrA[i] = rand() % 5;
		cout << arrA[i] << " ";
	}
	cout << endl;
	vector<int> vec = StatTimes(arrA, arrAsize, cnt);
	for (int i = 0; i < vec.size(); i++)cout << vec[i] << " ";*/

    /*int n, *arrA, arrAsize, cnt, num;
	cout << "输入测试次数: ";
	cin >> n;
	for (int j = 0; j < n; j++) {
		cout << "输入数组大小: ";
		cin >> arrAsize;
		if (arrAsize > 0) {
			arrA = new int[arrAsize];
			cout << "输入数组: ";
			for (int i = 0; i < arrAsize; i++) {
				cin >> num;
				arrA[i] = num;
			}
			cout << "输入cnt: ";
			cin >> cnt;
			vector<int> vec = StatTimes(arrA, arrAsize, cnt);
			for (int i = 0; i < vec.size(); i++)
				cout << vec[i] << " ";
			cout << endl;
		}
	}*/
    #pragma endregion

    #pragma region 文件读及hash_map的查找
    /*Staff staff("D:\\Users\\veev\\BigData\\staff.txt");
	pair<int, int> memberInfo;
	memberInfo = staff.getMemberInfo("chris");
	cout << memberInfo.first << " " << memberInfo.second << endl;
	memberInfo = staff.getMemberInfo("tom");
	cout << memberInfo.first << " " << memberInfo.second << endl;
	vector<string> members;
	members = staff.getMembersOfDepart(10);
	for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;
	members = staff.getMembersOfDepart(13);
	for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;
	members = staff.getMembersOfCenter(103);
	for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;
	members = staff.getMembersOfCenter(104);
	for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;*/

	/*int n, depart_id, center_id;
	string name;
	Staff staff("D:\\Users\\veev\\BigData\\staff.txt");
	pair<int, int> memberInfo;
	vector<string> members;
	cout << "输入测试次数: ";
	cin >> n;
	for (int j = 0; j < n; j++) {
		cout << "输入员工英文名称: ";
		cin >> name;
		memberInfo = staff.getMemberInfo(name);
		cout << "员工" << name << "所在的部门ID和中心ID: ";
		cout << memberInfo.first << " " << memberInfo.second << endl;
		cout << "输入部门ID: ";
		cin >> depart_id;
		members = staff.getMembersOfDepart(depart_id);
		cout << "部门" << depart_id << "下的所有员工: " << endl;
		for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;
		cout << "输入中心ID: ";
		cin >> center_id;
		members = staff.getMembersOfCenter(center_id);
		cout << "中心" << center_id << "下的所有员工: " << endl;
		for (int i = 0; i < members.size(); i++)cout << members[i].data() << endl;
	}*/
    #pragma endregion

    #pragma endregion

    #pragma region 统计x的二进制数中1的个数
    /*int x = 9999, count;
	count = count1ofx(x);
	cout << count << endl;*/
    #pragma endregion

    #pragma region 图的深度优先遍历
	/*int n = 5;
	int **a = new int*[n], *b=new int[n]{ 0 };
	for (int i = 0; i < n; i++) {
		a[i] = new int[n] { 0 };
		for (int j = 0; j < n; j++)
			a[i][j] = i == j ? 0 : 10 * i + j;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	b[0] = 1;
	dfs(a, b, n, 0);//起始点idx=0*/
    #pragma endregion

    #pragma region 图的广度优先遍历（未完成）
    #pragma endregion

    #pragma region 最短路径（有向带权图）
    /*int n, t;
	cin >> n;
	int **a = new int*[n], **d = new int*[n], **p = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		d[i] = new int[n];
		p[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> t;
			a[i][j] = t;
		}
	}
	floyd(a, 4, d, p);*/
    //int a[4][4]{ { 0,2,6,4 },{ 999,0,3,999 },{ 7,999,0,1 },{ 5,999,12,0 } }, d[4][4], p[4][4];
	/*int **a = new int*[4], **d = new int*[4], **p = new int*[4];
	a[0] = new int[4]{ 0,2,6,4 };
	a[1] = new int[4]{ 999, 0, 3, 999 };
	a[2] = new int[4]{ 7, 999, 0, 1 };
	a[3] = new int[4]{ 5, 999, 12, 0 };
	for (int i = 0; i < 4; i++) {
		d[i] = new int[4];
		p[i] = new int[4];
	}
	floyd(a, 4, d, p);*/

    /*
	      0
		 /  \
		1    \
		\     \
		 \      3
		  \     /
		   \   /
			  /
			 2
	*/
	/*int **a = new int*[4], *d = new int[4], *p = new int[4], *v = new int[4];
	a[0] = new int[4]{ 0, 999, 999, 999 };
	a[1] = new int[4]{ 1, 0, 999, 999 };
	a[2] = new int[4]{ 7, 4, 0, 3 };
	a[3] = new int[4]{ 3, 999, 999, 0 };
	dijkstra(a, 4, 2, d, p, v);*/
	/*int **a = new int*[6], *d = new int[6], *p = new int[6], *v = new int[6];
	a[0] = new int[6]{ 0, 999, 10, 999, 30, 100 };
	a[1] = new int[6]{ 999, 0, 5, 999, 999, 999 };
	a[2] = new int[6]{ 999, 999, 0, 50, 999, 999 };
	a[3] = new int[6]{ 999, 999, 999, 0, 999, 10 };
	a[4] = new int[6]{ 999, 999, 999, 20, 0, 60 };
	a[5] = new int[6]{ 999, 999, 999, 999, 999, 0 };
	dijkstra(a, 6, 0, d, p, v);*/
    #pragma endregion

    #pragma region 最短哈密尔顿回路（旅行商问题，无向带权图）
    //int **a = new int*[6]; // a[][]表示城市0~城市n的无向带权图的邻接矩阵
	/*// 无回路
	a[0] = new int[6]{ 0,   999, 10,  999, 30,  100 };
	a[1] = new int[6]{ 999, 0,   5,   999, 999, 999 };
	a[2] = new int[6]{ 10,  5,   0,   50,  999, 999 };
	a[3] = new int[6]{ 999, 999, 50,  0,   20,  10 };
	a[4] = new int[6]{ 30,  999, 999, 20,  0,   60 };
	a[5] = new int[6]{ 100, 999, 999, 10,  60,  0 };*/
	/*a[0] = new int[6]{ 0,   40, 10,  999, 30,  100 };
	a[1] = new int[6]{ 40, 0,   5,   999, 999, 999 };
	a[2] = new int[6]{ 10,  5,   0,   50,  999, 999 };
	a[3] = new int[6]{ 999, 999, 50,  0,   20,  10 };
	a[4] = new int[6]{ 30,  999, 999, 20,  0,   60 };
	a[5] = new int[6]{ 100, 999, 999, 10,  60,  0 };
	tsp(a, 5);*/
	/*int **a = new int*[5];
	a[0] = new int[5] { 0, 3, 999, 8, 9 };
	a[1] = new int[5] { 3, 0, 3, 10, 5 };
	a[2] = new int[5] { 999, 3, 0, 4, 3 };
	a[3] = new int[5] { 8, 10, 4, 0, 20 };
	a[4] = new int[5] { 9, 5, 3, 20, 0};
	tsp(a, 4);*/
	/*int **a = new int*[4];
	a[0] = new int[4]{ 0, 2, 6, 5 };
	a[1] = new int[4]{ 2, 0, 4, 4 };
	a[2] = new int[4]{ 6, 4, 0, 2 };
	a[3] = new int[4]{ 5, 4, 2, 0 };
	tsp(a, 3);*/
    #pragma endregion

    #pragma region 回路（未完成）
	/*vector<int> param;
	vector<Point> edge;
	param.push_back(4);
	param.push_back(4);
	edge.push_back(Point(1, 2));
	edge.push_back(Point(2, 3));
	edge.push_back(Point(3, 4));
	edge.push_back(Point(4, 1));
	cout << circuit(param, edge) << endl;*/
	//[7,11],[(3,2),(5,1),(1,6),(6,4),(7,2),(7,4),(4,2),(1,3),(6,3),(3,7),(5,6)]
	/*vector<int> param;
	vector<Point> edge;
	param.push_back(7);
	param.push_back(11);
	edge.push_back(Point(3, 2));
	edge.push_back(Point(5, 1));
	edge.push_back(Point(1, 6));
	edge.push_back(Point(6, 4));
	edge.push_back(Point(7, 2));
	edge.push_back(Point(7, 4));
	edge.push_back(Point(4, 2));
	edge.push_back(Point(1, 3));
	edge.push_back(Point(6, 3));
	edge.push_back(Point(3, 7));
	edge.push_back(Point(5, 6));
	cout << circuit(param, edge) << endl;*/
    #pragma endregion

    #pragma region 算术编解码
	//compress_uncompress_test();
    #pragma endregion

    #pragma region 金额大写转化
	/*double money = 12034050670.89;
	string out = "";
	money2capital(out, money);*/
    #pragma endregion

    #pragma region 0-1背包
	/*knapsack();*/
    #pragma endregion

    #pragma region 仓库问题（美团笔试，未完成）
	//warehouse();
    #pragma endregion

    #pragma region 深信服笔试
	/*查找两个字符串中那个有差别的字符*/
	//find_diff_char("acdb", "adebc");
	//find_diff_char("adebc", "acdb");
	//find_diff_char("adecc", "acdc");

	/*查找公共子串*/
	//find_same_char("adecc", "acdbc");
	/*string *chars = new string[3]{ "bella","label","roller" };
	common_chars(chars, 3);*/
    #pragma endregion
}

#pragma region stl容器测试
void stl_test() {
	/*vecotr*/
	/*std::vector<int> a;
	a.push_back(2);
	a.push_back(3);
	std::vector<int>::iterator itr;
	for (itr = a.begin(); itr != a.end(); itr++)
	cout << *itr << endl;*/

	/*queue*/
	/*std::queue<int> queue;
	queue.push(3);
	queue.push(2);
	int a = queue.front();
	a = queue.back();
	queue.pop();*/

	/*list*/
	/*//list<int> list;
	std::list<int> list(10,1);//初始化list，插入值为1的10个元素
	list.insert(list.begin(),3);
	list.push_back(2);
	list.remove(1);
	std::list<int>::iterator itr;
	for (itr = list.begin(); itr != list.end(); itr++)
		cout << *itr << endl;*/

	/*unordered_set*/
	/*std::unordered_set<char> set;
	set.insert(3);
	set.insert(2);
	set.insert('3');
	set.insert(3);
	set.insert(51);
	auto itr = set.find('3'); //std::unordered_set<char>::iterator itr = set.find('3');
	set.erase(itr);
	for (itr = set.begin(); itr != set.end(); itr++)
		cout << *itr << endl;*/

	/*unordered_map内部由hashtable实现，原理和hash_map类似，但其在某些方面做了优化，性能好于hash_map。
	从c++11开始，unordered_map被引入标准库，而hash_map没有，hash_map属于非标准容器，而且业界普遍使用unordered_map而不是hash_map*/
	/*std::unordered_map<string, int> map;
	map.insert(make_pair("c", 3));
	map.insert(make_pair("b", 2));
	map.insert(make_pair("e", 5));
	map.insert(make_pair("m", 13));
	map.insert(make_pair("g", 7));
	map.insert(make_pair("i", 9));
	map.insert(make_pair("q", 17));
	map.insert(make_pair("l", 12));
	map.insert(make_pair("l", 1));
	std::unordered_map<string, int>::iterator itr = map.find("i");
	cout << itr->first << ' ' << itr->second << endl; // itr->first是key，itr->second是value
	map.erase(itr);
	map.erase("e");
	for (itr = map.begin(); itr != map.end(); itr++)
		cout << itr->first << ' ' << itr->second << endl;*/

	/*set内部由红黑树实现，字符串按字典序排列*/
	/*std::set<string> set;
	set.insert("c");
	set.insert("b");
	set.insert("e");
	set.insert("m");
	set.insert("g");
	set.insert("i");
	set.insert("q");
	set.insert("l");
	std::set<string>::iterator itr = set.find("e");
	set.erase(itr);
	for (itr = set.begin(); itr != set.end(); itr++)
		cout << *itr << endl;*/

	/*map内部由红黑树实现*/
	std::map<int, string> map;
	map.insert(make_pair(3, "c"));
	map.insert(make_pair(2, "b"));
	map.insert(make_pair(5, "e"));
	map.insert(make_pair(13, "m"));
	map.insert(make_pair(7, "g"));
	map.insert(make_pair(9, "i"));
	map.insert(make_pair(17, "q"));
	map.insert(make_pair(12, "l"));
	std::map<int, string>::iterator itr = map.find(9);
	cout << itr->first << ' ' << itr->second << endl;
	map.erase(itr);
	map.erase(5);
	for (itr = map.begin(); itr != map.end(); itr++)
		cout << itr->first << ' ' << itr->second << endl;
}
#pragma endregion

#pragma region 栈测试
void stack_test() {
	Stack stack = Stack(20);
	stack.push(3);
	stack.push(2);
	stack.push(5);
	stack.push(13);
	stack.push(7);
	stack.push(9);
	stack.push(17);
	stack.push(12);
	int top = stack.pop();
}
#pragma endregion

#pragma region 队列测试
void queue_test() {
    #pragma region 循环队列
	/*RoundQueue queue = RoundQueue(10);
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(13);
	queue.push(7);
	queue.push(9);
	queue.push(17);
	queue.push(12);
	long top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	top = queue.pop();
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(13);
	queue.push(7);
	queue.push(9);
	queue.push(17);
	queue.push(12);
	queue.push(8);//队满时元素个数为maxSize-1
	queue.push(19);
	queue.push(11);*/
    #pragma endregion

    #pragma region 优先队列
	MaxPriorityQueue queue = MaxPriorityQueue(20);
	queue.push(3);
	queue.push(2);
	queue.push(5);
	queue.push(13);
	queue.push(7);
	queue.push(9);
	queue.push(17);
	queue.push(12);
	queue.print();
    #pragma endregion
}
#pragma endregion

#pragma region 堆测试
void heap_test() {
	/*int *a = new int[20], size = 0;
	MaxHeap::insert(a, 3, size);
	MaxHeap::insert(a, 2, size);
	MaxHeap::insert(a, 5, size);
	MaxHeap::insert(a, 13, size);
	MaxHeap::insert(a, 7, size);
	MaxHeap::insert(a, 9, size);
	MaxHeap::insert(a, 17, size);
	MaxHeap::insert(a, 12, size);
	for (int i = 1; i <= size; i++)
		cout << a[i] << endl;
	MaxHeap::adjust(a, size);
	for (int i = 1; i <= size; i++)
		cout << a[i] << endl;*/

	/*MaxHeap heap=MaxHeap(20);
	heap.push(3);
	heap.push(2);
	heap.push(5);
	heap.push(13);
	heap.push(7);
	heap.push(9);
	heap.push(17);
	heap.push(12);
	heap.print();
	int top = heap.pop();
	heap.print();
	top = heap.pop();
	heap.print();*/

    #pragma region 堆排序（top k，取最大的前k个数）
	/*算法思路：
	* 1.取前k个数建立初始小顶堆heapArray
	* 2.遍历其余的n-k个数，与堆顶元素比较：如果大于堆顶元素，则将堆顶元素替换成此数，同时重新调整小顶堆；否则，保持堆不变*/
	int n = 20, k = 6;
	long *a = new long[20] {42, 17, 6, 31, 5, 76, 69, 66, 19, 53, 4, 65, 46, 90, 7, 18, 37, 27, 62, 25}, *heapArray = new long[k + 1];
	//建立初始小顶堆heapArray
	for (int i = 0; i < k; i++) {
		heapArray[i + 1] = a[i];
		MinHeap::shift_up(heapArray, i + 1);
		MinHeap::print(heapArray, i + 1);
	}
	//遍历其余的n-k个数与堆顶元素比较，调整小顶堆
	for (int i = k; i < n; i++) {
		if (a[i]>heapArray[1]) {
			heapArray[1] = a[i];
			MinHeap::shift_down(heapArray, k);
		}
		MinHeap::print(heapArray, k);
	}
	for (int i = 1; i <= k; i++)
		cout << heapArray[i] << endl;
    #pragma endregion
}
#pragma endregion

#pragma region 节点测试
void node_test() {
#pragma region 生成链表
	int data;
	Node *list = new Node(), *current, *temp;
	cin >> data;
	list->data = data;
	current = list;
	while (cin.get() != '\n') {
		cin >> data;
		temp = new Node(data);
		current->next = temp;
		current = current->next;
	}
	current = list;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->next;
	}
#pragma endregion

}
#pragma endregion

#pragma region 链表测试
void list_test() {
	/*SortedList sortedList = SortedList();
	sortedList.insert(3);
	sortedList.insert(14);
	sortedList.insert(2);
	sortedList.insert(12);
	sortedList.insert(7);
	Node* node = sortedList.find(12);
	sortedList.remove(12);
	sortedList.remove(14);*/

	/*DoublySortedList doublySortedList = DoublySortedList();
	doublySortedList.insert(3);
	doublySortedList.insert(14);
	doublySortedList.insert(2);
	doublySortedList.insert(12);
	doublySortedList.insert(7);
	DoublyNode* doublyNode = doublySortedList.find(12);
	doublySortedList.remove(12);
	doublySortedList.remove(14);*/

	List list = List();
	list.insert(3);
	list.insert(14);
	list.insert(2);
	list.insert(12);
	list.insert(7);
	Node* node = list.find(12);
	list.remove(12);
	list.remove(14);
	list.reverse();
	List reverseList = List::reverse(list);

	/*DoublyList doublyList = DoublyList();
	doublyList.insert(3);
	doublyList.insert(14);
	doublyList.insert(2);
	doublyList.insert(12);
	doublyList.insert(7);
	DoublyNode* Doublynode = doublyList.find(12);
	doublyList.remove(12);
	doublyList.remove(14);*/
}
#pragma endregion

#pragma region 树测试
void tree_test() {
	/*BinaryTree<int> tree;
	tree.insertRoot(3);*/
	/*BinaryTree<int> tree = BinaryTree<int>(3);//初始化，建立根结点3
	tree.insert(2, 3, 0);//参数：要插入的数，要插入的父结点，要插入的父结点的左结点还是右结点（0表示插入到左结点，1表示插入到右结点）
	tree.insert(5, 3, 1);
	tree.insert(13, 2, 0);
	tree.insert(7, 2, 1);
	tree.insert(9, 5, 0);
	tree.insert(17, 5, 1);
	tree.insert(12, 13, 0);
	tree.insert(12, 13, 1);//因为是普通二叉树，插入时只考虑要插入的位置是否闲置，而不考虑元素的唯一性，所以元素可能会重复
	tree.insert(14, 13, 0);
	tree.insert(14, 5, 0);
	tree.levelOrder();
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();*/
	/*BinaryTree<int> tree = BinaryTree<int>(1);
	tree.insert(2, 1, 0);
	tree.insert(6, 1, 1);
	tree.insert(3, 2, 0);
	tree.insert(4, 2, 1);
	tree.insert(7, 6, 0);
	tree.insert(8, 6, 1);
	tree.insert(5, 4, 0);
	tree.printTree();
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();
	tree.dfs();*/

	/*BinarySearchTree<int> tree;
	tree.insert(3);
	tree.insert(1);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(9);
	tree.insert(17);
	tree.insert(12);
	TreeNode<int> *node = tree.find(13);
	node = tree.find(14);
	//node = tree.removeMin();
	//tree.remove(5);
	tree.remove(13);
	tree.printTree();
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();
	tree.dfs();*/

	/*BalanceBinaryTree<int> tree;
	tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.printTree();
	cout << endl;
	tree.insert(7);
	tree.printTree();
	cout << endl;
	tree.insert(9);
	tree.printTree();
	cout << endl;
	tree.insert(17);
	tree.printTree();
	cout << endl;
	tree.insert(12);
	tree.printTree();
	tree.levelOrder();
	tree.dfs();*/

	/*RedBlackTree<int> tree;
	tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.printTree();
	cout << endl;
	tree.insert(7);
	tree.printTree();
	cout << endl;
	tree.insert(9);
	tree.printTree();
	cout << endl;
	tree.insert(17);
	tree.printTree();
	cout << endl;
	tree.insert(12);
	tree.printTree();
	cout << endl;
	tree.insert(8);
	tree.printTree();*/
	/*RedBlackTree<int> tree;
	tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(17);
	tree.printTree();
	tree.levelOrder();
	tree.dfs();*/
	/*tree.insert(7);
	tree.insert(3);
	tree.insert(13);
	//tree.insert(2);
	tree.insert(5);
	tree.insert(9);
	tree.insert(17);
	tree.insert(12);
	tree.printTree();
	RedBlackTreeNode<int> *node = tree.removeMin();
	tree.printTree();*/
	/*tree.insert(3);
	//tree.insert(1);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(9);
	tree.insert(17);
	tree.insert(12);
	tree.printTree();
	tree.remove(13);//case2
	tree.printTree();
	tree.remove(9);//case4
	tree.printTree();
	tree.remove(17);//delete red node
	tree.printTree();
	tree.remove(12);//case5
	tree.printTree();*/
	/*tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(9);
	tree.insert(17);
	tree.insert(12);
	tree.printTree();
	tree.remove(2);//case4
	tree.printTree();*/
	/*tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(9);
	tree.insert(17);
	tree.printTree();
	tree.remove(5);//case3
	tree.printTree();*/
	/*tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(9);
	tree.printTree();
	tree.remove(5);//case2
	tree.printTree();*/
	/*tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(13);
	tree.insert(7);
	tree.insert(17);
	tree.printTree();
	tree.remove(5);//case1
	tree.printTree();
	tree.remove(3);//delete root, case4
	tree.printTree();*/

	/*BalanceTree<int> tree = BalanceTree<int>(4);
	tree.insert(3);
	cout << "insert 2" << endl;
	tree.insert(2);
	tree.levelOrder();
	cout << "insert 5" << endl;
	tree.insert(5);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 7" << endl;
	tree.insert(7);
	tree.levelOrder();
	cout << "insert 9" << endl;
	tree.insert(9);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "insert 1" << endl;
	tree.insert(1);
	tree.levelOrder();
	cout << "insert 4" << endl;
	tree.insert(4);
	tree.levelOrder();
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();*/
	/*BalanceTree<int> tree = BalanceTree<int>(5);
	tree.insert(3);
	cout << "insert 7" << endl;
	tree.insert(7);
	tree.levelOrder();
	cout << "insert 1" << endl;
	tree.insert(1);
	tree.levelOrder();
	cout << "insert 14" << endl;
	tree.insert(14);
	tree.levelOrder();
	cout << "insert 8" << endl;
	tree.insert(8);
	tree.levelOrder();
	cout << "insert 5" << endl;
	tree.insert(5);
	tree.levelOrder();
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 6" << endl;
	tree.insert(6);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "insert 20" << endl;
	tree.insert(20);
	tree.levelOrder();
	cout << "insert 23" << endl;
	tree.insert(23);
	tree.levelOrder();
	cout << "insert 26" << endl;
	tree.insert(26);
	tree.levelOrder();
	cout << "insert 4" << endl;
	tree.insert(4);
	tree.levelOrder();
	cout << "insert 16" << endl;
	tree.insert(16);
	tree.levelOrder();
	cout << "insert 18" << endl;
	tree.insert(18);
	tree.levelOrder();
	cout << "insert 24" << endl;
	tree.insert(24);
	tree.levelOrder();
	cout << "insert 25" << endl;
	tree.insert(25);
	tree.levelOrder();
	cout << "insert 19" << endl;
	tree.insert(19);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 15" << endl;
	tree.insert(15);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 9" << endl;
	tree.insert(9);
	tree.levelOrder();
	cout << "insert 10" << endl;
	tree.insert(10);
	tree.levelOrder();
	BalanceTreeNode<int> *node = tree.find(17);
	cout << "remove 24" << endl;
	tree.remove(24);
	tree.levelOrder();
	cout << "remove 19" << endl;
	tree.remove(19);
	tree.levelOrder();
	cout << "remove 18" << endl;
	tree.remove(18);
	tree.levelOrder();
	cout << "remove 25" << endl;
	tree.remove(25);
	tree.levelOrder();
	cout << "remove 16" << endl;
	tree.remove(16);
	tree.levelOrder();
	cout << "remove 4" << endl;
	tree.remove(4);
	tree.levelOrder();*/
	/*BalanceTree<int> tree = BalanceTree<int>(5);
	for(int i=1;i<=32;i++)
		tree.insert(i);
	tree.levelOrder();*/
	/*BalanceTree<int> tree = BalanceTree<int>(5);
	int m, data, a[] = { 1,3,7,14,8,5,11,17,13,6,12,20,23,26,4,16,18,24,25,19 };
	//int m, data, a[] = { 39,22,97,41,53,13,21,40,30,27,33,36,35,34,24,29,26,17,28,23,31,32 };
	//int size = end(a) - begin(a);//头指针与尾指针的差即数组长度。注：同类型的指针的差，与类型无关
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; i++)
		tree.insert(a[i]);
	tree.levelOrder();
	tree.dfs();*/
	/*cout << "输入b树阶数：";
	cin >> m;
	tree = BalanceTree<int>(m);
	while (true)
	{
		cout << "插入 ";
		cin >> data;
		if (data == -1)break;
		tree.insert(data);
		tree.levelOrder();
	}*/
	/*while (true)
	{
		cout << "删除 ";
		cin >> data;
		if (data == -1)break;
		tree.remove(data);
		tree.levelOrder();
	}*/

	/*Trie tree = Trie();
	tree.insert("inn");
	tree.insert("int");
	tree.insert("kit");
	tree.insert("kitchen");
	tree.insert("kite");
	tree.insert("kit");
	tree.insert("knee");
	tree.insert("kneel");
	tree.dfs();*/
	/*Trie tree = Trie();
	string strArray[8]{ "inn", "int", "kit", "kitchen", "kite", "kit", "knee", "kneel" };
	for (int i = 0; i < 8; i++)
		tree.insert(strArray[i]);
	tree.dfs();*/
	/*PrefixTrie tree = PrefixTrie();
	tree.insert("inn");
	tree.insert("int");
	tree.insert("kit");
	tree.insert("kitchen");
	tree.insert("kite");
	tree.insert("knee");
	tree.insert("kneel");
	tree.dfs();*/
    /*HDOJ 1251*/
	/*PrefixTrie tree = PrefixTrie();
	tree.insert("banana");
	tree.insert("band");
	tree.insert("bee");
	tree.insert("absolute");
	tree.insert("acm");
	cout << tree.find("ba") << endl;
	cout << tree.find("b") << endl;
	cout << tree.find("band") << endl;
	cout << tree.find("abc") << endl;*/
	/*POJ 2001 Shortest Prefixes*/
	/*PrefixTrie tree = PrefixTrie();
	tree.insert("banana");
	tree.insert("band");
	tree.insert("bee");
	tree.insert("absolute");
	tree.insert("acm");
	cout << tree.find("ba") << endl;
	cout << tree.find("b") << endl;
	cout << tree.find("band") << endl;
	cout << tree.find("abc") << endl;
	char *str = tree.findDistinct("banana");
	str = tree.findDistinct("band");
	str = tree.findDistinct("bee");
	str = tree.findDistinct("absolute");
	str = tree.findDistinct("acm");*/
	/*PrefixTrie tree = PrefixTrie();
	int size = 12;
	char **strArray = new char*[size] {
		"carbohydrate",
		"cart",
		"carburetor",
		"caramel",
		"caribou",
		"carbonic",
		"cartilage",
		"carbon",
		"carriage",
		"carton",
		"car",
		"carbonate"
	};
	for(int i=0;i<size;i++)
		tree.insert(strArray[i]);
	for (int i = 0; i < size; i++)
		cout << strArray[i] << " " << tree.findDistinct(strArray[i]) << endl;*/
    /*PrefixTrie tree = PrefixTrie();
    string strArray[1001];
	int i = 0;
	while (cin >> strArray[i]) // ctrl+z结束输入
		tree.insert(strArray[i++]);
	for (int j = 0; j < i; j++)
		cout << strArray[j] << " " << tree.findDistinct(strArray[j]) << endl;*/
    /*HashTrie tree = HashTrie();
	tree.insert("inn");
	tree.insert("int");
	tree.insert("kit");
	tree.insert("kitchen");
	tree.insert("kite");
	tree.insert("kit");
	tree.insert("knee");
	tree.insert("kneel");
	tree.dfs();*/
    /*#define BUFFER_SIZE 1024
    #define BUFFER_PADDING_SIZE 64
    HashTrie tree = HashTrie();
	FILE *freader;
	char *buffer = (char*)malloc(BUFFER_SIZE + BUFFER_PADDING_SIZE);
	memset(buffer + BUFFER_SIZE, 0, BUFFER_PADDING_SIZE);
	char *filename = "D:\\Users\\veev\\BigData\\userBehaviors";
	freader = fopen(filename, "rb");
	if (!freader) {
		fprintf(stderr, "Could not open %s\n", filename);
		exit(1);
	}
	char *strArray;
	while (!feof(freader) && NULL != fgets(buffer, BUFFER_SIZE, freader)) {
		strArray = strtok(buffer, "\1"); // 以"u0001"分割，取第1个
		strArray = strtok(NULL, "\1"); // 以"u0001"分割，取第2个
		tree.insert(strArray);
	}
	fclose(freader);
	tree.dfs();*/
    /*#define DEBUG_MODE 0
    #define BUFFER_SIZE 1024
    #define BUFFER_PADDING_SIZE 64
	HashTrie tree = HashTrie();
	FILE *freader, *fwriter;
	char *buffer = (char*)malloc(BUFFER_SIZE + BUFFER_PADDING_SIZE);
	memset(buffer + BUFFER_SIZE, 0, BUFFER_PADDING_SIZE);
	char *filename = "D:\\Users\\veev\\BigData\\userBehaviors";
	char *outfilename = "D:\\Users\\veev\\BigData\\userBehaviorsCountByTrie";
	freader = fopen(filename, "rb");
	if (!freader) {
		fprintf(stderr, "Could not open %s\n", filename);
		exit(1);
	}
	fwriter = fopen(outfilename, "wb");

	long long start_memsize, end_memsize;
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	start_memsize = pmc.WorkingSetSize / 1024;
	clock_t start_time, end_time;
	start_time = clock();
	char *strArray, *size = new char[20], *wordcount = new char[20], *nodecount = new char[20], *memusage = new char[20], *timecost = new char[20];
	while (!feof(freader) && NULL!=fgets(buffer, BUFFER_SIZE, freader)) {
		strArray = strtok(buffer, "\1"); // 以"u0001"分割，取第1个
		strArray = strtok(NULL, "\1"); // 以"u0001"分割，取第2个
		tree.insert(strArray);

        #if DEBUG_MODE==1
		end_time = clock();
		if ((end_time - start_time) / CLOCKS_PER_SEC > 3)break;
        #endif
	}
	fclose(freader);

	// 统计树字符串数（含重复字符串）
	fwrite("size of the trie: ", 1, 18, fwriter);
	sprintf(size, "%lld", tree.size());
	fwrite(size, 1, strlen(size), fwriter);
	fwrite("\n", 1, 1, fwriter);

	// 统计树单词数（不含重复单词）
	fwrite("word count of the trie: ", 1, 24, fwriter);
	sprintf(wordcount, "%lld", tree.wordcount());
	fwrite(wordcount, 1, strlen(wordcount), fwriter);
	fwrite("\n", 1, 1, fwriter);

	// 统计树结点数
	fwrite("node count of the trie: ", 1, 24, fwriter);
	sprintf(nodecount, "%lld", tree.nodecount());
	fwrite(nodecount, 1, strlen(nodecount), fwriter);
	fwrite("\n", 1, 1, fwriter);

	// 获取内存占用
	fwrite("memory usage of the trie construction: ", 1, 39, fwriter);
	//int size = sizeof(HashTrieNode);
	//size = sizeof(unordered_map<char, int>);
	//size = sizeof(unordered_map<char, HashTrieNode*>);
	//size = sizeof(map<char, int>);
	//size = sizeof(map<char, HashTrieNode*>);
	//sprintf(nodecount, "%lld", tree.nodecount() * sizeof(HashTrieNode));
	//fwrite(nodecount, 1, strlen(nodecount), fwriter);
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	end_memsize = pmc.WorkingSetSize / 1024;
	sprintf(memusage, "%lld", end_memsize - start_memsize);
	fwrite(memusage, 1, strlen(memusage), fwriter);
	fwrite("KB\n", 1, 3, fwriter);

	// 计算时间耗费
	end_time = clock();
	fwrite("time cost of the trie construction: ", 1, 36, fwriter);
	sprintf(timecost, "%f", (double)((end_time - start_time) / CLOCKS_PER_SEC));
	fwrite(timecost, 1, strlen(timecost), fwriter);
	fwrite("s\n", 1, 2, fwriter);
	fflush(fwriter);

	// 遍历并写入文件
	tree.dfs(fwriter);

	// 总的时间耗费
	end_time = clock();
	fwrite("total time cost: ", 1, 17, fwriter);
	sprintf(timecost, "%f", (double)((end_time - start_time) / CLOCKS_PER_SEC));
	fwrite(timecost, 1, strlen(timecost), fwriter);
	fwrite("s\n", 1, 2, fwriter);
	fclose(fwriter);*/

	/*BPlusTree<int> tree = BPlusTree<int>(4);
	tree.insert(3);
	cout << "insert 2" << endl;
	tree.insert(2);
	tree.levelOrder();
	cout << "insert 5" << endl;
	tree.insert(5);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 7" << endl;
	tree.insert(7);
	tree.levelOrder();
	cout << "insert 9" << endl;
	tree.insert(9);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "insert 1" << endl;
	tree.insert(1);
	tree.levelOrder();
	cout << "insert 4" << endl;
	tree.insert(4);
	tree.levelOrder();
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();
	cout << "remove 13" << endl;
	tree.remove(13);
	tree.levelOrder();
	cout << "remove 17" << endl;
	tree.remove(17);
	tree.levelOrder();
	cout << "remove 9" << endl;
	tree.remove(9);
	tree.levelOrder();
	cout << "remove 11" << endl;
	tree.remove(11);
	tree.levelOrder();
	cout << "remove 3" << endl;
	tree.remove(3);
	tree.levelOrder();
	tree.dfs();
	BPlusTreeNode<int> *node;
	node = tree.find(7);
	node = tree.find(12);
	tree.printData();*/
    /*int a[]{ 5, 8, 10, 15, 16, 17, 18, 6, 9, 19, 20, 21, 22, 7 };
	int size = sizeof(a) / sizeof(a[0]);
	BPlusTree<int> tree = BPlusTree<int>(5);
	for (int i = 0; i < size; i++) {
		cout << "insert " << a[i] << endl;
		tree.insert(a[i]);
		tree.levelOrder();
	}
	cout << "insert 23" << endl;
	tree.insert(23);
	tree.levelOrder();
	cout << "insert 24" << endl;
	tree.insert(24);
	tree.levelOrder();
	cout << "insert 25" << endl;
	tree.insert(25);
	tree.levelOrder();
	cout << "insert 26" << endl;
	tree.insert(26);
	tree.levelOrder();
	cout << "insert 27" << endl;
	tree.insert(27);
	tree.levelOrder();
	cout << "insert 28" << endl;
	tree.insert(28);
	tree.levelOrder();
	cout << "insert 29" << endl;
	tree.insert(29);
	tree.levelOrder();
	cout << "remove 22" << endl;
	tree.remove(22);
	tree.levelOrder();
	cout << "remove 15" << endl;
	tree.remove(15);
	tree.levelOrder();
	cout << "remove 7" << endl;
	tree.remove(7);
	tree.levelOrder();
	tree.dfs();
	BPlusTreeNode<int> *node;
	node = tree.find(7);
	tree.printData();*/
	/*int a[] {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	int size = sizeof(a) / sizeof(a[0]);
	BPlusTree<int> tree = BPlusTree<int>(4);
	for (int i = 0; i < size; i++) {
		cout << "insert " << a[i] << endl;
		tree.insert(a[i]);
		tree.levelOrder();
	}
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "remove 9" << endl;
	tree.remove(9);
	tree.levelOrder();
	cout << "remove 7" << endl;
	tree.remove(7);
	tree.levelOrder();
	cout << "remove 8" << endl;
	tree.remove(8);
	tree.levelOrder();
	tree.dfs();
	BPlusTreeNode<int> *node;
	node = tree.find(7);
	tree.printData();*/
	/*int a[]{ 1, 16, 4, 25, 9, 20, 13, 15, 10, 11, 12 };
	int size = sizeof(a) / sizeof(a[0]);
	BPlusTree<int> tree = BPlusTree<int>(4);
	for (int i = 0; i < size; i++) {
		cout << "insert " << a[i] << endl;
		tree.insert(a[i]);
		tree.levelOrder();
	}
	cout << "remove 13" << endl;
	tree.remove(13);
	tree.levelOrder();
	cout << "remove 15" << endl;
	tree.remove(15);
	tree.levelOrder();
	cout << "remove 1" << endl;
	tree.remove(1);
	tree.levelOrder();
	tree.dfs();
	BPlusTreeNode<int> *node;
	node = tree.find(7);
	tree.printData();*/

	/*BalancePlusTree<int> tree = BalancePlusTree<int>(3);
	tree.insert(3);
	cout << "insert 2" << endl;
	tree.insert(2);
	tree.levelOrder();
	cout << "insert 5" << endl;
	tree.insert(5);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 7" << endl;
	tree.insert(7);
	tree.levelOrder();
	cout << "insert 9" << endl;
	tree.insert(9);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "insert 1" << endl;
	tree.insert(1);
	tree.levelOrder();
	cout << "insert 4" << endl;
	tree.insert(4);
	tree.levelOrder();
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();
	cout << "remove 13" << endl;
	tree.remove(13);
	tree.levelOrder();
	cout << "remove 17" << endl;
	tree.remove(17);
	tree.levelOrder();
	cout << "remove 9" << endl;
	tree.remove(9);
	tree.levelOrder();
	cout << "remove 11" << endl;
	tree.remove(11);
	tree.levelOrder();
	cout << "remove 3" << endl;
	tree.remove(3);
	tree.levelOrder();
	tree.dfs();
	BalancePlusTreeNode<int> *node;
	node = tree.find(7);
	node = tree.find(12);
	tree.printData();*/
    /*float a[]{ 10, 20, 30, 7, 8, 25, 6, 7.5, 12, 13, 6.5 };
	int size = sizeof(a) / sizeof(a[0]);
	BalancePlusTree<float> tree = BalancePlusTree<float>(3);
	for (int i = 0; i < size; i++) {
		cout << "insert " << a[i] << endl;
		tree.insert(a[i]);
		tree.levelOrder();
	}
	cout << "remove 12" << endl;
	tree.remove(12);
	tree.levelOrder();
	cout << "remove 13" << endl;
	tree.remove(13);
	tree.levelOrder();
	cout << "remove 7.5" << endl;
	tree.remove(7.5);
	tree.levelOrder();
	cout << "remove 6" << endl;
	tree.remove(6);
	tree.levelOrder();
	cout << "remove 8" << endl;
	tree.remove(8);
	tree.levelOrder();
	cout << "remove 10" << endl;
	tree.remove(10);
	tree.levelOrder();
	tree.dfs();
	BalancePlusTreeNode<float> *node;
	node = tree.find(7);
	tree.printData();*/

	/*BalancePlusProTree<int> tree = BalancePlusProTree<int>(3);
	tree.insert(3);
	cout << "insert 2" << endl;
	tree.insert(2);
	tree.levelOrder();
	cout << "insert 5" << endl;
	tree.insert(5);
	tree.levelOrder();
	cout << "insert 13" << endl;
	tree.insert(13);
	tree.levelOrder();
	cout << "insert 7" << endl;
	tree.insert(7);
	tree.levelOrder();
	cout << "insert 9" << endl;
	tree.insert(9);
	tree.levelOrder();
	cout << "insert 17" << endl;
	tree.insert(17);
	tree.levelOrder();
	cout << "insert 12" << endl;
	tree.insert(12);
	tree.levelOrder();
	cout << "insert 1" << endl;
	tree.insert(1);
	tree.levelOrder();
	cout << "insert 4" << endl;
	tree.insert(4);
	tree.levelOrder();
	cout << "insert 11" << endl;
	tree.insert(11);
	tree.levelOrder();
	cout << "remove 13" << endl;
	tree.remove(13);
	tree.levelOrder();
	cout << "remove 17" << endl;
	tree.remove(17);
	tree.levelOrder();
	cout << "remove 9" << endl;
	tree.remove(9);
	tree.levelOrder();
	cout << "remove 11" << endl;
	tree.remove(11);
	tree.levelOrder();
	cout << "remove 3" << endl;
	tree.remove(3);
	tree.levelOrder();
	tree.dfs();
	BalancePlusProTreeNode<int> *node;
	node = tree.find(7);
	node = tree.find(12);
	tree.printData();*/
}
#pragma endregion

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
