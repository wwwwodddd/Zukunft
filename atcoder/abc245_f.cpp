#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[200020];
int d[200020];
queue<int> q;
int main()
{
	cin >> n >> m;
	z = n;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[y].push_back(x);
		d[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int u = q.front();
		q.pop();
		z--;
		for (int i : a[u])
		{
			if (!--d[i])
			{
				q.push(i);
			}
		}
	}
	cout << z << endl;
	return 0;
}
