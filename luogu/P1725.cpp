#include <bits/stdc++.h>
using namespace std;
int n, l, r, z = -2e9;
int a[200020];
int f[200020];
int q[200020], bb, ff;
int main()
{
	cin >> n >> l >> r;
	memset(f, 0xc0, sizeof f);
	f[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i >= l)
		{
			while (bb < ff && f[q[ff - 1]] < f[i - l])
			{
				ff--;
			}
			q[ff++] = i-l;
		}
		cin >> a[i];
		while (bb < ff && q[bb] < i - r)
		{
			bb++;
		}
		if (bb < ff)
		{
			f[i] = f[q[bb]] + a[i];
		}
		if (i > n - r)
		{
			z = max(z, f[i]);
		}
	}
	cout << z << endl;
	return 0;
}