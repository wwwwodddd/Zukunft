#include <bits/stdc++.h>
using namespace std;
int t, n, m;
bool v[256];
string s;
int get(string s) {
	if (s[0] == 'n') {
		return 10000;
	}
	int x;
	sscanf(s.c_str(), "%d", &x);
	return x;
}
int main() {
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n >> s;
		if (s[2] == '1') {
			m = 0;
		} else {
			sscanf(s.c_str(), "O(n^%d)", &m);
		}
		stack<pair<char, int> > st;
		bool err = false;
		memset(v, 0, sizeof v);
		int ans = 0, now = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "E") {
				if (st.size()) {
					v[st.top().first] = false;
					now -= st.top().second;
					st.pop();
				} else {
					err = true;
				}
			} else {
				string x, y, z;
				cin >> x >> y >> z;
				if (v[x[0]]) {
					err = true;
				}
				v[x[0]] = true;
				int d = get(z) - get(y) + 1;
				if (d <= 0) {
					d = -100;
				} else if (d > 1000) {
					d = 1;
				} else {
					d = 0;
				}
				now += d;
				ans = max(ans, now);
				st.push(make_pair(x[0], d));
			}
		}
		err |= st.size() > 0;
//		fprintf(stderr, "%d %d\n", m, ans);
		if (err) {
			printf("ERR\n");
		} else {
			printf("%s\n", m == ans ? "Yes" : "No");
		}
	}
	return 0;
}