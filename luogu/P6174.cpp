#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[50020];
bool ok(int l)
{
	int s = -1, c = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > s)
		{
			c++;
			s = a[i] + l;
		}
	}
	return c <= m;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int L = -1, R = 1e9;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(2 * M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}