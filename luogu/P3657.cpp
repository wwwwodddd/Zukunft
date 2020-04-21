#include <bits/stdc++.h>
using namespace std;
int n, x;
int p[100020];
int f[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		p[x] = i;
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		vector<int> b;
		for (int j = max(x - 4, 1); j <= min(x + 4, n); j++)
		{
			b.push_back(p[j]);
		}
		sort(b.begin(), b.end(), greater<int>());
		for (int j: b)
		{
			*lower_bound(f, f + n, j) = j;
		}
	}
	printf("%d\n", int(lower_bound(f, f + n, 0x3f3f3f3f) - f));
	return 0;
}