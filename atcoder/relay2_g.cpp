#include <bits/stdc++.h>
using namespace std;
int n, x, y;
string s, t;
int main() {
	cin >> n >> s >> t;
	if (s + t > t + s) {
		swap(s, t);
	}
	for (int i = 0; i < n; i++) {
		if ((n - i * t.size()) % s.size() == 0) {
			x = (n - i * t.size()) / s.size();
			y = i;
			break;
		}
	}
	for (int i = 0; i < x; i++) {
		cout << s;
	}
	for (int i = 0; i < y; i++) {
		cout << t;
	}
	cout << endl;
	return 0;
}