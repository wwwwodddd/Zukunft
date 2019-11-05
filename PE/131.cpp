#include <iostream>
#include <cstdio>
using namespace std;
int z;
int v[1000020];
int main() {
	for (int i = 2; i <= 1000000; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= 1000000; j += i) {
				v[j] = i;
			}
		}
	}
	for (int i = 1;; i++) {
		int u = (i + 1) * (i + 1) * (i + 1) - i * i * i;
		if (u > 1000000) {
			break;
		}
		if (v[u] == u) {
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}