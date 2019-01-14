#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[2020];
vector<pair<int, int> > res;
int center;
int query(int x, int y, int z) {
	if (x == y) {
		return x;
	}
	if (x == z) {
		return x;
	}
	if (z == y) {
		return z;
	}
	int r;
	printf("Q %d %d %d\n", x, y, z);
	fflush(stdout);
	scanf("%d", &r);
	return r;
}
bool cmp(int x, int y) {
	int t = query(center, x, y);
	assert(t == x || t == y);
	return t == x;
}
void solve(int x) {
	if (a[x].size() == 0) {
		return;
	}
	int y = a[x][rand() % a[x].size()];
	vector<int> o;
	o.swap(a[x]);
	set<int> b;
	for (int z: o) {
		if (z != y) {
			int t = query(x, y, z);
			b.insert(t);
			if (z != t) {
				a[t].push_back(z);
			}
		}
	}
	center = x;
	b.insert(x);
	b.insert(y);
	vector<int> bb(b.begin(), b.end());
	sort(bb.begin(), bb.end(), cmp);
//	printf("b[%d]:", x);
//	for (int i: bb) {
//		printf(" %d", i);
//	}
//	printf("\n");
	for (int i = 1; i < bb.size(); i++) {
		res.push_back(make_pair(bb[i - 1], bb[i]));
	}
	solve(x);
	for (int i: bb) {
		solve(i);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		a[1].push_back(i);
	}
	solve(1);
	printf("A\n");
	for (pair<int, int> u: res) {
		printf("%d %d\n", u.first, u.second);
	}
	return 0;
}