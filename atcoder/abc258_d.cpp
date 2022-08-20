#include <bits/stdc++.h>
using namespace std;
int n, x;
long long a, b, s, z = 9e18;
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n && i <= x; i++)
	{
		cin >> a >> b;
		s += a + b;
		z = min(z, s + (x - i) * b);
	}
	cout << z << endl;
	return 0;
}
