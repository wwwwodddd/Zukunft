#include <bits/stdc++.h>
using namespace std;
long long n, m, z;
int main()
{
	cin >> n >> m;
	if (n >= 3 * m)
	{
		z = (n - m) / (2 * m);
		n -= 2 * m * z;
	}
	while (n > 1)
	{
		n = (n + 2) / 3;
		z++;
	}
	cout << z << endl;
	return 0;
}