#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, pair<int, int> > a[100020];
int p[100020];
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	f[F(x)] = F(y);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
	}
	sort(a, a + m);
	int j = m;
	for (int i = 1; i <= n; i++)
	{
		for (;F(i) != F(p[i]);)
		{
			j--;
			U(a[j].second.first, a[j].second.second);
		}
	}
	printf("%d\n", j == m ? -1 : a[j].first);
	return 0;
}