#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long n, k;
int main()
{
	cin >> n >> k;
	cout << ((n * n - 1) % p * k + 1) % p << endl;
	return 0;
}
