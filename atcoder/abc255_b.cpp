#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1020];
int x[1020];
int y[1020];
int v[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	double z = 0;
	for (int i = 1; i <= n; i++)
	{
		double d = 1e30;
		for (int j = 0; j < m; j++)
		{
			d = min(d, hypot(x[i] - x[a[j]], y[i] - y[a[j]]));
		}
		z = max(z, d);
	}
	cout << fixed << setprecision(9) << z << endl;
	return 0;
}
