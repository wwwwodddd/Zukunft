#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int s[100020];
int x[12];
map<long long, int> g;
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	long long w = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			w += s[i];
		}
		else
		{
			w -= s[i];
		}
		for (int j = 0; j < m; j++)
		{
			if (i & 1)
			{
				z = max(z, ++g[w - x[j]]);
			}
			else
			{
				z = max(z, ++g[w + x[j]]);
			}
		}
	}
	cout << z << endl;
	return 0;
}
