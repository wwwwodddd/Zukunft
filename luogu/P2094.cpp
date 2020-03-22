#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n, k, x;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	while (q.size() > 1) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		q.push((x + y) / k);
	}
	cout << q.top() << endl;
	return 0;
}