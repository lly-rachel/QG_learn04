#include "sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100
#define MAXTIMES 100000

void print(int* a) {
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d,", a[i]);
	}

	printf("\n\n");
}

void RandArray(int* a) {

	FILE* fp;
	fp = fopen("number.txt", "at+");
	if (NULL == fp) { printf("open file failed!!\n");}
	else {
		fseek(fp, rand() , SEEK_SET);
		for (int i = 0; i < MAXSIZE;i++) {
			fscanf(fp, "%d,", &a[i]);			
		}
	}	
	fclose(fp);
}



int main(){
	int a[MAXSIZE];
	int temp[MAXSIZE] = { 0 };
	clock_t start,end;

	/*¹é²¢ÅÅÐò*/
	start = clock();
	for (int i = 0; i < MAXTIMES; i++) {
		RandArray(a);
		MergeSort(a, 0, MAXSIZE - 1, temp);
	}	
	end = clock() - start;
	printf("MergeSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*¿ìËÙÅÅÐò*/
	start = clock();
	for (int i = 0; i < MAXTIMES; i++) {
		RandArray(a);
		QuickSort_Recursion(a, 0, MAXSIZE - 1);
	}
	end = clock() - start;
	printf("QuickSort_Recursion use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*²åÈëÅÅÐò*/
	start = clock();
	for (int i = 0; i < MAXTIMES; i++) {
		RandArray(a);
		insertSort(a, MAXSIZE);
	}
	end = clock() - start;
	printf("insertSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*²åÈëÅÅÐò*/
	start = clock();
	for (int i = 0; i < MAXTIMES; i++) {
		RandArray(a);	
		CountSort(a, MAXSIZE, getMax(a, MAXSIZE));
	}
	end = clock() - start;
	printf("CountSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");

	/*»ùÊýÅÅÐò*/
	start = clock();
	for (int i = 0; i < MAXTIMES; i++) {
		RandArray(a);
		RadixCountSort(a, MAXSIZE);
	}
	end = clock() - start;
	printf("insertSort use time:%ldms\n", end);
	printf("--------------------------------------------------------------\n\n");
	system("PAUSE");


	return 0;
}