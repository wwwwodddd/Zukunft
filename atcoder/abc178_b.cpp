#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
	return 0;
}
