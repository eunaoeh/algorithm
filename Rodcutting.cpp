//2017030382_허은진_알고리즘

#include<stdio.h>

int p[101], arr[101], arr2[101];

int main()
{
	int N, max; 
	scanf("%d", &N); 
	arr[1] = p[1];
	
	for (int i = 1; i <= N; i++) 
		scanf("%d", &p[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (p[j] + arr[i - j] > arr[i]){
				arr[i] = p[j] + arr[i - j];
				arr2[i] = j;
			}
		}
	}
	printf("%d\n", arr[N]);
	while (N > 0)
	{
		printf("%d ", arr2[N]);
		N = N - arr2[N];
	}

	return 0;
}