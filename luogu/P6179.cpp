#include <bits/stdc++.h>
using namespace std;
int n, a[50020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int z = n;
	for (int i = 0; i < n; i++)
	{
		z = min(z, n + 2 * i + 1 - a[i]);
	}
	cout << z << endl;
	return 0;
}