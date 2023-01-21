#include <bits/stdc++.h>
using namespace std;
int n, x, y, s, l = 1e9;
int ans[2];
map<int, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		g[x]++;
		g[y]--;
	}
	for (pair<int, int> i : g)
	{
		ans[s > 0] = max(ans[s > 0], i.first - l);
		if ((s == 0) ^ (s + i.second == 0))
		{
			l = i.first;
		}
		s += i.second;
	}
	cout << ans[1] << " " << ans[0] << endl;
	return 0;
}
