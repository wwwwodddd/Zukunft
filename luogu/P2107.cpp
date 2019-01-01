#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, z;
ll m, s;
pair<ll, ll> a[100020];
priority_queue<ll> q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i].first > m) {
			break;
		}
		q.push(a[i].second);
		s += a[i].second;
		while (s + a[i].first > m) {
			s -= q.top();
			q.pop();
		}
		z = max(z, (int)q.size());
	}
	cout << z << endl;
}