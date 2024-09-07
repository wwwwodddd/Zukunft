#include <bits/stdc++.h>
using namespace std;
int n, ia, ib, ja, jb;
char s[22][22];
bool v[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct Rec
{
	int ia, ib, ja, jb;
};
vector<Rec> z;
bool in(int x, int y)
{
	return ia <= x && x <= ib && ja <= y && y <= jb;
}
void dfs(int x, int y)
{
	v[x][y] = true;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (in(nx, ny) && !v[nx][ny] && s[x][y] == s[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (ia = 0; ia < n; ia++)
	{
		for (ib = ia; ib < n; ib++)
		{
			for (ja = 0; ja < n; ja++)
			{
				for (jb = ja; jb < n; jb++)
				{
					map<int, int> c;
					memset(v, 0, sizeof v);
					for (int x = ia; x <= ib; x++)
					{
						for (int y = ja; y <= jb; y++)
						{
							if (!v[x][y])
							{
								c[s[x][y]]++;
								dfs(x, y);
							}
						}
					}
					vector<int> d;
					for (auto i : c)
					{
						d.push_back(i.second);
					}
					sort(d.begin(), d.end());
					if (d.size() == 2 && d[0] == 1 && d[1] > 1)
					{
						z.push_back({ia, ib, ja, jb});
					}
				}
			}
		}
	}
	int ans = 0;
	for (int p = 0; p < z.size(); p++)
	{
		bool f = true;
		for (int q = 0; q < z.size(); q++)
		{
			if (q != p && z[q].ia <= z[p].ia && z[p].ib <= z[q].ib && z[q].ja <= z[p].ja && z[p].jb <= z[q].jb)
			{
				f = false;
			}
		}
		if (f)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}