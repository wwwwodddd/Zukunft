#include <bits/stdc++.h>
using namespace std;
int f[4201];
int g[4201];
int n, p;
int main()
{
	cin >> n >> p;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		memcpy(g, f, sizeof g);
		for (int j = 1; j <= i; j++)
		{
			f[j] = (f[j - 1] + g[i - j]) % p;
		}
	}
	cout << f[n] * 2 % p << endl;
	return 0;
}