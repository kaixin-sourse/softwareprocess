#include<iostream>
#include"merge_Sort.h"
using namespace std;

FILE* fp4 = fopen("merge_Sort.txt", "w+");

//找到分割区间
void merge(int a[], int length, int temp[], int begin, int end) {
	if (length <= 0 || begin >= end)return;
	int mid = (end - begin) / 2 + begin;
	merge(a, length, temp, begin, mid);
	merge(a, length, temp, mid + 1, end);
	merge_Sort(a, length, temp, begin, end, mid);
	

}
//归并排序
void merge_Sort(int nums[], int length, int temp[], int begin, int end, int mid) {
	if (nums == NULL || length <= 0 || begin >= end || begin < 0)return;
	int left = begin;
	int right = mid + 1;
	int flag = begin;
	while (left <= mid && right <= end) {
		if (nums[left] < nums[right])
			temp[flag++] = nums[left++];
		else
			temp[flag++] = nums[right++];
	}
	while (left <= mid)
		temp[flag++] = nums[left++];
	while (right <= end)
		temp[flag++] = nums[right++];
	for (int i = begin; i <= end; i++)
	{
		nums[i] = temp[i];
	}
}
void push_merge(int a[]) {
	for (int i = 1; i < N; i++)
	{
		fprintf(fp4, "%4d ", a[i]);
		if (i % 10 == 0)fprintf(fp4, "\n");
	}
}