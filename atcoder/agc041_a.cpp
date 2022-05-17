#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main()
{
	cin >> n >> a >> b;
	if (b - a & 1)
	{
		cout << min((a + b - 1), (2 * n - a - b + 1)) / 2 << endl;
	}
	else
	{
		cout << (b - a) / 2 << endl;
	}
	return 0;
}
