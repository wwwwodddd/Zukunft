#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, z;
multiset<int> s;
map<int, int> g;
pair<int, pair<int, int> > a[100020];
int main() {
	scanf("%d%*d", &n);
	s.insert(0);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i].X, &a[i].Y.X, &a[i].Y.Y);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (g.find(a[i].Y.X) == g.end()) {
			s.insert(0);
		}
		int &o = g[a[i].Y.X];
		bool wastop = o == *s.rbegin();
		int wascnt = s.count(o);
		s.erase(s.find(o));
		o += a[i].Y.Y;
		s.insert(o);
		bool istop = o == *s.rbegin();
		int iscnt = s.count(o);
		if (wastop) {
			if (!istop || wascnt > 1 || iscnt > 1) {
				z++;
			}
		} else if (istop) {
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}