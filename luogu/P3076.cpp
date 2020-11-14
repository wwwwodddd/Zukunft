#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[100020];
int t[100020];
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s[i], &t[i]);
		z += abs(s[i] - t[i]);
	}
	s[n] = m;
	t[n] = 0;
	sort(s, s + n + 1);
	sort(t, t + n + 1);
	for (int i = 0; i <= n; i++)
	{
		z += abs(s[i] - t[i]);
	}
	printf("%lld\n", z);
	return 0;
}