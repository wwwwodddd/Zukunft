#include <bits/stdc++.h>
using namespace std;
int n;
int a[1020];
int b[1020];
int f[1020];
int g[1020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = max(f[i - 1], g[i - 1] + a[i]);
		g[i] = max(g[i - 1], f[i - 1] + b[i]);
	}
	cout << max(f[n], g[n]) << endl;
	return 0;
}
