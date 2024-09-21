#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, b[120];
int f[1000020];
int main()
{
	f[0] = 1;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[j] <= i)
			{
				f[i] = (f[i] + f[i - b[j]]) % p;
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}
