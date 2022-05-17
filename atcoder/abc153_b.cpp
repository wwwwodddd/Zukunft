#include <bits/stdc++.h>
using namespace std;
int h, n, x;
int main()
{
	cin >> h >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		h -= x;
	}
	cout << (0<h?"No":"Yes") << endl;
	return 0;
}
