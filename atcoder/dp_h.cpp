#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
char s[1020];
int f[1020][1020];
int main()
{
	cin >> n >> m;
	f[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			if (s[j - 1] == '.')
			{
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % p;
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
