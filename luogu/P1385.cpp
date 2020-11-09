#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t;
string s;
int f[101][2501];
int main()
{
	f[0][0] = 1;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 0; j <= 2500; j++)
		{
			f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;
		}
		for (int j = 2500; j >= 26; j--)
		{
			f[i][j] = (f[i][j] + mod - f[i][j - 26]) % mod;
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			c += s[i] - 'a';
		}
		cout << (f[s.size()][c] + mod - 1) % mod << endl;
	}
	return 0;
}