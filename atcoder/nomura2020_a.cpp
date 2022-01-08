#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, k;
int main()
{
	cin >> a >> b >> c >> d >> k;
	cout << (c - a) * 60 + d - b - k << endl;
	return 0;
}
