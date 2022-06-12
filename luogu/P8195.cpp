#include <bits/stdc++.h>
using namespace std;
int z, p;
string s;
int main()
{
	cin >> s;
	while (true)
	{
		p = s.find("chuanzhi", p);
		if (p == -1)
		{
			break;
		}
		p++;
		z++;
	}
	cout << z << endl;
	return 0;
}
