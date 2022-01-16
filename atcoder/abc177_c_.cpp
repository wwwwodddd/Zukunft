#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long x, s, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z = (z + s * x) % p;
		s = (s + x) % p;
	}
	cout << z << endl;
	return 0;
}
