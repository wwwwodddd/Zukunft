#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[500020];
long long z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == i)
		{
			z += c;
			c++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > i && a[a[i]] == i)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
