#include <bits/stdc++.h>
using namespace std;
int n, k, z;
int a[100020];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
		if (i >= k)
		{
			z = max(z, a[i] - a[i - k]);
		}
	}
	cout << z << endl;
	return 0;
}