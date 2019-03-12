#include <bits/stdc++.h>
using namespace std;
int n, p1, p2, x, y;
vector<int> a[100020];
int in[100020];
int pos[100020], cnt;
int main() {
	cin >> n >> p1 >> p2;
	for (int i = 0; i < p1; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		in[y]++;
	}
	queue<int> q; // stack
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (q.size() > 0) {
		int u = q.front(); // top
		q.pop();
		pos[u] = cnt++;
		for (int i = 0; i < a[u].size(); i++) {
			in[a[u][i]]--;
			if (in[a[u][i]] == 0) {
				q.push(a[u][i]);
			}
		}
	}
	for (int i = 0; i < p2; i++) {
		cin >> x >> y;
		if (pos[x] < pos[y]) {
			cout << x << ' ' << y << endl;
		} else {
			cout << y << ' ' << x << endl;
		}
	}
	return 0;
}