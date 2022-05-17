#include <bits/stdc++.h>
using namespace std;
int n;
long long k, x;
int a[200020];
long long f[200020];
long long g[200020];
// f[i] 表示第一次 x % n == i 时进行了几次操作
// 如果从未出现过，那么 f[i] = -1;
// g[i] 表示第一次 x % n == i 时，x 是多少？
int main()
{
	cin >> n >> k;
	memset(f, -1, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (long long i = 1; i <= k; i++)
	{
		x += a[x % n];
		if (f[x % n] == -1)
		{
			f[x % n] = i;
			g[x % n] = x;
		}
		else
		{
			int d = i - f[x % n];
			long long e = x - g[x % n];
			long long t = (k - i) / d;
			i += t * d;
			x += t * e;
		}
	}
	cout << x << endl;
	return 0;
}