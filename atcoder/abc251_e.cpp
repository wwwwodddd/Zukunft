#include <bits/stdc++.h>
using namespace std;
int n;
long long a[300020];
long long f[300020];
long long g[300020];
long long s;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	f[1] = a[1];
	for (int i = 2; i <= n - 1; i++)
	{
		f[i] = max(f[i - 1], f[i - 2] + a[i]);
	}
	for (int i = 2; i <= n - 2; i++)
	{
		g[i] = max(g[i - 1], g[i - 2] + a[i]);
	}
	cout << s - max(f[n - 1], g[n - 2] + a[n]) << endl;
	return 0;
}
