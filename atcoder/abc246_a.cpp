#include <bits/stdc++.h>
using namespace std;
int s, t, x, y;
int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		s ^= x;
		t ^= y;
	}
	cout << s << " " << t << endl;
	return 0;
}
