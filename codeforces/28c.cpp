/*
	Problem: 
	Algorithm: DP
	Time: O()
	Memory: O()
	Detail: Too simple, sometimes naive
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MaxN = 52;

int N, M;
double E[MaxN][MaxN][MaxN];
int A[MaxN];
double C[MaxN][MaxN];

double MemSch(int n, int m, int q)
{
	if (E[n][m][q] >= 0) return E[n][m][q];
	E[n][m][q] = 0;
	for (int t = 0; t <= n; ++t)
	{
		E[n][m][q] += C[n][t]*pow(1.0/m, t)*pow(1.0-1.0/m, n-t)*MemSch(n-t, m-1, max(q, (int)ceil((double)(t)/A[m])));
		//printf("??%f\n", E[n][m][q]);
	}
	return E[n][m][q];
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d", &A[i]);
	for (int i = 0; i <= N; ++i)
		C[i][0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= M; ++j)
			for (int k = 0; k <= N; ++k)
				E[i][j][k] = -1;
	for (int j = 0; j <= M; ++j)
		for (int k = 0; k <= N; ++k)
			E[0][j][k] = k;
	for (int i = 1; i <= N; ++i)
		for (int k = 0; k <= N; ++k)
			E[i][0][k] = 0;
	//printf("%f\n", E[1][1][0]);
	printf("%.10f\n", MemSch(N, M, 0));
	return 0;
}
