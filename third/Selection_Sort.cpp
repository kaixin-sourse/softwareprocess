#include"Selection_Sort.h"
#include<iostream>
#include<algorithm>
using namespace std;
FILE* fp6 = fopen("Selection_sort.txt", "w+");


//—°‘Ò≈≈–Ú
void Selection_Sort(int a[]) {
	for (int i = 1; i < N - 1; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			if (a[min] > a[j])min = j;
		}
		if (min != i)swap(a[i], a[min]);
	}
	for (int i = 1; i < N; i++)
	{
		fprintf(fp6, "%4d ", a[i]);
		if (i % 10 == 0)fprintf(fp6, "\n");
	}
}