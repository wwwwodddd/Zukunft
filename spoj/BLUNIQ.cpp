#include <bits/stdc++.h>
using namespace std;
int n, o, x;
set<int> a, b;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &o, &x);
		if (o == 1)
		{
			if (a.find(x) != a.end())
			{
				x = *b.lower_bound(x);
			}
			printf("%d\n", x);
			a.insert(x);
			b.erase(x);
			if (a.find(x + 1) == a.end())
			{
				b.insert(x + 1);
			}
		}
		else
		{
			a.erase(x);
			b.insert(x);
		}
	}
	return 0;
}