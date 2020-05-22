#include <bits/stdc++.h>
using namespace std;
int k, s, z;
int main() {
	cin >> k >> s;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (0 <= s - i - j && s - i - j <= k) {
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}