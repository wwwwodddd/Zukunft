#include <bits/stdc++.h>
using namespace std;
int l, r;
string s;
int main()
{
	cin >> l >> r >> s;
	reverse(s.begin() + l - 1, s.begin() + r);
	cout << s << endl;
	return 0;
}
