#include <bits/stdc++.h>
using namespace std;
int n = 1000000, x;
int v[1000020];
int f[1000020];
int main()
{
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == v[i / v[i]])
		{
			f[i] = f[i / v[i]] * 2 - f[i / v[i] / v[i]];
		}
		else
		{
			f[i] = f[i / v[i]] * 2;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cout << f[x] << endl;
	}
	return 0;
}