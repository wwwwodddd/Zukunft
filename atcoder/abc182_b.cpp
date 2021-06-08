#include <bits/stdc++.h>
using namespace std;
int n, x, a[1001], m, r;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
	}
	for (int i = 2; i <= 1000; i++)
	{
		int c = 0;
		for (int j = i; j <= 1000; j += i)
		{
			c += a[j];
		}
		if (m < c)
		{
			m = c;
			r = i;
		}
	}
	cout << r << endl;
	return 0;
}
