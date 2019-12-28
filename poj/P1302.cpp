#include <stdio.h>
#include <string.h>


int n;
char s[21];


int dfs(int pos) {
	if (s[pos] == '0' || pos == n) {
		return 0;
	}
	if (s[pos] >= 'A' && s[pos] <= 'Z')  {
		int x = dfs(pos+1);
		s[pos] = (x % 10) + '0';
		return x + 1;
	}
	if (s[pos] >= '1' && s[pos] <= '9')  {
		int x;
		if (pos + s[pos] - '0' < n)  {
			x = dfs(pos + s[pos] - '0');
		}
		else  {
			x = dfs(pos + 1);
		}
		s[pos] -= 1;
		return x + 1;
	}
}

int main() {
	while (true) {
		scanf("%s", s);
		if (strcmp(s, "ENDOFINPUT") == 0) {
			break;			
		}
		scanf("%d\n",&n);
		scanf("%s", s);
		dfs(0);
		printf("%s\n", s);
		scanf("%s", s);
	}
	return 0;
}