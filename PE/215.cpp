#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int>a;
vector<vector<int> >all;
long long g[12][4000];
int n = 32;
int m = 10 - 1;
bool f[4000][4000];
void dfs(int x) {
	if (x == 0) {
		all.push_back(a);
	}
	if (x <= 0) {
		return;
	}
	a.push_back(x);
	dfs(x - 2);
	dfs(x - 3);
	a.pop_back();
}

bool F(vector<int> a, vector<int> b) {
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	dfs(n);
	printf("%lu\n", all.size());
	for (int i = 0; i < all.size(); i++) {
		g[0][i] = 1;
	}
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < all.size(); j++) {
			if (F(all[i], all[j])) {
				f[i][j] = true;
			} else {
				f[i][j] = false;
			}
		}
	}
	printf("%lu\n", all.size());
	for (int k = 1; k <= m; k++) {
		for (int i = 0; i < all.size(); i++) {
			for (int j = 0; j < all.size(); j++) {
				if (f[i][j]) {
					g[k][i] += g[k - 1][j];
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < all.size(); i++) {
		ans += g[m][i];
	}
	printf("%lld\n", ans);
	return 0;
}