#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, w, f[30];
map<string, int> a, b, c;
string s;
int main()
{
	cin >> m >> n;
	m = 21 - m;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v >> w >> s;
		a[s] += u;
		b[s] = v;
		c[s] = w;
	}
	for (pair<string, int> i: c)
	{
		for (int j = 0; j < a[i.first] / c[i.first]; j++)
		{
			for (int k = m; k > 0; k--)
			{
				f[k] = max(f[k], f[k - 1] + c[i.first] * b[i.first]);
			}
		}
		for (int k = m; k > 0; k--)
		{
			f[k] = max(f[k], f[k - 1] + a[i.first] % c[i.first] * b[i.first]);
		}
	}
	printf("%d\n", f[m]);
	return 0;
}