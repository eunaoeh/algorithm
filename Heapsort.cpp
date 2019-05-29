//2017030482_허은진_알고리즘
#include <iostream>
#include <stdio.h>
using namespace std;

void max_heapify(int a[], int size, int idx) {
	int left = idx * 2;
	int right = (idx * 2) + 1;
	int max = idx;
	int tmp = 0;
	if (left <= size && a[left] > a[max]) {
		max = left;
	}
	if (right <= size && a[right] > a[max]) {
		max = right;
	}
	if (max != idx) {
		tmp = a[max];
		a[max] = a[idx];
		a[idx] = tmp;
		max_heapify(a, size, max);
	}
}
int main(int argc, const char * argv[]) {
	int a[2];
	scanf("%d%d", &(a[0]), &(a[1]));
	int b[a[0] + 1];
	b[0] = 0;
	for (int k = 1; k < a[0] + 1; k++)
	{
		scanf("%d", &b[k]);
	}
	for (int i = a[0] / 2; i > 0; i--) {
		max_heapify(b, a[0], i);
	}
	int tmp = 0;
	int size = a[0];

	for (int count = size; count > size - a[1]; count--) {
		tmp = b[count];
		b[count] = b[1];
		b[1] = tmp;
		max_heapify(b, count - 1, 1);
	}
	for (int count = size; count > size - a[1]; count--) {
		printf("%d ", b[count]);
	}
	printf("\n");
	for (int k = 1; k <= size - a[1]; k++)
	{
		printf("%d ", b[k]);
	}
	return 0;
}