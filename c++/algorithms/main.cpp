// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable:4996)

#include <iostream>

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>

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
	//tree_test();

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
	for (int i = 0; i < length; i++) data[i] = temp[i];

	cout << "After sorted:" << endl;
	quick_sort(data, 0, length - 1);
	for (int i = 0; i < length; ++i)
		cout << data[i] << "  ";
	cout << endl;*/
	#pragma endregion

    #pragma region 最长不重复子串长度
	/*int result=lengthOfLongestSubstring("adasdfasdf");
	cout << result << endl;*/
    #pragma endregion
	
    #pragma region 模式匹配
	//patternMatching();
    #pragma endregion

    #pragma region 删除字符串中的"ab"字符
	//deleteString();
    #pragma endregion

    #pragma region 大数的加法和乘法（a, b可能超integer和long的取值范围）
	bigNumber();
    #pragma endregion

    #pragma region top k problem
	//searchTopK();
    #pragma endregion

    #pragma region 递归数组
	//FibonacciSeq();
    #pragma endregion

    #pragma region 质因数分解
	//PrimeFactorization();
    #pragma endregion

    #pragma region 最大公约数
	//GreatestCommonFactor();
    #pragma endregion

    #pragma region 最小公倍数
	//LowestCommonMultiple();
    #pragma endregion

    #pragma region 字符统计
	//CharCount();
    #pragma endregion

    #pragma region 阶乘求和
	//FactorialSum();
    #pragma endregion

    #pragma region 整数位数统计
	//DigitCount();
    #pragma endregion

    #pragma region 回文数
	//PalindromeNumber();
    #pragma endregion

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
	cout << itr->first << ' ' << itr->second << endl;
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
	}
	//遍历其余的n-k个数与堆顶元素比较，调整小顶堆
	for (int i = k; i < n; i++) {
		if (a[i]>heapArray[1]) {
			heapArray[1] = a[i];
			MinHeap::shift_down(heapArray, k);
		}
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

	/*List list = List();
	list.insert(3);
	list.insert(14);
	list.insert(2);
	list.insert(12);
	list.insert(7);
	Node* node = list.find(12);
	list.remove(12);
	list.remove(14);*/

	DoublyList doublyList = DoublyList();
	doublyList.insert(3);
	doublyList.insert(14);
	doublyList.insert(2);
	doublyList.insert(12);
	doublyList.insert(7);
	DoublyNode* Doublynode = doublyList.find(12);
	doublyList.remove(12);
	doublyList.remove(14);
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
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();*/

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
	tree.printTree();*/

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

    BalanceTree<int> tree = BalanceTree<int>(4);
	/*tree.insert(3);
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
	/*tree = BalanceTree<int>(5);
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
	int m, data, a[] = { 1,3,7,14,8,5,11,17,13,6,12,20,23,26,4,16,18,24,25,19 };
	//int m, data, a[] = { 39,22,97,41,53,13,21,40,30,27,33,36,35,34,24,29,26,17,28,23,31,32 };
    tree = BalanceTree<int>(5);
	for(int i=1;i<=32;i++)
		tree.insert(i);
	tree.levelOrder();
	/*tree = BalanceTree<int>(5);
	//int size = end(a) - begin(a);//头指针与尾指针的差即数组长度。注：同类型的指针的差，与类型无关
	int size = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < size; i++)
		tree.insert(a[i]);
	tree.levelOrder();*/
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
	while (true)
	{
		cout << "删除 ";
		cin >> data;
		if (data == -1)break;
		tree.remove(data);
		tree.levelOrder();
	}
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
