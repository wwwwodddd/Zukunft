#include <bits/stdc++.h>
#define X first
#define Y second.first
#define Z second.second
using namespace std;
typedef pair<int, pair<int, int> > pos;
pos as, na, at, bs, nb, bt;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
void print(pos A, pos B) {
	printf("(%d %d %d) (%d %d %d)\n", A.X, A.Y, A.Z, B.X, B.Y, B.Z);
}
bool ok(pos A, pos B, pos C, pos D) {
	if (A == B || C == D) {
		return false;
	}
	if (A == D && B == C) {
		return false;
	}
	return true;
}
int main() {
	cin >> as.X >> as.Y >> as.Z;
	cin >> at.X >> at.Y >> at.Z;
	cin >> bs.X >> bs.Y >> bs.Z;
	cin >> bt.X >> bt.Y >> bt.Z;

	print(as, bs);
	while (as != at || bs != bt) {
		na = as;
		nb = bs;
		if (false) {

		} else if (na.X < at.X) {
			na.X++;
		} else if (na.X > at.X) {
			na.X--;
		} else if (na.Y < at.Y) {
			na.Y++;
		} else if (na.Y > at.Y) {
			na.Y--;
		} else if (na.Z < at.Z) {
			na.Z++;
		} else if (na.Z > at.Z) {
			na.Z--;
		}
		if (false) {

		} else if (nb.X < bt.X) {
			nb.X++;
		} else if (nb.X > bt.X) {
			nb.X--;
		} else if (nb.Y < bt.Y) {
			nb.Y++;
		} else if (nb.Y > bt.Y) {
			nb.Y--;
		} else if (nb.Z < bt.Z) {
			nb.Z++;
		} else if (nb.Z > bt.Z) {
			nb.Z--;
		}
		if (ok(as, bs, na, nb)) {
			as = na;
			bs = nb;
			print(as, bs);
		} else {
			while (true) {
				int da = rand() % 6;
				int db = rand() % 6;
				na = as;
				nb = bs;
				na.X += dx[da];
				na.Y += dy[da];
				na.Z += dz[da];
				nb.X += dx[db];
				nb.Y += dy[db];
				nb.Z += dz[db];
				if (ok(as, bs, na, nb)) {
					as = na;
					bs = nb;
					print(as, bs);
					break;
				}
			}
		}
	}
}