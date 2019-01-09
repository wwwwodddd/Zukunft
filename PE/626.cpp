#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > f[21];
int p = 1001001011;
long long z;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
long long pw(long long x, long long y) {
	long long re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
bool alleven(vector<int> a) {
	for (int i: a) {
		if (i & 1) {
			return false;
		}
	}
	return true;
}
bool allodd(vector<int> a, vector<int> b) {
	int ga = 32;
	int gb = 32;
	for (int i: a) {
		ga = gcd(ga, i);
	}
	for (int i: b) {
		gb = gcd(gb, i);
	}
	return ga == gb;
}
int main() {
	int n = 20;
	f[0].push_back(vector<int>(0, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + i <= n; j++) {
			for (vector<int> a: f[j]) {
				a.push_back(i);
				f[j + i].push_back(a);
			}
		}
	}
	for (vector<int> a: f[n]) {
		for (vector<int> b: f[n]) {
			long long u = 1;
			for (int i = 1; i <= n; i++) {
				u = u * i % p;
			}
			for (int i = 1; i <= n; i++) {
				u = u * i % p;
			}
			{
				int cnt = 0;
				for (int i = 0; i < a.size(); i++) {
					if (i == 0 || a[i] != a[i - 1]) {
						cnt = 0;
					}
					cnt++;
					u = u * pw(a[i], p - 2) % p;
					u = u * pw(cnt, p - 2) % p;
				}
			}
			{
				int cnt = 0;
				for (int i = 0; i < b.size(); i++) {
					if (i == 0 || b[i] != b[i - 1]) {
						cnt = 0;
					}
					cnt++;
					u = u * pw(b[i], p - 2) % p;
					u = u * pw(cnt, p - 2) % p;
				}
			}
			{
				int cnt = 0, cnt0 = 0, cnt1 = 0;
				for (int i: a) {
					bool flag = true;
					for (int j: b) {
						if ((j / gcd(i, j)) % 2 != 0) {
							flag = false;
						}
					}
					if (flag) {
						cnt0 += i;
					} else {
						cnt0 += i - 1;
					}
				}
				for (int i: b) {
					bool flag = true;
					for (int j: a) {
						if ((j / gcd(i, j)) % 2 != 0) {
							flag = false;
						}
					}
					if (flag) {
						cnt0 += i;
					} else {
						cnt0 += i - 1;
					}
				}
				for (int i: a) {
					for (int j: b) {
						cnt += gcd(i, j);
					}
				}
				u = u * pw(2, cnt) % p;
				long long t = pw(2, cnt0);
				if (allodd(a, b)) {
					cnt1 = 2 * n - a.size() - b.size();
					t = (t + pw(2, cnt1)) % p;
				}
				u = u * t % p;
			}
			/*
			for (int i: a) {
				printf("%d ", i);
			}
			for (int i: b) {
				printf("%d ", i);
			}
			printf("u=%lld\n", u);
			*/
			z = (z + u) % p;
		}
	}
	for (int i = 1; i <= n; i++) {
		z = z * pw(i, p - 2) % p;
		z = z * pw(2, p - 2) % p;
	}
	for (int i = 1; i <= n; i++) {
		z = z * pw(i, p - 2) % p;
		z = z * pw(2, p - 2) % p;
	}
	printf("%lld\n", z);
	return 0;
}