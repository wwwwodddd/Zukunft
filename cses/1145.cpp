#include <bits/stdc++.h>
using namespace std;
int n, x;
int f[200020];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		*lower_bound(f, f + n, x) = x;
	}
	cout << (lower_bound(f, f + n, 0x3f3f3f3f) - f) << endl;
	return 0;
}