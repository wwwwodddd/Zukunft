#include <bits/stdc++.h>
using namespace std;
int n, m, x;
multiset<int> s;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (i >= m)
		{
			x += *s.begin();
			s.erase(s.begin());
		}
		s.insert(x);
	}
	printf("%d\n", *s.rbegin());
	return 0;
}