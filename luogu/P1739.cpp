#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt++;
		} else if (s[i] == ')') {
			cnt--;
		}
		if (cnt < 0) {
			break;
		}
	}
	if (cnt == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}