#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[220];
int f[220][220];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	memset(f, 0x3f, sizeof f);
	int z = 1e9;
	for (int i = 0; i < n; i++)
	{
		f[i][1] = 0;
		for (int j = 1; j <= i + 1; j++)
		{
			for (int k = i + 1; k < n; k++)
			{
				f[k][j + 1] = min(f[k][j + 1], f[i][j] + abs(a[i].second - a[k].second));
			}
		}
		z = min(z, f[i][n - m]);
	}
	cout << z << endl;
	return 0;
}