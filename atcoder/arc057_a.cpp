#include <bits/stdc++.h>
using namespace std;
long long a, k, z = 2e12;
int main() {
	cin >> a >> k;
	if (k == 0) {
		cout << z - a << endl;
	} else {
		int i = 0;
		while (a < z) {
			a += 1 + k * a;
			i++;
		}
		cout << i << endl;
	}
	return 0;
}