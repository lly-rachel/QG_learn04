#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int getMax(int* a,int size) {
	int max = a[0];
	for (int i = 1; i < size; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n) {

	if (!a || 1 >= n){
		return;
	}

	int key = 0;
	for (int j = 1; j < n; j++) { 

		key = a[j];  

		for (int i=j-1; i >= 0; i--)
		{
			if (a[i] > a[i+1])
			{
				a[i+1] = a[i];
				a[i] = key;
			}
			else  break;
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {

	int i = begin, j = mid + 1;  
	int m = mid,n=end;
	int k = 0;          
	while (i <=m && j <= n) { 

		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
			
	}

	while (i <= mid) {
		temp[k++] = a[i++];
	}
		
	while (j <= end) {
		temp[k++] = a[j++];
	}
		
	for (i = 0; i < k; i++)       
		a[begin+i] =temp[i];
	
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {

	if (begin < end) {
		int mid = (begin + end) / 2;     
		MergeSort(a, begin, mid, temp);    //�������  
		MergeSort(a, mid + 1,end, temp); //�ұ�����   
		MergeArray(a, begin, mid, end, temp); //�ٽ������������кϲ�    
	}  
		
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end) {

	if (begin < end) {
		int mid = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid-1);
		QuickSort_Recursion(a, mid+1, end);
	}

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int* a, int begin, int end) {

	int pivot = a[begin];
	while (begin < end) {

		while (a[end] >= pivot && begin < end)
			end--;
		a[begin] = a[end];

		while (a[begin] <= pivot && begin < end)
			begin++;
		a[end] = a[begin];

	}
	a[begin] = pivot;
	return begin;

}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max) {

	int min = a[0];
	int i = 1;
	for (i=1; i < size; i++) {
		if (a[i] < min) min = a[i];
	}
	int range = max - min + 1;

	int* count = (int*)malloc(range * sizeof(int));
	if (count) {
		memset(count, 0, sizeof(int) * range);
		for (i = 0; i < size; i++) {
			count[a[i] - min]++;
		}
		int j = 0;
		for (i = 0; i < range; i++) {
			while (count[i] > 0) {
				a[j++] = i + min;
				count[i]--;
			}
		}
	}
	free(count);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */

void RadixCountSort(int* a, int size) {

	int exp;
	int max = getMax(a, size);

	for (exp = 1; max / exp > 0; exp *= 10) {

		int *output= (int*)malloc(size * sizeof(int));
		memset(output, 0, size * sizeof(int));
		int i, buckets[10] = {0};

		for (i = 0; i < size; i++) {
			buckets[(a[i] / exp) % 10]++;
		}

		for (i = 1; i < 10; i++) {
			buckets[i] += buckets[i - 1];
		}

		for (i = size - 1; i >= 0; i--) {
			output[buckets[(a[i] / exp) % 10] - 1] = a[i];
			buckets[(a[i] / exp) % 10]--;
		}

		for (i = 0; i < size; i++) {
			a[i] = output[i];
		}
		free(output);
	}

}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */

void ColorSort(int* a, int size) {

	int p0=0,p2=size-1;

	for (int i = 0; i <= p2; i++) {
		if (a[i] == 0) {
			swap(&a[i], &a[p0++]);
		}
		else if (a[i] == 2) {
			swap(&a[i--], &a[p2--]);
		}
	}

}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int FindKBiggest(int* a, int size,int K) {

	QuickSort_Recursion(a, 0, size - 1);
	return a[K - 1];
}

