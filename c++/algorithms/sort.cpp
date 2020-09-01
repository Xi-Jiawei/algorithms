#include "sort.h"

#pragma region 归并排序
/*
函数功能：归并
参数说明：
         data: 将被归并的数据，指向数据内存中的位置，以中间位索引为分界，左右两边均已经排好序，只待归并
         start: 数据起始索引
         end: 数据结束索引
         result: 归并结果
*/
void merge(int *data, int first, int last, int *result) {
	int left_index = first;
	//int right_index = left_index+(end - start + 1) / 2;
	int left_last = (first + last) / 2;//左部分区间的数据元素末位索引
	int right_index = left_last + 1;
	int result_index = first;
	while (left_index <= left_last && right_index <= last)
	{
		//对分别已经排好序的左区间和右区间进行合并
		if (data[left_index] <= data[right_index])
			result[result_index++] = data[left_index++];
		else
			result[result_index++] = data[right_index++];
	}
	while (left_index <= left_last)
		result[result_index++] = data[left_index++];
	while (right_index < last + 1)
		result[result_index++] = data[right_index++];
}
/*
函数功能：划分
参数说明：
         data: 将被归并的数据，指向数据内存中的位置，以中间位索引为分界，左右两边均已经排好序，只待归并
         start: 数据起始索引
         end: 数据结束索引
         result: 归并结果*/
void merge_sort(int *data, int first, int last, int *result) {
	if (1 == last - first)//如果区间中只有两个元素，则对这两个元素进行排序
	{
		if (data[first] > data[last])
		{
			int temp = data[first];
			data[first] = data[last];
			data[last] = temp;
		}
		return;
	}
	else if (0 == last - first)//如果只有一个元素，则不用排序
		return;
	else if (first<last) {
		int mid = (first + last) / 2;//左边末位索引，数据个数如果是单数则左边比右边多一个元素，双数则两边相同
		merge_sort(data, first, mid, result);//左边归并排序，使得左子序列有序
		merge_sort(data, mid + 1, last, result);//右边归并排序，使得右子序列有序
		merge(data, first, last, result);//将两个有序子数组合并操作

		//将已排好序的部分更新至data
		for (int i = first; i <= last; ++i)
			data[i] = result[i];
	}
}
#pragma endregion

#pragma region 快速排序
static int time = 0;
void quick_sort(int* data, int first, int last) {
	if (first < last)
	{
		int i = first, j = last, key = data[first];
		while (i != j)
		{
			while (j > i && data[j] >= key)
			{
				--j;
			}
			data[i] = data[j];
			while (i < j && data[i] <= key)
			{
				++i;
			}
			data[j] = data[i];

			printf("from data[%d] to data[%d]: ", first, last);
			for (int k = first; k <= last; k++)
				printf("%d, ", data[k]);
			printf("\n");
		}
		data[i] = key;

		printf("after %d sort, from data[%d] to data[%d]: ", time++, first, last);
		for (int k = first; k <= last; k++)
			printf("%d, ", data[k]);
		printf("\n");

		quick_sort(data, first, i - 1);
		quick_sort(data, i + 1, last);
	}
}
#pragma endregion
