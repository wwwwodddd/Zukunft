#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
int t, n, x;
int v[N + 20];
int u[N + 20];
int main()
{
	for (int i = 2; i <= N; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= N; j += i)
			{
				v[j] = i;
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			for (; x > 1; x /= v[x])
			{
				u[v[x]] = tt;
			}
		}
		for (int i = 1; i <= N; i++)
		{
			if (v[i] == i && u[i] != tt)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}