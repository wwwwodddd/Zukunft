#include <bits/stdc++.h>
using namespace std;
int h, m;
int main()
{
	cin >> h >> m;
	m += h * 60;
	m += 1395;
	h = m / 60 % 24;
	m %= 60;
	cout << h << " " << m << endl;
	return 0;
}
