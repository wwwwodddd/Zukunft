#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main()
{
	cin >> a >> b >> c;
	long long d = c - a - b;
	cout << (d > 0 && d * d > 4 * a * b ? "Yes" : "No") << endl;
	return 0;
}
