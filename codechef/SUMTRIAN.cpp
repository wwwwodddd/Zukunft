#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[120][120];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> a[i][j];
				a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
				z = max(z, a[i][j]);
			}
		}
		cout << z << endl;
	}
	return 0;
}