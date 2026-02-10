#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[1020][1020];
vector<int> b[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		sort(b[i].begin(), b[i].end());
		cout << b[i].size();
		for (int j : b[i])
		{
			cout << " " << j;
		}
		cout << endl;
	}
	return 0;
}