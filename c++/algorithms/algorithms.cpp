// algorithms.cpp : 此文件包含各算法函数。
//

#include "algorithms.h"
#include <map>

#include "strings.h"

#pragma region 二分查找

#pragma region 无重复元素的有序数组的二分查找
/*查找某个元素的位置，不存在则返回-1。*/
int binary_search(int v, int *a, int n) {
	if (n <= 0 || a[0] > v || a[n - 1] < v)return -1;
	int left = 0, right = n - 1, middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (a[middle] > v)
			right = middle - 1;
		else if (a[middle] < v)
			left = middle + 1;
		else break;
	}
	if (left > right)return -1;
	return middle;
}
#pragma endregion

#pragma region 有重复元素的有序数组的二分查找
/*查找第一个等于某个元素的位置，不存在则返回-1。*/
int binary_search2(int v, int *a, int n) {
	if (n <= 0 || a[0] > v || a[n - 1] < v)return -1;
	int left = 0, right = n - 1, middle;
	while (left < right) {
		middle = (left + right) / 2;
		if (a[middle] < v)
			left = middle + 1;
		else
			right = middle;
	}
	if (a[left] == v)return left;
	return -1;
}
#pragma endregion

#pragma region 有重复元素的有序数组的二分查找
/*查找最后一个等于某个元素的位置，不存在则返回-1。*/
int binary_search3(int v, int *a, int n) {
	if (n <= 0 || a[0] > v || a[n - 1] < v)return -1;
	int left = 0, right = n - 1, middle;
	while (left < right) {
		middle = (left + 1 + right) / 2; // 注意，一般情况都取靠左的中点，这里因为是取最后一个满足条件的元素，所以取靠右的中点
		if (a[middle] > v)
			right = middle - 1;
		else
			left = middle;
	}
	if (a[right] == v)return right;
	return -1;
}
#pragma endregion

#pragma region 二分查找之lower_bound
/*查找第一个大于或等于某个元素的位置，不存在则返回数组长度。*/
int lower_bound(int v, int *a, int n) {
	if (a[0] > v)return 0;
	if (n <= 0 || a[n - 1] < v)return n;
	int left = 0, right = n - 1, middle, idx;
	while (left < right) {
		middle = (left + right) / 2;
		if (a[middle] >= v) {
			right = middle;
			idx = right;
		}
		else
			left = middle + 1;
	}
	return idx;
}
#pragma endregion

#pragma region 二分查找之upper_bound
/*查找第一个大于某个元素的位置，不存在则返回数组长度。*/
int upper_bound(int v, int *a, int n) {
	if (a[0] > v)return 0;
	if (n <= 0 || a[n - 1] < v)return n;
	int left = 0, right = n - 1, middle, idx;
	while (left < right) {
		middle = (left + right) / 2;
		if (a[middle] > v) {
			right = middle;
			idx = right;
		}
		else
			left = middle + 1;
	}
	return idx;
}
#pragma endregion

#pragma endregion

#pragma region 不含有重复字符的最长子串的长度（未完成）
int length_of_longest_substring(string s) {
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
int brute_force(string str, string pattern) {
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
int brute_force(char *str, char *pattern) {
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
void pattern_matching() {
	string str, pattern;
	cin >> str >> pattern;//abcdeabfdabde abd, abcdeabcadfabcabde abcabd
	int index;
	//index = brute_force(str, pattern);
	char *cstr = new char[str.length()], *cpattern = new char[pattern.length()];
	strcpy(cstr, str.c_str());
	strcpy(cpattern, pattern.c_str());
	//index = brute_force(cstr, cpattern);
	index = kmp(cstr, cpattern);
	cout << index << endl;
}
#pragma endregion

#pragma region 删除字符串中的"ab"字符
void delete_string(){
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
	int index = brute_force(cstr, "ab");
	while (index != -1)
	{
		temp = new char[strlen(cstr) - 2];
		strncpy(temp, cstr, index);
		strncpy(temp + index, cstr + index + 2, strlen(cstr) - 2 - index);
		temp[strlen(cstr) - 2] = 0;
		cstr = temp;
		index = brute_force(cstr, "ab");
	}
	cout << cstr << endl;
}
#pragma endregion

#pragma region 大数的加法和乘法（a, b可能超integer和long的取值范围）
string bignumber_plus(string a_str, string b_str) {
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
char *bignumber_plus(char *a_str, char *b_str) {
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
string bignumber_multiply(string a_str, string b_str) {
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
char *bignumber_multiply(char *a_str, char *b_str) {
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
void bignumber(){
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
	//plus = bignumber_plus(a_str, b_str);
	plus = bignumber_plus(a_cstr, b_cstr);
	cout << plus << endl;
	//multiply = bignumber_multiply(a_str, b_str);
	multiply = bignumber_multiply(a_cstr, b_cstr);
	cout << multiply << endl;
}
#pragma endregion

#pragma region 单词拆分（未完成）https://leetcode-cn.com/problems/word-break-ii/
void word_break(){
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

#pragma region top k problem（找出前k大的数）
void print_heap(int *a, int k) {
	int l = log2(k) + 1;
	int p, q;
	for (int i = 0; i < l - 1; i++) {
		p = i ? 2 << (i - 1) : 1;
		q = 1 << i;
		for (int i = p; i < p + q; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	q = 1 << (l - 1);
	for (int i = q; i <= k; i++)
		cout << a[i] << " ";
	cout << endl;
}
void print_heap2(int *a, int k) {
	int l = log2(k) + 1, b = 3 * (1 << (l - 2));
	int p, q;
	for (int i = 1; i < b; i++)
		cout << " ";
	cout << a[1] << endl;
	for (int i = 1; i < l - 1; i++) {
		p = i ? 2 << (i - 1) : 1;
		q = 1 << i;
		b = 3 * (1 << (l - i - 2));
		for (int i = 1; i < b+1; i++)
			cout << " ";
		for (int i = p; i < p + q; i++) {
			if(!(i%2))
				cout << "/";
			else
				cout << "\\";
			for (int i = 1; i < b*2-1; i++)
				cout << " ";
		}
		cout << endl;
		for (int i = 1; i < b; i++)
			cout << " ";
		for (int i = p; i < p + q; i++) {
			cout << a[i];
			for (int i = 1; i < b*2+1; i++)
				cout << " ";
		}
		cout << endl;
	}
	q = 1 << (l - 1);
	b = 3;
	cout << " ";
	for (int i = q; i <= k; i++) {
		if (!(i % 2)) {
			cout << "/";
			for (int i = 1; i < b; i++)
				cout << " ";
		} else {
			cout << "\\";
			for (int i = 1; i < b+2; i++)
				cout << " ";
		}
	}
	cout << endl;
	for (int i = q; i <= k; i++) {
		cout << a[i];
		for (int i = 1; i < b; i++)
			cout << " ";
	}
	cout << endl;
}
void search_top_k() {
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
	/*vector<int> a; int k,t;
	while (cin >> t) {
		a.push_back(t);
		if (cin.get() == '\n')break;
	}
	cin >> k;
	if (k > a.size()) {
		cout << "error: k should be smaller than the length of array!" << endl;
		return;
	}
	int n = a.size();*/
	int a[13]{ 3,2,5,13,7,9,17,12,8,11,19,1,6 }, n = 13, k = 6;

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

	/*堆排序（复杂度n*logk）*/
	//建立初始小顶堆heapArray
	int *heapArray = new int[k + 1], j;
	for (int i = 1; i <= k; i++) {
		heapArray[i] = a[i - 1];
		j = i;
		while (j > 1) // 上浮调整
		{
			heapArray[0] = heapArray[j / 2]; // 暂存父结点
			if (heapArray[j] > heapArray[0]) {
				//print_heap2(heapArray, i);
				break;
			}
			else {
				heapArray[j / 2] = heapArray[j];
				heapArray[j] = heapArray[0];
				j /= 2;
				//print_heap2(heapArray, i);
			}
		}
	}
	cout << "init heap: " << endl;
	print_heap2(heapArray, k);

	//遍历其余的n-k个数与堆顶元素比较，调整小顶堆
	for (int i = k; i < n; i++) {
		if (a[i] > heapArray[1]) {
			heapArray[1] = a[i]; // 剔除原小顶堆最小数
			// 开始调整小顶堆（下沉调整）
			int parentIndex = 1, minIndex;
			while (parentIndex <= k / 2)
			{
				heapArray[0] = heapArray[parentIndex]; // 暂存父结点
				if (parentIndex * 2 < k&&heapArray[parentIndex * 2] > heapArray[parentIndex * 2 + 1])
					minIndex = parentIndex * 2 + 1;
				else minIndex = parentIndex * 2;
				if (heapArray[minIndex] > heapArray[0])break;
				else { // 交换父子结点
					heapArray[parentIndex] = heapArray[minIndex];
					heapArray[minIndex] = heapArray[0];
				}
				parentIndex = minIndex;
			}
		}
		cout << "compare " << a[i] << ": " << endl;
		print_heap2(heapArray, k);
	}
}
#pragma endregion

#pragma region rabbit problem（斐波那契数列）
/*方法一*/
/*void fibonacci_seq() {
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
void fibonacci_seq() {
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
void fibonacci_seq_pro() {
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
/*bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0) {
			cout << i << " ";
			if (is_prime(n / i))cout << n / i << " ";
			return false;
		}
	return true;
}*/
void prime_factorization() {
	int n,i=2,sqrt_n;
	cin >> n;

	//is_prime(n);

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
void greatest_common_factor() {
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
void lowest_common_multiple() {
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
void char_count() {
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
void factorial_sum() {
	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++)sum += factorial(i);
	cout << sum << endl;
}
#pragma endregion

#pragma region 整数位数统计
void digit_count() {
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
void palindrome_number() {
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

#pragma region 腾讯笔试

#pragma region strcpy
/*char *strcpy(char *strDest, const char *strSrc) {
	//if (strSrc == NULL)return NULL;
	if (strDest == NULL || strSrc == NULL) return NULL;
	while (*strSrc != '\0')
		*strDest++ = *strSrc++;
	*strDest = 0;
	return strDest;
}*/
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

#pragma endregion

#pragma region 统计x的二进制数中1的个数
int count1ofx(int x)
{
	int countx = 0;

	while (x)
	{
		countx++;
		x = x&(x - 1);
	}

	return countx;
}
#pragma endregion

#pragma region 图的深度优先遍历（有向图，权值为正表示有指向，为零表示无指向），a为邻接矩阵，b为结点是否访问的标志，idx表示当前位置
void dfs(int **a, int *b, int n, int idx)
{
	int i;
	for (i = 0; i < n; i++)
		if (*(b + i) == 0)
			break;
	if (i == n) {//如果已经过所有结点，则返回
		cout << "end" << endl;
		return;
	}

	for (i = 0; i < n; i++) {
		/*cout << "i: " << i << endl;
		cout << "b[" << i << "]: " << *(b + i) << endl;*/
		if (*(b + i) == 1 || i == idx)
			continue;
		if (*(*a + i) > 0) {
			cout << *(*(a + idx) + i) << endl;

			*(b + i) = 1;
			dfs(a, b, n, i);
			*(b + i) = 0;
		}
	}

	return;
}
#pragma endregion

#pragma region 最短路径（有向带权图）
/*
题意
给定n个结点的邻接矩阵，求各结点间的最短路径。

输入
第一行给定整数n。
接下来n行，每行有n个整数。

输出
最短路径*/
/*
print array step of 1: //初始邻接矩阵
0     2     6     4
∞     0     3     ∞
7     ∞     0     1
5     ∞    12     0
print array step of 1: //并入1号结点的结果
0     2     6     4
∞     0     3     ∞
7     9     0     1
5     7    11     0

print array step of 2: //并入2号结点的结果
0     2     5     4
∞     0     3     ∞
7     9     0     1
5     7    10     0

print array step of 3: //并入3号结点的结果
0     2     5     4
10     0     3     4
7     9     0     1
5     7    10     0

print array step of 4: //并入4号结点（图最终两两结点之间的最短路径值）
0     2     5     4
9     0     3     4
6     8     0     1
5     7    10     0*/
/*弗洛伊德算法（floyd algorithm）*/
void floyd(int **a, int n, int **d, int **p) {
	//初始化最短路径矩阵d、最短路径中转点矩阵p
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			d[i][j] = a[i][j];
			p[i][j] = j;
		}

	//算法核心代码
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}

	//打印最短路径矩阵d、最短路径中转点矩阵p
	for (int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cout << "minimum distance of from " << i << " to " << j << ": " << d[i][j] << "; path: " << i << "->";
			int itrmdt = p[i][j];
			while (itrmdt != j) {
				cout << itrmdt << "->";
				itrmdt = p[itrmdt][j];
			}
			cout << j << endl;
		}
}

/*迪杰斯特拉算法（dijkstra algorithm），求解单源最短路径。虽然是贪心算法，但是结果是单源最短路径的全局最优解*/
void dijkstra(int **a, int n, int origin, int *d, int *v, int *p) {
	/*初始化最短距离数组d，d[i]表示起点到i点的最短距离，初始值为a[origin][i]
	 *访问标志数组v（访问标志数组v中，值为1的属于集合S，值为0的属于集合Q）
	 *路径数组p，记录最短路径*/
	for (int i = 0; i < n; i++)
		d[i] = a[origin][i];
	v[origin] = 1;
	for (int i = 0; i < n; i++)
		if (i != origin)v[i] = 0;
	for (int i = 0; i < n; i++) {
		if (a[origin][i] < 999)p[i] = origin;
		else p[i] = -1;
	}

	//遍历n-1次，每次在集合Q中找到最短路径的点
	int min, minidx;
	for (int i = 1; i < n; i++) {
		//第一步，在集合Q中找到最短路径的点minidx
		min = 999;
		for (int j = 0; j < n; j++)
			if (!v[j] && d[j] < min) {
				min = d[j];
				minidx = j;
			}
		v[minidx] = 1;//点minidx加入集合S

		//第二步，更新起点到集合Q中结点的最短距离d[j]（实际上只更新与点minidx直连的点的距离）
		for (int j = 0; j < n; j++)
			if (!v[j] && d[j] > a[minidx][j] + min) {
				d[j] = a[minidx][j] + min;
				p[j] = minidx;
			}
	}

	// 打印最短距离数组d、最短路径数组p
	for (int i = 0; i < n; i++)
		if (i != origin) {
			/*cout << "minimum distance of from " << origin << " to " << i << ": " << d[i] << "; path: ";
			if (p[i] != -1)
			{
				cout << i << "<-";
				int itrmdt = p[i];
				while (itrmdt != origin) {
					cout << itrmdt << "<-";
					itrmdt = p[itrmdt];
				}
				cout << origin;
			}
			cout << endl;*/

			cout << "minimum distance of from " << origin << " to " << i << ": " << d[i] << "; path: ";
			char *path = "", *node = new char[20];
			if (p[i] != -1)
			{
				sprintf(node, "%d", i);
				path = string_concat({ path, node, ">-" });
				int itrmdt = p[i];
				while (itrmdt != origin) {
					sprintf(node, "%d", itrmdt);
					path = string_concat({ path, node, ">-" });
					itrmdt = p[itrmdt];
				}
				sprintf(node, "%d", origin);
				path = string_concat({ path, node });
				strrev(path);//字符串反转
			}
			cout << path << endl;
		}
}
#pragma endregion

#pragma region 最短哈密尔顿回路（旅行商问题，无向带权图）
/*
题意
给定n个结点的邻接矩阵，已知起点，求一条经过图中所有点且边权和最小的回路。
（背景：一个售货员必须访问n个城市，恰好访问每个城市一次，并最终回到出发城市。
售货员从城市i到城市j的旅行费用是一个整数，旅行所需的全部费用是他旅行经过的的各边费用之和，而售货员希望使整个旅行费用最低。）

输入
第一行给定整数n。
接下来n行，每行有n个整数。

输出
最短路径及回路*/
/*动态规划
 *假定起点为城市0，dp[i][j]表示从城市i经过集合j中的每一个城市，再回到城市0的最优解。回路距离d=a[i][0]+dp[i][j]。
 *注：因为要和a[][]的索引对应，dp[][]第1行保留不用，即城市0的这一行不用
 *集合j表示城市1~城市n的随机组合，例如，除城市0外有5个城市，那么j=0b11111表示城市1~城市5的集合，j=0b00001表示城市1的集合，j=0b00010表示城市2的集合。
 *集合j不包含城市0和城市i，j=0表示集合j为空集。如果集合j为空集，那么从城市i经过集合j回到城市0的最优解就是城市i到城市0的直线距离，即j=0，dp[i][0]=a[i][0]
 *状态转移方程dp[i][j] = a[i][k] + dp[k][j ^ (1 << (k - 1))];
 */
void tsp(int **a, int n) {
	int m = 2 << (n - 1); // n表示一共有n+1个城市，除城市0外有n个城市

	// 初始化状态表示数组，集合j为空集，即j=0，dp[i][0]=a[i][0]
	int **dp = new int*[n + 1];
	for (int i = 1; i <= n; i++) {
		dp[i] = new int[m];
		dp[i][0] = a[i][0];
	}

	/*更新状态表示数组dp。回路距离d=a[i][0]+dp[i][j]
	 *更新顺序（全局最优）：
	 *j=1, 0->2->[1]->0
	       0->3->[1]->0
	       0->4->[1]->0
	       0->5->[1]->0
	 *j=2, 0->1->[2]->0
	       0->3->[2]->0
	       0->4->[2]->0
	       0->5->[2]->0
	 *j=3, 0->3->[1,2]->0, 依赖子问题3->1->[2]->0和3->2->[1]->0
	       0->4->[1,2]->0, 依赖子问题4->1->[2]->0和4->2->[1]->0
	       0->5->[1,2]->0, 依赖子问题5->1->[2]->0和5->2->[1]->0
	 *j=4, 0->1->[3]->0
	       0->2->[3]->0
	       0->4->[3]->0
	       0->5->[3]->0
	 *j=5, 0->2->[1,3]->0, 依赖子问题2->1->[3]->0和2->3->[1]->0
	       0->4->[1,3]->0, 依赖子问题4->1->[3]->0和4->3->[1]->0
	       0->5->[1,3]->0, 依赖子问题5->1->[3]->0和5->3->[1]->0
	 *j=6, 0->1->[2,3]->0, 依赖子问题1->2->[3]->0和1->3->[2]->0
	       0->4->[2,3]->0, 依赖子问题4->2->[3]->0和4->3->[2]->0
	       0->5->[2,3]->0, 依赖子问题5->2->[3]->0和5->3->[2]->0
	 *j=7, 0->4->[1,2,3]->0, 依赖子问题4->1->[2,3]->0、4->2->[1,3]->0和4->3->[1,2]->0
	       0->5->[1,2,3]->0, 依赖子问题5->1->[2,3]->0、5->2->[1,3]->0和5->3->[1,2]->0
	 *…
	 *j=31, …*/
	for (int j = 1; j < m; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = 999;
			if (((j >> (i - 1)) & 1)) { // 集合j不应包含城市i
				continue;
			}
			for (int k = 1; k <= n; k++) { // 分解为子问题：从城市i先到集合中的城市k，再经过不包含城市k的集合城市，最后回到城市0
				if (!((j >> (k - 1)) & 1)) { // 集合j应包含城市k
					continue;
				}
				if (i == 1 && j == 30)
					cout << endl;
				if (i == 2 && j == 28)
					cout << endl;
				if (i == 3 && j == 24)
					cout << endl;
				if (dp[i][j] > a[i][k] + dp[k][j ^ (1 << (k - 1))]) { // j ^ (1 << (k - 1))表示不包含城市k的集合城市
					dp[i][j] = a[i][k] + dp[k][j ^ (1 << (k - 1))];
				}
			}
		}
	}

	// 最优路径
	vector<int> path; // 最优路径链表
	int d = 999, *v = new int[n + 1]{ 0 }, finished = 0, j = (2 << (n - 1)) - 1, origin = 0, temp; // 最优距离d，访问标志数组v，集合j初始化为0b11…1，起始点origin=0
	path.push_back(origin);
	v[origin] = 1;
	while (!finished){
		for (int i = 1; i <= n; i++) {
			if (!v[i] && ((j >> (i - 1)) & 1)) { // 集合j应包含城市i
				if (d > a[i][origin] + dp[i][(j ^ (1 << (i - 1)))]) {
					d = a[i][origin] + dp[i][(j ^ (1 << (i - 1)))];
					temp = i;
				}
			}
		}
		origin = temp;
		path.push_back(origin); // 到达新起始点
		v[origin] = 1;
		j ^= (1 << (origin - 1)); // 集合j剔除城市origin
		d = 999;

		finished = 1;
		for (int i = 1; i <= n; i++)
			finished &= v[i];
	}

	cout << "best travel path around " << (n + 1) << " cities where start from 0 and back to 0" << ": ";
	d = 0;
	std::vector<int>::iterator itr;
	for (itr = path.begin(); itr != path.end(); itr++) {
		cout << *itr << "->";
		if (itr + 1 != path.end())
			d += a[*itr][*(itr + 1)];
	}
	cout << "0" << endl;
	d += a[*(itr - 1)][0];
	cout << "min distance from " << 0 << " to " << (n - 1) << ": " << d << endl;
}
#pragma endregion

#pragma region 回路（未完成）
/*
题目来源牛客网，链接https://www.nowcoder.com/practice/2a5153a6d2bd43949764c068b4f29d26?tpId=110&&tqId=33506&rp=1&ru=/activity/oj&qru=/ta/job-code/question-ranking
题意
牛牛在一个迷宫中，迷宫有n个格子，有m条通道，每条通道连接两个格子，<u,v>表示编号为u的格子与编号为v的格子可互相到达，每人每条通道只能走一次。
牛牛想知道，他是否能从1号格子出发回到1号格子。

输入
第一行给定两个整数n,m。
接下来m行，每行有两个整数u,v。
m对u, v互不相同

输出
若能回到1号格子则返回Yes，否则返回No。*/
bool circuit_dfs(int **a, int **pathb, int *b, int n, int idx)
{
	int i;
	for (i = 0; i < n; i++)
		if (*(b + i) == 0)
			break;
	if (*b) // 如果已经回原点，返回true
		return true;
	else if (i == n && !*b) // 如果已经过所有结点且没回原点，则返回false
		return false;

	for (i = 0; i < n; i++) {
		if (*(b + i) == 1 || i == idx)
			continue;
		if (*(*(a + idx) + i) && !*(*(pathb + idx) + i)) {
			*(*(pathb + idx) + i) = 1;
			*(b + i) = 1;
			if (circuit_dfs(a, pathb, b, n, i))
				return true;
			*(*(pathb + idx) + i) = 0;
			*(b + i) = 0;
		}
	}

	return false;
}
/**
* 能回到1号点返回 Yes，否则返回 No
* @param param int整型vector param[0] 为 n，param[1] 为 m
* @param edge Point类vector Point.x , Point.y 分别为一条边的两个点
* @return string字符串
*/
string circuit(vector<int>& param, vector<Point>& edge) {
	int n = param[0], m = param[1], i, j;
	int **map = new int*[n], **pathb = new int*[n], *b = new int[n] {0};
	for (i = 0; i < n; i++) {
		map[i] = new int[n] {0};
		pathb[i] = new int[n] {0};
	}
	for (i = 0; i < m; i++)
		map[edge[i].x-1][edge[i].y-1] = map[edge[i].y-1][edge[i].x-1] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cout << map[i][j] << endl;
	j = *(*(map + 2) + 3);
	j = map[2][3];
	for (i = 1; i < n; i++)
		if (*(*map + i)) {
			*(*pathb + i) = 1;
			if(circuit_dfs(map, pathb, b, n, i))
				return "Yes";
			*(*pathb + i) = 0;
		}
	return "No";
}
#pragma endregion

#pragma region 算术编解码
/*函数功能：浮点算术编码
 *参数说明：
 */
void compress(float &out, char *in, int size, char *charset, float *charset_prob, int charset_size) {
	int i, j;
	float low = 0, range = 1, *cdf = new float[charset_size + 1]{ 0 };

	/*根据概率密度函数得到概率分布函数*/
	for (i = 1; i <= charset_size; i++)
		cdf[i] = cdf[i - 1] + charset_prob[i - 1];

	for (i = 0; i < size; i++) {
		for (j = 0; j < charset_size; j++) {
			if (in[i] == charset[j]) {
				low = low + range * cdf[j];
				range *= charset_prob[j];
				break;
			}
		}
	}

	out = low;
}

/*函数功能：浮点算术解码
 *参数说明：
 */
void uncompress(char *&out, float in, int size, char *charset, float *charset_prob, int charset_size) {
	int i, j;
	float low = 0, range = 1, *cdf = new float[charset_size + 1]{ 0 };

	/*根据概率密度函数得到概率分布函数*/
	for (i = 1; i <= charset_size; i++)
		cdf[i] = cdf[i - 1] + charset_prob[i - 1];

	for (i = 0; i < size; i++) {
		for (j = 0; j < charset_size; j++) {
			if (in < low + range * cdf[j + 1]) {
				out[i] = charset[j];
				low = low + range * cdf[j];
				range *= charset_prob[j];
				break;
			}
		}
	}
}

/*函数功能：定点算术编码，即二进制算术编码（存在精度问题，待优化）
 *参数说明：prob表示0的概率，1-prob则为1的概率，p是在range = 256范围下的概率
 |---0---|------1-----|
 |--prob-|---1-prob---|
 */
void compress(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, uint8_t p) {
	int i = 0, j = 0, byteIdx, bitIdx;
	uint8_t bit, low = 0;
	uint16_t range = 0x0100;

	while (i < in_bit_count && j < out_bit_count) {
		byteIdx = i / 8;
		bitIdx = i % 8;
		bit = *(in + byteIdx) >> (7 - bitIdx) & 1;
		if (bit == 1) {
			low = low + (range * p - 1) / 256 + 1; //ceil(n/m)=(n-1)/m+1，即除法的向上取整
			range = range - (range * p - 1) / 256 - 1;
		}
		else
			range = range * p / 256;

		/*放大range并输出二进制码*/
		while (range < 128) {
			byteIdx = j / 8;
			bitIdx = j % 8;
			*(out + byteIdx) &= ~(1 << (7 - bitIdx)); //指定位清零
			if (low + range < 128) { //赋0输出
				low <<= 1;
				range <<= 1;
			}
			else if (low >= 128) {
				*(out + byteIdx) |= (1 << (7 - bitIdx)); //赋1输出
				low -= 128;
				low <<= 1;
				range <<= 1;
			}
			else
				break;
			++j;
		}
		++i;
	}
}

/*函数功能：定点算术编码，即二进制算术编码（采用low=low+range*prob+1更新式，正确性待验证）
 *参数说明：prob表示0的概率，1-prob则为1的概率
 |---0---|------1-----|
 |--prob-|---1-prob---|
*/
void compress2(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, float prob) {
	int i = 0, j = 0, byteIdx, bitIdx;
	uint8_t bit, low = 0;
	uint16_t range = 0x0100;

	while (i < in_bit_count && j < out_bit_count) {
		byteIdx = i / 8;
		bitIdx = i % 8;
		bit = *(in + byteIdx) >> (7 - bitIdx) & 1;
		if (bit == 1) {
			low = low + range * prob + 1;
			range *= (1 - prob);
		}
		else
			range *= prob;

		/*放大range并输出二进制码*/
		while (range < 128) {
			byteIdx = j / 8;
			bitIdx = j % 8;
			*(out + byteIdx) &= ~(1 << (7 - bitIdx)); //指定位清零
			if (low + range < 128) { //赋0输出
				low <<= 1;
				range <<= 1;
			}
			else if (low >= 128) {
				*(out + byteIdx) |= (1 << (7 - bitIdx)); //赋1输出
				low -= 128;
				low <<= 1;
				range <<= 1;
			}
			else
				break;
			++j;
		}
		++i;
	}
}

/*函数功能：定点算术解码
 *参数说明：
 *备    注：未完成
*/
void uncompress(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, uint8_t p) {
	
}

int compress_uncompress_test() {
    #pragma region 浮点算术编码
	char *charset, *in, *uncompress_out;
	int charset_size, size, i, j; //size为待编码字符串in的长度
	float *charset_prob, compress_out;

	/*读取字符集及对应的概率密度*/
	/*scanf("%d", &charset_size);
	getchar();
	charset = new char[charset_size], charset_prob = new float[charset_size];
	for (i = 0; i < charset_size; i++) {
	scanf("%c", &charset[i]); //换行结束读取
	scanf("%f", &charset_prob[i]);
	getchar();
	}*/
	charset_size = 2;
	charset = new char[charset_size] {'0', '1'};
	charset_prob = new float[charset_size] {0.2f, 0.8f};
	for (i = 0; i < charset_size; i++) {
		printf("%c ", charset[i]);
		printf("%.4f\n", charset_prob[i]); //以小数点后四位打印显示
	}

	/*读取待编码字符串*/
	/*in = (char*)malloc(4096); //待编码字符串长度限制4096
	scanf("%s", in);
	size = strlen(in);*/
	in = new char[32]{ '0','0','1','0','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','0','0','1','0','1','1','0' };
	//in = "‭00101111111010111111111110010110‬";
	size = 32;

	/*浮点算术编码*/
	compress(compress_out, in, size, charset, charset_prob, charset_size);
	printf("%.10f\n", compress_out);

	/*浮点算术解码*/
	uncompress_out = new char[size];
	uncompress(uncompress_out, compress_out, size, charset, charset_prob, charset_size);
	printf("%s\n", uncompress_out);
    #pragma endregion

    #pragma region 定点算术编码
	uint8_t *inbits, *outbits, prob;
	int32_t in_bit_count = 32, out_bit_count = 16, in_size, out_size;
	in_size = (in_bit_count - 1) / 8 + 1, out_size = (out_bit_count - 1) / 8 + 1; //ceil(n/m)=(n-1)/m+1，即除法的向上取整
	inbits = new uint8_t[in_size]{ 0x2f, 0xeb, 0xff, 0x96 };
	outbits = new uint8_t[out_size];
	compress(outbits, out_bit_count, inbits, in_bit_count, 0x33); //256*0.2=0d51=0b00110011=0x33, 0.2(十进制)=.‭00110011(二进制)‬
	//compress2(outbits, out_bit_count, inbits, in_bit_count, 0.2);

	//以二进制形式打印输出显示
	uint8_t *out_print = new uint8_t[out_bit_count];
	for (i = 0; i < out_size; i++) {
		for (int j = 0; 8 * i + j < out_bit_count; j++)
			out_print[i * 8 + j] = outbits[i] & 1 << (7 - j) ? '1' : '0';
	}
	i = 0;
	while (i < out_bit_count) {
		cout << out_print[i];
		++i;
	}
    #pragma endregion

	return 0;
}
#pragma endregion

#pragma region 金额大写转化
void money2capital(string &out, double money) {
	long long money_integer = floor(money);
	int money_decimal = floor((money - money_integer) * 100); // 精确到分
	int money_integer_array[64], length, i = 0, j = 0;
	string number_map[]{ "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" }, integer_unit_map[]{ "元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟", "万亿", "拾", "佰", "仟" }, decimal_unit_map[]{ "整", "角", "分", "厘" };
	//整数部分
	money_integer_array[0] = money_integer % 10;
	money_integer = money_integer / 10;
	while (money_integer) {
		money_integer_array[++i] = money_integer % 10;
		money_integer = money_integer / 10;
	}
	length = i + 1;
	for (i = length - 1; i >= 0; i--) {
		if (!money_integer_array[i]) {
			if (i == 8 || i == 4 || i == 0)
				out += integer_unit_map[i];
			/*else if(amountIntegerArr[i-1])
			out += number_map[0];*/
			if (i&&money_integer_array[i - 1])
				out += number_map[0];
		}
		else {
			out += number_map[money_integer_array[i]] + integer_unit_map[i];
		}
	}
	//小数部分
	if (money_decimal) {
		int jiao = money_decimal / 10;
		int fen = money_decimal % 10;
		if (fen) {
			if (jiao) out += number_map[jiao] + decimal_unit_map[1] + number_map[fen] + decimal_unit_map[2];
			else out += number_map[0] + number_map[fen] + decimal_unit_map[2];
		}
		else out += number_map[jiao] + decimal_unit_map[1];
	}
	else out += decimal_unit_map[money_decimal];
}
#pragma endregion

#pragma region 0-1背包
void knapsack() {
	int m, n, *w, *v; // m表示背包容量，n表示n件物品，*w表示n件物品对应的重量，*v表示n件物品对应的价值
	/*cin >> m >> n;
	w = new int[n], v = new int[n];
	int **f = new int*[n]; // **f是状态表示数组，f[i+1][j]表示放入第i个物品时，背包容量为j的物品最大价值。注意第一行是初始化为0
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
		f[i] = new int[m + 1] {0};
	}*/
	m = 5, n = 3, w = new int[n] {1, 2, 3}, v = new int[n] {6, 10, 12};
	int f[4][6]{ 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (w[i] > j)
				f[i + 1][j] = f[i][j]; // 放不了第i件物品，所以f的当前解等于前一状态解
			else
				f[i + 1][j] = f[i][j - w[i]] + v[i] > f[i][j] ? f[i][j - w[i]] + v[i] : f[i][j];

			cout << f[i + 1][j] << " ";
		}
		cout << endl;
	}
	cout << "result: " << f[n][m];
}
#pragma endregion

#pragma region 仓库问题（美团笔试，未完成）
void warehouse(){
	/*int n, *w, *a, left = 0, right, leftw, rightw;
	cin >> n;
	w = new int[n], a = new int[n], right = n - 1;
	for (int i = 0; i<n; i++) {
	cin >> w[i];
	}
	for (int i = 0; i<n; i++) {
	cin >> a[i];
	}*/
	int n = 5, w[5]{ 3,2,4,4,5 }, a[5]{ 4,3,5,2,1 }, left = 0, right = 4, leftw, rightw, max = 0;

	for (int i = 0; i<n; i++) {
		leftw = 0, rightw = 0;
		for (int j = left; j<a[i] - 1; j++)
			leftw += w[j];
		for (int j = a[i]; j <= right; j++)
			rightw += w[j];
		if (leftw>rightw) {
			max = max > leftw ? max : leftw;
			right = a[i] - 2;
		}
		else {
			max = max > leftw ? max : leftw;
			left = a[i];
		}
		cout << max << endl;
	}
}
#pragma endregion

#pragma region 深信服笔试

#pragma region 查找两个字符串中那个有差别的字符
/*说明：有两个字符串str1、str2，str2是由str1随机打乱后组合的，但是比str1多一个字符或少一个字符，查找那个字符*/
string find_diff_char(string str1, string str2) {
	// write code here
	string a, b;
	int length1 = str1.length(), length2 = str2.length(), length;
	if (length1 > length2) {
		a = str1;
		b = str2;
		length = length1;
	}
	else
	{
		a = str2;
		b = str1;
		length = length2;
	}
	int *v = new int[length] {0};
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length; j++) {
			if (!v[j] && b[i] == a[j]) {
				v[j] = 1;
				break;
			}
		}
	}
	string result;
	for (int i = 0; i < length; i++) {
		cout << v[i] << endl;
		if (!v[i]) {
			cout << a[i] << endl;
			result = a[i];
		}
	}
	return result;
}
#pragma endregion

#pragma region 查找公共子串
string find_common_char(string str1, string str2) {
	string a, b;
	int length1 = str1.length(), length2 = str2.length(), len1, len2;
	if (length1 < length2) {
		a = str1;
		b = str2;
		len1 = length1;
		len2 = length2;
	}
	else
	{
		a = str2;
		b = str1;
		len1 = length2;
		len2 = length1;
	}
	int *v = new int[len1] {0};
	for (int i = 0; i < len2; i++) {
		for (int j = 0; j < len1; j++) {
			if (!v[j] && b[i] == a[j]) {
				v[j] = 1;
				break;
			}
		}
	}
	string result;
	for (int i = 0; i < len1; i++) {
		cout << v[i] << endl;
		if (v[i])result += a[i];
	}
	return result;
}
string common_chars(string* chars, int charsLen) {
	// write code here
	string a, b;
	a = chars[0];
	for (int i = 1; i < charsLen; i++) {
		b = chars[i];
		a = find_common_char(a, b);
	}
	int length = a.length();
	char temp;
	for (int i = length - 1; i >= 0; i--)
		for (int j = 0; j<i; j++)
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	return a;
}
#pragma endregion

#pragma endregion
