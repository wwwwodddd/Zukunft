#include <bits/stdc++.h>
using namespace std;
const int p = 19650827;
int n;
int a[1001];
int f[1001][1001];
int g[1001][1001];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i][i] = 1;
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = ((a[i] < a[i+1] ? f[i+1][j] : 0) + (a[i] < a[j] ? g[i+1][j] : 0)) % p;
			g[i][j] = ((a[j] > a[j-1] ? g[i][j-1] : 0) + (a[j] > a[i] ? f[i][j-1] : 0)) % p;
		}
	}
	cout << (f[1][n] + g[1][n]) % p << endl;
	return 0;
}