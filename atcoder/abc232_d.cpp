#include <bits/stdc++.h>
using namespace std;
int n, m, z = 1;
string s[100];
int f[100][100];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] != '#' && (i > 0 && f[i - 1][j] || j > 0 && f[i][j - 1]))
			{
				f[i][j] = 1;
				z = max(z, i + j + 1);
			}
		}
	}
	cout << z << endl;
	return 0;
}
