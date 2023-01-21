#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main()
{
	cin >> a >> b;
	long long r = pow(a * 0.5 / b, 2. / 3);
	double z = a;
	for (long long g = max(r - 10, 1LL); g <= r + 10; g++)
	{
		z = min(z, a / sqrt(g) + (g - 1) * b);
	}
	cout << fixed << setprecision(9) << z << endl;
	return 0;
}
