#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int l = 1; l != 2; l = a[l])
	{
		z++;
		if (z > n)
		{
			z = -1;
			break;
		}
	}
	cout << z << endl;
	return 0;
}
