#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[50020];
long long c[50020];
long long d[50020];
long long s, z;
void change(long long *c, int x, int y)
{
	for (; x < 50010; x += x & -x)
	{
		c[x] += y;
	}
}
long long query(long long *c, int x)
{
	long long re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		z += (s - 2 * query(d, a[i].second) - (i - 2 * query(c, a[i].second)) * a[i].second) * a[i].first;
		s += a[i].second;
		change(c, a[i].second, 1);
		change(d, a[i].second, a[i].second);
	}
	printf("%lld\n", z);
	return 0;
}
