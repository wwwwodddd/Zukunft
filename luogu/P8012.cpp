#include <bits/stdc++.h>
using namespace std;
int n, o, c;
int main()
{
	cin >> n >> o;
	c = o / (n - 1);
	cout << o + c - (o % (n - 1) == 0) << " " << o + c << endl;
	return 0;
}
