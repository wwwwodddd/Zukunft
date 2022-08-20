#include <bits/stdc++.h>
using namespace std;
int s, t, m, x, y;
vector<int> a[300020];
int v[3020][3020];
int main()
{
	scanf("%d%d%d", &s, &t, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y - s);
	}
	for (int i = 1; i <= s; i++)
	{
		sort(a[i].begin(), a[i].end());
		for (int j = 0; j < a[i].size(); j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (v[a[i][j]][a[i][k]])
				{
					cout << i << " " << a[i][j] + s << " " << v[a[i][j]][a[i][k]] << " " << a[i][k] + s << endl;
					return 0;
				}
				v[a[i][j]][a[i][k]] = i;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
