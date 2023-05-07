#include"Shell_Sort.h"
#include<iostream>
using namespace std;

FILE* fp5 = fopen("Shell_Sort.txt", "w+");

//Ï£¶ûÅÅÐò
void shellSort(int a[], int length) {
	int step = length / 2+1;
	while (step) {
		for (int i = step; i < length; i++) {
			int temp = a[i];
			int j = i;
			while (j >= step && temp < a[j - step]) {
				a[j] = a[j - step];
				j -= step;
			}
			a[j] = temp;
		}
		step /= 2;
	}
	for (int i = 1; i < length; i++) {
		fprintf(fp5, "%4d ", a[i]);
		if (i % 10 == 0)fprintf(fp5, "\n");
	}

}