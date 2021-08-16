#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	a = (a + 11) % 13;
	b = (b + 11) % 13;
	cout << ((a > b) ? "Alice" : ((a < b) ? "Bob" : "Draw")) << endl;
	return 0;
}