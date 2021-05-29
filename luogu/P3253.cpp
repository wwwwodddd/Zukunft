#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100020];
pair<int, int> a[100020];
long long z;
void change(int x, int y)
{
	for (int i = x; i <= n + m + 1; i += i & -i)
	{
		c[i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = n - i;
		change(n - i, 1);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i + n].first);
		a[i + n].second = i + n + 2;
		change(i + n + 2, 1);
	}
	a[n + m].second = n + 1;
	sort(a, a + n + m);
	for (int i = n + m - 1; i >= 0; i--)
	{
		change(a[i].second, -1);
		z += abs(query(a[i].second) - query(a[i + 1].second));
	}
	printf("%lld\n", z);
	return 0;
}