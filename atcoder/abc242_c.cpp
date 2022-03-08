#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n;
long long f[1000020][11];
int main()
{
	for (int i = 1; i < 10; i++)
	{
		f[1][i] = 1;
	}
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1]) % p;
		}
	}
	long long s = 0;
	for (int j = 1; j <= 9; j++)
	{
		s = (s + f[n][j]) % p;
	}
	cout << s << endl;
	return 0;
}