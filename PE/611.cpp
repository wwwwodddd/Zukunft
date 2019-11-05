#include <bits/stdc++.h>
using namespace std;
bool v[10101010];
long long fuck(long long l, long long r) {
	memset(v, 0, sizeof v);
	for (long long i = 1; i * i <= r; i++) {
		long long j = max(i + 1, (long long)ceil(sqrt(l - i * i)));
		while (i * i + j * j <= r) {
			if (i * i + j * j >= l) {
				v[i * i + j * j - l] ^= 1;
			}
			j++;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= r - l; i++) {
		if (v[i]) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	long long n = 1e12;
	long long l = 0;
	long long r = 0;
	long long ans = 0;
	while (true) {
		l = r + 1;
		r += 10000000;
		r = min(r, n);
		if (r % 100000000 == 0) {
			cerr << l << ' ' << r << endl;
		}
		ans += fuck(l, r);
		if (r == n) {
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int v[1000020];
int n = 1e6;
bool P(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool Q(int x) {
	if (x % 2 == 0) {
		return Q(x / 2);
	}
	if (x == 1) {
		return false;
	}
	map<int, int> g;
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			g[i]++;
			x /= i;
		}
	}
	if (x > 1) {
		g[x]++;
	}
	int cnt = 0, sum = 0;
	bool mask = false;
	vector<int> cao;
	for (pair<int, int> i: g) {
		if (i.first % 4 == 3 && i.second % 2 == 1) {
			return false;
		}
		if (i.first % 4 == 1) {
			cao.push_back(i.second);
		}
	}
	sort(cao.begin(), cao.end());
	if (cao == vector<int>({})) {
		return false;
	}
	if (cao == vector<int>({3})) {
		return false;
	}
	if (cao == vector<int>({4})) {
		return false;
	}
	if (cao == vector<int>({7})) {
		return false;
	}
	if (cao == vector<int>({8})) {
		return false;
	}
	if (cao == vector<int>({1, 1})) {
		return false;
	}
	if (cao == vector<int>({1, 3})) {
		return false;
	}
	if (cao == vector<int>({1, 5})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 1})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 2})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 3})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 4})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 5})) {
		return false;
	}
	if (cao == vector<int>({1, 2, 3})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 1, 1})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 1, 2})) {
		return false;
	}
	if (cao == vector<int>({1, 1, 1, 3})) {
		return false;
	}
	if (cao == vector<int>({2, 2})) {
		return false;
	}
	if (cao == vector<int>({2, 3})) {
		return false;
	}
	if (cao == vector<int>({3, 3})) {
		return false;
	}
	return true;
}
int main() {
	for (int i = 1; i * i <= n; i++) {
		for (int j = i + 1; i * i + j * j <= n; j++) {
			v[i * i + j * j] ^= 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (v[i] != Q(i)) {
			printf("%d %d %d\n", i, v[i], Q(i));
			break;
		}
		if (v[i]) {
			cnt++;
		}

	}
	printf("cnt %d\n", cnt);
	return 0;
}
*/