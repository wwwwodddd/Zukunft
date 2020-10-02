#include <bits/stdc++.h>
using namespace std;
int n, x, z[8];
set<int> s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &x);
		s.insert(x);
	}
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < 7; j++)
		{
			scanf("%d", &x);
			c += s.count(x);
		}
		z[c]++;
	}
	for (int i = 7; i > 0; i--)
	{
		printf("%d%c", z[i], i == 1 ? '\n' : ' ');
	}
	return 0;
}