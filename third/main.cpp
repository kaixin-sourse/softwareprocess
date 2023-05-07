#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include"Bubble Sort.h"
#include"Quick_Sort.h"
#include"merge_Sort.h"
#include"Shell_Sort.h"
#include"Selection_Sort.h"
#include"Insert_Sort.h"
#include"Heapsort.h"
#include"标头.h"
using namespace std;


int a[N],a1[N],a2[N],a3[N],a4[N],a5[N],a6[N];//确保每次测试时每种排序方法面临的数据是相同的
int temp[N];
//FILE* fp1 = fopen("temp.txt", "w+");


void Init() {
	for (int i = 1; i < N; i++)
	{
		a[i] = rand() % 1000;
		a1[i] = a2[i] = a3[i] = a4[i] = a5[i] =a6[i] = a[i];
		//fprintf(fp, "%d ", a[i]);
	}
}




int main() {
	system("color 7f");
	srand((unsigned)time(NULL));
	clock_t begin, end;
	Init();
	//插入排序
	begin = clock();
	InsertSort(a); 
	end = clock();
	cout << "插入排序用时为：" << end - begin << "ms"<<endl;
	//选择排序
	begin = clock();
	Selection_Sort(a1);
	end = clock();
	cout << "选择排序用时为：" << end - begin << "ms" << endl;
	//归并排序
	begin = clock();
	merge(a2, N, temp, 0, N-1);
	push_merge(a2);
	end = clock();
	cout << "归并排序用时为：" << end - begin << "ms" << endl;
	//希尔排序
	begin = clock();
	shellSort(a3, N);
	end = clock();
	cout << "希尔排序用时为：" << end - begin << "ms" << endl;
	//冒泡排序
	begin = clock();
	maopao(a4);
	end = clock();
	cout << "冒泡排序用时为：" << end - begin << "ms" << endl;
	//快排
	begin = clock();
	Quick_Sort(a5, 1, N-1);
	push_Quick_Sort(a5);
	end = clock();
	cout << "快速排序用时为：" << end - begin << "ms" << endl;
	//堆排序
	begin = clock();
	heap_sort(a6, N-1);
	end = clock();
	cout << "堆排序用时为：" << end - begin << "ms" << endl;
 	return 0;
}