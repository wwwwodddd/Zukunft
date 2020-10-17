#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g;
int main()
{
	scanf("%d:%d:%d %d:%d:%d %d", &a, &b, &c, &d, &e, &f, &g);
	printf("%lld\n", ((d - a) * 3600LL + (e - b) * 60 + (f - c)) * g);
	return 0;
}