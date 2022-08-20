#include <bits/stdc++.h>
using namespace std;
int n, c[10];
int f[1000020];
int main()
{
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		cin >> c[i];
		for (int j = c[i]; j <= n; j++)
		{
			f[j] = max(f[j], f[j - c[i]] + 1);
		}
	}
	while (f[n])
	{
		for (int i = 9; i > 0; i--)
		{
			if (n >= c[i] && f[n] == f[n - c[i]] + 1)
			{
				cout << i;
				n -= c[i];
				break;
			}
		}
	}
	return 0;
}
