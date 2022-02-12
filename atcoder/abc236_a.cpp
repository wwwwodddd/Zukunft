#include <bits/stdc++.h>
using namespace std;
string s;
int a, b;
int main()
{
	cin >> s >> a >> b;
	swap(s[a - 1], s[b - 1]);
	cout << s << endl;
	return 0;
}