#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int v[100000020];
int a[30];
typedef long long ll;
ll z = 1;
ll pw(ll x, ll y)
{
	ll re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main()
{
	int n = 100000000;
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
		int c = 0;
		for (int j = i; j > 1; j /= v[j])
		{
			a[c++] = v[j];
		}
		c = unique(a, a + c) - a;
		int s = 0;
		for (int j = 0; j < 1 << c; j++)
		{
			int t = n - i;
			for (int k = 0; k < c; k++)
			{
				if (j >> k & 1)
				{
					t = -t / a[k];
				}
			}
			s += t;
		}
		z = z * pw(i, s) % p;
	}
	cout << z << endl;
	return 0;
}