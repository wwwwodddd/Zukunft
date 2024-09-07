#include <bits/stdc++.h>
using namespace std;
int n, m = 100, r = 100, x, y, z;
pair<int, int> f[120][120];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		for (int i = m; i >= x; i--)
		{
			for (int j = r; j >= y; j--)
			{
				pair<int, int> u = f[i - x][j - y];
				f[i][j] = max(f[i][j], make_pair(u.first + 1, u.second - z));
			}
		}
	}
	cin >> m >> r;
	cout << -f[m][r].second << endl;
	return 0;
}