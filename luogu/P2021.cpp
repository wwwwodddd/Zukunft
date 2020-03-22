#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		q.push_front(n - i);
		q.push_front(q.back());
		q.pop_back();
	}
	for (int i = 0; i < n; i++) {
		cout << q[i] << ' ';
	}
	return 0;
}