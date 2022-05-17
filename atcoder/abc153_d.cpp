#include <bits/stdc++.h>
using namespace std;
long long F(long long x)
{
	return x > 0 ? 1 + 2 * F(x / 2) : 0;
}
long long h;
int main()
{
	cin >> h;
	cout << F(h) << endl;
	return 0;
}
