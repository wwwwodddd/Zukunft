#include <bits/stdc++.h>
using namespace std;
int m, n, x;
multiset<int> s, p;
int main()
{
	scanf("%d%d", &m, &n);
	s.insert(m);
	p.insert(0);
	p.insert(m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		auto it = p.lower_bound(x);
		auto ti = it;
		ti--;
		s.erase(s.find(*it - *ti));
		s.insert(*it - x);
		s.insert(x - *ti);
		p.insert(x);
		printf("%d ", *--s.end());
	}
	return 0;
}