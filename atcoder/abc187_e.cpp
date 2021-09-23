#include <bits/stdc++.h>
using namespace std;
int n, q;
int x[200020];
int y[200020];
int f[200020];
long long z[200020];
vector<int> a[200020];
void dfs(int x, int y)
{
	f[x] = y;
	z[x] += z[y];
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x[i] >> y[i];
		a[x[i]].push_back(y[i]);
		a[y[i]].push_back(x[i]);
	}
	dfs(1, 0);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int t, e, d;
		cin >> t >> e >> d;
		int xe = x[e], ye = y[e];
		if (t == 2)
		{
			swap(xe, ye);
		}
		if (f[xe] == ye)
		{
			z[xe] += d;
		}
		else
		{
			z[1] += d;
			z[ye] -= d;
		}
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}