#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int z[200020];
int main()
{
	cin >> n >> m;
	int r = 0, s = m;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		r = max(r, x);
		s = min(s, y);
	}
	for (int l = 1; l <= s; l++)
	{
		z[r - l + 1] += 1;
		z[m - l + 2] -= 1;
		for (int j : a[l])
		{
			r = max(r, j);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		z[i] += z[i - 1];
		cout << z[i] << " ";
	}
	cout << endl;
	return 0;
}
