#include <bits/stdc++.h>
using namespace std;
int n, w, minv = 1e9;
int v[120], p[120];
int f[120][320];
int ans;
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> p[i];
		minv = min(minv, v[i]);
	}
	for (int i = 0; i < n; i++)
	{
		v[i] -= minv;
		for (int j = n; j >= 1; j--)
		{
			for (int k = 3 * n; k >= v[i]; k--)
			{
				f[j][k] = max(f[j][k], f[j - 1][k - v[i]] + p[i]);
				if (j * minv + k <= w)
				{
					ans = max(ans, f[j][k]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}