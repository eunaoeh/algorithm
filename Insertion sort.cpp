//2017030482_허은진_알고리즘

#include<stdio.h>

int arr[30005];

int main() {
	int N, i, j, key;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (j = 1; j < N; j++) {
		key = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] < key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}

	for (i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}