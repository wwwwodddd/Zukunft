#include <bits/stdc++.h>
using namespace std;
int s, x, w;
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> x;
		s += (x + 9) / 10 * 10;
		w = max(w, 9 - (x + 9) % 10);
	}
	cout << s - w << endl;
}
