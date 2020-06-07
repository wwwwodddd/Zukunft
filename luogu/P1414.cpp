#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[1000001];
int z[10002];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 1; i < 1000001; i++)
	{
		int s = 0;
		for (int j = i; j < 1000001; j += i)
		{
			s += c[j];
		}
		z[s] = i;
	}
	for (int i = n; i > 0; i--)
	{
		z[i] = max(z[i], z[i + 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}