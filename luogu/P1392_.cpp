#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
int a[1020];
int b[1020];
int p[1020];
vector<int> F(const vector<int> &a, const vector<int> &b) {
	memset(p, 0, sizeof p);
	priority_queue<pair<int, int> > q;
	for (int i = 0; i < k; i++) {
		q.push(make_pair(-a[p[i]] - b[i], i));
	}
	vector<int> re;
	for (int i = 0; i < k; i++) {
		pair<int, int> u = q.top();
		q.pop();
		re.push_back(-u.first);
		p[u.second]++;
		if (p[u.second] < a.size()) {
			q.push(make_pair(-a[p[u.second]] - b[u.second], u.second));
		}
	}
	return re;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		vector<int> b;
		for (int j = 0; j < m; j++) {
			scanf("%d", &x);
			b.push_back(x);
		}
		sort(b.begin(), b.end());
		b.resize(k);
		if (i > 0) {
			a = F(a, b);
		} else {
			a = b;
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}