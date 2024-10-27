#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5020];
map<int, int> g;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (g.find(m - a[i] - a[j]) != g.end())
			{
				cout << g[m - a[i] - a[j]] + 1 << " " << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
		g[a[i]] = i;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}