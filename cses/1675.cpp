#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n, m;
long long s, c;
pair<int, pair<int, int> > a[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a, a + m);
	for (int i = 0; i < m; i++)
	{
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x != y)
		{
			f[x] = y;
			s += a[i].first;
			c++;
		}
	}
	if (c < n - 1)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else
	{
		cout << s << endl;
	}
	return 0;
}