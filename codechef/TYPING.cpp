#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		set<string> s;
		string t;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> t;
			int tmp = t.size() * 2;
			int d = 1;
			if (s.find(t) != s.end()) {
				d = 2;
			}
			s.insert(t);
			for (int j = 0; j < t.size(); j++) {
				if (t[j] == 'f') {
					t[j] = 'd';
				}
				if (t[j] == 'k') {
					t[j] = 'j';
				}
				if (j > 0 && t[j] == t[j - 1]) {
					tmp += 2;
				}
			}
			ans += tmp / d;
		}
		printf("%d\n", ans);
	}
}