#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > s;
long long z;
void add(int i, int x) {
	while (s.size() > 0 && s.back().second >= x) {
		s.pop_back();
	}
	s.push_back(make_pair(i, x));
	long long t = 0;
	for (int i = 0; i < s.size(); i++) {
		z += (s[i].first - t) * s[i].second;
		t = s[i].first;
	}
	return;
}
int main() {
	int n, x = 290797;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		x = (long long)x * x % 50515093;
		add(i, x);
		if (i % 1000000 == 0) {
			cerr << i << ' ' << s.size() << endl;
		}
	}
	cout << z << endl;
	return 0;
}