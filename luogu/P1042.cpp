#include <bits/stdc++.h>
using namespace std;
char s[66666], c;
int n, w, l;
int main()
{
	while (cin >> c, c != 'E')
	{
		s[n++] = c;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			w++;
		}
		else
		{
			l++;
		}
		if (abs(w - l) >= 2 && max(w, l) >= 11)
		{
			cout << w << ":" << l << endl;
			w = l = 0;
		}
	}
	cout << w << ":" << l << endl << endl;
	w = l = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			w++;
		}
		else
		{
			l++;
		}
		if (abs(w - l) >= 2 && max(w, l) >= 21)
		{
			cout << w << ":" << l << endl;
			w = l = 0;
		}
	}
	cout << w << ":" << l << endl;
	w = l = 0;
	return 0;
}