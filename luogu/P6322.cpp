#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main()
{
	cin >> n >> x;
	for (int i = 1; i < n; i++)
	{
		cin >> y;
		int g = __gcd(x, y);
		cout << x / g << "/" << y / g << endl;
	}
	return 0;
}
