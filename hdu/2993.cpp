#include <bits/stdc++.h>
using namespace std;
double s[100020];
int a[100020], n, k;

namespace fastIO
{
#define BUF_SIZE 100000
	// fread -> read
	bool IOerror = 0;
	inline char nc()
	{
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if (p1 == pend)
		{
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if (pend == p1)
			{
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch)
	{
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(int &x)
	{
		char ch;
		while (blank(ch = nc()))
			;
		if (IOerror)
			return;
		for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
			;
	}
#undef BUF_SIZE
};
using namespace fastIO;

int main()
{
	while (read(n), read(k), !IOerror)
	{
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
		}
		double l = 0, r = 2000;
		for (int _ = 0; _ < 25; _++)
		{
			double z = (l + r) / 2;
			bool ok = false;
			double m = 0;
			for (int i = 1; i <= n; i++)
			{
				s[i] = s[i - 1] + a[i] - z;
				if (i >= k)
				{
					m = min(m, s[i - k]);
					if (s[i] >= m)
					{
						ok = true;
						break;
					}
				}
			}
			if (ok)
			{
				l = z;
			}
			else
			{
				r = z;
			}
		}
		printf("%.2f\n", l);
	}
	return 0;
}