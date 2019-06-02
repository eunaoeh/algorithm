//2017030482_허은진_알고리즘

#include<stdio.h>
#include<iostream>
using namespace std;

int p[105], m[105][105], s[105][105];


void Print_Matrix(int s[105][105], int i, int j) {
	if (i == j)
		printf("%d", i);
	else {
		printf("(");
		Print_Matrix(s, i, s[i][j]);
		Print_Matrix(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main(void) {
	int N, i, j, l, k, q;
	scanf("%d", &N);
	for (i = 0; i < N + 1; i++)
		scanf("%d", &p[i]);

	for (i = 1; i <= N; i++)
		m[i][i] = 0;

	for (l = 2; l <= N; l++) {
		for (i = 1; i <= N - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = 10000000;
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", m[1][N]);
	Print_Matrix(s, 1, N);
	printf("\n");
	
	return 0;
}