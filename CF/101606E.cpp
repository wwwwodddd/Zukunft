#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[10020];
pair<int, pair<int, int> > b[10020];
set<pair<int, int> >s;
int z[10020];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].first;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i].second.first;
		b[i].second.second = i;
	}
	sort(a, a + n);
	sort(b, b + m);
	int j = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		while (j >= 0 && b[j].first >= a[i].first) {
			s.insert(b[j].second);
			j--;
		}
		if (s.size() == 0) {
			printf("impossible\n");
			return 0;
		} else {
			z[a[i].second] = s.begin()->second + 1;
			s.erase(s.begin());
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d%c", z[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}