#include <bits/stdc++.h>
using namespace std;
int n, x, t;
map<int, int> g;
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		if (g.find(x - t) != g.end())
		{
			cout << g[x - t] << " " << i << endl;
			return 0;
		}
		g[t] = i;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}