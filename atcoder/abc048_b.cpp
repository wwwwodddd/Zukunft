#include <bits/stdc++.h>
using namespace std;
long long a, b, x;
long long F(long long n)
{
	return (n + x - 1) / x;
}
int main()
{
	cin >> a >> b >> x;
	cout << F(b + 1) - F(a) << endl;
}
