#include <bits/stdc++.h>
using namespace std;
void P(long long n)
{
	if (n)
	{
		P(n / 2);
		cout << n % 2 * 2;
	}
}
int main()
{
	long long n;
	cin >> n;
	P(n);
	return 0;
}
