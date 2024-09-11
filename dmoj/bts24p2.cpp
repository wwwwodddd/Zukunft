#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int a[1000020];
int b[1000020];
long long s[1000020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		s[p] += a[i];
		p += b[i];
		if (p >= m)
		{
			s[m] -= a[i];
			p -= m;
			s[0] += a[i];
		}
		s[p] -= a[i];
	}
	for (int i = 0; i < m; i++)
	{
		s[i + 1] += s[i];
		printf("%lld%c", s[i], i == m - 1 ? '\n' : ' ');
	}
	return 0;
}