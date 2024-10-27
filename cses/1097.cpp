#include <bits/stdc++.h>
using namespace std;
int n;
int a[5020];
long long f[5020][5020];
long long s;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i][i] = a[i];
		s += a[i];
	}
	for (int i = n; i > 0; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1]);
		}
	}
	cout << (s + f[1][n]) / 2 << endl;
	return 0;
}