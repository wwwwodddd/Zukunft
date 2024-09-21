#include <bits/stdc++.h>
using namespace std;
int n;
long long x, s, z = -1e18;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s = max(s, 0LL) + x;
		z = max(z, s);
	}
	cout << z << endl;
	return 0;
}