#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	cout << (max(a, c) <= min(b, d) ? "Yes" : "No") << endl;
	return 0;
}
