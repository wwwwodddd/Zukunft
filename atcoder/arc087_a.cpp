#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int c[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > n)
		{
			z++;
		}
		else
		{
			c[x]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] < i)
		{
			z += c[i];
		}
		else
		{
			z += c[i] - i;
		}
	}
	cout << z << endl;
	return 0;
}
