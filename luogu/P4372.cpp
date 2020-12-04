#include <bits/stdc++.h>
using namespace std;
int n, mx;
long long z;
int a[100020];
int b[100020];
int r[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		r[i] = i;
	}
	sort(r, r + n, [](int x, int y){return a[x] < a[y] || (a[x] == a[y] && x < y);});
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, r[i]);
		b[i + 1] = max(mx - i, 1);
	}
	for (int i = 0; i < n; i++)
	{
		z += max(b[i], b[i + 1]);
	}
	printf("%lld\n", z);
	return 0;
}