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

#pragma region ���ֲ���

#pragma region ���ظ�Ԫ�ص���������Ķ��ֲ���
/*����ĳ��Ԫ�ص�λ�ã��������򷵻�-1��*/
int binary_search(int v, int *a, int n);
#pragma endregion

#pragma region ���ظ�Ԫ�ص���������Ķ��ֲ���
/*���ҵ�һ������ĳ��Ԫ�ص�λ�ã��������򷵻�-1��*/
int binary_search2(int v, int *a, int n);
#pragma endregion

#pragma region ���ظ�Ԫ�ص���������Ķ��ֲ���
/*�������һ������ĳ��Ԫ�ص�λ�ã��������򷵻�-1��*/
int binary_search3(int v, int *a, int n);
#pragma endregion

#pragma region ���ֲ���֮lower_bound
/*���ҵ�һ�����ڻ����ĳ��Ԫ�ص�λ�ã��������򷵻����鳤�ȡ�*/
int lower_bound(int v, int *a, int n);
#pragma endregion

#pragma region ���ֲ���֮upper_bound
/*���ҵ�һ������ĳ��Ԫ�ص�λ�ã��������򷵻����鳤�ȡ�*/
int upper_bound(int v, int *a, int n);
#pragma endregion

#pragma endregion

#pragma region �������ظ��ַ�����Ӵ��ĳ��ȣ�δ��ɣ�
int length_of_longest_substring(string s);
#pragma endregion

#pragma region ģʽƥ��
void pattern_matching();
#pragma endregion

#pragma region ɾ���ַ����е�"ab"�ַ�
void delete_string();
#pragma endregion

#pragma region �����ļӷ��ͳ˷���a, b���ܳ�integer��long��ȡֵ��Χ��
void bignumber();
#pragma endregion

#pragma region ���ʲ�֣�δ��ɣ�https://leetcode-cn.com/problems/word-break-ii/
void word_break();
#pragma endregion

#pragma region top k problem���ҳ�ǰk�������
void search_top_k();
#pragma endregion

#pragma region rabbit problem��쳲��������У�
void fibonacci_seq();
#pragma endregion

#pragma region ��ǿ��쳲��������У���ǰ��=ǰ4��֮��
void fibonacci_seq_pro();
#pragma endregion

#pragma region �ֽ�������
void prime_factorization();
#pragma endregion

#pragma region ���Լ��
void greatest_common_factor();
#pragma endregion

#pragma region ��С������
void lowest_common_multiple();
#pragma endregion

#pragma region �ַ�ͳ��
void char_count();
#pragma endregion

#pragma region �׳���ͣ�Sn=1!+2!+...+n!
void factorial_sum();
#pragma endregion

#pragma region ����λ��ͳ��
void digit_count();
#pragma endregion

#pragma region ������
void palindrome_number();
#pragma endregion

#pragma region ��Ѷ����

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

#pragma endregion

#pragma region ͳ��x�Ķ���������1�ĸ���
int count1ofx(int x);
#pragma endregion

#pragma region ͼ��������ȱ���
void dfs(int **a, int *b, int n, int idx);
#pragma endregion

#pragma region ͼ�Ĺ�����ȱ�����δ��ɣ�
#pragma endregion

#pragma region ���·���������Ȩͼ��
/*
����
����n�������ڽӾ��������������·����

����
��һ�и�������n��
������n�У�ÿ����n��������

���
���·��*/
/*���������㷨��floyd algorithm��*/
void floyd(int **a, int n, int **d, int **p);

/*�Ͻ�˹�����㷨��dijkstra algorithm������ⵥԴ���·��*/
void dijkstra(int **a, int n, int origin, int *d, int *p, int *v);
#pragma endregion

#pragma region ��̹��ܶ��ٻ�·�����������⣬�����Ȩͼ��
/*
����
����n�������ڽӾ�����֪��㣬��һ������ͼ�����е��ұ�Ȩ����С�Ļ�·��
��������һ���ۻ�Ա�������n�����У�ǡ�÷���ÿ������һ�Σ������ջص��������С�
�ۻ�Ա�ӳ���i������j�����з�����һ�����������������ȫ�������������о����ĵĸ��߷���֮�ͣ����ۻ�Աϣ��ʹ�������з�����͡���

����
��һ�и�������n��
������n�У�ÿ����n��������

���
���·������·*/
/*��̬�滮*/
void tsp(int **a, int n);

/*�������*/

#pragma endregion

#pragma region ��·��δ��ɣ�
/*
��Ŀ��Դţ����������https://www.nowcoder.com/practice/2a5153a6d2bd43949764c068b4f29d26?tpId=110&&tqId=33506&rp=1&ru=/activity/oj&qru=/ta/job-code/question-ranking
����
ţţ��һ���Թ��У��Թ���n�����ӣ���m��ͨ����ÿ��ͨ�������������ӣ�<u,v>��ʾ���Ϊu�ĸ�������Ϊv�ĸ��ӿɻ��ൽ�ÿ��ÿ��ͨ��ֻ����һ�Ρ�
ţţ��֪�������Ƿ��ܴ�1�Ÿ��ӳ����ص�1�Ÿ��ӡ�

����
��һ�и�����������n,m��
������m�У�ÿ������������u,v��
m��u, v������ͬ

���
���ܻص�1�Ÿ����򷵻�Yes�����򷵻�No��*/
struct Point {
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
/**
* �ܻص�1�ŵ㷵�� Yes�����򷵻� No
* @param param int����vector param[0] Ϊ n��param[1] Ϊ m
* @param edge Point��vector Point.x , Point.y �ֱ�Ϊһ���ߵ�������
* @return string�ַ���
*/
string circuit(vector<int>& param, vector<Point>& edge);
#pragma endregion

#pragma region ���������
void compress(float &out, char *in, int size, char *charset, float *charset_prob, int charset_size); //������������
void uncompress(char *&out, float in, int size, char *charset, float *charset_prob, int charset_size);
void compress(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, uint8_t p); //������������
void compress2(uint8_t *&out, int32_t out_bit_count, uint8_t *in, int32_t in_bit_count, float prob);
int compress_uncompress_test();
#pragma endregion

#pragma region ����дת��
void money2capital(string &out, double money);
#pragma endregion

#pragma region 0-1����
void knapsack();
#pragma endregion

#pragma region �ֿ����⣨���ű��ԣ�δ��ɣ�
void warehouse();
#pragma endregion

#pragma region ���ŷ�����

#pragma region ���������ַ������Ǹ��в����ַ�
/*˵�����������ַ���str1��str2��str2����str1������Һ���ϵģ����Ǳ�str1��һ���ַ�����һ���ַ��������Ǹ��ַ�*/
string find_diff_char(string str1, string str2);
#pragma endregion

#pragma region ���ҹ����Ӵ�
string common_chars(string* chars, int charsLen);
#pragma endregion

#pragma endregion
