#include <bits/stdc++.h>
using namespace std;
long long n;
long long z;
int main()
{
	cin >> n;
	z = n;
	for (int b = 0; b < 62; b++)
	{
		z = min(z, (n >> b) + b + (n % (1LL << b)));
	}
	cout << z << endl;
	return 0;
}
