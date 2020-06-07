#include <bits/stdc++.h>
using namespace std;
bitset<1000> a[1000];
int n, m, x, y, z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x-1][y-1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j][i])
			{
				a[j] |= a[i];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		z += a[i].count();
	}
	cout << n * (n - 1) / 2 - z << endl;
	return 0;
}