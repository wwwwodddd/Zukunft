#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[30];
int d[30];
int c[30];
char s[30];
int gao()
{
	// 0 Sorted sequence cannot be determined
	// 1 Sorted sequence determined
	// 2 Inconsistency found after
	memcpy(d, c, sizeof d);
	int f = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		for (int j = 0; j < n; j++)
		{
			if (d[j] == 0)
			{
				if (u == -1)
				{
					u = j;
				}
				else
				{
					f = 0;
				}
			}
		}
		if (u == -1)
		{
			return 2;
		}
		d[u]--;
		s[i] = 'A' + u;
		for (int j: a[u])
		{
			d[j]--;
		}
	}
	return f;
}
void work()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		char x, y;
		scanf(" %c<%c", &x, &y);
		a[x - 'A'].push_back(y - 'A');
		c[y - 'A']++;
		int t = gao();
		if (t == 1)
		{
			printf("Sorted sequence determined after %d relations: %s.\n", i, s);
			return;
		}
		else if (t == 2)
		{
			printf("Inconsistency found after %d relations.\n", i);
			return;
		}
	}
	printf("Sorted sequence cannot be determined.\n");
	return;
}
int main()
{
	work();
	return 0;
}