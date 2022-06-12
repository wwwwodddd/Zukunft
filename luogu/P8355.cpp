#include <bits/stdc++.h>
using namespace std;
string s;
int n, x;
int main()
{
	cin >> n >> s;
	for (char c : s)
	{
		x += c == '(';
	}
	cout << min(x, n - x) * 2 << endl;
	return 0;
}
