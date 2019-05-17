//2017030482_허은진_알고리즘

#include<stdio.h>

int A[100005];

int main() {
	int N, M, i, j,k, tmp, key;
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &A[i]);
	i = 0;

	while (1) {
		tmp = i;
		for (j = i + 1; j < N; j++) {
			if (A[tmp] > A[j]) {
				tmp = j;
			}
		}
		key = A[i];
		A[i] = A[tmp];
		A[tmp] = key;

		i++;

		//done
		if (i == M) {
			for (k = 0; k < N; k++)
				printf("%d\n", A[k]);
			break;
		}
	}
	return 0;
}