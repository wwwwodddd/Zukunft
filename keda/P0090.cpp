#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int k[201];
int d[201];
int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
	}
	memset(d, -1, sizeof d);
	d[a] = 0;
	queue<int> q;
	q.push(a);
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		if (u + k[u] <= n && d[u + k[u]] == -1)
		{
			d[u + k[u]] = d[u] + 1;
			q.push(u + k[u]);
		}
		if (u - k[u] >= 1 && d[u - k[u]] == -1)
		{
			d[u - k[u]] = d[u] + 1;
			q.push(u - k[u]);
		}
	}
	cout << d[b] << endl;
	return 0;
}