#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a % c != 0 || b % c != 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << (a / c) * (b / c) << endl;
	}
	return 0;
}