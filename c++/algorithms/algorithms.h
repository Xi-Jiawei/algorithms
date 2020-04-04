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

int LengthOfLongestSubstring(string s);
void DeleteString();
void Multiply();
void WordBreak();
void SearchTopK();
void FibonacciSeq();
void FibonacciSeqPro();
void PrimeFactorization();
void GreatestCommonFactor();
void LowestCommonMultiple();
void CharCount();
void FactorialSum();
void DigitCount();
void PalindromeNumber();

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
