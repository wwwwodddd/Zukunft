#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		z += a[i] * (2 * i + 1LL - n);
	}
	cout << z << endl;
	return 0;
}
