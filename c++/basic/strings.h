/*
保证同一个文件不会被包含多次，也就是防止嵌套包含（多重包含）而导致的“LNK1169 找到一个或多个多重定义的符号”，有两种方式：
1、#ifndef、#define、#endif
2、#pragma once
实际使用过程中，发现方式1的效果要优于方式2
*/

#pragma once

#ifndef _STRINGS_H
#define _STRINGS_H

#include <vector>
#include <stdarg.h>
using namespace std;

#pragma region 字符串拼接
char *string_concat(int count, ...);
char *string_concat(vector<char*> params);
#pragma endregion

#pragma region 字符串格式化
char *string_format(char *format, ...);
#pragma endregion

#endif