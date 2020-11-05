#include <bits/stdc++.h>
using namespace std;
string s[3] = {"none", "one", "both"};
int a, b, c, d, p, m, g;
int main()
{
	cin >> a >> b >> c >> d >> p >> m >> g;
	p--;
	m--;
	g--;
	b += a;
	d += c;
	cout << s[(p % b < a) + (p % d < c)] << endl;
	cout << s[(m % b < a) + (m % d < c)] << endl;
	cout << s[(g % b < a) + (g % d < c)] << endl;
	return 0;
}