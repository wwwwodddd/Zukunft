#include <bits/stdc++.h>
using namespace std;
int n, m, k, r;
int a[20];
int b[20];
int c[20];
int f[200];
int main()
{
	cin >> n >> m >> k >> r;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = r; j >= b[i]; j--)
		{
			f[j] = max(f[j], f[j - b[i]] + c[i]);
		}
	}
	int t = 0;
	for (int i = 0; i <= r; i++)
	{
		if (f[i] >= k)
		{
			t = r - i;
			break;
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		if (t >= a[i])
		{
			t -= a[i];
			z++;
		}
	}
	cout << z << endl;
	return 0;
}