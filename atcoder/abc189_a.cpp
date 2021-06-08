#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	cout << (s[0] == s[1] && s[1] == s[2] ? "Won" : "Lost") << endl;
}
