#include <bits/stdc++.h>
using namespace std;
long long a1, a2, n, d;
int main()
{
	cin >> a1 >> a2 >> n;
	d = a2 - a1;
	cout << (n * a1 + n * (n - 1) / 2 * d) << endl;
	return 0;
}