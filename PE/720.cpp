#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, x;
int a[1 << 25 | 7];
int c[1 << 25 | 7];
void change(int x, int y)
{
	for (int i = x; i <= n; i += i & -i)
	{
		c[i] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		re += c[i];
	}
	return re;
}
int main()
{
	n = 1 << 25;
	a[0] = 0;
	a[1] = 2;
	a[2] = 1;
	a[3] = 3;
	for (m = 4; m < n; m *= 2)
	{
		for (int i = 0; i < m; i++)
		{
			a[i] *= 2;
			a[i + m] = a[i] + 1;
		}
		swap(a[m - 1], a[m]);
	}
	long long re = 0;
	for (int i = 0; i < n; i++)
	{
		int x = a[i] + 1;
		change(x, 1);
		re = (re * (n - i) + x - query(x)) % mod;
	}
	printf("%lld\n", (re + 1) % mod);
	return 0;
}