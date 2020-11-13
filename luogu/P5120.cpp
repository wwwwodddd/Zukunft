#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
pair<pair<int, int>, int> a[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].X.X, &a[i].Y);
		a[i].X.Y = i;
	}
	sort(a, a + n);
	int z = 0, i = 0, t = 0;
	set<pair<pair<int, int>, int> > s;
	while (i < n || s.size()) {
		while (i < n && a[i].X.X <= t) {
			swap(a[i].X.X, a[i].X.Y);
			s.insert(a[i++]);
		}
		if (s.size() == 0) {
			t = a[i].X.X;
			continue;
		}
		z = max(z, t - s.begin()->X.Y);
		t += s.begin()->Y;
		s.erase(s.begin());
	}
	printf("%d\n", z);
	return 0;
}