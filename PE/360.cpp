#include <bits/stdc++.h>
using namespace std;
long long n = 45 * 45;
set<tuple<int, int, int> >s;
map<int, int> g;
void fuck(int x, int y, int z) {
	s.insert(make_tuple(x, y, z));
	s.insert(make_tuple(x, y, -z));
	s.insert(make_tuple(x, -y, z));
	s.insert(make_tuple(x, -y, -z));
	s.insert(make_tuple(-x, y, z));
	s.insert(make_tuple(-x, y, -z));
	s.insert(make_tuple(-x, -y, z));
	s.insert(make_tuple(-x, -y, -z));
}
int main() {
	int cnt = 0;
	for (long long i = 0; i * i <= n; i++) {
		if (i % 100 == 0) {
			cerr << i << endl;
		}
		for (long long j = i; i * i + j * j + j * j <= n; j++) {
			long long kk = n - i * i - j * j;
			long long k = (int)(sqrt(kk) + 0.5);
			if (k * k == kk) {
				assert(i <= j && j <= k);
				s.clear();
				fuck(i, j, k);
				fuck(j, k, i);
				fuck(k, i, j);
				fuck(i, k, j);
				fuck(k, j, i);
				fuck(j, i, k);
				cnt++;
				cerr << i << ' ' << j << ' ' << k << endl;
				for (const auto &i: s) {
					g[get<0>(i)]++;
				}
			}
		}
	}
	long long sum = 0;
	for (const auto &i: g) {
		sum += abs(i.first) * i.second;
	}
	cerr << sum * 3 << endl;
	cerr << cnt << endl;
}