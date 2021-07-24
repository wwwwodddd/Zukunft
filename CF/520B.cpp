#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[20020];
queue<int> q;
int main()
{
	cin >> n >> m;
	memset(d, -1, sizeof d);
	d[n] = 0;
	q.push(n);
	while (q.size() > 0)
	{
		int u = q.front();
		q.pop();
		if (u > 0)
		{
			if (d[u - 1] == -1)
			{
				d[u - 1] = d[u] + 1;
				q.push(u - 1);
			}
		}
		if (2 * u < 20010)
		{
			if (d[u * 2] == -1)
			{
				d[u * 2] = d[u] + 1;
				q.push(u * 2);
			}
		}
	}
	cout << d[m] << endl;
	return 0;
}
