#include <bits/stdc++.h>
using namespace std;
int f[100020];
int n, m, x, y;
int F(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
}
vector<int> z;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			z.push_back(i);
			f[x] = y;
		}
	}
	if (z.size() == n - 1)
	{
		for (int i : z)
		{
			cout << i << endl;
		}
	}
	else
	{
		cout << "Disconnected Graph" << endl;
	}
	return 0;
}