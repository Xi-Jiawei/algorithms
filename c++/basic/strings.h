/*
��֤ͬһ���ļ����ᱻ������Σ�Ҳ���Ƿ�ֹǶ�װ��������ذ����������µġ�LNK1169 �ҵ�һ���������ض���ķ��š��������ַ�ʽ��
1��#ifndef��#define��#endif
2��#pragma once
ʵ��ʹ�ù����У����ַ�ʽ1��Ч��Ҫ���ڷ�ʽ2
*/

#pragma once

#ifndef _STRINGS_H
#define _STRINGS_H

#include <vector>
#include <stdarg.h>
using namespace std;

#pragma region �ַ���ƴ��
char *string_concat(int count, ...);
char *string_concat(vector<char*> params);
#pragma endregion

#pragma region �ַ�����ʽ��
char *string_format(char *format, ...);
#pragma endregion

#endif