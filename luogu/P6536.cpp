#include <bits/stdc++.h>
using namespace std;
int n, m;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	cin >> n >> m;
	cout << m - gcd(n, m) << endl;
	return 0;
}