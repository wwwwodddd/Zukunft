#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[10002];
vector<int> a[10001];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	for (int i = n; i > 0; i--)
	{
		if (a[i].empty())
		{
			f[i] = f[i + 1] + 1;
		}
		for (int j: a[i])
		{
			f[i] = max(f[i], f[i + j]);
		}
	}
	cout << f[1] << endl;
	return 0;
}