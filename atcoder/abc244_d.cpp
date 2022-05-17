#include <bits/stdc++.h>
using namespace std;
char a, b, c;
int z;
int main()
{
	cin >> a >> b >> c;
	z += (a > b) + (b > c) + (a > c);
	cin >> a >> b >> c;
	z += (a > b) + (b > c) + (a > c);
	cout << (z & 1 ? "No" : "Yes") << endl;
	return 0;
}
