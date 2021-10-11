#include <bits/stdc++.h>
using namespace std;
int n, m, x;
map<int, int> g;
int b[200020];
int c[200020];
int zi, zb, zc;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		g[x]++;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i];
	}
	zi = zb = zc = -1;
	for (int i = 1; i <= m; i++)
	{
		if (zb < g[b[i]] || zb == g[b[i]] && zc < g[c[i]])
		{
			zb = g[b[i]];
			zc = g[c[i]];
			zi = i;
		}
	}
	cout << zi << endl;
}
