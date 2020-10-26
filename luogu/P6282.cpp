#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020][2];
int z[100020];
int v[100020];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = n; i > 0; i--)
	{
		int j = i;
		z[i] = z[i + 1];
		while (true)
		{
			if (v[a[j][0]] == 0)
			{
				v[a[j][0]] = j;
				z[i]++;
				break;
			}
			else if (v[a[j][0]] > j)
			{
				int nj = v[a[j][0]];
				v[a[j][0]] = j;
				j = nj;
			}
			else if (v[a[j][1]] == 0)
			{
				v[a[j][1]] = j;
				z[i]++;
				break;
			}
			else if (v[a[j][1]] > j)
			{
				int nj = v[a[j][1]];
				v[a[j][1]] = j;
				j = nj;
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}