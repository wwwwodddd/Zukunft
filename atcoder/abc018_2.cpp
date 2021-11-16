#include <bits/stdc++.h>
using namespace std;
string s;
int n, l, r;
int main()
{
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		reverse(s.begin() + l - 1, s.begin() + r);
	}
	cout << s << endl;
}
