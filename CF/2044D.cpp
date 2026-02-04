#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		set<int> s;
		vector<int> a;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (s.find(x) == s.end())
			{
				s.insert(x);
				a.push_back(x);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (s.find(i) == s.end())
			{
				s.insert(i);
				a.push_back(i);
			}
		}
		for (int i : a)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
