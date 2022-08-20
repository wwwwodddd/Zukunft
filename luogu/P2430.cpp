#include <bits/stdc++.h>
using namespace std;
int x, y, n, m, l;
int t[5020];
int a[5020];
int b[5020];
int f[5020];
int main()
{
	cin >> x >> y >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	};
	cin >> l;
	l = l * x / y;
	for (int i = 0; i < n; i++)
	{
		for (int j = l; j >= t[a[i]]; j--)
		{
			f[j] = max(f[j], f[j - t[a[i]]] + b[i]);
		}
	}
	cout << f[l] << endl;
	return 0;
}
