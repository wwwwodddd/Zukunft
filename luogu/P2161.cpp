#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
int n, x, y;
char o;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &o);
		if (o == 'A')
		{
			scanf("%d%d", &x, &y);
			set<pair<int, int> >::iterator it = s.lower_bound(make_pair(x, 0));
			int cnt = 0;
			while (it != s.end() && it->second <= y)
			{
				cnt++;
				s.erase(it++);
			}
			s.insert(make_pair(y, x));
			printf("%d\n", cnt);
		}
		else
		{
			printf("%d\n", int(s.size()));
		}
	}
}