#include <bits/stdc++.h>
using namespace std;
map<string, vector<int> > g;
int n, m, l;
string s;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l;
		for (int j = 0; j < l; j++)
		{
			cin >> s;
			if (g[s].empty() || g[s].back() != i)
			{
				g[s].push_back(i);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (g.find(s) != g.end())
		{
			for (int j: g[s])
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}