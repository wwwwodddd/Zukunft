#include <bits/stdc++.h>
using namespace std;
int x, y, n;
int main()
{
	cin >> x >> y >> n;
	cout << n / x + n / y - n / lcm(x, y) << endl;
	return 0;
}