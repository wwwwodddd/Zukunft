#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int main() {
	int n = 125000;
	for (int i = 1; i < n; i++) {
		if (i % 1000 == 0) {
			cerr << i << ' ' << a.size() << endl;
		}
		long long t = (long long)i * i + 1;
		for (long long j = 1; j < t / j; j++) {
			if (t % j == 0) {
				if (((double)i * (i + j) * (i + t / j)) > 1884161251122450) {
					continue;
				}
				a.push_back((long long)i * (i + j) * (i + t / j));
			}
		}
	}
	cerr << a.size() << endl;
	sort(a.begin(), a.end());
	for (int i = 0; i < 10; i++) {
		//cerr << a[i] << endl;
	}
	cout << a[150000 - 1] << endl;
	return 0;
}
