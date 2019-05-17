//2017030482_허은진_알고리즘
#include<stdio.h>
#include<iostream>
using namespace std;

int arr[2][100005];
int key[100005];
int c[1000005];
//int sort[100005];

int main(void) {
	int N, M, K, i, j;
	int cnt = 0;
	scanf("%d%d%d", &N, &M, &K);
	for (i = 0; i < K; i++) scanf("%d%d", &arr[0][i], &arr[1][i]);
	for (i = 0; i < N; i++) {
		scanf("%d", &key[i]);
	}

	for (i = 0; i < N; i++) {
		c[key[i]]++;
	}
	for (i = 0; i <= M; i++)
		c[i] = c[i] + c[i-1];

	for (i = 0; i < K; i++) {
		printf("%d\n", c[arr[1][i]] - c[arr[0][i] - 1]);
	}
	return 0;
}