#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		double n, z = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			z += n / i;
		}
		printf("%.2f\n", z);
	}
	return 0;
}