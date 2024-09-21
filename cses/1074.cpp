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
		z += abs(a[i] - a[n / 2]);
	}
	cout << z << endl;
	return 0;
}