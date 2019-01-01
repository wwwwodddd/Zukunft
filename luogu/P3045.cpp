#include <bits/stdc++.h>
using namespace std;
int n, k;
long long m, s;
int c[100020];
int p[100020];
pair<int, int> a[100020];
pair<int, int> b[100020];
bool v[100020];
int main() {
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> c[i];
		a[i].first = c[i];
		b[i].first = p[i];
		a[i].second = b[i].second = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	priority_queue<int, vector<int>, greater<int> > q;
	q.push(1000000000);
	for (int i = 0; i < k; i++) {
		q.push(0);
	}
	int pa = 0;
	int pb = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (v[a[pa].second]) {
			pa++;
		}
		while (v[b[pb].second]) {
			pb++;
		}
		if (a[pa].first + q.top() < b[pb].first) {
			v[a[pa].second] = true;
			s += a[pa].first + q.top();
			q.pop();
			q.push(p[a[pa].second] - a[pa].first);
			assert(c[a[pa].second] == a[pa].first);
		} else {
			v[b[pb].second] = true;
			s += b[pb].first;
		}
		if (s <= m) {
			ans = max(ans, i + 1);
		}
	}
	cout << ans << endl;
}