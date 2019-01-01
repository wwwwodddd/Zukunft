#include <bits/stdc++.h>
using namespace std;
int n, x;
long long ans;
int main() {
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
	for (int i = 1; i < n; i++) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans << endl;
}