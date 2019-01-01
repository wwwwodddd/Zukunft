#include <bits/stdc++.h>
using namespace std;
long long k, n, z, t = 1;
int main() {
	cin >> k >> n;
	for (int i = 0; i < 15; i++) {
		if (n >> i & 1) {
			z += t;
		}
		t *= k;
	}
	cout << z << endl;
	return 0;
}