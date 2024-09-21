#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	a[n] = 1e18;
	long long s = 0;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] <= s + 1)
		{
			s += a[i];
		}
		else
		{
			cout << s + 1 << endl;
			break;
		}
	}
	return 0;
}