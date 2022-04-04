#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[3];
int g[3];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		f[i%3] = min(g[(i-1)%3], g[(i+1)%3]);		
		g[i%3] = min(f[(i-1)%3], g[(i-1)%3]) + x;
	}
	printf("%d\n", min(f[n%3], g[n%3]));
	return 0;
}
