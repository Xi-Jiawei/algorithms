// algorithms.cpp : 此文件包含各算法函数。
//

#include "algorithms.h"
#include <map>

#pragma region 不含有重复字符的 最长子串 的长度：待优化
int LengthOfLongestSubstring(string s) {
    #pragma region 使用set
	int n = s.length();
	unordered_set<char> set;
	int ans = 0, i = 0, j = 0;
	while (i < n && j < n) {
		// try to extend the range [i, j]
		/*find会挨个查找set，当到达set.end()时，也就是一个也没找到，返回end*/
		if (set.find(s[j]) == set.end()) {
			set.insert(s[j++]);
			ans = max(ans, j - i);
		}
		else {
			set.erase(s[i++]);
		}
	}
	return ans;
    #pragma endregion

    #pragma region 使用map
	/*int n = s.length();
	unordered_map<char, int> map; // current index of character
	int ans = 0;
	for (int j = 0, i = 0; j < n; j++) {
		// try to extend the range [i, j]
		//find会挨个查找set，当到达set.end()时，也就是一个也没找到，返回end
		if (map.find(s[j]) != map.end()) {
			i = max(map.find(s[j])->second, i);
		}
		ans = max(ans, j - i + 1);
		map.insert(make_pair(s[j], j + 1));
	}
	return ans;*/
    #pragma endregion
}
#pragma endregion

#pragma region 删除字符串中的"ab"字符
void DeleteString(){
	string str;
	cin >> str;
	int index = str.find("ab");
	while (index != -1)
	{
		str = str.substr(0, index) + str.substr(index + 2, str.length() - 2 - index);
		index = str.find("ab");
	}
	cout << str << endl;
}
#pragma endregion

#pragma region 计算a*b（a, b可能超integer和long的取值范围）：待优化
void Multiply(){
	string a_str, b_str;
	cin >> a_str >> b_str;
	/*int a = 0, b = 0;
	for (int i = 0; i < a_str.length(); i++)
		a += pow(10, a_str.length() - 1-i)*(a_str[i] - '0');
	for (int i = 0; i < b_str.length(); i++)
		b += pow(10, b_str.length() - 1-i)*(b_str[i] - '0');*/
	int multiply = 0;
	for (int i = 0; i < a_str.length(); i++)
		for (int j = 0; j < b_str.length(); j++) {
			multiply += pow(10, a_str.length() - 1 - i)*(a_str[i] - '0')*pow(10, b_str.length() - 1 - j)*(b_str[j] - '0');
		}
	cout << multiply << endl;
}
#pragma endregion

#pragma region 单词拆分：待优化，https://leetcode-cn.com/problems/word-break-ii/
void WordBreak(){
	//typedef list<string> LISTINT;
	unordered_map<string, int> map;
	list<string> d;
	string str, t, word, temp;
	int row, i = 0, start = 0;
	bool flag = true;
	cin >> row >> str;
	temp = str;
	for (int i = 0; i < row - 1; i++) {
		cin >> word;
		map.insert(make_pair(word, 0));
	}
	while (1) {
		for (i = 0; i < str.length(); i++) {
			t = str.substr(0, i + 1);
			if (map.find(t) != map.end()) {
				if (flag) { start = i; flag = false; }
				str = str.substr(i + 1, str.length() - i - 1);
				d.push_back(t);
			}
			else
			{
				start += i;
			}
		}
		if (map.find(t) == map.end() && start >= str.length()) {
			str = temp;
			d.clear();
			flag = true;
		}
		else if (map.find(t) != map.end() && start >= str.length()) {
			list<string>::reverse_iterator ir;
			for (ir = d.rbegin(); ir != d.rend(); ir++) {
				cout << *ir << " ";
			}
			cout << endl;
			break;
		}
	}
}
#pragma endregion

#pragma region top k problem：找出前k大的数
void SearchTopK() {
	/*读取数据*/
	/*int a[100],i=0;
	while (cin.get()!='\n')cin >> a[i++];*/
	/*int i = 0; string str;
	getline(cin, str);
	vector<int> a;
	a.clear();
	istringstream ss(str);
	string temp;
	while (getline(ss, temp, ' ')) {
		a.push_back(stoi(temp));
	}*/
	vector<int> a; int k,t;
	while (cin >> t) {
		a.push_back(t);
		if (cin.get() == '\n')break;
	}
	cin >> k;
	if (k > a.size()) {
		cout << "error: k should be smaller than the length of array!" << endl;
		return;
	}

	/*冒泡排序，从小到大，大数向后冒*/
	/*for(int i=0;i< a.size() - 1;i++)
		for(int j=0;j<a.size()-1-i;j++)
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}*/
	/*冒泡排序找第k大的数，时间复杂度k*n*/
	/*for(int i=0;i< k;i++)
		for(int j=0;j<a.size()-1-i;j++)
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
	for (int i = a.size() - 1; i >= a.size() - k; i--)
		cout << a[i] << "  ";*/

	/*归并排序，时间复杂度n*log2(n)*/
	/*int *data = new int[a.size()];//不能使用"int data[a.size()];"定义数组，因为数组长度必须是静态常量
	memcpy(data, &a[0], a.size() * sizeof(int));//vector转数组
	int *result = new int[a.size()];
	merge_sort(data, 0,a.size()-1,result); 
	for (int i = 0; i < a.size(); ++i)
		cout << result[i] << "  ";
	cout << endl;
	for (int i = a.size() - 1; i >= a.size() - k; i--)
		cout << result[i] << "  ";*/

	/*快速排序，时间复杂度n*log2(n)*/
	int *data = new int[a.size()];//不能使用"int data[a.size()];"定义数组，因为数组长度必须是静态常量
	memcpy(data, &a[0], a.size() * sizeof(int));//vector转数组
	quick_sort(data, 0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i)
		cout << data[i] << "  ";
	cout << endl;
	for (int i = a.size() - 1; i >= a.size() - k; i--)
		cout << data[i] << "  ";
}
#pragma endregion

#pragma region rabbit problem（斐波那契数列）
/*方法一*/
/*void FibonacciSeq() {
	int n,i=2;
	int* a=0;
	cin >> n;
	if (n < 3) {
		cout << 1 << endl;
		return;
	}
	else a = new int[n];//int a[n];
	a[0] = 1, a[1] = 1;
	while (i<=n)
		a[i++] = a[i - 2] + a[i - 1];
	for (i = 0; i < n; i++)cout << a[i]<<" ";
	cout << endl;
	cout << a[n-1] << endl;
}*/
/*方法二*/
int fibonacci(int n) {
	if (n <= 2)return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
void FibonacciSeq() {
	int n, i = 2;
	cin >> n;
	if (n <= 0) {
		cout << "error" << endl;
		return;
	}
	/*int* a = 0;
	a = new int[n];//int a[n];
	for (i = 0; i < n; i++) {
		a[i] = fibonacci(n+1);
		cout << a[i] << " ";
	}
	cout << endl;*/
	cout << fibonacci(n) << endl;
}
#pragma endregion

#pragma region 增强版斐波那契数列：当前项=前4项之和
void FibonacciSeqPro() {
	int a1, a2, a3, a4, n;
	int* a = 0;
	cin >> a1 >> a2 >> a3 >> a4 >> n;
	if (n < 5)memset(a, 0, 5 * sizeof(int)); else a = new int[n + 1];//int a[n];
	a[1] = a1, a[2] = a2, a[3] = a3, a[4] = a4;
	int i = 5;
	if (n < 5) { cout << a[n] << endl; return; }
	while (i <= n)
		a[i++] = a[i - 4] + a[i - 3] + a[i - 2] + a[i - 1];
	for (i = 5; i < n; i++)cout << a[i] << " ";
	cout << a[n] << endl;
}
#pragma endregion

#pragma region 分解质因数
/*bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0) {
			cout << i << " ";
			if (isPrime(n / i))cout << n / i << " ";
			return false;
		}
	return true;
}*/
void PrimeFactorization() {
	int n,i=2,sqrt_n;
	cin >> n;

	//isPrime(n);

	cout << n << " = ";

	/*while (i<= n)
	{
		if (i == n) {
			cout << n << endl; break;
		}
		else if (n%i == 0) {
			cout << i << "*";
			n = n / i;
		}
		else
		{
			i++;
		}
	}*/

	sqrt_n = sqrt(n);
	while (i <= n)
	{
		if (i > sqrt_n) {
			cout << n << endl; break;
		}
		else if (n%i == 0) {
			cout << i << "*";
			n = n / i;
			sqrt_n = sqrt(n);
		}
		else
		{
			i++;
		}
	}
}
#pragma endregion

#pragma region 最大公约数
void GreatestCommonFactor() {
	int m,n,t;
	cin >> m >> n;
	if (m < n) { //取m为较大数
		t = m;
		m = n;
		n = t;
	}

	while (m%n!=0)
	{
		t = m;
		m = n;
		n = t % n;
	}

	cout << n << endl;
}
#pragma endregion

#pragma region 最小公倍数
void LowestCommonMultiple() {
	int m, n, m_t,n_t,t;
	cin >> m >> n;
	m_t = m, n_t = n;
	/*先求最大公约数*/
	if (m < n) { //取m为较大数
		t = m;
		m = n;
		n = t;
	}
	while (m%n != 0)
	{
		t = m;
		m = n;
		n = t % n;
	}
	/*再算最小公倍数*/
	cout << m_t * n_t / n << endl;
}
#pragma endregion

#pragma region 字符统计
void CharCount() {
	string str;
	//cin >> str;
	getline(cin,str);//cin.getline(str,100);
	/*const char* c;
	cin >> c;
	c = str.data();*/
	int i = 0, num_count = 0, character_count = 0, blank_count = 0, other_count = 0;
	while (i<str.length())
	{
		if (str[i] >= '0'&&str[i] <= '9')num_count++;
		else if ((str[i] >= 'a'&&str[i] <= 'z')|| (str[i] >= 'a'&&str[i] <= 'z'))character_count++;
		else if (str[i] ==' ')blank_count++;
		else other_count++;
		i++;
	}
	cout << num_count << " " << character_count << " " << blank_count << " " << other_count << endl;
}
#pragma endregion

#pragma region 阶乘求和：Sn=1!+2!+...+n!
int factorial(int n) {
	if (n == 1)return 1;
	else return factorial(n - 1)*n;
}
void FactorialSum() {
	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++)sum += factorial(i);
	cout << sum << endl;
}
#pragma endregion

#pragma region 整数位数统计
void DigitCount() {
	int n,k=0;
	cin >> n;
	while (n!=0)
	{
		cout << n % 10;
		n = n / 10;
		k++;
	}
	cout << endl;
	cout << k << endl;
}
#pragma endregion

#pragma region 回文数
void PalindromeNumber() {
	string n;//注意这里直接按字符读取，而不按数字读取
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n.length() / 2; i++) {
		if (n[i] != n[n.length() - 1 - i]) {
			flag = false;
			break;
		}
	}
	if (flag)cout << "n is a palindrome number. " << endl;
	else cout << "n isn't a palindrome number. " << endl;
}
#pragma endregion

#pragma region strcpy
char *strcpy(char *strDest, const char *strSrc) {
	//if (strSrc == NULL)return NULL;
	if (strDest == NULL || strSrc == NULL) return NULL;
	while (*strSrc != '\0')
		*strDest++ = *strSrc++;
	*strDest = 0;
	return strDest;
}
#pragma endregion

#pragma region 查找点e附近距离最近的k个点
bool coord_sort(const Coord &c1, const Coord &c2) {
	return c1.x*c1.x + c1.y*c1.y<c2.x*c2.x + c2.y*c2.y;
}
vector< Coord > GetNearestCoord(vector<Coord> &vec, Coord e, int k) {
	vector<Coord>::iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++) {
		itr->x = itr->x - e.x;
		itr->y = itr->y - e.y;
	}
	sort(vec.begin(), vec.end(), coord_sort);
	vector<Coord> k_vec;
	for (int i = 0; i<k; i++) {
		vec[i].x = vec[i].x + e.x;
		vec[i].y = vec[i].y + e.y;
		k_vec.push_back(vec[i]);
	}
	return k_vec;
}
#pragma endregion

#pragma region 查找单链表倒数第k个结点
ListNode *GetLastNodes(ListNode *head, int k) {
	if (head == NULL)return NULL;
	//找到尾结点，并计算链表长度
	ListNode *current = head;
	int size = 1;
	while (current->m_pNext != NULL) {
		current = current->m_pNext;
		size++;
	}
	if (size<k)return NULL;
	current = head;
	for (int i = 0; i<size - k; i++) {
		current = current->m_pNext;
	}
	return current;
}
#pragma endregion

#pragma region 找出所有重复数大于阈值的数
vector<int> StatTimes(int arrA[], int arrAsize, int cnt) {
	/*map<int, int> m;
	for (int i = 0; i<arrAsize; i++) {
		if (m.find(arrA[i]) == m.end())m.insert(make_pair(arrA[i], 1));
		else m[arrA[i]] = m.find(arrA[i])->second + 1;
	}
	vector<int> vec;
	map<int, int>::iterator itr;
	for (itr = m.begin(); itr != m.end(); itr++)
		if (itr->second>cnt)
			vec.push_back(itr->first);
	return vec;*/

	vector<int> vec;
	map<int, int> m;
	for (int i = 0; i<arrAsize; i++) {
		if (m.find(arrA[i]) == m.end())m.insert(make_pair(arrA[i], 1));
		else m[arrA[i]] = m[arrA[i]] + 1;
		if (m[arrA[i]] == cnt+1)
			vec.push_back(arrA[i]);
	}
	return vec;
}
#pragma endregion

