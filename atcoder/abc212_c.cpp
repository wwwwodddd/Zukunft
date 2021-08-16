#include <bits/stdc++.h>
using namespace std;
pair<int, int> c[400020];
int n, m, z = 1e9;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].first;
		c[i].second = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> c[i + n].first;
		c[i + n].second = 1;
	}
	sort(c, c + n + m);
	for (int i = 1; i < n + m; i++)
	{
		if (c[i].second != c[i - 1].second)
		{
			z = min(z, c[i].first - c[i - 1].first);
		}
	}
	cout << z << endl;
	return 0;
}
