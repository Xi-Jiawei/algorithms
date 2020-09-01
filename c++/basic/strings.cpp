#include "strings.h"

#pragma region 字符串拼接
char *string_concat(int count, ...) {
	int size = 0;
	char *param;
	vector<char*> paramList;
	va_list list;
	va_start(list, count);//取第1个参数
	for (int i = 0; i < count; i++)
	{
		param = va_arg(list, char *);
		paramList.push_back(param);
		size += strlen(param);
	}
	va_end(list);

	char *result = (char*)malloc(size);

	int address = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < strlen(paramList[i]); j++) {
			result[address + j] = paramList[i][j];
		}
		address += strlen(paramList[i]);
	}
	result[address] = 0;

	return result;
}

char *string_concat(vector<char*> params) {
	int size = 0;
	for (int i = 0; i<params.size(); i++)size += strlen(params[i]);

	char *result = (char*)malloc(size);

	int address = 0;
	for (int i = 0; i < params.size(); i++) {
		for (int j = 0; j < strlen(params[i]); j++) {
			result[address + j] = params[i][j];
		}
		address += strlen(params[i]);
	}
	result[address] = 0;

	return result;
}
#pragma endregion

#pragma region 字符串格式化
char *string_format(char *format, ...)
{
	va_list list;
	//1. 先获取格式化后字符串的长度
	va_start(list, format);
	int size = vsnprintf(NULL, 0, format, list);
	va_end(list);
	if (size <= 0) {
		return NULL;
	}
	size++;

	//2. 复位va_list，将格式化字符串写入到result
	va_start(list, format);
	char *result = (char *)malloc(size);
	vsnprintf(result, size, format, list);
	va_end(list);
	return result;
}
#pragma endregion