#include <iostream>
using namespace std;
bool P(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int F(int x) {
	int a[10], c = 0;
	for (int i = 0; i < 9; i++) {
		if (x >> i & 1) {
			a[c++] = i + 1;
		}
	}
	int cnt = 0;
	do {
		int t = 0;
		for (int i = 0; i < c; i++) {
			t = 10 * t + a[i];
		}
		if (P(t)) {
			cnt++;
		}
	} while(next_permutation(a, a + c));
	return cnt;
}
int v[2048];
long long f[2048];
int main() {
	for (int i = 0; i < 1 << 9; i++) {
		v[i] = F(i);
	}
	f[0] = 1;
	for (int i = 1; i < 1 << 9; i++) {
		int l = i & -i;
		for (int j = i; j; j = (j - 1) & i) {
			if (j & l) {
				f[i] += f[i ^ j] * v[j];
			}
		}
	}
	printf("%lld\n", f[511]);
	return 0;
}