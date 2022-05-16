#include <bits/stdc++.h>
using namespace std;
int n, q, o, x;
set<int> s;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &o, &x);
		if (o == 1)
		{
			s.insert(x);
		}
		else
		{
			auto it = s.lower_bound(x);
			if (it == s.end())
			{
				puts("-1");
			}
			else
			{
				printf("%d\n", *it);
			}
		}
	}
	return 0;
}