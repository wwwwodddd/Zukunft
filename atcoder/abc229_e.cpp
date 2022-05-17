#include <bits/stdc++.h>
using namespace std;
int n, m, c, x, y;
int f[200020];
int z[200020];
vector<int> a[200020];
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
		cin >> x >> y;
		if (x > y)
		{
			swap(x, y);
		}
		a[x].push_back(y);
	}
	c = 0;
	for (int i = n; i > 0; i--)
	{
		z[i] = c;
		c++;
		for (int j: a[i])
		{
			if (F(j) != i)
			{
				f[f[j]] = i;
				c--;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}
