#include <bits/stdc++.h>
using namespace std;
const int p = 6662333;
long long n;
long long pw(long long x, long long y)
{
	long long re = 1;
	for (; y; y >>= 1)
	{
		if (y & 1)
		{
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main()
{
	cin >> n;
	cout << pw(2, n - 1) << endl;
	return 0;
}