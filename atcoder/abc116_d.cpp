#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[100020], b, c;
long long z, s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
		if (a[i].size() > 0)
		{
			for (int j = 0; j < a[i].size() - 1; j++)
			{
				c.push_back(a[i][j]);
			}
			b.push_back(a[i].back());
		}
	}
	while (c.size() < m)
	{
		c.push_back(0);
	}
	sort(b.begin(), b.end(), greater<int>());
	sort(c.begin(), c.end(), greater<int>());
	for (int i = 0; i < m; i++)
	{
		s += c[i];
	}
	z = s;
	for (int i = 1; i <= m && i <= b.size(); i++)
	{
		s += b[i - 1] - c[m - i];
		z = max(z, s + (long long)i * i);
	}
	cout << z << endl;
	return 0;
}
