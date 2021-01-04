#include <bits/stdc++.h>
using namespace std;
const int M = 5e6;
int t, n;
int v[M + 20];
int phif[M + 20], muf[M + 20];
long long phis[M + 20], mus[M + 20];
map<long long, long long> phig, mug;
void init() {
	for (int i = 2; i <= M; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= M; j += i) {
				v[j] = i;
			}
		}
	}
	phif[1] = 1;
	muf[1] = 1;
	for (int i = 2; i <= M; i++) {
		if (v[i] == v[i / v[i]]) {
			phif[i] = phif[i / v[i]] * v[i];
			muf[i] = 0;
		} else {
			phif[i] = phif[i / v[i]] * (v[i] - 1);
			muf[i] = -muf[i / v[i]];
		}
	}
	for (int i = 1; i <= M; i++) {
		phis[i] = (phis[i - 1] + phif[i]);
		mus[i] = (mus[i - 1] + muf[i]);
	}
}
long long phisum(long long n) {
	if (n <= M) {
		return phis[n];
	}
	if (phig.find(n) != phig.end()) {
		return phig[n];
	}
	long long &re = phig[n];
	re = n;
	re = re * (re + 1) / 2;
	for (long long i = 2, l; i <= n; i = l + 1) {
		l = n / (n / i);
		re = re - (l - i + 1) * phisum(n / i);
	}
	return re;
}
long long musum(long long n) {
	if (n <= M) {
		return mus[n];
	}
	if (mug.find(n) != mug.end()) {
		return mug[n];
	}
	long long &re = mug[n];
	re = 1;
	for (long long i = 2, l; i <= n; i = l + 1) {
		l = n / (n / i);
		re = (re - (l - i + 1) * musum(n / i));
	}
	return re;
}
int main() {
	init();
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> n;
		cout << phisum(n) << ' ' << musum(n) << endl;
	}
	return 0;
}