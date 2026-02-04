#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
bool ok(int M)
{
	int s = 0, cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (s + a[i] > M)
		{
			s = 0;
			cnt++;
		}
		s += a[i];
		if (s > M)
		{
			return false;
		}
	}
	return cnt <= m;
}
int main()
{
	scanf("%d%d", &n, &m);
	int L = 0, R = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		R += a[i];
	}
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
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