#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> points[1000020];
int lastmin[1000020];
long long t;
vector<pair<int, int> > group[200020];
vector<long long> dp[200020];
vector<int> querys[800020];

void build(int x, int l, int r) {
	querys[x].clear();
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
}

void change(int x, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		querys[x].push_back(v);
		return;
	}
	if (R < l || r < L) {
		return;
	}
	int mid = (l + r) / 2;
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid + 1, r, L, R, v);
}

void solve(const vector<int> &querys, int l, int r, int L, int R, int index) {
	if (l > r) {
		return;
	}
	int mid = (l + r) / 2;
	int j = querys[mid];
	long long best = 1e18;
	int pos = -1;
	for (int k = L; k <= R; k++) {
		int dx = (group[index][j].first - group[index - 1][k].first);
		int dy = (group[index][j].second - group[index - 1][k].second);
		if (dx > 0 && dy > 0) {
			long long tmp = dp[index - 1][k] + (long long)dx * dy;
			if (best > tmp) {
				best = tmp;
				pos = k;
			}
		}
	}
	assert(pos != -1);
	dp[index][j] = min(dp[index][j], best);
	solve(querys, l, mid - 1, pos, R, index);
	solve(querys, mid + 1, r, L, pos, index);
}

void query(int x, int l, int r, int index) {
	solve(querys[x], 0, querys[x].size() - 1, l, r, index);
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	query(x * 2, l, mid, index);
	query(x * 2 + 1, mid + 1, r, index);
}

int main() {
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	points[n + 1] = make_pair(t, t);
	sort(points, points + n + 2);
	for (int i = 0; i < n + 2; i++) {
		lastmin[i] = 1e9;
	}
	int length = 0;
	for (int i = 0; i < n + 2; i++) {
		int L = -1;
		int R = n + 2;
		while (L < R - 1) {
			int M = (L + R) / 2;
			if (lastmin[M] < points[i].second) {
				L = M;
			} else {
				R = M;
			}
		}
		lastmin[R] = points[i].second;
		group[R].push_back(points[i]);
		length = max(length, R);
	}
	dp[0].resize(1);
	dp[0][0] = 0;
	for (int i = 1; i <= length; i++) {
		dp[i].resize(group[i].size());
		build(1, 0, dp[i-1].size() - 1);
		for (int j = 0; j < group[i].size(); j++) {
			dp[i][j] = 1e18;
			int st = -1, ed = -1;
			{
				int L = -1, R = group[i-1].size();
				while (L < R - 1) {
					int M = (L + R) / 2;
					if (group[i-1][M].second > group[i][j].second) {
						L = M;
					} else {
						R = M;
					}
				}
				st = R;
			}
			{
				int L = -1, R = group[i-1].size();
				while (L < R - 1) {
					int M = (L + R) / 2;
					if (group[i-1][M].first > group[i][j].first) {
						R = M;
					} else {
						L = M;
					}
				}
				ed = L;
			}
			change(1, 0, group[i-1].size() - 1, st, ed, j);
		}
		query(1, 0, group[i-1].size() - 1, i);
	}
	cout << dp[length][0] << endl;
	return 0;
}