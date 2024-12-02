#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[100];
int b[100];
int d[1025];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			if (x == 1)
			{
				a[i] |= 1 << j;
			}
			else if (x == -1)
			{
				b[i] |= 1 << j;
			}
		}
	}
	memset(d, -1, sizeof d);
	queue<int> q;
	q.push((1 << n) - 1);
	d[(1 << n) - 1] = 0;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < m; i++)
		{
			int v = (u & ~a[i]) | b[i];
			if (d[v] == -1)
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	printf("%d\n", d[0]);
	return 0;
}