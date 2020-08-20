#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[300];
pair<int, int> b[300];
vector<int> z[300];
void gao()
{
	sort(a, a + n, greater<pair<int, int> >());
	for (int i = 0; i < n; i++)
	{
		sort(b, b + m, greater<pair<int, int> >());
		for (int j = 0; j < a[i].first; j++)
		{
			if (b[j].first > 0)
			{
				b[j].first--;
				z[a[i].second].push_back(b[j].second);
			}
			else
			{
				printf("0\n");
				return;
			}
		}
	}
	printf("1\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < z[i].size(); j++)
		{
			printf("%d%c", z[i][j] + 1, j == z[i].size() - 1 ? '\n' : ' ');
		}
	}
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	gao();
	return 0;
}