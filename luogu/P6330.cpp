#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	cout << (a ^ c ^ e) << " " << (b ^ d ^ f) << endl;
}