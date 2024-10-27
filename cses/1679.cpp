#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int d[100020];
vector<int> a[100020];
vector<int> q;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!d[i])
		{
			q.push_back(i);
		}
	}
	for (int i = 0; i < q.size(); i++)
	{
		for (int j : a[q[i]])
		{
			if (!--d[j])
			{
				q.push_back(j);
			}
		}
	}
	if (q.size() < n)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else
	{
		for (int i : q)
		{
			cout << i << " ";
		}
	}
	return 0;
}