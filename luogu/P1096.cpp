#include <bits/stdc++.h>
using namespace std;
stringstream ss;
string s;
int n;
int main() {
	cin >> n;
	ss << fixed << setprecision(0) << pow(2, n + 1);
	ss >> s; // s = ss.str();
	s[s.size() - 1] -= 2;
	cout << s << endl;
	return 0;
}