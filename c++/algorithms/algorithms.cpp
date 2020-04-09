// algorithms.cpp : 此文件包含各算法函数。
//

#include "algorithms.h"
#include <map>

#include "strings.h"

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

#pragma region 模式匹配
int bruteForce(string str, string pattern) {
	int i, j;
	for (i = 0; i < str.length(); i++)
	{
		for (j = 0; j < pattern.length(); j++) {
			if (str[i + j] != pattern[j])
				break;
		}
		if (j == pattern.length())
			break;
	}
	if (j == pattern.length())
		return i;
	else
		return -1;
}
int bruteForce(char *str, char *pattern) {
	int i = 0, j = 0;
	while (str[i])
	{
		while (pattern[j]) {
			if (str[i + j] != pattern[j])
				break;
			j++;
		}
		if (!pattern[j])break;
		i++, j = 0;
	}
	if (!pattern[j])
		return i;
	else
		return -1;
}
/*next数组，next[j] = k，代表j之前的字符串中有最大长度为k的相同前缀后缀，其中k<j-1*/
void next(char *pattern,int *next) {
	int length = strlen(pattern), j = 0, k = -1;//注，j、k为一前一后的同步频索引，当字符不匹配时，k回溯至next[k]
	next[0] = -1;
	while (j < length - 1) {
		if (k == -1 || pattern[j] == pattern[k]) {
			next[++j] = ++k;
			/*if (pattern[++j] == pattern[++k])
				next[j] = next[k];
			else
				next[j] = k;*/
		}
		else {
			k = next[k];
		}
	}
	for (int i = 0; i < length; i++)cout << next[i] << " ";
	cout << endl;
}
int kmp(char *str, char *pattern) {
	int i = 0, j = 0;
	int *nextArr = new int[strlen(pattern)];
	next(pattern, nextArr);
	while (str[i] && pattern[j])
	{
		if (j == -1 || str[i] == pattern[j]) {
			i++;
			j++;
		}
		else
		{
			j = nextArr[j];
		}
	}
	if (!pattern[j])
		return i - strlen(pattern);
	else
		return -1;
}
void patternMatching() {
	string str, pattern;
	cin >> str >> pattern;//abcdeabfdabde abd, abcdeabcadfabcabde abcabd
	int index;
	//index = bruteForce(str, pattern);
	char *cstr = new char[str.length()], *cpattern = new char[pattern.length()];
	strcpy(cstr, str.c_str());
	strcpy(cpattern, pattern.c_str());
	//index = bruteForce(cstr, cpattern);
	index = kmp(cstr, cpattern);
	cout << index << endl;
}
#pragma endregion

#pragma region 删除字符串中的"ab"字符
void deleteString(){
	string str;
	cin >> str;
	/*int index = str.find("ab");
	while (index != -1)
	{
		str = str.substr(0, index) + str.substr(index + 2, str.length() - 2 - index);
		index = str.find("ab");
	}*/
	char *cstr = new char[str.length()], *temp;
	strcpy(cstr, str.c_str());
	int index = bruteForce(cstr, "ab");
	while (index != -1)
	{
		temp = new char[strlen(cstr) - 2];
		strncpy(temp, cstr, index);
		strncpy(temp + index, cstr + index + 2, strlen(cstr) - 2 - index);
		temp[strlen(cstr) - 2] = 0;
		cstr = temp;
		index = bruteForce(cstr, "ab");
	}
	cout << cstr << endl;
}
#pragma endregion

#pragma region 大数的加法和乘法（a, b可能超integer和long的取值范围）
string bigNumberPlus(string a_str, string b_str) {
	/*string result;
	int digit, carry = 0;
	if (a_str.length() < b_str.length()) {
		string temp = a_str;
		a_str = b_str;
		b_str = temp;
	}
	result = string(a_str.length() + 1, 0);
	for (int i = 0; i < b_str.length(); i++) {
		digit = b_str[b_str.length() - 1 - i] + a_str[a_str.length() - 1 - i] - 2 * '0' + carry;
		if (digit >= 10) {
			result[result.length() - 1 - i] = digit - 10 + '0';
			carry = 1;
		}
		else
		{
			result[result.length() - 1 - i] = digit + '0';
			carry = 0;
		}
	}
	for (int i = b_str.length(); i < a_str.length(); i++) {
		digit = a_str[a_str.length() - 1 - i] - '0' + carry;
		if (digit >= 10) {
			result[result.length() - 1 - i] = digit - 10 + '0';
			carry = 1;
		}
		else
		{
			result[result.length() - 1 - i] = digit + '0';
			carry = 0;
		}
	}
	if (carry != 0) {
		result[0] = '1';
		return result;
	}
	else
		return result.substr(1);*/

	string result = string((a_str.length() > b_str.length() ? a_str.length() : b_str.length()) + 1, 0);
	int digit, carry = 0, i = a_str.length() - 1, j = b_str.length() - 1, k = result.length() - 1;
	while (i >=0 || j >=0)
	{
		int a_digit = i >= 0 ? a_str[i] - '0' : 0, b_digit = j >= 0 ? b_str[j] - '0' : 0;
		digit = a_digit + b_digit + carry;
		result[k] = digit % 10 + '0';
		carry = digit / 10;
		i--, j--, k--;
	}
	if (carry != 0) {
		result[0] = '1';
		return result;
	}
	else
		return result.substr(1);
}
char *bigNumberPlus(char *a_str, char *b_str) {
	int a_strlen=strlen(a_str), b_strlen = strlen(b_str);
	char *result = new char[(a_strlen > b_strlen ? a_strlen : b_strlen) + 1];
	int digit, carry = 0, i = a_strlen - 1, j = b_strlen - 1, k = a_strlen > b_strlen ? a_strlen : b_strlen;
	while (i >= 0 || j >= 0)
	{
		int a_digit = i >= 0 ? a_str[i] - '0' : 0, b_digit = j >= 0 ? b_str[j] - '0' : 0;
		digit = a_digit + b_digit + carry;
		result[k] = digit % 10 + '0';
		carry = digit / 10;
		i--, j--, k--;
	}
	if (carry != 0) {
		result[0] = '1';
		result[(a_strlen > b_strlen ? a_strlen : b_strlen) + 1] = 0;
		return result;
	}
	else {
		char *resultsub = new char[a_strlen > b_strlen ? a_strlen : b_strlen];
		strcpy(resultsub, result + 1);
		resultsub[a_strlen > b_strlen ? a_strlen : b_strlen] = 0;
		return resultsub;
	}
}
string bigNumberMultiply(string a_str, string b_str) {
	int *result = new int[a_str.length() + b_str.length()]{ 0 }, *middle_result = new int[a_str.length() + 1];
	int digit, carry = 0;
	for (int i = 0; i < b_str.length(); i++) {
		for (int j = 0; j < a_str.length(); j++) {
			digit = (a_str[a_str.length() - 1 - j] - '0')*(b_str[b_str.length() - 1 - i] - '0') + carry;
			middle_result[a_str.length() - j] = digit % 10;
			carry = digit / 10;
		}
		middle_result[0] = carry;
		/*for (int j = 0; j <= a_str.length(); j++)cout << middle_result[j];
		cout << endl;*/

		carry = 0;
		for (int j = 0; j <= a_str.length(); j++) {
			digit = result[a_str.length() + b_str.length() - 1 - i - j] + middle_result[a_str.length() - j] + carry;
			result[a_str.length() + b_str.length() - 1 - i - j] = digit % 10;
			carry = digit / 10;
		}
		/*for (int j = 0; j < a_str.length() + b_str.length(); j++)cout << result[j];
		cout << endl;*/
	}

	/*将整型数组转成字符串*/
	string result_str;
	if (result[0] != 0) {
		result_str = string(a_str.length() + b_str.length(), 0);
		for (int i = 0; i < a_str.length() + b_str.length(); i++)
			result_str[i] = result[i] + '0';
	}
	else
	{
		result_str = string(a_str.length() + b_str.length() - 1, 0);
		for (int i = 1; i < a_str.length() + b_str.length(); i++)
			result_str[i - 1] = result[i] + '0';
	}
	return result_str;
}
char *bigNumberMultiply(char *a_str, char *b_str) {
	int a_strlen = strlen(a_str), b_strlen = strlen(b_str);
	int *result = new int[a_strlen + b_strlen]{ 0 }, *middle_result = new int[a_strlen + 1];
	int digit, carry = 0;
	for (int i = 0; i < b_strlen; i++) {
		for (int j = 0; j < a_strlen; j++) {
			digit = (a_str[a_strlen - 1 - j] - '0')*(b_str[b_strlen - 1 - i] - '0') + carry;
			middle_result[a_strlen - j] = digit % 10;
			carry = digit / 10;
		}
		middle_result[0] = carry;
		/*for (int j = 0; j <= a_str.length(); j++)cout << middle_result[j];
		cout << endl;*/

		carry = 0;
		for (int j = 0; j <= a_strlen; j++) {
			digit = result[a_strlen + b_strlen - 1 - i - j] + middle_result[a_strlen - j] + carry;
			result[a_strlen + b_strlen - 1 - i - j] = digit % 10;
			carry = digit / 10;
		}
		/*for (int j = 0; j < a_str.length() + b_str.length(); j++)cout << result[j];
		cout << endl;*/
	}

	/*将整型数组转成字符串*/
	char *result_cstr;
	if (result[0] != 0) {
		result_cstr = new char[a_strlen + b_strlen];
		for (int i = 0; i < a_strlen + b_strlen; i++)
			result_cstr[i] = result[i] + '0';
		result_cstr[a_strlen + b_strlen] = 0;
	}
	else
	{
		result_cstr = new char[a_strlen + b_strlen - 1];
		for (int i = 1; i < a_strlen + b_strlen; i++)
			result_cstr[i - 1] = result[i] + '0';
		result_cstr[a_strlen + b_strlen - 1] = 0;
	}
	return result_cstr;
}
void bigNumber(){
	string a_str, b_str;
	cin >> a_str >> b_str;
	/*int a = 0, b = 0;
	for (int i = 0; i < a_str.length(); i++)
		a += pow(10, a_str.length() - 1 - i)*(a_str[i] - '0');
	for (int i = 0; i < b_str.length(); i++)
		b += pow(10, b_str.length() - 1 - i)*(b_str[i] - '0');*/
	/*int multiply = 0;
	for (int i = 0; i < a_str.length(); i++)
		for (int j = 0; j < b_str.length(); j++) {
			multiply += pow(10, a_str.length() - 1 - i)*(a_str[i] - '0')*pow(10, b_str.length() - 1 - j)*(b_str[j] - '0');
		}*/

	/*大数的加法和乘法*/
	char *a_cstr = new char[a_str.length()], *b_cstr = new char[b_str.length()];
	strcpy(a_cstr, a_str.c_str());
	strcpy(b_cstr, b_str.c_str());
	string multiply, plus;
	//plus = bigNumberPlus(a_str, b_str);
	plus = bigNumberPlus(a_cstr, b_cstr);
	cout << plus << endl;
	//multiply = bigNumberMultiply(a_str, b_str);
	multiply = bigNumberMultiply(a_cstr, b_cstr);
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
void searchTopK() {
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
	/*int *data = new int[a.size()];//不能使用"int data[a.size()];"定义数组，因为数组长度必须是静态常量
	memcpy(data, &a[0], a.size() * sizeof(int));//vector转数组
	quick_sort(data, 0, a.size() - 1);
	for (int i = 0; i < a.size(); ++i)
		cout << data[i] << "  ";
	cout << endl;
	for (int i = a.size() - 1; i >= a.size() - k; i--)
		cout << data[i] << "  ";*/

	/*堆排序*/
	//建立初始小顶堆heapArray
	int *heapArray = new int[k + 1];
	for (int i = 1; i <= k; i++) {
		heapArray[i] = a[i - 1];
		while (i > 1)
		{
			a[0] = a[i / 2];//暂存父结点
			if (a[i] > a[0])
				break;
			else {
				a[i / 2] = a[i];
				a[i] = a[0];
				i /= 2;
			}
		}
	}
	//遍历其余的n-k个数与堆顶元素比较，调整小顶堆
	for (int i = k; i < a.size(); i++) {
		if (a[i]>heapArray[1]) {
			heapArray[1] = a[i];
			//开始调整小顶堆
			int parentIndex = 1, minIndex;
			while (parentIndex <= k / 2)
			{
				heapArray[0] = heapArray[parentIndex];//暂存父结点
				if (parentIndex * 2 < k&&heapArray[parentIndex * 2] > heapArray[parentIndex * 2 + 1])
					minIndex = parentIndex * 2 + 1;
				else minIndex = parentIndex * 2;
				if (heapArray[minIndex] > heapArray[0])break;
				else {
					heapArray[parentIndex] = heapArray[minIndex];
					heapArray[minIndex] = heapArray[0];
				}
				parentIndex = minIndex;
			}
		}
	}
	for (int i = 1; i <= k; i++)
		cout << heapArray[i] << endl;
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

