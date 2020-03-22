#include <bits/stdc++.h>
using namespace std;
int n, p1, p2, x, y;
vector<int> a[100020];
bool v[100020];
int pos[100020], cnt;
void dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		if (!v[a[x][i]]) {
			dfs(a[x][i]);
		}
	}
	v[x] = true;
	pos[x] = cnt++;	
}
int main() {
	cin >> n >> p1 >> p2;
	for (int i = 0; i < p1; i++) {
		cin >> x >> y;
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < p2; i++) {
		cin >> x >> y;
		if (pos[x] > pos[y]) {
			cout << x << ' ' << y << endl;
		} else {
			cout << y << ' ' << x << endl;
		}
	}
	return 0;
}