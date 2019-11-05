#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int v[10000020];
set<int>s;
long long ans = 1;
int p = 500500507;
int main() {
	int n = 10000000;
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			s.insert(i);
			for (int j = i + i; j <= n; j += i) {
				v[j] = 1;
			}
		}
	}
	for (int i = 0; i < 500500; i++) {
		int u = *s.begin();
		s.erase(s.begin());
		if (u <= 10000000 / u) {
			s.insert(u * u);
		}
		ans = ans * u % p;
	}
	printf("%lu\n", s.size());
	printf("%lld\n", ans);
	return 0;
}