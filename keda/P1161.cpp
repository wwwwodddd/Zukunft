#include <bits/stdc++.h>
using namespace std;
string s;
long long p;
long long F(long long x, long long y)
{
	if (y < x)
	{
		return y;
	}
	long long p = F(2 * x, y);
	return p < x ? p : (p + x - 1) % x;
}
int main()
{
	cin >> s >> p;
	cout << s[F(s.size(), p - 1)] << endl;
	return 0;
}