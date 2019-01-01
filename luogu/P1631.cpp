#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int b[100020];
int p[100020];
priority_queue<pair<int, int> > q;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		q.push(make_pair(-a[p[i]] - b[i], i));
	}
	for (int i = 0; i < n; i++) {
		pair<int, int> u = q.top();
		q.pop();
		printf("%d", -u.first);
		if (i == n - 1) {
			printf("\n");
			break;
		} else {
			printf(" ");
		}
		p[u.second]++;
		q.push(make_pair(-a[p[u.second]] - b[u.second], u.second));
	}
	return 0;
}