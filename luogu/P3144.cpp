#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, s;
vector<int> a[200020];
int f[200020];
int p[200020];
bool v[200020];
bool z[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		f[i] = i;
	}
	for (int i = n; i > 0; i--)
	{
		v[p[i]] = true;
		s++;
		for (int j: a[p[i]])
		{
			if (v[j] && F(j) != F(p[i]))
			{
				f[F(j)] = F(p[i]);
				s--;
			}
		}
		z[i] = s == 1;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%s\n", z[i] ? "YES" : "NO");
	}
	return 0;
}