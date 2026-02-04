#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		multiset<int> s;
		s.insert(100000000);
		scanf("%d", &n);
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			s.insert(0);
			if (x > *s.begin())
			{
				z += x - *s.begin();
				s.erase(s.begin());
				s.insert(x);
			}
			if (x > *s.begin())
			{
				z += x - *s.begin();
				s.erase(s.begin());
				s.insert(x);
			}
		}
		printf("%d\n", z);
	}
	return 0;
}