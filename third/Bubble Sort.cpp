#include<iostream>
#include<ctime>
#include"Bubble Sort.h"
#include"标头.h"
using namespace std;
FILE* fp3 = fopen("Bubble Sort.txt", "w+");

void maopao(int a[]) {
	for (int i = 1; i <= N; i++) {
		bool falg = true;
		for (int j = 1; j < N - i; j++) {
			if (a[j] > a[j + 1]) {
				falg = false;
				//swap(a[j], a[j + 1]);太耗时了
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				falg = false;
			}
		}
		if (falg)break;
	}
	for (int i = 1; i < N; i++) {
		fprintf(fp3, "%4d ", a[i]);
		if (i % 10 == 0) fprintf(fp3, "\n");
	}
}