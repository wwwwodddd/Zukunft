#include <bits/stdc++.h>
using namespace std;
int v[100000020];
long long ans = 5;
int cnt = 1;

bool judge(int p) {
	return true;
}
int main() {
	int n = 100;
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		if (i % 10 == 1 || i % 10 == 9) {
			if (judge(i)) {
				ans += i;
				cnt++;
				printf("%d\n", i);
			}
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	cout << cnt << endl;
	cout << ans << endl;
	return 0;
}