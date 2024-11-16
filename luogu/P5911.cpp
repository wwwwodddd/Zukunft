#include <bits/stdc++.h>
using namespace std;
int l, n;
int t[65537];
int w[65537];
int f[65537];
int main()
{
	cin >> l >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[1 << i] >> w[1 << i];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		t[i] = max(t[i & i - 1], t[i & -i]);
		w[i] = w[i & i - 1] + w[i & -i];
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = i; j > 0; j = (j - 1) & i)
		{
			if (w[j] <= l)
			{
				f[i] = min(f[i], f[i ^ j] + t[j]);
			}
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}