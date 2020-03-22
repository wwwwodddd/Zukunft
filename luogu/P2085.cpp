#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10020];
int b[10020];
int c[10020];
int p[10020];
priority_queue<pair<int, int> > q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		int j = i;
		p[j]++;
		q.push(make_pair(-a[j] * p[j] * p[j] - b[j] * p[j] - c[j], j));
	}
	for (int i = 0; i < m; i++) {
		pair<int, int> u = q.top();
		q.pop();
		printf("%d%c", -u.first, i == m - 1 ? '\n' : ' ');
		int j = u.second;
		p[j]++;
		q.push(make_pair(-a[j] * p[j] * p[j] - b[j] * p[j] - c[j], j));
	}
	return 0;
}