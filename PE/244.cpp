#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long d[17][65537];
long long f[17][65537];
long long g[17][65537];
int b[17];
queue<pair<int, int> > q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dc[] = "LRUD";
int mod = 100000007;
bool in(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}
int main() {
	int s = 0b1100110011001100;
	int t = 0b0101101001011010;
	memset(d, -1, sizeof d);
	d[0][s] = 0;
	f[0][s] = 0;
	g[0][s] = 1;
	q.push(make_pair(0, s));
	while (q.size()) {
		pair<int, int> u = q.front();
		q.pop();
		int x = u.X / 4;
		int y = u.X % 4;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (in(nx, ny)) {
				for (int i = 0; i < 16; i++) {
					b[i] = (u.Y >> i & 1);
				}
				int nz = nx * 4 + ny;
				swap(b[u.X], b[nz]);
				int nb = 0;
				for (int i = 0; i < 16; i++) {
					nb |= b[i] << i;
				}
				assert(__builtin_popcount(nb) == 8 && (nb >> nz & 1) == 0);
				if (d[nz][nb] == -1) {
					d[nz][nb] = d[u.X][u.Y] + 1;
					f[nz][nb] = (f[u.X][u.Y] * 243 + dc[k] * g[u.X][u.Y]) % mod;
					g[nz][nb] = g[u.X][u.Y];
					q.push(make_pair(nz, nb));
				} else if (d[nz][nb] == d[u.X][u.Y] + 1) {
					f[nz][nb] = (f[nz][nb] + f[u.X][u.Y] * 243 + dc[k] * g[u.X][u.Y]) % mod;
					g[nz][nb] = (g[nz][nb] + g[u.X][u.Y]) % mod;
				}
			}
		}
	}
	cout << d[0][t] << ' ' << f[0][t] << ' ' << g[0][t] << endl;
	return 0;
}