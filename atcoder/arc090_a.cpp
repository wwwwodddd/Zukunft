#include <bits/stdc++.h>
using namespace std;
int n, f[3][120];
int main()
{
	cin >> n;
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> f[i][j];
			f[i][j] += max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[2][n] << endl;
	return 0;
}
