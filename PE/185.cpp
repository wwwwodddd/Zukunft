#include <bits/stdc++.h>
using namespace std;
string s[22] = {"5616185650518293", "3847439647293047", "5855462940810587", "9742855507068353", "4296849643607543", "3174248439465858", "4513559094146117", "7890971548908067", "8157356344118483", "2615250744386899", "8690095851526254", "6375711915077050", "6913859173121360", "6442889055042768", "2321386104303845", "2326509471271448", "5251583379644322", "1748270476758276", "4895722652190306", "3041631117224635", "1841236454324589", "2659862637316867"};
int a[22] = {2, 1, 3, 3, 3, 1, 2, 3, 1, 2, 3, 1, 1, 2, 0, 2, 2, 3, 1, 3, 3, 2};


int gao(string c) {
	int err = 0;
	for (int i = 0; i < 22; i++) {
		int cnt = 0;
		for (int j = 0; j < 16; j++) {
			if (s[i][j] == c[j]) {
				cnt++;
			}
		}
		int dd = abs(cnt - a[i]);
		err += dd * dd;
	}
	return err;
}

unsigned int myrand(unsigned int modulo = 160)
{
  static unsigned int seed = 0;
  seed = 110351511113 * seed + 12345;
  return seed % modulo;
}


string better(string c) {
	int err = gao(c);
	for (int _ = 0; _ < 1000000; _++) {
		string t = c;
		t[rand() % 16] = rand() % 10 + '0';
		t[rand() % 16] = rand() % 10 + '0';
		t[rand() % 16] = rand() % 10 + '0';
		if (gao(t) < err) {
			return t;
		}
	}
	return c;
}

string work() {
	string c = "0000000000000000";
	for (int i = 0; i < 16; i++) {
		c[i] = rand() % 10 + '0';
	}
	int rounds = 0;
	while (true) {
		string t;
		t = better(c);
		if (t == c) {
			break;
		}
		c = t;
		++rounds;
//		cout << ++rounds << ' ' << c << endl;
	}
	return c;
}
int main() {
	for (int _ = 0; _ < 1000; _++) {
		string c = work();
		int err = gao(c);
		if (err < 2) {
			cout << c << ' ' << err << endl;
		}
	} 
	return 0;
}
