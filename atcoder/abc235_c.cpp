#include <bits/stdc++.h>
using namespace std;
int n, q, x, k;
map<int, vector<int> > g;
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		g[x].push_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> k;
		if (g.find(x) == g.end() || g[x].size() < k)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << g[x][k - 1] << endl;
		}
	}
	return 0;
}
