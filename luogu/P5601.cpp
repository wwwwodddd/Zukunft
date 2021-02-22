#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, c;
map<string, string> g;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> c;
		g[s] = c;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (int j = 0; j < 4; j++)
		{
			cin >> c;
			if (g[s] == c)
			{
				cout << char('A' + j) << endl;
			}
		}
	}
	return 0;
}