#include"Insert_Sort.h"
#include<iostream>
#include<algorithm>
	
using namespace std;

FILE* fp7 = fopen("Insert_Sort.txt", "w+");

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int b[]) {
	int j;
	for (int i = 2; i < N; i++) {
		if (b[i] < b[i - 1]) {
			b[0] = b[i];
			for (j = i - 1; b[j] > b[0]; j--) {
				b[j + 1] = b[j];
			}
			b[j + 1] = b[0];
		}
	}
	for (int i = 1; i < N; i++) {
		fprintf(fp7, "%4d ", b[i]);
		if (i % 10 == 0)fprintf(fp7, "\n");
	}
}