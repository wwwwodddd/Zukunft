#include <bits/stdc++.h>
using namespace std;
set<vector<pair<int, int> > > s[9];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char c[9][9];
bool can(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n && c[x][y] != '#';
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == '.')
			{
				vector<pair<int, int> > t;
				t.push_back(make_pair(i, j));
				s[1].insert(t);
			}
		}
	}
	for (int i = 1; i < m; i++)
	{
		for (const vector<pair<int, int> > &a: s[i])
		{
			for (const pair<int, int> &j: a)
			{
				for (int k = 0; k < 4; k++)
				{
					pair<int, int> p = make_pair(j.first + dx[k], j.second + dy[k]);
					if (can(p.first, p.second) && *lower_bound(a.begin(), a.end(), p) != p)
					{
						vector<pair<int, int> > t = a;
						t.push_back(p);
						sort(t.begin(), t.end());
						s[i + 1].insert(t);
					}
				}
			}
		}
	}
	cout << s[m].size() << endl;
	return 0;
}