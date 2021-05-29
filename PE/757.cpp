#include <bits/stdc++.h>
using namespace std;
long long a[300000020];
int c;
long long N = 100000000000000LL;
int main()
{
	for (int i = 1; i <= 10000000; i++)
	{
		for (int j = 1; i * j <= 10000000; j++)
		{
			a[c] = (long long)i * (i + 1) * j * (j + 1);
			if (a[c] <= N)
			{
				c++;
			}
		}
	}
	sort(a, a + c);
	c = unique(a, a + c) - a;
	cout << c << endl;
	return 0;
}