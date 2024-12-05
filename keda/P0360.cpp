#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[120];
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		p[i] = i + 1;
	}
	p[n] = 1;
	int x = n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			x = p[x];
		}
		cout << p[x] << " ";
		p[x] = p[p[x]];
	}
	return 0;
}