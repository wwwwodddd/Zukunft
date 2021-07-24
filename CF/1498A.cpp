#include <bits/stdc++.h>
using namespace std;
long long S(long long x)
{
	return x < 10 ? x : S(x / 10) + x % 10;
}
int main()
{
	int t;
	long long n;
	for (cin >> t; t--;)
	{
		for (cin >> n; __gcd(n, S(n)) == 1; n++);
		cout << n << endl;		
	}
	return 0;
}
