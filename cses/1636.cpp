#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m, x;
int f[1000020];
int main()
{
	f[0] = 1;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		for (int i = x; i <= n; i++)
		{
			f[i] = (f[i] + f[i - x]) % p;
		}
	}
	cout << f[n] << endl;
	return 0;
}
