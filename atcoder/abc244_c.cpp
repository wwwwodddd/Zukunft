#include <bits/stdc++.h>
using namespace std;
int n, x;
set<int> s;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n + 1; i++)
	{
		s.insert(i);
	}
	for (int i = 0; i <= n; i++)
	{
		printf("%d\n", *s.begin());
		fflush(stdout);
		s.erase(s.begin());
		scanf("%d", &x);
		s.erase(x);
	}
	return 0;
}
