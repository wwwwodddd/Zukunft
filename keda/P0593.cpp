#include <bits/stdc++.h>
using namespace std;
int n, m, d;
string s;
map<pair<int, int>, vector<string> > g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> m >> d;
		g[{m, d}].push_back(s);
	}
	for (const auto &i : g)
	{
		if (i.second.size() > 1)
		{
			cout << i.first.first << ' ' << i.first.second;
			for (const string &j : i.second)
			{
				cout << ' ' << j;
			}
			cout << endl;
		}
	}
	return 0;
}