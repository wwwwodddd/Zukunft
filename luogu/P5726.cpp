#include <bits/stdc++.h>
using namespace std;
int n, x, mx = 0, mn = 10, s = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	printf("%.2f\n", (s - mx - mn) / (n - 2.));
	return 0;
}