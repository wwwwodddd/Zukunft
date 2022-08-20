#include <bits/stdc++.h>
using namespace std;
int l1, r1, l2, r2;
int main()
{
	cin >> l1 >> r1 >> l2 >> r2;
	cout << max(min(r1, r2) - max(l1, l2), 0) << endl;
	return 0;
}
