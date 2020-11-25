#include <bits/stdc++.h>
using namespace std;
string s;
int a[8];
int main()
{
	cin >> s;
	for (char c: s)
	{
		if (c == '1' || c == 'Q' || c == 'A' || c == 'Z')
		{
			a[0]++;
		}
		if (c == '2' || c == 'W' || c == 'S' || c == 'X')
		{
			a[1]++;
		}
		if (c == '3' || c == 'E' || c == 'D' || c == 'C')
		{
			a[2]++;
		}
		if (c == '4' || c == 'R' || c == 'F' || c == 'V' || c == '5' || c == 'T' || c == 'G' || c == 'B')
		{
			a[3]++;
		}
		if (c == '6' || c == 'Y' || c == 'H' || c == 'N' || c == '7' || c == 'U' || c == 'J' || c == 'M')
		{
			a[4]++;
		}
		if (c == '8' || c == 'I' || c == 'K' || c == ',')
		{
			a[5]++;
		}
		if (c == '9' || c == 'O' || c == 'L' || c == '.')
		{
			a[6]++;
		}
		if (c == '0' || c == 'P' || c == ';' || c == '/' || c == '-' || c == '[' || c == ']' || c == '=' || c == '\'')
		{
			a[7]++;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}