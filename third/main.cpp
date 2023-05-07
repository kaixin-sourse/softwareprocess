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
#include"��ͷ.h"
using namespace std;


int a[N],a1[N],a2[N],a3[N],a4[N],a5[N],a6[N];//ȷ��ÿ�β���ʱÿ�����򷽷����ٵ���������ͬ��
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
	//��������
	begin = clock();
	InsertSort(a); 
	end = clock();
	cout << "����������ʱΪ��" << end - begin << "ms"<<endl;
	//ѡ������
	begin = clock();
	Selection_Sort(a1);
	end = clock();
	cout << "ѡ��������ʱΪ��" << end - begin << "ms" << endl;
	//�鲢����
	begin = clock();
	merge(a2, N, temp, 0, N-1);
	push_merge(a2);
	end = clock();
	cout << "�鲢������ʱΪ��" << end - begin << "ms" << endl;
	//ϣ������
	begin = clock();
	shellSort(a3, N);
	end = clock();
	cout << "ϣ��������ʱΪ��" << end - begin << "ms" << endl;
	//ð������
	begin = clock();
	maopao(a4);
	end = clock();
	cout << "ð��������ʱΪ��" << end - begin << "ms" << endl;
	//����
	begin = clock();
	Quick_Sort(a5, 1, N-1);
	push_Quick_Sort(a5);
	end = clock();
	cout << "����������ʱΪ��" << end - begin << "ms" << endl;
	//������
	begin = clock();
	heap_sort(a6, N-1);
	end = clock();
	cout << "��������ʱΪ��" << end - begin << "ms" << endl;
 	return 0;
}