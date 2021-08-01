#include <bits/stdc++.h>
using namespace std;
int n, k, s, z;
int a[100020];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
		if (i > k)
		{
			s -= a[i - k];
		}
		if (i >= k)
		{
			z = max(z, s);
		}
	}
	cout << z << endl;
	return 0;
}