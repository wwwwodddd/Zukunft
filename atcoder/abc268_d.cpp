#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int v[9];
string s[9], t;
set<string> st;
void dfs(int x, int y, string w)
{
	if (w.size() > 16)
	{
		return;
	}
	if (x == n)
	{
		if (w.size() >= 3 && st.find(w) == st.end())
		{
			cout << w << endl;
			exit(0);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!v[i])
		{
			v[i] = 1;
			string u = w;
			if (x == 0)
			{
				dfs(x + 1, y, w + s[i]);
			}
			else
			{
				for (int j = 1; y + j + (n - x - 1) <= 16; j++)
				{
					u += '_';
					dfs(x + 1, y, u + s[i]);
				}
			}
			v[i] = 0;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		l += s[i].size();
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		st.insert(t);
	}
	dfs(0, l, "");
	cout << "-1" << endl;
	return 0;
}