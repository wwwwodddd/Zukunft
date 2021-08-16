#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	cout << ((a + b > c + d) ? "Left" : ((a + b < c + d) ? "Right" : "Balanced")) << endl;
	return 0;
}