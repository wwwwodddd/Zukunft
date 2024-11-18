#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> s[300020];
pair<int, int> t[300020];
pair<int, int> st[600020];
int ss;
vector<pair<pair<int, int>, int>> z;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i].first);
		s[i].second = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i].first);
		t[i].second = i + 1;
	}
	sort(s, s + n);
	sort(t, t + n);
	for (int i = 0; i < n; i++)
	{
		s[i].first = t[i].first - s[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i].first > 0)
		{
			st[ss++] = s[i];
		}
		else
		{
			int nd = -s[i].first;
			while (nd > 0)
			{
				if (ss == 0)
				{
					printf("NO\n");
					exit(0);
				}
				int tmp = min(nd, st[ss - 1].first);
				nd -= tmp;
				st[ss - 1].first -= tmp;
				z.push_back(make_pair(make_pair(s[i].second, st[ss - 1].second), tmp));
				if (st[ss - 1].first == 0)
				{
					ss--;
				}
			}
		}
	}
	if (ss)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		printf("%d\n", (int)z.size());
		for (int i = 0; i < z.size(); i++)
		{
			printf("%d %d %d\n", z[i].first.second, z[i].first.first, z[i].second);
		}
	}
	return 0;
}