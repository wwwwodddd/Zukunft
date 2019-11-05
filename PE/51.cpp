#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
bitset<100000001>v;
int t[10];
int main() {
	for (int i = t[0] = 1; i < 10; i++) {
		t[i] = t[i - 1] * 10;
	}
	int n = 1000000;
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i]) {
			continue;
		}
		for (int j = i + i; j <= n; j += i) {
			v[j] = 1;
		}
	}
	for (long long i = 1; i <= n; i++) {
		int weishu = 0;
		while (i >= t[weishu]) {
			weishu++;
		}
		for (int j = 1; j < 1 << weishu; j++) {
			int last = -1;
			int wrong = 0;
			for (int k = 0; k < weishu; k++) {
				if (j >> k & 1) {
					int zhewei = i / t[k] % 10;
					if (last == -1) {
						last = zhewei;
					}
					if (last != zhewei) {
						wrong = 1;
						break;
					}
				}
			}
			if (wrong) {
				continue;
			}
			int mask = 0;
			for (int k = 0; k < weishu; k++) {
				if (j >> k & 1) {
					mask += t[k];
				}
			}
			int guo = i - last * mask;
			int cnt = 0;
			int start = 0;
			if (2 * j >= 1 << weishu) {
				start = 1;
			}
			for (int j = start; j < 10; j++) {
				if (v[guo + mask * j] == 0) {
					cnt++;
				}
			}
			if (cnt >= 8) {
				printf("%d\n", cnt);
				printf("%lld\n", i);
				return 0;
			}
		}
	}
	return 0;
}