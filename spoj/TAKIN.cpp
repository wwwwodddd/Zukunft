#include <bits/stdc++.h>
using namespace std;
int t, n, a[20];
long long m, z;
void dfs(int x, long long y)
{
	if (x == n)
	{
		z = max(z, y);
		return;
	}
	dfs(x + 1, y);
	if (y + a[x] <= m)
	{
		dfs(x + 1, y + a[x]);
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		z = 0;
		dfs(0, 0);
		cout << z << endl;
	}
	return 0;
}