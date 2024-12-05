#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	scanf("%d/%d%d/%d", &a, &b, &c, &d);
	a *= c;
	b *= d;
	printf("%d %d\n", b / gcd(a, b), a / gcd(a, b));
	return 0;
}