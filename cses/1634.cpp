#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int f[1000020];
int main()
{
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = x; j <= m; j++)
		{
			f[j] = min(f[j], f[j - x] + 1);
		}
	}
	if (f[m] == 0x3f3f3f3f)
	{
		f[m] = -1;
	}
	cout << f[m] << endl;
	return 0;
}