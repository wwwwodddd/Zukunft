#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> y;
		z = __gcd(z, abs(x - y));
	}
	cout << z << endl;
	return 0;
}
