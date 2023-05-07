#include<iostream>
#include<algorithm>
#include"Heapsort.h"
using namespace std;

FILE* fp8 = fopen("HeapSort.txt", "w+");

void adjust_heap(int a[], int father, int len)//�ж��ǲ��Ƿ��ϴ����
{
    int left = 2 * father;
    int right = 2 * father + 1;
    int max = father;
    if (left <= len && a[left] > a[max])//left <= len ��ֹ�ڵ㲻����
        max = left;
    if (right <= len && a[right] > a[max])//a[right] > a[max] �ж��ǲ��Ǹ��ڵ����(��Ϊ��ÿ��������Ҫ���ϴ���ѵ����ʰ�)
        max = right;
    if (max != father)
    {
        int temp = a[max];
        a[max] = a[father];
        a[father] = temp;
        adjust_heap(a, max, len);//�ӵ�������ǰ�ڵ㿪ʼ, ��������Ķ�
    }//����� max �ǵ�ǰ father ��ĳһ������, ������ father ����,����Ϊ������ father �������������.
}

void heap_sort(int a[], int len)
{
    for (int i = len / 2; i >= 1; --i) //1.������make_heap, �����һ����Ҷ�ӽڵ㿪ʼ
        adjust_heap(a, i, len);

    for (int i = len; i >= 1; --i)//2. ������, ��ʱ [1, len] Ϊһ����
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        adjust_heap(a, 1, i - 1); // ��ʱ��ĩԪ���Ѿ�����(��������ֵ), 
    }// ʣ��ѵķ�Χ����� [1, len-1], ��������һ���Ľ��������ƻ��ѵ�����, ��Ҫ���е���

    for (int i = 1; i < N; i++)
    {
        fprintf(fp8, "%4d ", a[i]);
        if (i % 10 == 0) {
            fprintf(fp8, "\n");
        }
    }
}