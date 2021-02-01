#include <bits/stdc++.h>
using namespace std;
int n;
int f[101][101];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 100;
		}
	}
	cout << f[n][n] << endl;
	return 0;
}