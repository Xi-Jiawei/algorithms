#pragma once
// algorithms.h : 此文件自定义算法函数头文件，区别于STL库“algorithm”。
//

#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "sort.h"

using namespace std;

#pragma region 二分查找

#pragma region 无重复元素的有序数组的二分查找
/*查找某个元素的位置，不存在则返回-1。*/
int binary_search(int v, int *a, int n);
#pragma endregion

#pragma region 有重复元素的有序数组的二分查找
/*查找第一个等于某个元素的位置，不存在则返回-1。*/
int binary_search2(int v, int *a, int n);
#pragma endregion

#pragma region 有重复元素的有序数组的二分查找
/*查找最后一个等于某个元素的位置，不存在则返回-1。*/
int binary_search3(int v, int *a, int n);
#pragma endregion

#pragma region 二分查找之lower_bound
/*查找第一个大于或等于某个元素的位置，不存在则返回数组长度。*/
int lower_bound(int v, int *a, int n);
#pragma endregion

#pragma region 二分查找之upper_bound
/*查找第一个大于某个元素的位置，不存在则返回数组长度。*/
int upper_bound(int v, int *a, int n);
#pragma endregion

#pragma endregion

#pragma region 不含有重复字符的最长子串的长度（未完成）
int length_of_longest_substring(string s);
#pragma endregion

#pragma region 模式匹配
void pattern_matching();
#pragma endregion

#pragma region 删除字符串中的"ab"字符
void delete_string();
#pragma endregion

#pragma region 大数的加法和乘法（a, b可能超integer和long的取值范围）
void bignumber();
#pragma endregion

#pragma region 单词拆分（未完成）https://leetcode-cn.com/problems/word-break-ii/
void word_break();
#pragma endregion

#pragma region top k problem（找出前k大的数）
void search_top_k();
#pragma endregion

#pragma region rabbit problem（斐波那契数列）
void fibonacci_seq();
#pragma endregion

#pragma region 增强版斐波那契数列：当前项=前4项之和
void fibonacci_seq_pro();
#pragma endregion

#pragma region 分解质因数
void prime_factorization();
#pragma endregion

#pragma region 最大公约数
void greatest_common_factor();
#pragma endregion

#pragma region 最小公倍数
void lowest_common_multiple();
#pragma endregion

#pragma region 字符统计
void char_count();
#pragma endregion

#pragma region 阶乘求和：Sn=1!+2!+...+n!
void factorial_sum();
#pragma endregion

#pragma region 整数位数统计
void digit_count();
#pragma endregion

#pragma region 回文数
void palindrome_number();
#pragma endregion

#pragma region 腾讯笔试

#pragma region strcpy
char *strcpy(char *strDest, const char *strSrc);
#pragma endregion

#pragma region 查找点e附近距离最近的k个点
struct Coord {
	int x;
	int y;
};
bool coord_sort(const Coord &c1, const Coord &c2);
vector< Coord > GetNearestCoord(vector<Coord> &vec, Coord e, int k);
#pragma endregion

#pragma region 查找单链表倒数第k个结点
struct ListNode
{
	int m_nkey;
	ListNode *m_pNext;
};
ListNode *GetLastNodes(ListNode *head, int k);
#pragma endregion

#pragma region 找出所有重复数大于阈值的数
vector<int> StatTimes(int arrA[], int arrAsize, int cnt);
#pragma endregion

#pragma region 文件读及hash_map的查找
struct Member {
	string name;
	int departID;
	int centerID;

	bool Member::operator ==(const string &name) {
		return this->name == name;
	}
};
class Staff {
public:
	//构造函数，输入为文件名
	Staff(string filename)
	{
		//请面试人实现该函数体
		FILE *f;
		int c, i = 0, count = 0, n = 0;
		char lineArr[3][128];
		Member temp;
		if ((f = fopen(filename.c_str(), "rb"))) {
			while ((c = fgetc(f)) != -1) {
				if (c != '\n'&&c != ' ') {
					if (count < 3)lineArr[count][i++] = c;
				}
				else
				{
					if (count < 3) lineArr[count][i] = 0;//字符串结束标志
					count++;
					i = 0;
				}

				if (c == '\n'&&count >= 2)
				{//读完一行
					count = 0;

					temp.name = lineArr[0];
					sscanf(lineArr[1], "%d", &n);
					temp.departID = n;
					sscanf(lineArr[2], "%d", &n);
					temp.centerID = n;

					this->staff.push_back(temp);
					temp = Member();
				}
			}
			//存入最后一行
			if ((count == 2 && i != 0) || count > 2) {
				temp.name = lineArr[0];
				sscanf(lineArr[1], "%d", &n);
				temp.departID = n;
				sscanf(lineArr[2], "%d", &n);
				temp.centerID = n;

				this->staff.push_back(temp);
			}

			fclose(f);
		}
	};
	//获取员工所在的部门ID和中心ID
	pair<int, int> getMemberInfo(string name)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		pair<int, int> result(NULL,NULL);
		vector<Member>::iterator itr = find(this->staff.begin(), this->staff.end(), name);
		if (itr != this->staff.end()) {
			result.first = itr->departID;
			result.second = itr->centerID;
		}
		return result;
	};
	//获取某部门下的所有员工
	vector<string> getMembersOfDepart(int depart_id)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		vector<string> result;
		vector<Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const Member& item) {return (item.departID == depart_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->name);
			itr = find_if(++itr, this->staff.end(), [&](const Member& item) {return (item.departID == depart_id); });
		}
		return result;
	};
	//获取某中心下的所有员工
	vector<string> getMembersOfCenter(int center_id)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		vector<string> result;
		vector<Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const Member& item) {return (item.centerID == center_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->name);
			itr = find_if(++itr, this->staff.end(), [&](const Member& item) {return (item.centerID == center_id); });
		}
		return result;
	};
private:
	//所需字段及函数请面试人自行补齐
	vector<Member> staff;
};

/*struct Member {
	int departID;
	int centerID;
};
class Staff {
public:
	//构造函数，输入为文件名
	Staff(string filename)
	{
		//请面试人实现该函数体
		FILE *f;
		int c, i = 0, count = 0, n = 0;
		char lineArr[3][128];
		Member temp;
		if ((f = fopen(filename.c_str(), "rb"))) {
			while ((c = fgetc(f)) != -1) {
				if (c != '\n'&&c != ' ') {
					if (count < 3)lineArr[count][i++] = c;
				}
				else
				{
					if (count < 3) lineArr[count][i] = 0;//字符串结束标志
					count++;
					i = 0;
				}

				if (c == '\n'&&count >= 2)
				{//读完一行
					count = 0;

					sscanf(lineArr[1], "%d", &n);
					temp.departID = n;
					sscanf(lineArr[2], "%d", &n);
					temp.centerID = n;

					this->staff.insert(make_pair(lineArr[0], temp));
					temp = Member();
				}
			}
			//存入最后一行
			if ((count == 2 && i != 0)|| count > 2) {
				sscanf(lineArr[1], "%d", &n);
				temp.departID = n;
				sscanf(lineArr[2], "%d", &n);
				temp.centerID = n;

				this->staff.insert(make_pair(lineArr[0], temp));
			}

			fclose(f);
		}
	};
	//获取员工所在的部门ID和中心ID
	pair<int, int> getMemberInfo(string name)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		pair<int, int> result(NULL, NULL);
		unordered_map<string, Member>::iterator itr = staff.find(name);
		if (itr != this->staff.end()) {
			result.first = itr->second.departID;
			result.second = itr->second.centerID;
		}
		return result;
	};
	//获取某部门下的所有员工
	vector<string> getMembersOfDepart(int depart_id)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		vector<string> result;
		unordered_map<string, Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.departID == depart_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->first);
			itr = find_if(++itr, this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.departID == depart_id); });
		}
		return result;
	};
	//获取某中心下的所有员工
	vector<string> getMembersOfCenter(int center_id)
	{
		//请面试人实现该函数体，时间复杂度O(1)
		vector<string> result;
		unordered_map<string, Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.centerID == center_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->first);
			itr = find_if(++itr, this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.centerID == center_id); });
		}
		return result;
	};
private:
	//所需字段及函数请面试人自行补齐
	//hash_map<string,Member> staff;
	unordered_map<string, Member> staff;
};*/
#pragma endregion

#pragma endregion

#pragma region 统计x的二进制数中1的个数
int count1ofx(int x);
#pragma endregion

#pragma region 图的深度优先遍历
void dfs(int **a, int *b, int n, int idx);
#pragma endregion

#pragma region 图的广度优先遍历（未完成）
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
/*弗洛伊德算法（floyd algorithm）*/
void floyd(int **a, int n, int **d, int **p);

/*迪杰斯特拉算法（dijkstra algorithm），求解单源最短路径*/
void dijkstra(int **a, int n, int origin, int *d, int *p, int *v);
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
/*动态规划*/
void tsp(int **a, int n);

/*暴力求解*/

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
struct Point {
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
/**
* 能回到1号点返回 Yes，否则返回 No
* @param param int整型vector param[0] 为 n，param[1] 为 m
* @param edge Point类vector Point.x , Point.y 分别为一条边的两个点
* @return string字符串
*/
string circuit(vector<int>& param, vector<Point>& edge);
#pragma endregion

#pragma region 算术编解码
void compress(float &out, char *in, int size, char *charset, float *charset_prob, int charset_size); //浮点算术编码
void uncompress(char *&out, float in, int size, char *charset, float *charset_prob, int charset_size);
void compress(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, uint8_t p); //定点算术编码
void compress2(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, float prob);
int compress_uncompress_test();
#pragma endregion

#pragma region 金额大写转化
void money2capital(string &out, double money);
#pragma endregion

#pragma region 0-1背包
void knapsack();
#pragma endregion

#pragma region 仓库问题（美团笔试，未完成）
void warehouse();
#pragma endregion

#pragma region 深信服笔试

#pragma region 查找两个字符串中那个有差别的字符
/*说明：有两个字符串str1、str2，str2是由str1随机打乱后组合的，但是比str1多一个字符或少一个字符，查找那个字符*/
string find_diff_char(string str1, string str2);
#pragma endregion

#pragma region 查找公共子串
string common_chars(string* chars, int charsLen);
#pragma endregion

#pragma endregion
