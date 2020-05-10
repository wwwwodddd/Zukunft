#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
long long ans = -1e18;
int w[100020];
vector<int> a[100020];
pair<long long, long long> dfs(int x, int y) {
//	printf("%d %d\n", x, y);
	vector<long long>r;
	long long s = w[x];
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] == y) {
			continue;
		}
		pair<long long, long long> u = dfs(a[x][i], x);
		s += u.first;
		r.push_back(u.second);
	}
	sort(r.begin(), r.end());
	reverse(r.begin(), r.end());
	if (r.size() >= 2) {
		ans = max(ans, r[0] + r[1]);
	}
	if (r.size() >= 1) {
		return make_pair(s, max(s, r[0]));
	} else {
		return make_pair(s, s);		
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	if (ans == -1e18) {
		puts("Impossible");
	} else {
		cout << ans << endl;
	}
	return 0;
}