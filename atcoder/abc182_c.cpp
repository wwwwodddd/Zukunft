#include <bits/stdc++.h>
using namespace std;
long long n;
int d[3], c;
int main()
{
	cin >> n;
	for (long long m = n; m > 0; m /= 10)
	{
		d[m % 10 % 3]++;
		c++;
	}
	if (n % 3 == 0)
	{
		cout << 0 << endl;
	}
	else if (d[n % 3] > 0)
	{
		cout << (c == 1 ? -1 : 1) << endl;
	}
	else
	{
		cout << (c == 2 ? -1 : 2) << endl;
	}
	return 0;
}
