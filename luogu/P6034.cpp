#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long n, z, c;
int main() {
	cin >> n;
	n++;
	for (int i = 60; i >= 0; i--)
	{
		z = z * 3 % mod;
		if (n >> i & 1)
		{
			z = (z + (1LL << c++)) % mod;
		}
	}
	cout << (z - n % mod + mod) % mod << endl;
	return 0;
}