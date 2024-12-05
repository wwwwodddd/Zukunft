#include <bits/stdc++.h>
using namespace std;
int n, m, x, l, z;
int a[120];
vector<int> b[120];
bool gao(int x)
{
	if (a[x] > 0)
	{
		a[x]--;
		return true;
	}
	if (b[x].size() == 0)
	{
		return false;
	}
	for (int i : b[x])
	{
		if (!gao(i))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> l;
		b[x].resize(l);
		for (int j = 0; j < l; j++)
		{
			cin >> b[x][j];
		}
	}
	while (gao(n))
	{
		z++;
	}
	cout << z << endl;
	return 0;
}