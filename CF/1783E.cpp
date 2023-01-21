#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int b[200020];
int s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			s[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] > b[i])
			{
				s[b[i]]++;
				s[a[i]]--;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			s[i] += s[i - 1];
		}
		vector<int> z;
		for (int i = 1; i <= n; i++)
		{
			int c = 0;
			for (int j = i; j <= n; j += i)
			{
				c += s[j] > 0;
			}
			if (c == 0)
			{
				z.push_back(i);
			}
		}
		printf("%lu\n", z.size());
		for (int i : z)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}