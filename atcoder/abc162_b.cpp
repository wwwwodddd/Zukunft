#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
long long S(long long n)
{
	return n * (n + 1) / 2;
}
int main()
{
	cin >> n;
	cout << S(n) - 3 * S(n / 3) - 5 * S(n / 5) + 15 * S(n / 15) << endl;
	return 0;
}
