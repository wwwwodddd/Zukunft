#include <bits/stdc++.h>
using namespace std;
int n;
int answer;
int number, price;
int main() {
	scanf("%d", &n);
	scanf("%d%d", &number, &price);
	answer = (n + number - 1) / number * price;
	scanf("%d%d", &number, &price);
	answer = min(answer, (n + number - 1) / number * price);
	scanf("%d%d", &number, &price);
	answer = min(answer, (n + number - 1) / number * price);
	printf("%d\n", answer);
	return 0;
}