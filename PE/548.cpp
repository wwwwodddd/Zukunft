#include <bits/stdc++.h>
using namespace std;
map<vector<int>, long long> g;
long long n = 1e16;
long long F(vector<int> a);
long long dfs(const vector<int> &a, vector<int> &b) {
	if (b.size() == a.size()) {
		if (a == b) {
			return 0;
		}
		return F(b);
	}
	long long re = 0;
	for (int i = 0; i <= a[b.size()]; i++) {
		b.push_back(i);
		re += dfs(a, b);
		if (re > 2 * n) {
			re = 2 * n;
		}
		b.pop_back();
	}
	return re;
}
long long F(vector<int> a) {
	sort(a.begin(), a.end(), greater<int>());
	while (a.size() > 0 && a.back() == 0) {
		a.pop_back();
	}
	if (g.find(a) != g.end()) {
		return g[a];
	}
	vector<int> b;
	g[a] = dfs(a, b);
	return g[a];
}
long long ans = 0;
void calc(vector<int> &a) {
	long long re = F(a);
	if (re <= n) {
		vector<int> b;
		long long tmp = re;
		for (long long i = 2; i * i <= tmp; i++) {
			if (tmp % i == 0) {
				int cnt = 0;
				while (tmp % i == 0) {
					tmp /= i;
					cnt++;
				}
				b.push_back(cnt);
			}
		}
		if (tmp > 1) {
			b.push_back(1);
		}
		sort(b.begin(), b.end(), greater<int>());
		if (a == b) {
			ans += re;
			cout << re << endl;
		}
	} else {
		return;
	}
	if (a.size() == 0) {
		for (int i = 1; i < 70; i++) {
			a.push_back(i);
			calc(a);
			a.pop_back();
		}
	} else {
		for (int i = 1; i <= a.back(); i++) {
			a.push_back(i);
			calc(a);
			a.pop_back();
		}
	}
}
int main() {
	vector<int> a;
	g[a] = 1;
	calc(a);
	cout << ans << endl;
	return 0;
}