#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	if (-(1LL<<31) <= n && n < (1LL<<31))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}