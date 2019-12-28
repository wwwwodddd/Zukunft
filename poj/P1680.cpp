#include <iostream>
#include <cstdio>
using namespace std;
int id, n, k, cnt, t;
void dfs(int s) {
	for (int i = s, pid = id; i < n; i++) {
		if (++cnt == k) {
			printf("Loop %d: Process ID=%d\n", i, pid);
		}
		id++;
		if (++cnt == k) {
			printf("Process ID=%d, A=%d\n", id, (i + 1) * 7);
		}
		dfs(i + 1);
	} 
}
int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d%d", &n, &k);
		cnt = 0;
		id = 1000;
		dfs(0);
	}
	return 0;
}