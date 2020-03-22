#include <bits/stdc++.h>
using namespace std;
int n, x;
priority_queue<int, vector<int>, greater<int> > q1;
// q1 小根堆，存最大的若干的数字
priority_queue<int, vector<int>, less<int> > q2;
// q2 大根堆，存最小的若干的数字
// 时刻保证 q1中的最小值 >= q2中的最大值 
// 时刻保证 q1.size()==q2.size() 或 q1.size()==q2.size()+1
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (i == 1 || x > q1.top()) {
			q1.push(x);
		} else {
			q2.push(x);
		}
		if (q1.size() < q2.size()) {
			q1.push(q2.top());
			q2.pop();
		}
		if (q1.size() > q2.size() + 1) {
			q2.push(q1.top());
			q1.pop();
		}
		if (i % 2 == 1) {
			printf("%d\n", q1.top());
		}
	}
	return 0;
}