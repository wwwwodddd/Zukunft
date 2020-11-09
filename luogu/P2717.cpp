#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n, m;
int c[100020];
long long z;
void change(int x, int y) {
	for (x++; x <= n + 1; x += x & -x) {
		c[x] += y;
	}
}
int query(int x) {
	int re = 0;
	for (x++; x > 0; x -= x & -x) {
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].first);
		a[i].first += a[i - 1].first - m;
		a[i].second = i;
	}
	sort(a, a + n + 1);
	for (int i = 0; i <= n; i++)
	{
		z += query(a[i].second);
		change(a[i].second, 1);
	}
	printf("%lld\n", z);
	return 0;
}