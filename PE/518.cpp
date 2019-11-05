#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
bitset<100000001>v;
long long guoqianyunhaolihaia(long long x) {
	long long qianyunguo = 1;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				x /= i;
				cnt++;
			}
			cnt = (cnt + 1) / 2;
			for (int j = 1; j <= cnt; j++) {
				qianyunguo *= i;
			}
		}
	}
	if (x > 0) {
		qianyunguo *= x;
	}
	return qianyunguo;
}
int main() {
	int n = 100000000;
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i + i; j <= n; j += i) {
			v[j] = 1;
		}
	}
	long long sum = 0;
	for (long long i = 2; i < n; i++) {
		if (i % 1000000 == 0) {
			printf("%lld\n", i);
		}
		if (v[i]) {
			continue;
		}
		long long gqy = guoqianyunhaolihaia(i + 1);
		for (long long j = i + 1 + gqy; j * j / (i + 1) <= n; j += gqy) {
			if (v[j - 1] == 0 && v[j * j / (i + 1) - 1] == 0) {
//				printf("%lld %lld %lld\n", i, j - 1, j * j / (i + 1) - 1);
				sum += i + j - 1 + j * j / (i + 1) - 1;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}