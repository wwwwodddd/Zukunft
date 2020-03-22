#include <bits/stdc++.h>
using namespace std;
int a[10];
int fac[10];
int d[362881];
int p[362881];
void decode(int x) {
	int v[10] = {};
	for (int i = 0; i < 9; i++) {
		int cnt = x % fac[9 - i] / fac[8 - i];
		for (int j = 0; j < 9; j++) {
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
	int v[10] = {};
	int re = 0;
	for (int i = 0; i < 9; i++) {
		int cnt = 0;
		for (int j = 0; j < a[i]; j++) {
			if (v[j] == 0) {
				cnt++;
			}
		}
		v[a[i]] = 1;
		re += cnt * fac[8 - i];
	}
	return re;
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < 10; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < fac[9]; i++) {
		d[i] = -1;
	}
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int u = q.front();
		q.pop();
		decode(u);
		{
			swap(a[3], a[4]);
			swap(a[4], a[5]);
			int w = encode();
			if (d[w] == -1) {
				d[w] = d[u] + 1;
				p[w] = u;
				q.push(w);
			}
			swap(a[4], a[5]);
			swap(a[3], a[4]);
		}
		{
			swap(a[2], a[1]);
			swap(a[5], a[2]);
			swap(a[8], a[5]);
			swap(a[7], a[8]);
			swap(a[6], a[7]);
			swap(a[3], a[6]);
			swap(a[0], a[3]);
			int w = encode();
			if (d[w] == -1) {
				d[w] = d[u] + 1;
				p[w] = u;
				q.push(w);
			}
			swap(a[0], a[3]);
			swap(a[3], a[6]);
			swap(a[6], a[7]);
			swap(a[7], a[8]);
			swap(a[8], a[5]);
			swap(a[5], a[2]);
			swap(a[2], a[1]);
		}
	}
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}
	int u = encode();
	printf("%d\n", d[u]);
	while (true) {
		decode(u);
		for (int i = 0; i < 9; i++) {
			printf("%d", a[i]);
			if (i % 3 == 2) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
		printf("\n");
		if (u == 0) {
			break;
		}
		u = p[u];
	}
}