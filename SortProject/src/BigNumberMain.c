#include "sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 30

void print(int* a) {
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d,", a[i]);
	}

	printf("\n\n");
}

void RandArray(int* a) {
	for (int i = 0; i < MAXSIZE;) {
		a[i++] = 10000 + rand() % 10000;
		a[i++] = 50000 + rand() % 10000;
		a[i++] = 200000 + rand() % 100000;
	}
	printf("before sort:");
	print(a);
	printf("\n\n");
}

int main(){

	int a[MAXSIZE];
	int temp[MAXSIZE] = {0};

	/*¹é²¢ÅÅÐò*/
	RandArray(a);
	clock_t start = clock();
	MergeSort(a, 0,MAXSIZE-1, temp); 
	printf("after sort:");
	print(a);
	clock_t end = clock() - start;
	printf("MergeSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*¿ìËÙÅÅÐò*/
	RandArray(a);
	start = clock();
	QuickSort_Recursion(a, 0, MAXSIZE - 1);
	printf("after sort:");
	print(a);
	end = clock() - start;
	printf("QuickSort_Recursion use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*²åÈëÅÅÐò*/
	RandArray(a);
	start = clock();
	insertSort(a, MAXSIZE);
	printf("after sort:");
	print(a);
	end = clock() - start;
	printf("insertSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*²åÈëÅÅÐò*/
	RandArray(a);
	int max = getMax(a,MAXSIZE);

	start = clock();
	CountSort(a, MAXSIZE, max);
	printf("after sort:");
	print(a);
	end = clock() - start;
	printf("CountSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*»ùÊýÅÅÐò*/
	RandArray(a);
	start = clock();
	RadixCountSort(a, MAXSIZE);
	printf("after sort:");
	print(a);
	end = clock() - start;
	printf("insertSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");
	system("PAUSE");
	
	return 0;
}