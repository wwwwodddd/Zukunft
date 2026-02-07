#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101][101], s[101];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			s[j] += a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < m; j++)
		{
			c += a[i][j] * n >= s[j];
		}
		cout << c << endl;
	}
	return 0;
}