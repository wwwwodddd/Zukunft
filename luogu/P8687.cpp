#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int f[1048577];
int main()
{
	cin >> n >> m >> k;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int b = 0, x;
		for (int j = 0; j < k; j++)
		{
			cin >> x;
			b |= 1 << --x;
		}
		for (int j = 0; j < 1 << m; j++)
		{
			f[j | b] = min(f[j | b], f[j] + 1);
		}
	}
	int z = f[(1 << m) - 1];
	if (z > 1e9)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}
