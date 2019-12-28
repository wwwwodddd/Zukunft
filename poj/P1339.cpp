#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int t, n;
int main() {
	for (scanf("%d", &t); t--;) {
		priority_queue<int>q;
		int z = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			q.push(-x);
		}
		for (int i = 1; i < n; i++) {
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			z -= x + y;
			q.push(x + y);
		}
		printf("%d\n", z);
	}
	return 0;
}