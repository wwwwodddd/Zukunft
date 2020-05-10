#include <bits/stdc++.h>
using namespace std;
int n;
int h[1000], r[1000], t[1000];
int main() {
	cin >> n;
	int maxh = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i] >> r[i] >> t[i];
		maxh = max(maxh, h[i]);
	}
	for (int i = 0; i <= maxh * 1825; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			int tt = i % h[j];
			if (r[j] < t[j]) {
				if (r[j] < tt && tt < t[j]) {
					flag = false;
				}
			} else {
				if (tt > r[j] || tt < t[j]) {
					flag = false;
				}
			}
		}
		if (flag) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("impossible\n");
	return 0;
}