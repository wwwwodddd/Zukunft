#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, z;
int main()
{
	cin >> a >> b >> c >> d;
	a--;
	long long l = c / __gcd(c, d) * d;
	z += b - a;
	z -= b / c - a / c;
	z -= b / d - a / d;
	z += b / l - a / l;
	cout << z << endl;
	return 0;
}
