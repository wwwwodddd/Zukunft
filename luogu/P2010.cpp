#include <bits/stdc++.h>
using namespace std;
int date1, date2, answer;
int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	scanf("%d%d", &date1, &date2);
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= days[i]; j++) {
			char s[5];
			sprintf(s, "%02d%02d", i, j);
			reverse(s, s + 4);
			int k;
			sscanf(s, "%d", &k);
			int date = 10000 * k + 100 * i + j;
			if (date1 <= date && date <= date2) {
				answer++;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}