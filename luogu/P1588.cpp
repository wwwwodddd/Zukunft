#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int d[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> y;
		memset(d, -1, sizeof d);
		d[x] = 0;
		queue<int> q;
		q.push(x);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			if (u > 0 && d[u - 1] == -1)
			{
				d[u - 1] = d[u] + 1;
				q.push(u - 1);
			}
			if (u < 100000 && d[u + 1] == -1)
			{
				d[u + 1] = d[u] + 1;
				q.push(u + 1);
			}
			if (u <= 50000 && d[u * 2] == -1)
			{
				d[u * 2] = d[u] + 1;
				q.push(u * 2);
			}
		}
		cout << d[y] << endl;
	}
}