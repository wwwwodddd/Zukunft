#include <bits/stdc++.h>
using namespace std;
int n, x, mx = 0, mn = 1000;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		mn = min(mn, x);
		mx = max(mx, x);
	}
	printf("%d\n", mx - mn);
	return 0;
}