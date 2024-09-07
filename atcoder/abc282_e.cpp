#include <bits/stdc++.h>
using namespace std;
int n;
int a[520];
int g[520][520];
int d[520];
int v[520];
long long ans;
long long p;
long long pw(long long x, long long y)
{
	long long re = 1;
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
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				g[i][j] = (pw(a[i], a[j]) + pw(a[j], a[i])) % p;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int mini = -1;
		int mind = -1e9;
		for (int j = 0; j < n; j++) {
			if (!v[j]) {
				if (mind < d[j]) {
					mind = d[j];
					mini = j;
				}
			}
		}
		ans += mind;
		v[mini] = true;
		for (int j = 0; j < n; j++) {
			if (!v[j]) {
				d[j] = max(d[j], g[j][mini]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
