#include <bits/stdc++.h>
using namespace std;
int t, n;
int v[2020];
int p[2020], pc;
int s[2020];
int f[2020];
int main()
{
	for (int i = 2; i < 2010; i++)
	{
		if (!v[i])
		{
			p[pc++] = i;
			for (int j = i; j < 2010; j += i)
			{
				v[j] = i;
			}
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			s[i] += s[i - 1];
			f[i] = f[i - 1];
			for (int j = 0; j < pc && p[j] <= i; j++)
			{
				f[i] = max(f[i], f[max(i - p[j] - 1, 0)] + s[i] - s[i - p[j]]);
			}
		}
		cout << f[n] << endl;
	}
	return 0;
}