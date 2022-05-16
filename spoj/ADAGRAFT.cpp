#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, x;
set<int> s[400020];
int f[400020];
long long z = 1;
void merge(int x, int y)
{
	if (x == y)
	{
		return;
	}
	if (s[x].size() < s[y].size())
	{
		s[x].swap(s[y]);
	}
	for (int i : s[y])
	{
		s[x].insert(i);
	}
	s[y].clear();
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &f[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s[i].insert(x);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		z = z * s[i].size() % p;
		merge(f[i], i);
	}
	printf("%lld\n", z);
	return 0;
}