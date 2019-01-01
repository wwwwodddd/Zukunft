#include <bits/stdc++.h>
using namespace std;
int x, w[] = {1, 2, 3, 5, 10, 20};
bitset<1001> f;
int main() {
	f[0] = 1;
	for (int i = 0; i < 6; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			f |= f << w[i];
		}
	}
	cout << "Total=" << f.count() - 1 << endl;
	return 0;
}