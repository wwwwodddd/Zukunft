#include <bits/stdc++.h>
using namespace std;
int n, r, f[11][11];
int main()
{
	cin >> n >> r;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			f[i][j] = j * (f[i-1][j-1] + f[i-1][j]);
		}
	}
	cout << f[n][r] << endl;
	return 0;
}