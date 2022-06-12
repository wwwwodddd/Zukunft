#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> k;
		if (n * m % k)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << (i * m + (i & 1 ? m - 1 - j : j)) / k + 1 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
