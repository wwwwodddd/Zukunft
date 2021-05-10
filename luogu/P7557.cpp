#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int a[100020];
bool ok(int M)
{
	if (a[M] + m < M)
	{
		return false;
	}
	long long s = 0;
	for (int i = 1; i <= M; i++)
	{
		s += max(0, M - a[i]);
	}
	return s <= (long long)l * m;
}
int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n, greater<int>());
	int L = 0, R = n + 1;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		(ok(M) ? L : R) = M;
	}
	printf("%d\n", L);
	return 0;
}