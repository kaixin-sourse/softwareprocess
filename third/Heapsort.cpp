#include<iostream>
#include<algorithm>
#include"Heapsort.h"
using namespace std;

FILE* fp8 = fopen("HeapSort.txt", "w+");

void adjust_heap(int a[], int father, int len)//判断是不是符合大根堆
{
    int left = 2 * father;
    int right = 2 * father + 1;
    int max = father;
    if (left <= len && a[left] > a[max])//left <= len 防止节点不存在
        max = left;
    if (right <= len && a[right] > a[max])//a[right] > a[max] 判断是不是根节点最大(因为你每个子树都要符合大根堆的性质啊)
        max = right;
    if (max != father)
    {
        int temp = a[max];
        a[max] = a[father];
        a[father] = temp;
        adjust_heap(a, max, len);//从当交换后前节点开始, 调整下面的堆
    }//这里的 max 是当前 father 的某一个儿子, 而不是 father 自身,　因为交换后 father 本来就是有序的.
}

void heap_sort(int a[], int len)
{
    for (int i = len / 2; i >= 1; --i) //1.创建堆make_heap, 从最后一个非叶子节点开始
        adjust_heap(a, i, len);

    for (int i = len; i >= 1; --i)//2. 堆排序, 此时 [1, len] 为一个堆
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        adjust_heap(a, 1, i - 1); // 此时堆末元素已经有序(存的是最大值), 
    }// 剩余堆的范围变成了 [1, len-1], 但由于上一步的交换可能破坏堆的性质, 故要进行调整

    for (int i = 1; i < N; i++)
    {
        fprintf(fp8, "%4d ", a[i]);
        if (i % 10 == 0) {
            fprintf(fp8, "\n");
        }
    }
}