#include <bits/stdc++.h>
using namespace std;
int t, n;
int f[45] = {1, 2};
int main() {
	for (int i = 2; i < 45; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		vector<int> a;
		int m = n;
		for (int i = 44; i >= 0; i--) {
			if (m >= f[i]) {
				m -= f[i];
				a.push_back(f[i]);
			}
		}
		reverse(a.begin(), a.end());
		printf("%d=", n);
		for (int i = 0; i < a.size(); i++) {
			if (i > 0) {
				printf("+");
			}
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}