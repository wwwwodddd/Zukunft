#include <bits/stdc++.h>
using namespace std;
long long n;
int F(int n)
{
	int r = 0;
	while (n > 0)
	{
		n -= (n + 2) / 3;
		r++;
	}
	return r;
}
int G(int n)
{
	if (n % 3 == 1)
	{
		return 1;
	}
	return G(n - (n + 2) / 3) + 1;
}
int main()
{
	cin >> n;
	cout << F(n) << " " << G(n) << endl;
	return 0;
}