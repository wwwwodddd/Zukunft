#include <bits/stdc++.h>
using namespace std;
int n, x, mn = 1000;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		mn = min(mn, x);
	}
	printf("%d\n", mn);
	return 0;
}