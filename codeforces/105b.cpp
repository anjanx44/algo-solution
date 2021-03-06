#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct snode
{
	int b, l;
	void read() {scanf("%d%d", &b, &l); l /= 10;}
}node[10];

int N, K, A;
int l[10];
double ans;

double calc()
{
	int i, s, cnt, suml;
	double p, res=0;
	for (s = 0; s < (1<<N); ++s)
	{
		p = 1;
		cnt = 0;
		suml = 0;
		for (i = 0; i < N; ++i)
			if (s&(1<<i))
			{
				p *= (10.0-l[i])/10.0;
				suml += node[i].b;
			}
			else
			{
				p *= l[i]/10.0;
				cnt++;
			}
		if ((cnt<<1) > N) res += p;
		else res += p*A/(A+suml);
	}
	return res;
}

void dfs(int i, int c)
{
	if (i==N)
	{
		ans = max(ans, calc());
		return;
	}
	if (i==N-1)
	{
		l[i] = min(node[i].l+c, 10);
		dfs(i+1, 0);
		l[i] = node[i].l;
		return;
	}
	for (int j = 0; j <= min(10-node[i].l, c); ++j)
	{
		l[i] = node[i].l+j;
		dfs(i+1, c-j);
		l[i] = node[i].l;
	}
}

int main()
{
	int i, j, k;
	scanf("%d%d%d", &N, &K, &A);
	for (i = 0; i < N; ++i)
		node[i].read();
	ans = 0;
	dfs(0, K);
	printf("%f\n", ans);
	return 0;
}
