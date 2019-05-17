//2017030482_허은진_알고리즘
#include<stdio.h>
#include<iostream>
#define MAX 100000
using namespace std;

int arr[MAX];
int arr2[MAX];
int cnt[MAX];

int main() {
	int N, M;
	int tmp = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < M; ++i)
		cin >> arr2[i];

	for (int i = 0; i < N; ++i)
		cnt[arr[i]] = cnt[arr[i]] + 1;
	for(int i = 0; i < M; ++i)
		cnt[arr2[i]] = cnt[arr2[i]] + 1;
	for (int i = 0; i < MAX; ++i) {
		if (cnt[i] > 1)
			tmp++;
	}
	cout << tmp << "\n";
	return 0;
}