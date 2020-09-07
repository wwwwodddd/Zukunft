#include <bits/stdc++.h>
using namespace std;
int n, tmax, a[10020];
bool ok(int m)
{
	multiset<int> s;
	for (int i = 0; i < m; i++)
	{
		s.insert(a[i]);
	}
	for (int i = m; i < n; i++)
	{
		s.insert(*s.begin() + a[i]);
		s.erase(s.begin());
	}
	return *--s.end() <= tmax;
}
int main()
{
	scanf("%d%d", &n, &tmax);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int L = 0;
	int R = n;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}