#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[50020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		a[i].first += a[i].second;
	}
	sort(a, a + n);
	int z = -1e9, s = 0;
	for (int i = 0; i < n; i++)
	{
		z = max(z, s - a[i].second);
		s += a[i].first - a[i].second;
	}
	printf("%d\n", z);
	return 0;
}