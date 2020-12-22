#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
int d[200020];
int v[200020];
int x[200020];
int y[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		d[x[i]]++;
		d[y[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		if (d[x[i]] > d[y[i]] || (d[x[i]] == d[y[i]] && x[i] > y[i]))
		{
			swap(x[i], y[i]);
		}
		a[x[i]].push_back(y[i]);
	}
	int z = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j: a[i])
		{
			v[j] = i;
		}
		for (int j: a[i])
		{
			for (int k: a[j])
			{
				if (v[k] == i)
				{
					z++;
				}
			}
		}
	}
	printf("%d\n", z);
	return 0;
}