//2017030482_허은진_알고리즘
#include<stdio.h>
#include<iostream>
#define MAX_SIZE 100005
using namespace std;
int arr[MAX_SIZE];
int arr2[MAX_SIZE];

void merge(int arr[], int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (arr[i] >= arr[j]) 
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	while (i <= mid)
		arr2[k++] = arr[i++];
	while (j <= end)
		arr2[k++] = arr[j++];

	for (i = start; i <= end; i++)
		arr[i] = arr2[i];
}

void merge_sort(int arr[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}



int main() {
	int N, i;
	scanf("%d", &N);
	int start, mid, end;

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	merge_sort(arr, 0, N);

	for (i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	return 0;
}