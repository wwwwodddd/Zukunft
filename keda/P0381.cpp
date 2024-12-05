#include <bits/stdc++.h>
using namespace std;
int n, a[101], z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 1; i < n; i++)
	{
		if (a[n] * i != a[i] * n)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}