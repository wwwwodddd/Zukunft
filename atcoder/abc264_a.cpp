#include <bits/stdc++.h>
using namespace std;
int l, r;
int main()
{
	cin >> l >> r;
	cout << string("atcoder").substr(l - 1, r - l + 1) << endl;
	return 0;
}
