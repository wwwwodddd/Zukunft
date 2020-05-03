#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[50020];
int main()
{
	cin >> n >> m;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = 0; j <= m; j++)
		{
			int k = min(j + x, m);
			f[k] = min(f[k], f[j] + y);
		}
	}
	cout << f[m] << endl;
	return 0;
}