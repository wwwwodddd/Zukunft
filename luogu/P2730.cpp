#include <bits/stdc++.h>
using namespace std;
int a[9];
int fac[9];
int d[40321];
char o[40321];
int p[40321];
void decode(int x) {
	int v[9] = {};
	for (int i = 0; i < 8; i++) {
		int cnt = x % fac[8 - i] / fac[7 - i];
		for (int j = 0; j < 8; j++) {
			if (v[j] == 0) {
				if (cnt == 0) {
					a[i] = j;
					v[j] = 1;
					break;
				} else {
					cnt--;
				}
			}
		}
	}
}
int encode() {
	int v[9] = {};
	int re = 0;
	for (int i = 0; i < 8; i++) {
		int cnt = 0;
		for (int j = 0; j < a[i]; j++) {
			if (v[j] == 0) {
				cnt++;
			}
		}
		v[a[i]] = 1;
		re += cnt * fac[7 - i];
	}
	return re;
}
void dfs(int x) {
	if (x > 0) {
		dfs(p[x]);
		printf("%c", o[x]);
	}
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < 9; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < fac[8]; i++) {
		d[i] = -1;
	}
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int u = q.front(), w;
		q.pop();
		decode(u);
		reverse(a, a + 8);
		w = encode();
		if (d[w] == -1) {
			d[w] = d[u] + 1;
			o[w] = 'A';
			p[w] = u;
			q.push(w);
		}
		decode(u);
		rotate(a + 0, a + 3, a + 4);
		rotate(a + 4, a + 5, a + 8);
		w = encode();
		if (d[w] == -1) {
			d[w] = d[u] + 1;
			o[w] = 'B';
			p[w] = u;
			q.push(w);
		}
		decode(u);
		swap(a[1], a[2]);
		swap(a[1], a[6]);
		swap(a[5], a[6]);
		w = encode();
		if (d[w] == -1) {
			d[w] = d[u] + 1;
			o[w] = 'C';
			p[w] = u;
			q.push(w);
		}
	}
	for (int i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	printf("%d\n", d[encode()]);
	dfs(encode());
	printf("\n");
	return 0;
}