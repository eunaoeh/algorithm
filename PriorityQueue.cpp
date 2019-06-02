//2017030482_허은진_알고리즘
#include <iostream>
#include <stdio.h>
using namespace std;

void max_heapify(int a[], int size, int idx) {
	int left = idx * 2;
	int right = (idx * 2) + 1;
	int largest = idx;
	int tmp = 0;
	if (left <= size && a[left] > a[largest]) {
		if (right <= size &&a[left] == a[right])
		{
			largest = right;
		}
		else
		{
			largest = left;
		}
	}
	if (right <= size && a[right] > a[largest]) {
		largest = right;
	}
	if (largest != idx) {
		tmp = a[largest];
		a[largest] = a[idx];
		a[idx] = tmp;
		max_heapify(a, size, largest);
	}
}
void insert_heap(int b[], int idx)
{
	if (idx == 1)
	{
		return;
	}
	else
	{
		int left = (idx / 2) * 2;
		int right = left + 1;

		if (b[left]>b[idx / 2])
		{
			int temp = b[left];
			b[left] = b[idx / 2];
			b[idx / 2] = temp;
			insert_heap(b, idx / 2);
		}
		else if (right <= idx && b[idx / 2]<b[right])
		{
			int temp = b[right];
			b[right] = b[idx / 2];
			b[idx / 2] = temp;
			insert_heap(b, idx / 2);
		}
	}
}

int main(int argc, const char * argv[]) {
	int size = 100000;
	int count = 0;
	int b[size + 1];
	int ans[100000];
	int ans_cnt = 0;
	b[0] = 0;
	while (true) {
		int a;
		scanf("%d", &(a));

		if (a == 0)
		{
			break;
		}
		else if (a == 2)
		{
			ans[ans_cnt] = b[1];
			ans_cnt++;
			b[1] = b[count];
			b[count] = 0;
			count--;
			max_heapify(b, count, 1);
		}
		else if (a == 3)
		{
			int t = 0;
			scanf("%d", &t);
			scanf("%d", &b[t]);
			int origin = b[t];
			max_heapify(b, count, t);
			if (origin == b[t])
			{
				insert_heap(b, t);
			}
		}
		else if (a == 1)
		{
			scanf("%d", &(b[count + 1]));
			count++;
			insert_heap(b, count);
		}

	}
	for (int k = 0; k<ans_cnt; k++) {
		cout << ans[k] << " ";
	}
	cout << "\n";
	for (int k = 1; k<count + 1; k++) {
		cout << b[k] << " ";
	}
	return 0;
}