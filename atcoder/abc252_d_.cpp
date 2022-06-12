#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	long long z = n * (n - 1) * (n - 2);
	for (int i = 0; i < 200010; i++)
	{
		z -= c[i] * (c[i] - 1LL) * (n - 2) * 3;
		z += c[i] * (c[i] - 1LL) * (c[i] - 2) * 2;
	}
	z /= 6;
	cout << z << endl;
	return 0;
}
