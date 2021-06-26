#include <bits/stdc++.h>
using namespace std;
int n;
int a[1020], as, an = (1 << 30);
int b[1020], bs, bn = (1 << 30);
pair<int, int> o[1020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		as += a[i];
		an = min(an, a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		bs += b[i];
		bn = min(bn, b[i]);
		o[i].second = i + 1;
		if (a[i] < b[i])
		{
			o[i].first = a[i] - (1 << 30);
		}
		else
		{
			o[i].first = -b[i] + (1 << 30);
		}
	}
	sort(o, o + n);
	printf("%d\n", max(as + bn, bs + an));
	for (int i = 0; i < n; i++)
	{
		printf("%d%c", o[i].second, i == n - 1 ? '\n' : ' ');
	}
	return 0;
}