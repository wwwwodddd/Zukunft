#include <bits/stdc++.h>
using namespace std;
int n, l, p, z;
pair<int, int> a[100020];
int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		p = max(p, a[i].first);
		int t = (a[i].second - p + l - 1) / l;
		p += t * l;
		z += t;
	}
	printf("%d\n", z);
	return 0;
}