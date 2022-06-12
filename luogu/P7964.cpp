#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
string s, t;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		if (s == "section")
		{
			a++;
			b = 0;
			c = 0;
			cout << a << " " << t << endl;
		}
		else if (s == "subsection")
		{
			b++;
			c = 0;
			cout << a << "." << b << " " << t << endl;
		}
		else
		{
			c++;
			cout << a << "." << b << "." << c << " " << t << endl;
		}
	}
	return 0;
}
