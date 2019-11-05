#include <bits/stdc++.h>
using namespace std;
int a[20020];
int b[20020], c;
int v[1000020];
int p = 1004535809;
int n = 20000;
int k = 20000;
void mul(int a[], int b[]) {
	int w[20020] = {};
	for (int i = 0; i <= k; i++) {
		for (int j = 0; i + j <= k; j++) {
			w[i + j] = (w[i + j] + (long long)a[i] * b[j]) % p;
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	b[0]++;
	a[0] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (v[i] > 0) {
			b[c]++;
			continue;
		} else {
			c++;
			if (c > k) {
				printf("Correct!!! %d\n", i);
				break;
			}
			b[c]++;
		}
		for (int j = i; j <= 1000000; j += i) {
			v[j] = i;
		}
	}
	for (; n > 0; n /= 2) {
		cerr << n << endl;
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
//	for (int i = 0; i <= k; i++) {
//		printf("%d %d\n", i, a[i]);
//	}
	printf("%d\n", a[k]);
	return 0;
}
