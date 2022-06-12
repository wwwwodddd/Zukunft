#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[200020];
int b[200020];
int p[200020];
int L[200020];
int R[200020];
int dfs(int l, int r)
{
	if (l > r)
	{
		return 0;
	}
	int x = a[c++], m = p[x];
	if (m < l || m > r)
	{
		cout << -1 << endl;
		exit(0);
	}
	L[x] = dfs(l, m - 1);
	R[x] = dfs(m + 1, r);
	return x;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		p[b[i]] = i;
	}
	if (dfs(0, n - 1) != 1)
	{
		cout << -1 << endl;
		exit(0);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << L[i] << " " << R[i] << endl;
	}
	return 0;
}
