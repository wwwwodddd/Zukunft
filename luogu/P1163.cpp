#include <bits/stdc++.h>
using namespace std;
double a, b;
int n;
int main()
{
	cin >> a >> b >> n;
	a /= b;
	double L = 1, R = 10;
	for (int _ = 0; _ < 100; _++)
	{
		double M = (L + R) / 2;
		double s = 0, r = 1;
		for (int i = 0; i < n; i++)
		{
			r /= M;
			s += r;
		}
		if (s > a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	printf("%.1f\n", ((L + R) / 2 - 1) * 100);
	return 0;
}