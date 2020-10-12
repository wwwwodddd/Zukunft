#include <bits/stdc++.h>
using namespace std;
int n, m, x, f[32];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = x > 1; j <= m; j += 2)
		{
			f[j]++;
		}
		for (int j = 1; j <= m; j++)
		{
			f[j] = max(f[j], f[j - 1]);
		}
	}
	cout << f[m] << endl;
	return 0;
}