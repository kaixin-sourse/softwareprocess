#include<iostream>
#include"Quick_Sort.h"
#include"БъЭЗ.h"
using namespace std;
FILE* fp2 = fopen("Quick_Sort.txt", "w+");


void Quick_Sort(int a[], int left, int right) {
	if (left >= right)return;
	int i = left - 1, j = right + 1, mid = a[i + j >> 1];
	while (i < j) {
		do i++; while (a[i] < mid);
		do j--; while (a[j] > mid);
		if (i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}

	}
	Quick_Sort(a, left, j);
	Quick_Sort(a, j + 1, right);
	
}
void push_Quick_Sort(int a[]) {
	for (int i = 1; i < N; i++) {
		fprintf(fp2, "%4d ", a[i]);
		if (i  % 10 == 0)fprintf(fp2, "\n");
	}
}