#include <bits/stdc++.h>
using namespace std;
vector<int> a[1020];
int f[1020];
int n, x;
void dfs(int x, int y)
{
	f[x] = 1;
	vector<int> b;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			b.push_back(f[i]);
		}
	}
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < b.size(); i++)
	{
		f[x] = max(f[x], b[i] + i + 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> x;
		a[x].push_back(i);
		a[i].push_back(x);
	}
	int z = n;
	vector<int> b;
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0);
		if (z > f[i])
		{
			z = f[i];
			b.clear();
		}
		if (z == f[i])
		{
			b.push_back(i);
		}
	}
	cout << z << endl;
	for (int i : b)
	{
		cout << i << " ";
	}
	return 0;
}