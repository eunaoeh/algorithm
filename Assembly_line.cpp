//2017030482_허은진_알고리즘

#include<stdio.h>
#define min(a,b) a > b ? b : a
#define ex(a) a==1 ? a=2 : a=1

int a[3][101], t[3][101], arr[3][102];
int main()
{
	int N;
	scanf("%d", &N);
	scanf("%d %d", &t[1][0], &t[2][0]);
	scanf("%d %d", &t[1][N], &t[2][N]);

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= N - 1; j++) {
			scanf("%d", &t[i][j]);
		}
	}

	arr[1][1] = t[1][0] + a[1][1];
	arr[2][1] = t[2][0] + a[2][1];
	
	for (int j = 2; j <= N; j++)
	{
		arr[1][j] = min(arr[1][j - 1] + a[1][j], arr[2][j - 1] + t[2][j - 1] + a[1][j]);
		arr[2][j] = min(arr[2][j - 1] + a[2][j], arr[1][j - 1] + t[1][j - 1] + a[2][j]);
	}

	int tmp = min(arr[1][N] + t[1][N], arr[2][N] + t[2][N]); 
	printf("%d\n", tmp);
	int i, j = N; 
	arr[1][N] + t[1][N] > arr[2][N] + t[2][N] ? i = 2 : i = 1;

	int res[101]; 
	res[j] = i;
	while (j > 0)
	{
		if (arr[i][j] == arr[i][j - 1] + a[i][j]) res[--j] = i;
		else { i = ex(i);  res[--j] = i; }
	}
	for (int i = 1; i <= N; i++) 
		printf("%d %d\n", res[i], i);

	return 0;
}