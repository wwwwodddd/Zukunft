#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int q, o, x, c;
int main()
{
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d", &x);
			s.insert(x);
		}
		else if (o == 2)
		{
			scanf("%d%d", &x, &c);
			for (int j = 0; j < c; j++)
			{
				set<int>::iterator it = s.find(x);
				if (it == s.end())
				{
					break;
				}
				s.erase(it);
			}
		}
		else
		{
			printf("%d\n", *s.rbegin() - *s.begin());
		}
	}
	return 0;
}
