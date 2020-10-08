#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[20020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	int e = a[0].first, z = 0;
	for (int i = 0; i < n; i++)
	{
		z += max(a[i].second - max(e, a[i].first), 0);
		e = max(e, a[i].second);
	}
	printf("%d\n", z);
	return 0;
}