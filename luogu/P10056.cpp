#include <bits/stdc++.h>
using namespace std;
long long a, b, n;
int main()
{
	cin >> a >> b >> n;
	cout << b * min(a / b, n) << endl;
	return 0;
}