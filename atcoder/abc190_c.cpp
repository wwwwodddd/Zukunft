#include <bits/stdc++.h>
using namespace std;
int n, m, k, z;
int a[120];
int b[120];
int c[20][2];
int p[120];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[i][0] >> c[i][1];
	}
	for (int i = 0; i < 1 << k; i++)
	{
		memset(p, 0, sizeof p);
		for (int j = 0; j < k; j++)
		{
			p[c[j][i >> j & 1]]++;
		}
		int s = 0;
		for (int j = 0; j < m; j++)
		{
			if (p[a[j]] && p[b[j]])
			{
				s++;
			}
		}
		z = max(z, s);
	}
	cout << z << endl;
	return 0;
}
