#include <bits/stdc++.h>
using namespace std;
int t[4500020][2], tt;
int n, x;
void ins(int x)
{
	int p = 0;
	for (int i = 29; i >= 0; i--)
	{
		if (t[p][x >> i & 1] == 0)
		{
			t[p][x >> i & 1] = ++tt;
		}
		p = t[p][x >> i & 1];
	}
}
int dfs(int x, int d)
{
	if (d == -1)
	{
		return 0;
	}
	if (t[x][0] && t[x][1])
	{
		return (1 << d) | min(dfs(t[x][0], d - 1), dfs(t[x][1], d - 1));
	}
	else
	{
		return dfs(t[x][0] + t[x][1], d - 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		ins(x);
	}
	cout << dfs(0, 29) << endl;
	return 0;
}
