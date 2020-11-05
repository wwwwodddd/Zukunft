#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main()
{
	cin >> a >> b >> c;
	puts(a * a > b * c ? "Alice" : "Bob");
	return 0;
}