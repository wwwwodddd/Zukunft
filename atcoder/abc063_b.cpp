#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	sort(s.begin(), s.end());
	cout << (unique(s.begin(), s.end()) == s.end() ? "yes" : "no") << endl;
	return 0;
}
