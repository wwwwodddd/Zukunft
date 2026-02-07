#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	double s = (a + b + c) / 2;
	if (s <= a || s <= b || s <= c)
	{
		printf("No solution.\n");
	}
	else
	{
		printf("%.2f\n", sqrt(s * (s - a) * (s - b) * (s - c)));
	}
	return 0;
}