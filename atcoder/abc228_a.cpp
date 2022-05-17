#include <bits/stdc++.h>
using namespace std;
int s, t, x;
int main()
{
	cin >> s >> t >> x;
	cout << (s < t ^ s <= x ^ x < t ? "Yes" : "No") << endl;
	return 0;
}
