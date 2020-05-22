#include <bits/stdc++.h>
using namespace std;
int x;
int d[100020];
priority_queue<pair<int, int> >q;
int main() {
	scanf("%d", &x);
	memset(d, 0x3f, sizeof d);
	for (int i = 9; i > 0; i--) {
		d[i % x] = i;
		q.push(make_pair(-d[i % x], i % x));
	}
	while (q.size()) {
		pair<int, int> u = q.top();
		q.pop();
		if (d[u.second] < -u.first) {
			continue;
		}
		for (int i = 0; i < 10; i++) {
			int np = (u.second * 10 + i) % x;
			int nd = (-u.first + i);
			if (d[np] > nd) {
				d[np] = nd;
				q.push(make_pair(-d[np], np));
			}
		}
	}
	printf("%d\n", d[0]);
	return 0;
}