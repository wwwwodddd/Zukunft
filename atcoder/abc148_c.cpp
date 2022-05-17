#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y)
{
	return x / gcd(x, y) * y;
}
int main()
{
	cin >> x >> y;
	cout << lcm(x, y) << endl;
	return 0;	
}
