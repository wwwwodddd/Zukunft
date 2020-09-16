#include <bits/stdc++.h>
using namespace std;
double a, b, c, p;
int main()
{
	cin >> a >> b >> c;
	p = (a + b + c) / 2;
	printf("%.1f\n", sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}