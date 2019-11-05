#include <bits/stdc++.h>
using namespace std;
const int L = 15;
vector<vector<int> >s;
int a[40][40];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int xx[20];
int yy[20];
void dfs(int x, int y, int l) {
	xx[l] = x;
	yy[l] = y;
	a[x][y] = l;
	if (l == 1) {
		vector<int> r(L * (L + 1));
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < i; j++) {
				if (abs(xx[i + 1] - xx[j + 1]) + abs(yy[i + 1] - yy[j + 1]) == 1) {
					r[i * (i - 1) / 2 + j] = 1;
				}
			}
		}
		s.push_back(r);
	} else {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (a[nx][ny] > 0) {
				continue;
			}
			dfs(nx, ny, l - 1);
		}
	}
	a[x][y] = 0;
}

int main() {
	dfs(20, 20, L);
	int ans = 0;
	set<vector<int> > ss(s.begin(), s.end());
	cerr << ss.size() << endl;
	vector<vector<int> > sss(ss.rbegin(), ss.rend());
	s.clear();
	for (int i = 0; i < sss.size(); i++) {
		bool cao = true;
		for (int j = 0; j < s.size(); j++) {
			bool gao = true;
			for (int k = 0; k < L * (L - 1) / 2; k++) {
				if (sss[i][k] > s[j][k]) {
					gao = false;
					break;
				}
			}
			if (gao) {
				cao = false;
				break;
			}
		}
		if (cao) {
			s.push_back(sss[i]);
		}
	}
	cerr << s.size() << endl;
	for (int i = 0; i < 1 << L; i++) {
		int best = 0;
		for (int j = 0; j < s.size(); j++) {
			int tmp = 0;
			for (int k = 0; k < L; k++) {
				for (int l = 0; l < k; l++) {
					if ((i >> k & 1) && (i >> l & 1)) {
						if (s[j][k * (k - 1) / 2 + l]) {
							tmp++;
						}
					}
				}
			}
			best = max(best, tmp);
		}
		ans += best;
	}
	cerr << ans << endl;
	return 0;
}
