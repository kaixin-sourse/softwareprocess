#pragma once
#include"标头.h"

//找到分割区间
void merge(int a[], int length, int temp[], int begin, int end);

//归并排序
void merge_Sort(int nums[], int length, int temp[], int begin, int end, int mid);

//输出到文件中
void push_merge(int a[]);
