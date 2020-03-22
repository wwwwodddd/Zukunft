#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n, x, y, z;
long long ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[2 * i] = make_pair(x, z);
		a[2 * i + 1] = make_pair(y, -z);
	}
	sort(a, a + 2 * n);
	multiset<int> s;
	s.insert(0);
	for (int i = 0; i + 1 < 2 * n; i++) {
		if (a[i].second > 0) {
			s.insert(a[i].second);
		} else {
			s.erase(s.find(-a[i].second));
		}
		ans += (long long)(a[i + 1].first - a[i].first) * (*--s.end());
	}
	cout << ans << endl;
}