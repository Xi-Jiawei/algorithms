#pragma once
// algorithms.h : ���ļ��Զ����㷨����ͷ�ļ���������STL�⡰algorithm����
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

#pragma region ���ҵ�e�������������k����
struct Coord {
	int x;
	int y;
};
bool coord_sort(const Coord &c1, const Coord &c2);
vector< Coord > GetNearestCoord(vector<Coord> &vec, Coord e, int k);
#pragma endregion

#pragma region ���ҵ���������k�����
struct ListNode
{
	int m_nkey;
	ListNode *m_pNext;
};
ListNode *GetLastNodes(ListNode *head, int k);
#pragma endregion

#pragma region �ҳ������ظ���������ֵ����
vector<int> StatTimes(int arrA[], int arrAsize, int cnt);
#pragma endregion

#pragma region �ļ�����hash_map�Ĳ���
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
	//���캯��������Ϊ�ļ���
	Staff(string filename)
	{
		//��������ʵ�ָú�����
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
					if (count < 3) lineArr[count][i] = 0;//�ַ���������־
					count++;
					i = 0;
				}

				if (c == '\n'&&count >= 2)
				{//����һ��
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
			//�������һ��
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
	//��ȡԱ�����ڵĲ���ID������ID
	pair<int, int> getMemberInfo(string name)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		pair<int, int> result(NULL,NULL);
		vector<Member>::iterator itr = find(this->staff.begin(), this->staff.end(), name);
		if (itr != this->staff.end()) {
			result.first = itr->departID;
			result.second = itr->centerID;
		}
		return result;
	};
	//��ȡĳ�����µ�����Ա��
	vector<string> getMembersOfDepart(int depart_id)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		vector<string> result;
		vector<Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const Member& item) {return (item.departID == depart_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->name);
			itr = find_if(++itr, this->staff.end(), [&](const Member& item) {return (item.departID == depart_id); });
		}
		return result;
	};
	//��ȡĳ�����µ�����Ա��
	vector<string> getMembersOfCenter(int center_id)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		vector<string> result;
		vector<Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const Member& item) {return (item.centerID == center_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->name);
			itr = find_if(++itr, this->staff.end(), [&](const Member& item) {return (item.centerID == center_id); });
		}
		return result;
	};
private:
	//�����ֶμ����������������в���
	vector<Member> staff;
};

/*struct Member {
	int departID;
	int centerID;
};
class Staff {
public:
	//���캯��������Ϊ�ļ���
	Staff(string filename)
	{
		//��������ʵ�ָú�����
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
					if (count < 3) lineArr[count][i] = 0;//�ַ���������־
					count++;
					i = 0;
				}

				if (c == '\n'&&count >= 2)
				{//����һ��
					count = 0;

					sscanf(lineArr[1], "%d", &n);
					temp.departID = n;
					sscanf(lineArr[2], "%d", &n);
					temp.centerID = n;

					this->staff.insert(make_pair(lineArr[0], temp));
					temp = Member();
				}
			}
			//�������һ��
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
	//��ȡԱ�����ڵĲ���ID������ID
	pair<int, int> getMemberInfo(string name)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		pair<int, int> result(NULL, NULL);
		unordered_map<string, Member>::iterator itr = staff.find(name);
		if (itr != this->staff.end()) {
			result.first = itr->second.departID;
			result.second = itr->second.centerID;
		}
		return result;
	};
	//��ȡĳ�����µ�����Ա��
	vector<string> getMembersOfDepart(int depart_id)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		vector<string> result;
		unordered_map<string, Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.departID == depart_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->first);
			itr = find_if(++itr, this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.departID == depart_id); });
		}
		return result;
	};
	//��ȡĳ�����µ�����Ա��
	vector<string> getMembersOfCenter(int center_id)
	{
		//��������ʵ�ָú����壬ʱ�临�Ӷ�O(1)
		vector<string> result;
		unordered_map<string, Member>::iterator itr = find_if(this->staff.begin(), this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.centerID == center_id); });
		while (itr != this->staff.end()) {
			result.push_back(itr->first);
			itr = find_if(++itr, this->staff.end(), [&](const pair<string, Member>& item) {return (item.second.centerID == center_id); });
		}
		return result;
	};
private:
	//�����ֶμ����������������в���
	//hash_map<string,Member> staff;
	unordered_map<string, Member> staff;
};*/
#pragma endregion
