#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		double s = 0;
		for (int i = 1; i < n; i++)
		{
			s += s / i + 1;
		}
		printf("%.9f\n", s / n + 1);
	}
	return 0;
}