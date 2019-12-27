#include <bits/stdc++.h>
using namespace std;
long n = 1e18;
const int N = 1e9;
int *v, *f;
int main()
{
	v = new int[N + 10];
	f = new int[N + 10];
	for (int i = 2; i <= N; i++)
	{
		if (v[i] == 0)
		{
			for (int j = i; j <= N; j += i)
			{
				v[j] = i;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (v[i / v[i]] == v[i])
		{
			f[i] = 0;
		}
		else
		{
			f[i] = -f[i / v[i]];
		}
	}
	long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (f[i] == 1)
		{
			ans += long(cbrt(n / i / i));
		}
	}
	cout << ans << endl;
	return 0;
}