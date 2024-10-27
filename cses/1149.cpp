#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long f[256], r, t;
string s;
int main()
{
	cin >> s;
	for (char c : s)
	{
		t = (r + p - f[c]) % p;
		f[c] = (r + 1) % p;
		r = (t + f[c]) % p;
	}
	cout << r << endl;
	return 0;
}