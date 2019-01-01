#include <bits/stdc++.h>
using namespace std;
int v[1001], a[1001], n;
bool gao() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int d = abs(a[i] - a[i - 1]);
		if (d >= n) {
			return false;
		}
		v[d] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (v[i] == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	printf("%s\n", gao() ? "Jolly" : "Not jolly");
	return 0;
}