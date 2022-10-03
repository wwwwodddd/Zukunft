#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		long long r = sqrt(n);
		puts(r * r == n ? "YES" : "NO");
	}
	return 0;
}