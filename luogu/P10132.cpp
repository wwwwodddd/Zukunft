#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[200020][2];
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	int p = 1;
	int d = 1;
	int z = 0;
	s -= 1;
	int cnt = 0;
	while (0 <= s && s < n)
	{
		cnt++;
		if (cnt > 30000000)
		{
			break;
		}
		if (a[s][0] == 1)
		{
			if (p >= a[s][1])
			{
				z += 1;
				a[s][1] = 1000000000;
			}
			s += p * d;
		}
		else
		{
			p += a[s][1];
			d = -d;
			s += p * d;
		}
	}
	cout << z << endl;
	return 0;
}
