#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int in[200020];
int pos[200020], cnt;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
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
		if (q.size() > 1) {
			cout << "No" << endl;
			return 0;
		}
		int u = q.front(); // top
		q.pop();
		pos[u] = ++cnt;
		for (int i = 0; i < a[u].size(); i++) {
			in[a[u][i]]--;
			if (in[a[u][i]] == 0) {
				q.push(a[u][i]);
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++) {
		cout << pos[i] << " ";
	}
	return 0;
}