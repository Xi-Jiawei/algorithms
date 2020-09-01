#include "sort.h"

#pragma region �鲢����
/*
�������ܣ��鲢
����˵����
         data: �����鲢�����ݣ�ָ�������ڴ��е�λ�ã����м�λ����Ϊ�ֽ磬�������߾��Ѿ��ź���ֻ���鲢
         start: ������ʼ����
         end: ���ݽ�������
         result: �鲢���
*/
void merge(int *data, int first, int last, int *result) {
	int left_index = first;
	//int right_index = left_index+(end - start + 1) / 2;
	int left_last = (first + last) / 2;//�󲿷����������Ԫ��ĩλ����
	int right_index = left_last + 1;
	int result_index = first;
	while (left_index <= left_last && right_index <= last)
	{
		//�Էֱ��Ѿ��ź�������������������кϲ�
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
�������ܣ�����
����˵����
         data: �����鲢�����ݣ�ָ�������ڴ��е�λ�ã����м�λ����Ϊ�ֽ磬�������߾��Ѿ��ź���ֻ���鲢
         start: ������ʼ����
         end: ���ݽ�������
         result: �鲢���*/
void merge_sort(int *data, int first, int last, int *result) {
	if (1 == last - first)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
	{
		if (data[first] > data[last])
		{
			int temp = data[first];
			data[first] = data[last];
			data[last] = temp;
		}
		return;
	}
	else if (0 == last - first)//���ֻ��һ��Ԫ�أ���������
		return;
	else if (first<last) {
		int mid = (first + last) / 2;//���ĩλ���������ݸ�������ǵ�������߱��ұ߶�һ��Ԫ�أ�˫����������ͬ
		merge_sort(data, first, mid, result);//��߹鲢����ʹ��������������
		merge_sort(data, mid + 1, last, result);//�ұ߹鲢����ʹ��������������
		merge(data, first, last, result);//����������������ϲ�����

		//�����ź���Ĳ��ָ�����data
		for (int i = first; i <= last; ++i)
			data[i] = result[i];
	}
}
#pragma endregion

#pragma region ��������
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
