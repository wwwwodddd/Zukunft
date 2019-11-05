#include <iostream>
#include <cstdio>

char s[10000020];
int ss;
int main ()
{
	int i = 0;
	while (true) {
		int tmp = sprintf(s + ss, "%d", i);
		ss += tmp;
		if (ss >= 100) {
			break;
		}
		i += 1;
	}
	printf("%s\n", s);
	return 0;
}