#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
vector<int> a[2020];
int v[2020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		memset(v, 0, sizeof v);
		z++;
		v[i] = 1;
		q.push(i);
		while (q.size())
		{
			int u = q.front();
			q.pop();
			for (int j: a[u])
			{
				if (!v[j])
				{
					z++;
					v[j] = 1;
					q.push(j);
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
