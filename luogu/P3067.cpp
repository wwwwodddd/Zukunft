#include <bits/stdc++.h>
using namespace std;
int n, ss1, ss2;
int a[22];
pair<int, int> s1[60000];
pair<int, int> s2[60000];
bitset<1048576> v;
void gao(int *a, int n, pair<int, int> *s, int &ss)
{
	ss = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = i;; j = (j - 1) & i)
		{
			int u = 0;
			for (int k = 0; k < n; k++)
			{
				if (j >> k & 1)
				{
					u -= a[k];
				}
				else if (i >> k & 1)
				{
					u += a[k];
				}
			}
			s[ss++] = make_pair(u, i);
			if (j == 0)
			{
				break;
			}
		}
	}
	sort(s, s + ss);
	ss = unique(s, s + ss) - s;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	random_shuffle(a, a + n);
	gao(a, n / 2, s1, ss1);
	gao(a + n / 2, n - n / 2, s2, ss2);
	for (int i = 0, j = 0; i < ss1; i++)
	{
		while (j < ss2 && s1[i].first > s2[j].first)
		{
			j++;
		}
		for (int k = j; k < ss2 && s1[i].first == s2[k].first; k++)
		{
			v[s1[i].second | s2[k].second << (n / 2)] = 1;
		}
	}
	cout << v.count() - 1 << endl;
	return 0;
}