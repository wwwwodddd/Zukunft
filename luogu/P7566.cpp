#include <bits/stdc++.h>
using namespace std;
long long n, m, c, o, i;
char s[20];
int main()
{
	cin >> n;
	while(n--)
	{
		cin >> s;
		if (*s == 'M')
		{
			m++;
		}
		else if (*s == 'C')
		{
			c++;
		}
		else if (*s == 'O')
		{
			o++;
		}
		else if (*s == 'I')
		{
			i++;
		}
	}
	cout << m * c * o + m * c * i + m * o * i + c * o * i << endl;
	return 0;
}