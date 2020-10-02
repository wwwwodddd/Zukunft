#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%*d%d%d", &x, &y);
		puts(x + y > 140 && 7 * x + 3 * y >= 800 ? "Excellent" : "Not excellent");
	}
	return 0;
}