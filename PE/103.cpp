#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n = 7;
int a[10];
bool test(int x) {
	vector<pair<int, int> >b;
	for (int i = 0; i < 1 << x; i++) {
		int s = 0;
		int c = 0;
		for (int j = 0; j < x; j++) {
			if (i >> j & 1) {
				s += a[j];
				c += 1;
			}
		}
		b.push_back(make_pair(s, c));
	}
	sort(b.begin(), b.end());
	for (int i = 1; i < b.size(); i++) {
		if (b[i - 1].first == b[i].first) {
			return false;
		}
		if (b[i - 1].second > b[i].second) {
			return false;
		}
	}
	return true;
}
void dfs(int x, int y) {
	if (!test(x)) {
		return;
	} 
	if (x == n) {
		int sum = 0;
		for (int i = n - 1; i >= 0; i--) {
			printf("%d", a[i]);
			sum += a[i];
		}
		printf("%d\n", sum);
//		exit(0);
	}
	if (x == 0) {
		a[x] = y;
		dfs(x + 1, y);
	} else {
		for (int i = y - 1; i >= 0; i--) {
			a[x] = i;
			dfs(x + 1, i);
		}
	}
}
int main() {
	for (int i = 0; i < 100; i++) {
		dfs(0, i);
	}
	return 0;
}